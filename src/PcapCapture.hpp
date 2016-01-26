//
//  PcapCapture.hpp
//  IpTetris
//
//  Created by Ludovic Laffineur on 26/01/16.
//
//

#ifndef PcapCapture_hpp
#define PcapCapture_hpp

#include <stdio.h>
#include "ofMain.h"

#include "pcap.h"

typedef struct ip_address_struct{
    u_char byte1;
    u_char byte2;
    u_char byte3;
    u_char byte4;
}ip_address_struct;

typedef union ip_address{
    ip_address_struct struct_bytes;
    u_int32_t int_address;
} ip_address;

typedef struct ip_header{
    u_char  ver_ihl;        // Version (4 bits) + Internet header length (4 bits)
    u_char  tos;            // Type of service
    u_short tlen;           // Total length
    u_short identification; // Identification
    u_short flags_fo;       // Flags (3 bits) + Fragment offset (13 bits)
    u_char  ttl;            // Time to live
    u_char  proto;          // Protocol
    u_short crc;            // Header checksum
    ip_address  saddr;      // Source address
    ip_address  daddr;      // Destination address
    u_int   op_pad;         // Option + Padding
}ip_header;


class MyThread : public ofThread {
public:
    MyThread();
    void threadedFunction();
    // the thread function
    bool        running;
    pcap_t*     mHandle;
    ip_header*  current_frame;
    ip_header*  candidate;
    };

#endif /* PcapCapture_hpp */
