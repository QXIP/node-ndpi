{
  "targets": [{
    "target_name": "napi_ndpi",
    "include_dirs": [
      "<!@(node -p \"require('node-addon-api').include\")",
      "<!(node -e \"require('napi-macros')\")",
      "./include"
    ],
    "sources": [ "./ndpiexlib.c" ]
  }]
}
