// #include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pcap/pcap.h>
using namespace std;

int cui(){ // Wellcom Print
    int select;
    for(int count=0;count<10;++count){
        system("clear");
        printf("\n");
        printf("\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ \n");
        printf("\t\t\t┃ Mode selection (Input num) ┃ \n");
        printf("\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ \n\n\n");
        printf("\t\t\t  1. online \t 2. offline \n\n");
        printf("\t\t\t input (1 or 2): ");
        scanf("%d",&select);
        if(select == 1 || select == 2) break;
    }
    return select;
}

void OpenPcap(int select){
    char *device = const_cast<char*>("wlan1");
    char errbuf[PCAP_ERRBUF_SIZE]; // PCAP_ERRBUF_SIZE : 256
    pcap_t *handle = pcap_open_offline("/home/pi/RasPi/Debug_Pcap",errbuf); //파일이름 , 
    // pcap_t *handle = pcap_open_live(device,BUFSIZ,1,1000,errbuf); // BUFSIZ : 8192 , 3,4번째 인자가 아마 패킷 탐지 시간이였던거 같음.
    if(handle == nullptr){
        fprintf(stderr, "couldn't opeen device %s: %s\n",device, errbuf);
        return;
    }
    printf("Pcap_open_live 성공\n");
    pcap_close(handle);
}
int main(int argc, char* argv[]){

    int select = cui();
    
    return 0;
}