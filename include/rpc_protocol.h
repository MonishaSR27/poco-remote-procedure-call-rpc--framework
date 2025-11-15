#ifndef RPC_PROTOCOL_H
#define RPC_PROTOCOL_H

#include <string>
#include <vector>
#include <cstdint>

namespace poco_rpc {

// RPC message types
enum class MessageType : uint8_t {
    REQUEST = 0,
    RESPONSE = 1,
    ERROR = 2
};

// RPC request structure
struct RpcRequest {
    uint32_t request_id;
    std::string method_name;
    std::vector<uint8_t> parameters;
};

// RPC response structure
struct RpcResponse {
    uint32_t request_id;
    bool success;
    std::vector<uint8_t> result;
    std::string error_message;
};

// Protocol version
constexpr uint8_t PROTOCOL_VERSION = 1;

// Serialization functions
std::vector<uint8_t> serialize_request(const RpcRequest& request);
RpcRequest deserialize_request(const std::vector<uint8_t>& data);

std::vector<uint8_t> serialize_response(const RpcResponse& response);
RpcResponse deserialize_response(const std::vector<uint8_t>& data);

} // namespace poco_rpc

#endif // RPC_PROTOCOL_H

