#include "napi.h"



Napi::Value getJson(const Napi::CallbackInfo &info){
    if(info.Length()<2){
        Napi::TypeError::New(info.Env(),"Wrong number of Arguements").ThrowAsJavaScriptException();
        return info.Env().Null();
    }
    if(!info[0].IsNumber()||!info[1].IsString()){
        Napi::TypeError::New(info.Env(),"Wrong Arguements").ThrowAsJavaScriptException();
        return info.Env().Null();
    }

    int timeStamp = info[0].As<Napi::Number>().Int32Value();
    std::string path = info[1].As<Napi::String>().Utf8Value();
}

Napi::Object Init (Napi::Env env, Napi::Object exports){
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME,Init);