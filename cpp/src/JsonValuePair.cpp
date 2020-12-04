#include <string>
#include "../include/JsonValuePair.hpp"
#include <memory>

JsonValuePair::JsonValuePair(const char* key, std::shared_ptr<JsonData> value):_key(key),_value(value){}
std::string JsonValuePair::getString(){
    return "\""+_key+"\""+":"+_value->getString();
}

