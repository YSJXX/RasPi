#include <pcap/pcap.h>
#define True 1
#define Fales 0

// Pcap Open Func
pcap_t* OpenPcap(int select);

// Data extraction
void PcapDataCheck(pcap_t * handle);

//use Pcap_findalldevs() to get a list of device
void NetworkDeviceList();

// 802.11 Packet Analysis
void PacketAnalysis_80211(pcap_t *hadle);

// tcp(http) Packet Analysis
void PacketAnalysis_tcp(pcap_t *hadle);

// udp Packet Analysis
void PacketAnalysis_udp(pcap_t *hadle);