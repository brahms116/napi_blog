#include "../include/JsonPrimitive.hpp"
#include <string>
#include <cmath>
#include <memory>
#include <sstream>
#include <iostream>
#include <iomanip>
JsonPrimitiveDouble::JsonPrimitiveDouble(const double x):_value(x){};
std::string JsonPrimitiveDouble::getValue(){
    if(std::ceil(_value)==_value){
        return std::to_string(static_cast<int>(_value));
    }else{
        std::stringstream stream;
        stream<<std::fixed<<std::setprecision(10)<<_value;
        // stream<<_value;
        std::string str = stream.str();
        bool isDecimal = false;
        bool countingZero = false;
        int startOfZero = 0;
        for(int i = 0; i<str.size();i++){
            if(str[i]=='.'){
                isDecimal = true;
            }
            if(str[i]=='0'&& isDecimal &&!countingZero){
                startOfZero = i;
                countingZero = true;
            }
            if(!(str[i]=='0') && isDecimal){
                countingZero = false;
            }
            if(i==str.size()-1){
                if(countingZero){
                    str.erase(startOfZero);
                }
            }
        }
        return str;
    }
}

JsonPrimitiveLong::JsonPrimitiveLong(const long x):_value(x){};
std::string JsonPrimitiveLong::getValue(){
    return std::to_string(_value);
}

JsonPrimitiveString::JsonPrimitiveString(const char* x):_value(x){};
std::string JsonPrimitiveString::getValue(){
    return "\""+std::string(_value)+"\"";
}


JsonPrimitive::JsonPrimitive(){
    _isNull = true;
}
JsonPrimitive::JsonPrimitive(const std::string x){
    _isNull = false;
    _data = std::make_shared<JsonPrimitiveString>(x.c_str()); 

}
JsonPrimitive::JsonPrimitive(const char * x){
    _isNull = false;
    _data = std::make_shared<JsonPrimitiveString>(x); 
}
JsonPrimitive::JsonPrimitive(const double x){
    _isNull = false;
    _data = std::make_shared<JsonPrimitiveDouble>(x);
}
JsonPrimitive::JsonPrimitive(const long x){
    _isNull = false;
    _data = std::make_shared<JsonPrimitiveLong>(x);
}
JsonPrimitive::JsonPrimitive(const int x){
    _isNull= false;
    _data = std::make_shared<JsonPrimitiveLong>(x);
}

std::string JsonPrimitive::getString(){
    if(_isNull){
        return "null";
    }else{
        return _data->getValue();
    }
}


