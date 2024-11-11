#include <stdio.h>
#include <stdlib.h>

#define MAX_JUDGES 100    // 최대 심사자 수
#define MAX_STRING 1000   // 문자열 최대 길이

int main() {
    char project[50];                          // 프로젝트명
    int judge_num, select_num;                 // 심사자 수, 선발 인원
    char *judges_array[MAX_JUDGES];            // 포인터 배열로 변경
    char check;                                // 확인 입력용

    // 프로그램 시작 및 기본 정보 입력
    printf("####################################\n");
    printf("#       심사자 풀 데이터 입력      #\n");
    printf("####################################\n");

    printf("참여 프로젝트: ");
    scanf("%s", project);

    printf("심사 풀 인원: ");
    scanf("%d", &judge_num);

    printf("선발 멤버 수: ");
    scanf("%d", &select_num);

    // 심사자 정보 입력 시작
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사자 정보 입력을 시작합니다.\n", judge_num);
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 각 심사자의 정보를 콤마로 구분하여 한 줄로 입력받기
    for (int i = 0; i < judge_num; i++) {
        char name[50], gender[10], company[50], position[50];
        char expertise[50], email[50], phone[20];
        char input_line[MAX_STRING];
        int valid_input = 0;

        while (!valid_input) {
            printf("\n심사자 %d의 정보: ", i + 1);
            scanf(" %[^\n]s", input_line);

            // " 제거
            int j = 0, k = 0;
            while (input_line[j]) {
                if (input_line[j] != '"') {
                    input_line[k++] = input_line[j];
                }
                j++;
            }
            input_line[k] = '\0';

            // 콤마로 구분된 입력을 분리
            int fields = sscanf(input_line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                                name, gender, company, position, expertise, email, phone);

            if (fields == 7 &&
                name[0] != '\0' && gender[0] != '\0' && company[0] != '\0' &&
                position[0] != '\0' && expertise[0] != '\0' && email[0] != '\0' &&
                phone[0] != '\0') {
                valid_input = 1;
            } else {
                printf("Error: 모든 필드를 입력해주세요 (이름,성별,소속,직함,전문분야,이메일,전화번호)\n");
            }
        }

        // 동적 메모리 할당으로 변경
        judges_array[i] = (char *)malloc(MAX_STRING * sizeof(char));
        sprintf(judges_array[i],
                "{\"name\":\"%s\",\"gender\":\"%s\",\"company\":\"%s\","
                "\"position\":\"%s\",\"expertise\":\"%s\",\"email\":\"%s\",\"phone\":\"%s\"}",
                name, gender, company, position, expertise, email, phone);
    }

    // 데이터 확인 여부 체크
    printf("\n[%s] 심사자 풀을 확인할까요? (y/n): ", project);
    scanf(" %c", &check);

    // 데이터 출력
    if (check == 'y' || check == 'Y') {
        printf("\n####################################\n");
        printf("#       심사자 풀 데이터 출력      #\n");
        printf("####################################\n");

        for (int i = 0; i < judge_num; i++) {
            printf("\n[심사자 %d]\n", i + 1);
            char name[50], gender[10], company[50], position[50];
            char expertise[50], email[50], phone[20];

            // JSON 문자열에서 각 필드의 값을 추출
            sscanf(judges_array[i],
                   "{\"name\":\"%[^\"]\",\"gender\":\"%[^\"]\",\"company\":\"%[^\"]\","
                   "\"position\":\"%[^\"]\",\"expertise\":\"%[^\"]\",\"email\":\"%[^\"]\",\"phone\":\"%[^\"]\"}",
                   name, gender, company, position, expertise, email, phone);

            printf("%s\n", name);
            printf("%s\n", gender);
            printf("%s\n", company);
            printf("%s\n", position);
            printf("%s\n", expertise);
            printf("%s\n", email);
            printf("%s\n", phone);
            printf("----------------------------------\n");
        }
    } else {
        printf("프로그램을 종료합니다.\n");
    }

    // 프로그램 종료 전 메모리 해제
    for (int i = 0; i < judge_num; i++) {
        free(judges_array[i]);
    }

    while (getchar() != '\n');
    getchar();

    return 0;
}
