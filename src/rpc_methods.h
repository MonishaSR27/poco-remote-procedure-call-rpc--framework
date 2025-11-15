#pragma once
#include <string>
#include <sstream>

class RPCMethods {
public:
    static std::string add(int a, int b) {
        return std::to_string(a + b);
    }

    static std::string subtract(int a, int b) {
        return std::to_string(a - b);
    }

    static std::string reverse_string(const std::string& s) {
        std::string r = s;
        std::reverse(r.begin(), r.end());
        return r;
    }
};
