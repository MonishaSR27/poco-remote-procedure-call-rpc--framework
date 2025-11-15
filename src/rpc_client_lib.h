#pragma once
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/JSON/Object.h"
#include "Poco/JSON/Stringifier.h"
#include <iostream>

class RPCClient {
private:
    std::string host;
    int port;

public:
    RPCClient(const std::string& h, int p) : host(h), port(p) {}

    // Send request with retry mechanism
    std::string call(const std::string& method, Poco::JSON::Object::Ptr params) {
        int retries = 3;

        while (retries--) {
            try {
                Poco::Net::SocketAddress sa(host, port);
                Poco::Net::StreamSocket socket(sa);
                Poco::Net::SocketStream str(socket);

                // Build JSON request
                Poco::JSON::Object req;
                req.set("method", method);
                req.set("params", params);

                std::stringstream out;
                Poco::JSON::Stringifier::stringify(req, out);

                std::cout << "Sending: " << out.str() << std::endl;
                str << out.str() << std::endl;
                str.flush();

                // Read response
                std::string response;
                std::getline(str, response);

                return response;
            }
            catch (std::exception& e) {
                std::cout << "[Error] " << e.what()
                    << " | retrying..." << std::endl;

                Poco::Thread::sleep(500);  // retry delay
            }
        }

        return "{\"error\":\"Failed after retries\"}";
    }
};
