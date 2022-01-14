// #include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>
#include "cui.cpp"

pcap_t* OpenPcap(int select){
    char errbuf[PCAP_ERRBUF_SIZE]; // PCAP_ERRBUF_SIZE : 256
    char *device;
    pcap_t *handle;
    if(select == 1){
        printf("[ Start pcap open online ] \n");
        device = const_cast<char*>("wlan1");
        handle = pcap_open_live(device,BUFSIZ,1,1000,errbuf); // BUFSIZ : 8192 , 3,4번째 인자가 아마 패킷 탐지 시간이였던거 같음.
    }else{
        printf("[ Start pcap open offline ] \n");
        handle = pcap_open_offline("/home/pi/RasPi/Debug_Pcap/AP_YSJnetwork2G.pcap",errbuf); //파일이름 , 
    }
    
    if(handle == nullptr){
        fprintf(stderr, "[ 🚨 ERROR ] couldn't open device %s: %s\n",device, errbuf);
    }
    return handle;
}
int main(int argc, char* argv[]){

    CuiData cuiData = cui();
    pcap_t *handle = OpenPcap(cuiData.select);
    if(handle == nullptr) return -1;
    pcap_close(handle);
    return 0;
}