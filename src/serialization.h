#pragma once
#include <string>

std::string serializeRequest(const std::string& method, const std::string& param);
void deserializeRequest(const std::string& json, std::string& method, std::string& param);
std::string makeResponse(const std::string& result);
