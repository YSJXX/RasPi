#include <pcap/pcap.h>

#define True 1
#define Fales 0

// Pcap Open Func
pcap_t* OpenPcap(int select);

// Data extraction
void PcapDataCheck(pcap_t * handle);

//use Pcap_findalldevs() to get a list of device
void NetworkDeviceList()