# fuzzing_semina
2024 SSG 여름 세미나



#AFL++
```
sudo apt install gcc make
git clone https://github.com/AFLplusplus/AFLplusplus.git
cd AFLplusplus
make distrib
sudo make install
```

다 설치했으면 이제 끝!
export PATH=$PATH:/설치해둔/경로입력하세요/aflplusplus
환경변수를 위 명령어를 통해 설정해두면, 어느 창에서든 afl 명령어 사용 가능
(터미널 껏다 켜면 다시 설정해야하기 때문에 영구적 설정은 gpt한테 물어보기)


# dumb.c 컴파일
```
 gcc -fno-stack-protector -o dumb dumb.c
```


# afl 실습 명령어
```
afl-clang-fast -o dumb_afl dumb.c
```
