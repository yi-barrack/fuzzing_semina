#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 200  // 입력 문자열의 최대 크기
#define NUM_TESTS 1000      // 수행할 테스트 횟수

// 무작위 문자열을 생성하는 함수 (첫 번째 문자는 0~9 사이로 고정)
void generate_random_input(char *input, int length) {
    // TODO: 첫 번째 문자를 0~9 사이의 숫자로 설정하세요.
    // 예시: input[0] = '0' + (무작위 숫자);

    // TODO: 나머지 입력을 무작위 문자로 채워 넣으세요.
    // for 문을 사용하여 입력의 나머지를 채울 수 있습니다.
    
    input[length - 1] = '\0';  // 문자열의 끝을 null-terminate
}

// 주어진 프로그램에 대해 덤프 퍼징을 수행하는 함수
void fuzz_test() {
    char input[MAX_INPUT_SIZE];
    char command[MAX_INPUT_SIZE + 50];  // 명령어를 저장할 배열

    // 난수 시드 초기화
    srand(time(NULL));

    // NUM_TESTS만큼 무작위 입력을 생성하고 테스트
    for (int i = 0; i < NUM_TESTS; i++) {
        // TODO: 무작위로 2에서 MAX_INPUT_SIZE 길이 사이의 입력을 생성하세요.
        // input_length를 설정하는 부분을 구현하세요.

        generate_random_input(input, input_length);

        // 생성된 무작위 입력을 출력
        printf("Test %d: Input = %s\n", i + 1, input);

        // ./dumb 프로그램에 입력을 전달하기 위한 명령어를 구성
        snprintf(command, sizeof(command), "./dumb %s", input);

        // 명령어 실행 (생성된 입력을 ./dumb 프로그램에 전달)
        system(command);
    }
}

int main() {
    fuzz_test();
    return 0;
}

