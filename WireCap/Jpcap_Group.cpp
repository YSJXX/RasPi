#include <stdio.h>
#include "Jpcap_Group.h"

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

//Pcap에서 유의미한 정보 유/무 확인
void PcapDataCheck(pcap_t * handle){
    struct bpf_program fp;
    // pcap_compile(handle,&fp,(char*)"tcp port 80",0,)
}

//Pcap_findalldevs() 사용해 dev list print
void NetworkDeviceList(){
    char * dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *alldevsp;
    int ret, i=1;
    // dev = pcap_lookupdev(errbuf);
    ret = pcap_findalldevs(&alldevsp,errbuf);
    if(ret == -1){
        printf("%s\n",errbuf);
        return;
    }
    for(pcap_if_t *d = alldevsp; d; d=d->next){
        printf("%d. %s", i++,d->name);
        if(d->description){
            printf("(%s)\n",d->description);
        }else{
            printf("(None)\n");
        }
    }
}