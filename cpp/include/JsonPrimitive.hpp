#ifndef JSON_PRIMITIVE
#define JSON_PRIMITIVE

#include "./JsonData.hpp"
#include <string>
#include <memory>


class JsonPrimitiveHolder{
public:
    virtual std::string getValue() = 0;
};

class JsonPrimitiveDouble: public JsonPrimitiveHolder{
private:
    double _value;
public:
    JsonPrimitiveDouble(const double x);
    std::string getValue() override;
};
class JsonPrimitiveLong: public JsonPrimitiveHolder{
private:
    long _value;
public:
    JsonPrimitiveLong(const long x);
    std::string getValue() override;
};

class JsonPrimitiveString: public JsonPrimitiveHolder{
private:
    std::string _value;
public:
    JsonPrimitiveString(const char* x);
    std::string getValue() override;
};


class JsonPrimitive :public JsonData{
private:
    bool _isNull;
    std::shared_ptr<JsonPrimitiveHolder> _data;
public:
    JsonPrimitive();
    JsonPrimitive(const char * x);
    JsonPrimitive(const std::string x);
    JsonPrimitive(const double x);
    JsonPrimitive(const int x);
    JsonPrimitive(const long x);

    std::string getString() override;
};

#endif