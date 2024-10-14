#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CANDIDATES 2
#define ATTRIBUTES 12

const char* membercount[] = {"첫", "두", "세", "네", "다섯", "여섯"};

typedef struct {
    char member_info[ATTRIBUTES][200];
} Candidate;

#pragma region 날짜, 만나이 계산, 공백 밑줄 삭제 함수

int calculate_age(char *birth) {
    int birth_year, birth_month, birth_day;
    int current_year, current_month, current_day;
    sscanf(birth, "%4d/%2d/%2d", &birth_year, &birth_month, &birth_day);

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    current_year = tm->tm_year + 1900;
    current_month = tm->tm_mon + 1;
    current_day = tm->tm_mday;

    int age = current_year - birth_year;

    if (current_month < birth_month || (current_month == birth_month && current_day < birth_day)) {
        age--;
    }

    return age;
}

void remove_newline(char *str) {
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }

    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

#pragma endregion

int main() {
    Candidate candidates[NUM_CANDIDATES];
    int i = 0;

    while (i < NUM_CANDIDATES) {
        printf("오디션 그룹명: ");
        fgets(candidates[i].member_info[0], sizeof(candidates[i].member_info[0]), stdin);
        remove_newline(candidates[i].member_info[0]);

        printf("####################################\n");
        printf("[%s] 오디션 후보자 데이터 입력\n", candidates[i].member_info[0]);
        printf("####################################\n");
        printf("%s번째 후보자의 정보를 입력합니다.\n", membercount[i]);
        printf("---------------------------------\n");

        printf("1. 성명: ");
        fgets(candidates[i].member_info[1], sizeof(candidates[i].member_info[1]), stdin);
        remove_newline(candidates[i].member_info[1]);

        printf("2. 생일(YYYY/MM/DD 형식): ");
        fgets(candidates[i].member_info[2], sizeof(candidates[i].member_info[2]), stdin);
        remove_newline(candidates[i].member_info[2]);

        printf("3. 성별(여성이면 F 또는 남성이면 M): ");
        fgets(candidates[i].member_info[3], sizeof(candidates[i].member_info[3]), stdin);
        remove_newline(candidates[i].member_info[3]);

        if (candidates[i].member_info[3][0] == 'F') {
            snprintf(candidates[i].member_info[3], sizeof(candidates[i].member_info[3]), "여");
        } else if (candidates[i].member_info[3][0] == 'M') {
            snprintf(candidates[i].member_info[3], sizeof(candidates[i].member_info[3]), "남");
        }

        printf("4. 메일 주소: ");
        fgets(candidates[i].member_info[4], sizeof(candidates[i].member_info[4]), stdin);
        remove_newline(candidates[i].member_info[4]);

        printf("5. 국적: ");
        fgets(candidates[i].member_info[5], sizeof(candidates[i].member_info[5]), stdin);
        remove_newline(candidates[i].member_info[5]);

        printf("6. BMI: ");
        fgets(candidates[i].member_info[6], sizeof(candidates[i].member_info[6]), stdin);
        remove_newline(candidates[i].member_info[6]);

        printf("7. 주 스킬: ");
        fgets(candidates[i].member_info[7], sizeof(candidates[i].member_info[7]), stdin);
        remove_newline(candidates[i].member_info[7]);

        printf("8. 보조 스킬: ");
        fgets(candidates[i].member_info[8], sizeof(candidates[i].member_info[8]), stdin);
        remove_newline(candidates[i].member_info[8]);

        printf("9. 한국어 등급(TOPIK): ");
        fgets(candidates[i].member_info[9], sizeof(candidates[i].member_info[9]), stdin);
        remove_newline(candidates[i].member_info[9]);

        printf("10. MBTI: ");
        fgets(candidates[i].member_info[10], sizeof(candidates[i].member_info[10]), stdin);
        remove_newline(candidates[i].member_info[10]);

        printf("11. 소개: ");
        fgets(candidates[i].member_info[11], sizeof(candidates[i].member_info[11]), stdin);

        printf("=================================\n");
        i++;
    }

    for (i = 0; i < NUM_CANDIDATES; i++) {
        printf("####################################\n");
        printf("[%s] 오디션 후보자 데이터 조회\n", candidates[i].member_info[0]);
        printf("####################################\n");
        printf("성   명 |  생   일  | 성 별 |       메   일      | 국적 | BMI | 주스킬 | 보조스킬 | TOPIK | MBTI |\n");
        printf("================================================================================================\n");

        int age = calculate_age(candidates[i].member_info[2]);

        printf("%s(%d)  | %s | %s | %s | %s | %s | %s | %s | %s | %s |\n",
            candidates[i].member_info[1],
            age,
            candidates[i].member_info[2],
            candidates[i].member_info[3],
            candidates[i].member_info[4],
            candidates[i].member_info[5],
            candidates[i].member_info[6],
            candidates[i].member_info[7],
            candidates[i].member_info[8],
            candidates[i].member_info[9],
            candidates[i].member_info[10]
        );
        printf("---------------------------------------------------------------------------------------------\n");
        printf("%s", candidates[i].member_info[11]);
        printf("---------------------------------------------------------------------------------------------\n");
    }

    while (getchar() != '\n');
    getchar();

    return 0;
}
