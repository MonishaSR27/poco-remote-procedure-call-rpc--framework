#include "serialization.h"
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Parser.h>
#include <Poco/Dynamic/Var.h>
#include <sstream>

using namespace Poco::JSON;
using namespace Poco::Dynamic;

// Converts method + parameter into JSON text
std::string serializeRequest(const std::string& method, const std::string& param) {
    Object obj;
    obj.set("method", method);
    obj.set("param", param);
    std::ostringstream oss;
    obj.stringify(oss);
    return oss.str();
}

// Reads JSON text and extracts method + parameter
void deserializeRequest(const std::string& json, std::string& method, std::string& param) {
    Parser parser;
    Var result = parser.parse(json);
    Object::Ptr object = result.extract<Object::Ptr>();
    method = object->getValue<std::string>("method");
    param = object->getValue<std::string>("param");
}

// Makes a simple response JSON
std::string makeResponse(const std::string& result) {
    Object obj;
    obj.set("result", result);
    std::ostringstream oss;
    obj.stringify(oss);
    return oss.str();
}
