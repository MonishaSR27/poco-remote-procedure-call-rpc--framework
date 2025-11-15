#include <iostream>
#include "serialization.h"

int main() {
    // Convert data into JSON
    std::string j = serializeRequest("echo", "Hello RPC");
    std::cout << "Serialized: " << j << std::endl;

    // Convert JSON back to variables
    std::string method, param;
    deserializeRequest(j, method, param);
    std::cout << "Deserialized: method=" << method << ", param=" << param << std::endl;

    // Make response
    std::string resp = makeResponse("OK");
    std::cout << "Response: " << resp << std::endl;

    return 0;
}
