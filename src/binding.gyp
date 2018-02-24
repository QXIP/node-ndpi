{
  "targets": [{
    "target_name": "napi_ndpi",
    "dependencies": ["<!(node -p \"require('node-addon-api').gyp\")"],
    "include_dirs": [
      "<!(node -e \"require('napi-macros')\")",
      "include"
    ],
    "sources": [ "./ndpiexlib.c" ]
  }]
}
