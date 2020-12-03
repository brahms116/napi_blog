#ifndef JSON_NODE
#define JSON_NODE
#include "./JsonData.hpp"
#include <vector>
#include <memory>
#include "./JsonValuePair.hpp"

class JsonNode:public JsonData{
public:
    virtual std::string readChildren()=0;
};

class JsonObject:public JsonNode{
private:
    std::vector<std::shared_ptr<JsonValuePair>> _children;
public:
    JsonObject()=default;
    std::string readChildren() override;
    std::string getString() override;
    void addChild(std::shared_ptr<JsonValuePair>);
};

class JsonArray: public JsonNode{
private:
    std::vector<std::shared_ptr<JsonData>> _children;
public:
    JsonArray()=default;
    std::string readChildren() override;
    std::string getString() override;
    void addChild(std::shared_ptr<JsonData>);
};

#endif