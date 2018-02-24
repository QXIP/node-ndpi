{
  "targets": [{
    "target_name": "napi_ndpi",
    "include_dirs": [
      "<!(node -e \"require('napi-macros')\")",
      "./include"
    ],
    "sources": [ "./ndpiexlib.c" ]
  }]
}
