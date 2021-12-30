#include <iostream>
#include <pcap/pcap.h>
using namespace std;
int main(int argc, char* argv[]){
    char *device = const_cast<char*>("wlan1");
    char errbuf[PCAP_ERRBUF_SIZE]; // PCAP_ERRBUF_SIZE : 256
    pcap_t *handle = pcap_open_live(device,BUFSIZ,1,1000,errbuf); // BUFSIZ : 8192 , 3,4번째 인자가 아마 패킷 탐지 시간이였던거 같음.
    if(handle == nullptr){
        fprintf(stderr, "couldn't opeen device %s: %s\n",device, errbuf);
        return -1;
    }
    cout<<"Pcap_open_live 성공\n";
    pcap_close(handle);
    return 0;
}