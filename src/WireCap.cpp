// #include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>
#include "cui.h"
#include "Jpcap_Group.h"

int main(int argc, char* argv[]){

    CuiData cuiData = cui();
    pcap_t *handle = OpenPcap(cuiData.select);
    if(handle == nullptr) return -1;
    PcapDataCheck(handle);  // pcap 필터 
    pcap_close(handle);
    return 0;
}