#include <pcap/pcap.h>
#define True 1
#define False 0

//Mac Addresses save
struct uint48{
    unsigned long long v:48;
}__attribute__((packed));

// ieee802.11 Frame Control Field
typedef struct _FrameControlField{
	uint8_t Version : 2;
	uint8_t Type : 2;           // Three types: Management(0) , Control(1) , Data(2)
	uint8_t Subtype : 4;        
	uint8_t Flag;
}FrameControlField;

typedef struct _Radiotap{
    uint8_t j_revision;
    uint8_t j_pad;
    uint16_t j_length;
    uint32_t j_present;
}Radiotap;

typedef struct _ieee80211_beacon_frame{
    FrameControlField j_Frame_control;
    uint16_t j_Duration;
    uint48 j_Destination_address;
    uint48 j_Source_address;
    uint48 j_BSSID;
    uint16_t j_SequenceControl;
}Ieee80211_beacon_frame;

typedef struct _tag_ssid{
    uint8_t j_tag_number;
    uint8_t j_tag_length;
    char SSID[32];
}Tag_ssid;

// Pcap Open Func
pcap_t* OpenPcap(int select);

// Data extraction
void PcapDataCheck(pcap_t * handle);

//use Pcap_findalldevs() to get a list of device
void NetworkDeviceList();

// 802.11 Packet Analysis
void PacketAnalysis_80211(pcap_t *hadle, uint8_t* packet);

// tcp(http) Packet Analysis
void PacketAnalysis_tcp(pcap_t *hadle);

// udp Packet Analysis
void PacketAnalysis_udp(pcap_t *hadle);