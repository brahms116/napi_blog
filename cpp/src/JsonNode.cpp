#include "../include/JsonNode.hpp"
#include <memory>



void JsonObject::addChild(std::shared_ptr<JsonValuePair> x){
    _children.emplace_back(x);
}

std::string JsonObject::readChildren(){
    std::string str = "";
    for(std::shared_ptr<JsonValuePair> valuePair: _children){
        str+=valuePair->getString();
        str+=",";
    }
    if(str.size()!=0){
        str.erase(str.size()-1);
    }
    return str;

}

std::string JsonObject::getString(){
    return "{"+readChildren()+"}";
}



void JsonArray::addChild(std::shared_ptr<JsonData> x){
    _children.emplace_back(x);
}

std::string JsonArray::readChildren(){
    std::string str = "";
    for(std::shared_ptr<JsonData> element: _children){
        str+=element->getString();
        str+=",";
    }
    if(str.size()!=0){
        str.erase(str.size()-1);
    }
    return str;
}

std::string JsonArray::getString(){
    return "["+readChildren()+"]";
}