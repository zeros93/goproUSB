#!/bin/bash

# 최신 GoPro IP를 가져오기 위해 SerialNumber를 확인
serial_number_line=$(dmesg | grep "SerialNumber: C3" | tail -n 1)

# SerialNumber를 추출
serial_number=$(awk -F 'SerialNumber: ' '{print $2}' <<< "$serial_number_line")

# SerialNumber의 마지막 3자리를 추출
last_three_digits=${serial_number: -3}

# GoPro IP address를 생성
gopro_addr="172.2${last_three_digits:0:1}.1${last_three_digits:1:1}${last_three_digits:2:1}.51"

# GoPro에 ping을 보내 연결 여부를 확인
if ping -c 4 $gopro_addr > /dev/null 2>&1; then
    echo "Ping to GoPro(IP address: $gopro_addr) was successful."
    exit 0
else
    echo "Ping to GoPro(IP address: $gopro_addr) failed."
fi

# USB 인터페이스 이름을 확인
usb_interface_line=$(dmesg | grep "renamed from usb" | tail -n 1)
interface_name=$(awk '{print $(NF-3)}' <<< "$usb_interface_line" | awk -F ':' '{print $1}')

# 새 IP address를 설정
ip_address="${gopro_addr:0:12}5"
sudo ip addr flush dev $interface_name
sudo ip addr add $ip_address/24 dev $interface_name
sudo ip link set dev $interface_name up
echo "Set the IP address of $interface_name to $ip_address."

# GoPro에 다시 ping을 보내 연결 여부를 확인
if ping -c 1 $gopro_addr > /dev/null 2>&1; then
    echo "Ping to GoPro was successful."
    exit 0
else
    echo "Ping to GoPro failed."
    exit 1
fi
