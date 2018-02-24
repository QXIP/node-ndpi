/*
 * nDPI Native Binding Exports
 * (c) 2018 QXIP BV
 */
var bindings = require('node-gyp-build')(__dirname)

exports.init = bindings.ndpi_init;
exports.finish = bindings.ndpi_finish;
exports.processPacket = bindings.ndpi_processPacket;
exports.setDatalinkType = bindings.ndpi_setDatalinkType;
exports.addProtocolHandler = bindings.ndpi_addProtocolHandler;
exports.testdouble = bindings.times_two;

