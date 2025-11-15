#include <Poco/Net/TCPServer.h>
#include <Poco/Net/TCPServerConnection.h>
#include <Poco/Net/TCPServerConnectionFactory.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketStream.h>

#include <Poco/JSON/Parser.h>
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Stringifier.h>

#include <iostream>
#include <algorithm>

using namespace Poco::Net;
using namespace Poco::JSON;

class RPCConnection : public TCPServerConnection {
public:
    RPCConnection(const StreamSocket& s) : TCPServerConnection(s) {}

    void run() override {
        try {
            StreamSocket& socket = this->socket();
            Poco::Net::SocketStream str(socket);

            std::string request;
            std::getline(str, request);

            std::cout << "Received: " << request << std::endl;

            Parser parser;
            Poco::Dynamic::Var json = parser.parse(request);
            Object::Ptr obj = json.extract<Object::Ptr>();

            std::string method = obj->getValue<std::string>("method");
            Object::Ptr params = obj->getObject("params");

            Object reply;

            if (method == "reverse") {
                std::string text = params->getValue<std::string>("text");
                std::reverse(text.begin(), text.end());
                reply.set("result", text);
            }
            else if (method == "add") {
                int a = params->getValue<int>("a");
                int b = params->getValue<int>("b");
                reply.set("result", a + b);
            }
            else if (method == "subtract") {
                int a = params->getValue<int>("a");
                int b = params->getValue<int>("b");
                reply.set("result", a - b);
            }
            else {
                reply.set("error", "Unknown method");
            }

            std::stringstream out;
            Stringifier::stringify(reply, out);
            str << out.str() << std::endl;
            str.flush();
        }
        catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
};

int main() {
    std::cout << "RPC Server starting..." << std::endl;

    ServerSocket svs(9000);
    TCPServer server(new TCPServerConnectionFactoryImpl<RPCConnection>(), svs);

    server.start();
    std::cout << "Server running on port 9000. Waiting for RPC calls..." << std::endl;

    for (;;) Poco::Thread::sleep(1000);
    return 0;
}
