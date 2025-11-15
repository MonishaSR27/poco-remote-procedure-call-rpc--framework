#ifndef RPC_PROTOCOL_H
#define RPC_PROTOCOL_H

#include <string>

struct RPCRequest {
    std::string method;
    std::string param;
};

struct RPCResponse {
    std::string result;
};

#endif
