/*
 * ndpiexlib.h
 * Copyright (C) 2018 by QXIP BV
 *
 * Author: Lorenzo Mangani - Michele Campus
 *         based on code of ndpiReader and nDPI
 *
 * This is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ndpiex is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with nDPI.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "include/ndpi_api.h"
#include <pcap.h>

typedef void (*callback)(int, const u_int8_t *packet);
static pcap_t *_pcap_handle = NULL;

void init();
void setDatalinkType(pcap_t *handle);
void processPacket(const struct pcap_pkthdr *header, const u_char *packet);
void finish();
void dumpResults();
void addProtocolHandler(callback handler);

#ifdef __cplusplus
}
#endif
