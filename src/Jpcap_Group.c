#include <stdio.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <stdlib.h>
#include <string.h>
#include "Jpcap_Group.h"

/*
 * Open the Pcap file and return its handler
 */
pcap_t* OpenPcap(int select){
    char errbuf[PCAP_ERRBUF_SIZE]; // PCAP_ERRBUF_SIZE : 256
    char *device;
    pcap_t *handle;
    if(select == 1){
        printf("[ Start pcap open online ] \n");
        device = (char*)("wlan1");
        handle = pcap_open_live(device,BUFSIZ,1,1000,errbuf); // BUFSIZ : 8192 , 3,4번째 인자가 아마 패킷 탐지 시간이였던거 같음.
    }else{
        printf("[ Start pcap open offline ] \n");
        handle = pcap_open_offline("/home/pi/RasPi/Debug_Pcap/AP_YSJnetwork2G.pcap",errbuf); //파일이름 ,
    }

    if(handle == NULL){
		fprintf(stderr, "[ 🚨 ERROR ] couldn't open device %s: %s\n",device, errbuf);
    }
    return handle;
}

/*
 * Pcap에서 유의미한 정보 유/무 확인
 * tcp, http, eapol,
 */
void PcapDataCheck(pcap_t * handle){
    // Packet Type
    int loop_Cnt = 100;

    while(loop_Cnt--){
        struct pcap_pkthdr* header;
        const uint8_t *pkt;
        int res = pcap_next_ex(handle,&header,&pkt);
        if(res == 0) continue;

        uint8_t* packet = (uint8_t *)(pkt);
        Radiotap *radiotap = (Radiotap*)(packet);
        FrameControlField* frame_control_field = (FrameControlField*)(packet+radiotap->j_length);   //typeCheck : beacon,prob,data 등 패킷 타입 확인

        // Three types: Management(0) , Control(1) , QOS Data(2)
        if(frame_control_field->type == 0)
		{
			// Management(0)
            PacketAnalysis_80211(handle,packet);
        }
		else if(frame_control_field->type == 1)
		{
			// Control(1)
        }
		else if(frame_control_field->type == 2)
		{
			// Data(2)
			i80211mac_data_frame_check(handle, packet);
        }
		else
		{
            // error
        }


        // // TCP(QoS data(0x0028))
        // PacketAnalysis_tcp(handle);


        // // UDP (Data(0x0020), QosData(0x0028))
        // PacketAnalysis_udp(handle);
    }
}

void PacketAnalysis_80211(pcap_t *hadle, uint8_t *packet){
    // radiotap
    Radiotap *radiotap = (Radiotap*)(packet);
    Ieee80211_beacon_frame *ieee80211_beacon = (Ieee80211_beacon_frame*)(packet + radiotap->j_length);
    Tag_ssid * tag_ssid = (Tag_ssid *)(packet + radiotap->j_length +24+12);   // 24 : beacon length, 12 : fixed parameters length
    // ssid
    char * ssid = (char*)(malloc(tag_ssid->j_tag_length+1));
    // AP Mac address

    strncpy(ssid,tag_ssid->SSID,tag_ssid->j_tag_length);
    printf("[# Print]: %s\n",ssid);
    free(ssid);
}

// 연결된 랜카드 목록
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
