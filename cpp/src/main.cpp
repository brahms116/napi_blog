#include "napi.h"

std::string parsefile(int timestamp,const char* path);

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
    std::string jsonResult = parsefile(timeStamp,path.c_str());

    if(jsonResult.size()==0){
        Napi::Error::New(info.Env(),"Cannot parse file").ThrowAsJavaScriptException();
        return info.Env().Null();
    }
    Napi::String napiJsonResult = Napi::String::New(info.Env(),jsonResult.c_str());
    return napiJsonResult;
}

Napi::Object Init (Napi::Env env, Napi::Object exports){
    exports.Set(Napi::String::New(env,"getJson"),Napi::Function::New(env,getJson));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME,Init);