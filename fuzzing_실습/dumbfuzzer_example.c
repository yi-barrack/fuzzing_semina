#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 200  // 입력 문자열의 최대 크기
#define NUM_TESTS 1000      // 수행할 테스트 횟수

// 무작위 문자열을 생성하는 함수 (첫 번째 문자는 0~9 사이로 고정)
void generate_random_input(char *input, int length) {
    // TODO: 첫 번째 문자를 0~9 사이의 숫자로 설정하세요.
    // 첫 번째 문자는 0~9 중 하나

    // TODO: 나머지 부분을 임의의 알파벳 소문자로 채우세요.
    // for 문을 사용하여 나머지 문자를 무작위로 채울 수 있습니다.
    // 힌트: 알파벳 소문자는 'a'에서 'z' 사이의 문자입니다.
    
    input[length - 1] = '\0';  // 문자열 끝을 null로 마무리
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
        // TODO: 무작위로 2에서 MAX_INPUT_SIZE 길이 사이의 입력을 생성하세요.
        // 힌트: rand() 함수를 사용하여 길이를 무작위로 설정할 수 있습니다.
        
        generate_random_input(input, input_length);  // 무작위 입력 생성

        // 테스트 번호와 생성된 입력 출력
        printf("Test %d: Input = %s\n", i + 1, input);

        // ./dumb 프로그램에 입력 전달 (파이프 사용)
        fp = popen("./dumb", "w");  // ./dumb 프로그램 실행
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

