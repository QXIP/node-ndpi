#include "node_ndpi.h"
#include "ndpiexlib.h"

using namespace Napi;

NodeNdpi::NodeNdpi(const Napi::CallbackInfo& info) : ObjectWrap(info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments")
          .ThrowAsJavaScriptException();
        return;
    }

    if (!info[0].IsString()) {
        Napi::TypeError::New(env, "You need to name yourself")
          .ThrowAsJavaScriptException();
        return;
    }

    this->_greeterName = info[0].As<Napi::String>().Utf8Value();
}

Napi::Value NodeNdpi::Greet(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "Wrong number of arguments")
          .ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString()) {
        Napi::TypeError::New(env, "You need to introduce yourself to greet")
          .ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::String name = info[0].As<Napi::String>();

    printf("Hello %s\n", name.Utf8Value().c_str());
    printf("I am %s\n", this->_greeterName.c_str());

    return Napi::String::New(env, this->_greeterName);
}

void NdpiInit(const Napi::CallbackInfo& info) {
  init();
}

void NdpiDumpResults(const Napi::CallbackInfo& info) {
  dumpResults();
}


Napi::Function NodeNdpi::GetClass(Napi::Env env) {
    return DefineClass(env, "NodeNdpi", {
        NodeNdpi::InstanceMethod("greet", &NodeNdpi::Greet),
    });
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    Napi::String name = Napi::String::New(env, "NodeNdpi");
    exports.Set(name, NodeNdpi::GetClass(env));
    exports.Set(Napi::String::New(env, "init"),
              Napi::Function::New(env, NdpiInit));
    exports.Set(Napi::String::New(env, "dumpResults"),
              Napi::Function::New(env, NdpiDumpResults));
    return exports;
}

NODE_API_MODULE(addon, Init)
