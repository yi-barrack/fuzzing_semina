#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func1(char *input) {
    if (strlen(input) < 5) {
        printf("Function 1: Input is too short!\n");
        return;
    }
    char buffer[100]; 
    
    
    if (strlen(input) >= sizeof(buffer)) {
        printf("Function 1: Input is too large!\n");
        return;
    }

    strcpy(buffer, input); 
    printf("Function 1 executed: %s\n", buffer);
}

void func2(char *input) {
    if (strlen(input) < 5) {
        printf("Function 2: Input is too short!\n");
        return;
    }
    char buffer[100];  
    
    
    if (strlen(input) >= sizeof(buffer)) {
        printf("Function 2: Input is too large!\n");
        return;
    }

    strcpy(buffer, input); 
    printf("Function 2 executed: %s\n", buffer);
}

void func3(char *input) {
    if (strlen(input) < 5) {
        printf("Function 3: Input is too short!\n");
        return;
    }
    char buffer[100];   
    
     
    if (strlen(input) >= sizeof(buffer)) {
        printf("Function 3: Input is too large!\n");
        return;
    }

    strcpy(buffer, input);  
    printf("Function 3 executed: %s\n", buffer);
}

void func4(char *input) {
    if (strlen(input) < 5) {
        printf("Function 4: Input is too short!\n");
        return;
    }
    char buffer[100];   
    
     
    if (strlen(input) >= sizeof(buffer)) {
        printf("Function 4: Input is too large!\n");
        return;
    }

    strcpy(buffer, input);  
    printf("Function 4 executed: %s\n", buffer);
}

void func5(char *input) {
    if (strlen(input) < 5) {
        printf("Function 5: Input is too short!\n");
        return;
    }
    char buffer[100];   
    
     
    if (strlen(input) >= sizeof(buffer)) {
        printf("Function 5: Input is too large!\n");
        return;
    }

    strcpy(buffer, input);  
    printf("Function 5 executed: %s\n", buffer);
}

void func6(char *input) {
    if (strlen(input) < 5) {
        printf("Function 6: Input is too short!\n");
        return;
    }
    char buffer[100];   
    
     
    if (strlen(input) >= sizeof(buffer)) {
        printf("Function 6: Input is too large!\n");
        return;
    }

    strcpy(buffer, input);  
    printf("Function 6 executed: %s\n", buffer);
}

void func7(char *input) {
    if (strlen(input) < 5) {
        printf("Function 7: Input is too short!\n");
        return;
    }
    char buffer[100];   
    
     
    if (strlen(input) >= sizeof(buffer)) {
        printf("Function 7: Input is too large!\n");
        return;
    }

    strcpy(buffer, input);  
    printf("Function 7 executed: %s\n", buffer);
}

void func8(char *input) {
    if (strlen(input) < 5) {
        printf("Function 8: Input is too short!\n");
        return;
    }
    char buffer[100];   
    
     
    if (strlen(input) >= sizeof(buffer)) {
        printf("Function 8: Input is too large!\n");
        return;
    }

    strcpy(buffer, input);  
    printf("Function 8 executed: %s\n", buffer);
}

void func9(char *input) {
    if (strlen(input) < 5) {
        printf("Function 9: Input is too short!\n");
        return;
    }
    char buffer[100];   
    
     
    if (strlen(input) >= sizeof(buffer)) {
        printf("Function 9: Input is too large!\n");
        return;
    }

    strcpy(buffer, input);  
    printf("Function 9 executed: %s\n", buffer);
}

void func10(char *input) {
    if (strlen(input) < 5) {
        printf("Function 10: Input is too short!\n");
        return;
    }
    char buffer[100];  
    
    
    strcpy(buffer, input); 
    printf("Function 10 executed: %s\n", buffer);
}

void process_input(char *input) {
    // 입력값이 최소 1글자 이상인 경우만 처리
    if (strlen(input) < 1) {
        printf("Input is too short!\n");
        return;
    }

    // 첫 글자를 기준으로 함수를 호출
    switch (input[0]) {
        case '1':
            func1(input);
            break;
        case '2':
            func2(input);
            break;
        case '3':
            func3(input);
            break;
        case '4':
            func4(input);
            break;
        case '5':
            func5(input);
            break;
        case '6':
            func6(input);
            break;
        case '7':
            func7(input);
            break;
        case '8':
            func8(input);
            break;
        case '9':
            func9(input);
            break;
        case '0':
            func10(input); 
            break;
        default:
            printf("No matching function for input: %s\n", input);
            break;
    }
}

int main() {
    char input[200];

    printf("Enter input: ");
    scanf("%199s", input);  // 사용자 입력을 받음 (최대 199자까지)

    process_input(input);

    return 0;
}

