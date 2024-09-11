#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 200  // 입력 문자열의 최대 크기
#define NUM_TESTS 1000      // 수행할 테스트 횟수

// 무작위 문자열을 생성하는 함수 (첫 번째 문자는 0~9 사이로 고정)
void generate_random_input(char *input, int length) {
    input[0] = '0' + (rand() % 10);  // 첫 번째 문자는 0~9 중 하나

    // 나머지 부분은 임의의 알파벳 소문자로 채우기
    for (int i = 1; i < length - 1; i++) {
        input[i] = 'a' + (rand() % 26);  // 알파벳 소문자 중 하나
    }
    input[length - 1] = '\0';  // 문자열의 끝에 null 추가
}

// 주어진 프로그램에 대해 덤프 퍼징을 수행하는 함수
void fuzz_test() {
    char input[MAX_INPUT_SIZE];  // 입력 문자열 저장 공간
    FILE *fp;
    int input_length;  // 입력 문자열 길이
    int result;  // 프로그램 실행 결과 저장
    
    srand(time(NULL));  // 난수 시드 초기화

    // NUM_TESTS만큼 무작위 입력을 생성하고 테스트
    for (int i = 0; i < NUM_TESTS; i++) {
        input_length = rand() % (MAX_INPUT_SIZE - 1) + 2;  // 길이는 2에서 200 사이

        generate_random_input(input, input_length);  // 무작위 입력 생성

        // 입력된 테스트 번호와 문자열 출력
        printf("Test %d: Input = %s\n", i + 1, input);

        // ./dumb 프로그램에 입력 전달 (파이프 사용)
        fp = popen("./dumb", "w");  // ./dumb 프로그램을 실행 (쓰기 모드로)
        if (fp == NULL) {
            perror("Failed to run command");
            exit(1);
        }

        // ./dumb 프로그램에 무작위 입력 전달
        fprintf(fp, "%s\n", input);  // 무작위 입력을 표준 입력으로 전달

        // 파이프 종료
        result = pclose(fp);  // 프로그램이 정상 종료했는지 확인

        // pclose()의 반환 값이 0이 아니면 크래시로 간주하고 종료
        if (result != 0) {
            printf("Program crashed on Test %d with input: %s\n", i + 1, input);
            exit(1);  // 크래시 발생 시 프로그램 종료
        }
    }
}

int main() {
    fuzz_test();
    return 0;
}

