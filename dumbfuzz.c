#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

#define MAX_INPUT_SIZE 200  // 입력 문자열의 최대 크기
#define NUM_TESTS 1000      // 수행할 테스트 횟수

// 무작위 문자열을 생성하는 함수 (첫 번째 문자는 0~9 사이로 고정)
void generate_random_input(char *input, int length) {
    const char charset[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    // 첫 번째 문자는 0에서 9 사이의 숫자로 고정
    input[0] = '0' + (rand() % 10);

    // 나머지 입력은 무작위 문자로 채움
    for (int i = 1; i < length - 1; i++) {
        int key = rand() % (sizeof(charset) - 1);
        input[i] = charset[key];
    }
    input[length - 1] = '\0';  // 문자열의 끝을 null-terminate
}

// 주어진 프로그램에 대해 덤프 퍼징을 수행하는 함수
void fuzz_test() {
    char input[MAX_INPUT_SIZE];
    char command[MAX_INPUT_SIZE + 50];  // 명령어를 저장할 배열
    int input_length;  // input_length 변수를 선언
    int result;  // 시스템 명령어 실행 결과 저장
    
    // 난수 시드 초기화
    srand(time(NULL));

    // NUM_TESTS만큼 무작위 입력을 생성하고 테스트
    for (int i = 0; i < NUM_TESTS; i++) {
        // 무작위로 2에서 MAX_INPUT_SIZE 길이 사이의 입력을 생성
        input_length = rand() % (MAX_INPUT_SIZE - 1) + 2;  // 최소 길이는 2

        generate_random_input(input, input_length);

        // 생성된 무작위 입력을 출력
        printf("Test %d: Input = %s\n", i + 1, input);

        // ./dumb 프로그램에 입력을 전달하기 위한 명령어를 구성
        snprintf(command, sizeof(command), "echo '%s' | ./dumb", input);

        // 명령어 실행 (생성된 입력을 ./dumb 프로그램에 전달)
        result = system(command);

        // result 값이 0이 아닌 경우 크래시가 발생한 것으로 판단
        if (result != 0) {
            printf("Program crashed on Test %d with input: %s\n", i + 1, input);
            exit(1);  // 크래시가 발생하면 프로그램을 종료
        }
    }
}

int main() {
    fuzz_test();
    return 0;
}

