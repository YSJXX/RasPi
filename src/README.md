# Wireless Capture

> ## To Do List
> 1. void PacketAnalysis_80211(pcap_t *hadle);
>>       radiotap header는 건너뛰고 id(),pw(),쿠키 세션 탐지(),ssid()
> 2. void PacketAnalysis_tcp(pcap_t *hadle);
> 3. void PacketAnalysis_udp(pcap_t *hadle);
> 4. ssid, id 등 저장 자료구조 무엇으로 할지 생각
>
> - SNI, http, DNS, SMTP에서 이메일 주소, 주변 SSID,
>>      UDP, http, TCP 정보가 있는 패킷 파일 필요
> - 각 필요 함수 만들기
> - 애러 로그파일 만들기
> - 어느정도 개발 진행 후 함수 기능별 정리하기
> - cui 함수에서 인터페이스 선택 후 모니터모드 설정 기능 추가.
> - pcap_loop() testing

# 작동 순서
1. online , offline 선택
	online : live packet Capture
	offline : pcap file, debug mode
2. open pcap 작동
3. monitor mode 설정 유/무


### 참고
- ADT 가능하면 적용해보기
- reinterpret_cast
    reinterpret_cast는 어떠한 포인터 타입도 어떠한 포인터 타입으로든 변환이 가능합니다. - 어떠한 정수 타입도 어떠한 포인터 타입으로 변환이 가능하고, 그 역(포인터 타입->정수 타입)도 가능합니다.

    char* -> int 또는 int* 에서 char* 로 또는 any_class* 에서 another_Class* 로도 가능합니다. 얼핏 봤을 때 상당히 자유롭고 강력한 캐스터 같지만, 특수한 케이스가 아니면 사용하지 않는 것을 권합니다.
    우선, 전통적인 캐스팅의 개념에서 벗어날 수 있는 포인터 변환 등이 reinterpret_cast를 씀으로써 강제 형변환되기 때문입니다.

    변환 관계에 놓인 두 개체의 관계가 명확하거나, 특정 목적을 달성하기 위할 때만 사용하는 것이 바람직합니다. 게다가 이 연산자가 적용된 후의 변환 결과는 거의 항상 컴파일러에 따라 다르게 정의되어 있습니다. 따라서, 이 캐스팅 연산자가 쓰인 소스는 직접 다른 곳에 소스 이식이 불가능할 수 있습니다.


# ADT
### 1. CUI
### 2. 패킷탐지 기능

<br>

## CUI
- 시작 화면
- 결과 화면

## 패킷탐지 기능
- 세션 탐지

## Code Convention


## 참조
- - - - -
ieee802.11 type/subtype 종류
> https://howiwifi.com/2020/07/13/802-11-frame-types-and-formats/

<br><br><br>
