# 문제 & 해결

## radiotap header를 어떻게 처리할지
> header length를 구하고 length만큼 건너뛴다.
> 
> :: 나중에 혹시라도 radiotap header에서 필요한 값이 있을까봐



## pcaket , radiotap 주소값은 같은데 각 주소에 +1 하면 서로 다른값 낭옴
> radiotap의 경우 8byte의 구조체 크기를 가지고 있어 "radiotap[0]+1"을 하면 8이 증가된 값을 가져온다.
