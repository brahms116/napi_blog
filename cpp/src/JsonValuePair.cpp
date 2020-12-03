#include <string>
#include "../include/JsonValuePair.hpp"
#include <memory>

JsonValuePair::JsonValuePair(const char* key, std::shared_ptr<JsonData> value):_value(value),_key(key){}
std::string JsonValuePair::getString(){
    return "\""+_key+"\""+":"+_value->getString();
}

