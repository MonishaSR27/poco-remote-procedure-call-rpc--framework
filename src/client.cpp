#include <iostream>
#include "rpc_client_lib.h"
#include "Poco/JSON/Object.h"
#include "Poco/JSON/Parser.h"

int main() {
    std::cout << "RPC Client starting..." << std::endl;

    RPCClient client("127.0.0.1", 9000);

    // ----------- EXAMPLE CALL 1: Echo ---------------
    {
        Poco::JSON::Object::Ptr p = new Poco::JSON::Object();
        p->set("text", "Hello RPC");

        std::string res = client.call("reverse", p);
        std::cout << "Server replied: " << res << std::endl;
    }

    // ----------- EXAMPLE CALL 2: Add ---------------
    {
        Poco::JSON::Object::Ptr p = new Poco::JSON::Object();
        p->set("a", 10);
        p->set("b", 20);

        std::string res = client.call("add", p);
        std::cout << "Server replied: " << res << std::endl;
    }

    // ----------- EXAMPLE CALL 3: Subtract -----------
    {
        Poco::JSON::Object::Ptr p = new Poco::JSON::Object();
        p->set("a", 50);
        p->set("b", 15);

        std::string res = client.call("subtract", p);
        std::cout << "Server replied: " << res << std::endl;
    }

    return 0;
}
