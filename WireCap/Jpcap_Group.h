#include <pcap/pcap.h>

#define True 1
#define Fales 0

// Pcap Open Func
pcap_t* OpenPcap(int select);

// 정보 추출
void PcapDataCheck(pcap_t * handle);
