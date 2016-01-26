//
//  PcapCapture.cpp
//  IpTetris
//
//  Created by Ludovic Laffineur on 26/01/16.
//
//

#include "PcapCapture.hpp"

MyThread::MyThread(){
    int a;
    pcap_if_t* d;
    pcap_if_t **alldev;
    if (pcap_findalldevs(alldev, NULL)==-1){
        fprintf(stderr, "Couldn't find default device: %s\n", "YOUPS");
        return -1;
    }
    int i=0;
    for( d = alldev[0]; d; d=d->next){
        printf("%d. %s", ++i, d->name);
        if (d->description)
            printf(" (%s)\n", d->description);
        else
            printf(" (No description available)\n");
    }
    pcap_if_t* selected = alldev[0];
    std::cout<< "Select your interface :";
    std::cin >> a;
    for (int i = 1; i<a; i++){
        selected = selected->next;
    }
    mHandle = pcap_open_live(selected->name, BUFSIZ, 1, 1000, NULL);
    running = true;
    
//mHandle = openLive(selected->name, BUFSIZ, 1, 1000, NULL);
    
}

void MyThread::threadedFunction() {

    // start

    while(isThreadRunning()) {
        struct pcap_pkthdr* header;
        const u_char* data;
        int res;
        while(running){
            res = pcap_next_ex(mHandle, &header, &data);
            if (res >0 && data ){
                const char* c = (const char*) data;
                //ip_header *ih;
                candidate = (ip_header *) (data + 14);
                if (candidate->tlen > 200)
                    current_frame = candidate;
                
            }
        }
        return NULL;
    }

    // done
}


