#pragma once

#include <napi.h>

class NodeNdpi : public Napi::ObjectWrap<NodeNdpi>
{
public:
    NodeNdpi(const Napi::CallbackInfo&);
    Napi::Value Greet(const Napi::CallbackInfo&);

    static Napi::Function GetClass(Napi::Env);

private:
    std::string _greeterName;
};
