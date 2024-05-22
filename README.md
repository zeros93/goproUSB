# goproUSB

USB를 통해 연결된 GoPro camera를 제어하고 저장된 media를 다운로드하기 위한 간단한 모듈

## Documentation
- [Open GoPro](https://gopro.github.io/OpenGoPro/http)
- [Open GoPro Python SDK](https://gopro.github.io/OpenGoPro/python_sdk/)

## 개발 환경
- Ubuntu 18.04
- GoPro HERO 9 Black

## 환경 설정
GoPro camera를 USB로 연결하여 제어하려고 하더라도, serial 통신이 아닌 Network Control Model (NCM) protocol로 제어함.

USB 연결을 통한 socket address는 **172.2X.1YZ.51:8080**이며, **XYZ** 값은 camera의 SerialNumber의 마지막 세자리 숫자임.

GoPro camera를 ubuntu pc에 USB로 연결하고, `dmesg` 명령으로 메시지 확인
```
[424294.899711] usb 1-2: new high-speed USB device number 17 using xhci_hcd
[424295.049935] usb 1-2: New USB device found, idVendor=2672, idProduct=0052, bcdDevice= 4.04
[424295.049942] usb 1-2: New USB device strings: Mfr=1, Product=2, SerialNumber=3
[424295.049946] usb 1-2: Product: HERO9
[424295.049950] usb 1-2: Manufacturer: GoPro
[424295.049953] usb 1-2: SerialNumber: C3*********799
[424295.053013] cdc_ether 1-2:1.0 usb0: register 'cdc_ether' at usb-0000:00:14.0-2, CDC Ethernet Device, 06:02:75:72:53:9b
[424295.073456] cdc_ether 1-2:1.0 enp0s20f0u2: renamed from usb0
```

GoPro camera의 SerialNumber는 **C3**로 시작하는 14자리 구성되며, 위 값의 SerialNumber가 `C3*********799`인 경우 USB 연결을 위한 ip address는 172.2**7**.1**99**.51 임.

USB to Ethernet으로 인식하여 interface명은 **enp0s20f0u2**으로 인식함. `ifconfig` 명령으로 ip address를 확인.
```
~/workspace/goproUSB$ ifconfig enp0s20f0u2
enp0s20f0u2: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 172.27.199.55  netmask 255.255.255.0  broadcast 172.27.199.255
        inet6 fe80::c2aa:1756:2bbc:5763  prefixlen 64  scopeid 0x20<link>
        ether 06:02:75:72:53:9b  txqueuelen 1000  (Ethernet)
        ......
```

`ping` 명령으로 GoPro camera와 연결이 되는지 확인
```
~/workspace/goproUSB$ ping -c 4 172.27.199.51
PING 172.27.199.51 (172.27.199.51) 56(84) bytes of data.
64 bytes from 172.27.199.51: icmp_seq=1 ttl=64 time=0.666 ms
64 bytes from 172.27.199.51: icmp_seq=2 ttl=64 time=0.561 ms
64 bytes from 172.27.199.51: icmp_seq=3 ttl=64 time=0.610 ms
64 bytes from 172.27.199.51: icmp_seq=4 ttl=64 time=0.716 ms

--- 172.27.199.51 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3078ms
rtt min/avg/max/mdev = 0.561/0.638/0.716/0.060 ms
```

PC에 설정 ip address가 camera와 다른 클래스이면 `ifconfig` 명령으로 동일 클래스 대역의 ip address로 할당하고, `ping` 명령으로 연결 확인.
```
$ sudo ifconfig enp0s20f0u2 down
$ sudo ifconfig enp0s20f0u2 172.27.199.55 up
```

## GoPro camera 데이터 확인
Ubuntu shell에서 `wget`과 `cat` 명령으로 camera 정보 확인
```
~/workspace/goproUSB$ wget http://172.27.199.51:8080/gopro/camera/get_date_time
--2024-05-22 14:02:14--  http://172.27.199.51:8080/gopro/camera/get_date_time
Connecting to 172.27.199.51:8080... connected.
HTTP request sent, awaiting response... 200 OK
Length: 54 [application/json]
Saving to: ‘get_date_time’

get_date_time                                              100%[========================================================================================================================================>]      54  --.-KB/s    in 0s      

2024-05-22 14:02:14 (2.58 MB/s) - ‘get_date_time’ saved [54/54]

~/workspace/goproUSB$ cat get_date_time 

{
    "date": "2024_05_22",
    "time": "23_25_58"
}
```
