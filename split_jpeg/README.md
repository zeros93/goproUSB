
### Requirement library
- ubuntu 18.04: libjpeg-dev
- Debian Buster (BBB 2020-04-06): 

### Compile
``` sh
gcc -o split_jpeg split_jpeg.c -ljpeg
```

### 원본 이미지
<img src="./moon.jpg" width="480">

<sub> [이미지 출처] https://cdn.pixabay.com/photo/2021/06/26/06/52/moon-6365467_960_720.jpg </sub>

### 실행
``` sh
./split_jpeg moon.jpg
```

### 분할된 이미지
<img src="./output_0.jpg"> <img src="./output_1.jpg"> <img src="./output_2.jpg">
<img src="./output_3.jpg"> <img src="./output_4.jpg"> <img src="./output_5.jpg">
<img src="./output_6.jpg"> <img src="./output_7.jpg"> <img src="./output_8.jpg">
