
#ifndef JSON_VALUE_PAIR
#define JSON_VALUE_PAIR
#include "./JsonData.hpp"
#include "./JsonPrimitive.hpp"
#include <memory>
#include <string>
class JsonValuePair{
private:
    std::string _key;
    std::shared_ptr<JsonData> _value;

public:
    JsonValuePair(const char * key, std::shared_ptr<JsonData> value);
    std::string getString();
};

#endif