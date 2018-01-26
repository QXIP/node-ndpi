{
  'targets': [
    {
      'target_name': 'node-ndpi-native',
      'sources': [ 
	'src/node_ndpi.cc',
	'src/ndpiexlib.c'
      ],
      'libraries': [
      '-lndpi', '-L/usr/local/include/'
      ],
      'include_dirs': [
	"<!@(node -p \"require('node-addon-api').include\")",
	"src/include/",
	"../nDPIex/nDPI/src/include/"
      ],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'xcode_settings': {
        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
        'CLANG_CXX_LIBRARY': 'libc++',
        'MACOSX_DEPLOYMENT_TARGET': '10.7'
      },
      'msvs_settings': {
        'VCCLCompilerTool': { 'ExceptionHandling': 1 },
      }
    }
  ]
}
