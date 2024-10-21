#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JUDGE_LENGTH 512

int main() {
    int num_judges;
    int selected_members;

    printf("####################################\n");
    printf("#       심사자 풀 데이터 입력      #\n");
    printf("####################################\n");

    char project_name[200];
    printf("> 참여 프로젝트: ");
    fgets(project_name, sizeof(project_name), stdin);
    project_name[strcspn(project_name, "\n")] = '\0'; // 새줄 제거
    
    printf("> 심사 풀 인원: ");
    scanf("%d", &num_judges);
    getchar();  // 개행 문자 제거

    printf("> 선발 멤버 수: ");
    scanf("%d", &selected_members);
    getchar();  // 개행 문자 제거


    // 1차원 배열로 심사자 정보를 저장할 공간 할당
    char judges_array[num_judges * MAX_JUDGE_LENGTH]; // 1차원 배열
    memset(judges_array, 0, sizeof(judges_array)); // 배열 초기화

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사자 정보 입력을 시작합니다.\n", num_judges);
    printf("++++++++++++++++++++++++++++++++++++\n");

    for (int i = 0; i < num_judges; i++) {
        printf("*심사자 %d: ", i + 1);
        fgets(judges_array + (i * MAX_JUDGE_LENGTH), MAX_JUDGE_LENGTH, stdin);

        // 새줄 제거
        size_t len = strlen(judges_array + (i * MAX_JUDGE_LENGTH));
        if (len > 0 && judges_array[i * MAX_JUDGE_LENGTH + len - 1] == '\n') {
            judges_array[i * MAX_JUDGE_LENGTH + len - 1] = '\0';
        }
    }

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("심사자 풀 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    char confirm;
    printf("[ %s ] 심사자 풀을 확인할까요? Y/N: ", project_name);
    scanf(" %c", &confirm); // confirm 앞에 공백 추가로 이전 입력에서 개행문자 제거

    if (confirm == 'Y' || confirm == 'y') {
        printf("####################################\n");
        printf("#       심사자 풀 데이터 출력      #\n");
        printf("####################################\n");

        for (int i = 0; i < num_judges; i++) {
            printf("[심사자 %d]\n", i + 1);
            // JSON 형식에서 데이터를 파싱하여 출력
            char name[50], gender[10], affiliation[100], position[100], specialty[100], email[100], phone[20];
            sscanf(judges_array + (i * MAX_JUDGE_LENGTH), "이름:%[^,],성별:%[^,],소속:%[^,],직함:%[^,],전문분야:%[^,],메일:%[^,],전화:%s",
                   name, gender, affiliation, position, specialty, email, phone);
            printf("이름: %s\n", name);
            printf("성별: %s\n", gender);
            printf("소속: %s\n", affiliation);
            printf("직함: %s\n", position);
            printf("전문분야: %s\n", specialty);
            printf("메일: %s\n", email);
            printf("전화: %s\n", phone);
            printf("-----------------------------------\n");
        }
    }

    // JSON 파일 저장
    FILE *file = fopen("judges.json", "w");
    if (file) {
        fprintf(file, "{\n\t\"project\": \"%s\",\n\t\"judges\": [\n", project_name);
        for (int i = 0; i < num_judges; i++) {
            fprintf(file, "\t\t\"%s\"", judges_array + (i * MAX_JUDGE_LENGTH));
            if (i < num_judges - 1) {
                fprintf(file, ",");
            }
            fprintf(file, "\n");
        }
        fprintf(file, "\t]\n}");
        fclose(file);
        printf("심사자 정보가 JSON 파일로 저장되었습니다: judges.json\n");
    } else {
        printf("파일을 저장할 수 없습니다.\n");
    }
    while (getchar() != '\n');
    getchar();

    return 0;
}
