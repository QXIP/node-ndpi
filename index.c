#include <node_api.h>
#include <napi-macros.h>

NAPI_METHOD(init) {
  NAPI_ARGV(0)
  setupDetection();
  gettimeofday(&begin, NULL);
}

void getResults() {
  dumpResults();
}

NAPI_METHOD(setDatalinkType) {
  NAPI_ARGV(1)
  NAPI_ARGV_BUFFER_CAST(pcap_t *, handle, 0)
  _pcap_datalink_type = pcap_datalink(handle);
}

NAPI_METHOD(processPacket) {
  NAPI_ARGV(2)
  NAPI_ARGV_BUFFER_CAST(pcap_pkyhdr *, header, 0)
  NAPI_ARGV_BUFFER_CAST(u_char *, packet, 1)
  pcap_packet_callback(NULL, header, packet);
}

NAPI_METHOD(finish) {
  NAPI_ARGV(0)
  terminateDetection();
}

NAPI_METHOD(addProtocolHandler) {
  NAPI_ARGV(1)
  NAPI_ARGV_BUFFER_CAST(callback, handler, 0)
  protocolHandler = handler;
}

NAPI_INIT() {
  NAPI_EXPORT_FUNCTION(addProtocolHandler)
  NAPI_EXPORT_FUNCTION(setDatalinkType)
  NAPI_EXPORT_FUNCTION(processPacket)
  NAPI_EXPORT_FUNCTION(finish)
  NAPI_EXPORT_FUNCTION(init)
}
