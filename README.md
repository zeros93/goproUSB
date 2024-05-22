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

GoPro camera를 ubuntu pc에 USB로 연결하고, `dmesg`를 명령으로 메시지 확인
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
