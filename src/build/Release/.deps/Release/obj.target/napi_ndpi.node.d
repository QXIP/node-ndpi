cmd_Release/obj.target/napi_ndpi.node := g++ -shared -pthread -rdynamic -m64  -Wl,-soname=napi_ndpi.node -o Release/obj.target/napi_ndpi.node -Wl,--start-group Release/obj.target/napi_ndpi/ndpiexlib.o -Wl,--end-group 
