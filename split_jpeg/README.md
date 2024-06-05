
### Requirement library
- ubuntu 18.04: libjpeg-dev
- Debian Buster (BBB 2020-04-06): 

### Compile
``` sh
gcc -o split_jpeg split_jpeg.c -ljpeg
```

### 원본 이미지
<img src="./keyboard.jpg" width="960">

### 실행
``` sh
./split_jpeg keyboard.jpg
```

### 분할된 이미지
<img src="./output_0.jpg" width="320"> <img src="./output_1.jpg" width="320"> <img src="./output_2.jpg" width="320">
<img src="./output_3.jpg" width="320"> <img src="./output_4.jpg" width="320"> <img src="./output_5.jpg" width="320">
