#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // 현재 시간 관련 함수 사용을 위해 추가

#define NUM_CANDIDATES 2
const char* membercount[] = {"첫", "두", "세", "네", "다섯", "여섯"};

// 후보자 정보를 저장하기 위한 구조체 정의
typedef struct {
    char name[50];            // 성명
    char birth[11];           // 생일
    char gender;              // 성별
    char email[100];          // 메일 주소
    char nationality[50];     // 국적
    float bmi;                // BMI
    char main_skill[50];      // 주 스킬
    char sub_skill[50];       // 보조 스킬
    char korean_level[10];    // 한국어 등급
    char mbti[10];            // MBTI
    char introduction[200];   // 소개
    char group_name[50];      // 오디션 그룹명
} Candidate;

// 만 나이를 계산하는 함수
int calculate_age(char *birth) {
    int birth_year, birth_month, birth_day;
    int current_year, current_month, current_day;
    sscanf(birth, "%4d/%2d/%2d", &birth_year, &birth_month, &birth_day);

    // 현재 날짜를 구하기 위해 time.h 라이브러리 사용
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    current_year = tm.tm_year + 1900;  // tm_year는 1900년을 기준으로 하므로 1900을 더해줘야 함
    current_month = tm.tm_mon + 1;     // tm_mon은 0부터 시작하므로 1을 더해줘야 함
    current_day = tm.tm_mday;

    int age = current_year - birth_year;

    // 생일이 아직 지나지 않았으면 나이를 1살 빼야 함
    if (current_month < birth_month || (current_month == birth_month && current_day < birth_day)) {
        age--;
    }

    return age;
}

int main() {
    Candidate candidates[NUM_CANDIDATES];  // 후보자 정보를 저장할 배열
    int i = 0;

    // 후보자 데이터를 입력받음
    while (i < NUM_CANDIDATES) {
        printf("오디션 그룹명: ");
        scanf("%s", candidates[i].group_name);

        printf("####################################\n");
        printf("[%s] 오디션 후보자 데이터 입력\n", candidates[i].group_name);
        printf("####################################\n");
        printf("%s번째 후보자의 정보를 입력합니다.\n", membercount[i]);
        printf("---------------------------------\n");

        printf("1. 성명: ");
        scanf("%s", candidates[i].name);
        getchar();  // 버퍼 비우기

        printf("2. 생일(YYYY/MM/DD 형식): ");
        scanf("%s", candidates[i].birth);
        getchar();  // 버퍼 비우기

        printf("3. 성별(여성이면 F 또는 남성이면 M): ");
        scanf(" %c", &candidates[i].gender);  // 공백을 넣어 버퍼 비움
        getchar();  // 버퍼 비우기

        printf("4. 메일 주소: ");
        scanf("%s", candidates[i].email);
        getchar();  // 버퍼 비우기

        printf("5. 국적: ");
        scanf("%s", candidates[i].nationality);
        getchar();  // 버퍼 비우기

        printf("6. BMI: ");
        scanf("%f", &candidates[i].bmi);
        getchar();  // 버퍼 비우기

        printf("7. 주 스킬: ");
        scanf("%s", candidates[i].main_skill);
        getchar();  // 버퍼 비우기

        printf("8. 보조 스킬: ");
        scanf("%s", candidates[i].sub_skill);
        getchar();  // 버퍼 비우기

        printf("9. 한국어 등급(TOPIK): ");
        scanf("%s", candidates[i].korean_level);
        getchar();  // 버퍼 비우기

        printf("10. MBTI: ");
        scanf("%s", candidates[i].mbti);
        getchar();  // 버퍼 비우

        printf("11. 소개: ");
        fgets(candidates[i].introduction, sizeof(candidates[i].introduction), stdin);  // 소개는 공백 포함 입력을 받기 위해 fgets 사용

        printf("=================================\n");

        i++;  // 다음 후보자로 이동
    }

    // 후보자 데이터 출력
    for (i = 0; i < NUM_CANDIDATES; i++) {
        printf("####################################\n");
        printf("[%s] 오디션 후보자 데이터 조회\n", candidates[i].group_name);
        printf("####################################\n");
        printf("================================================================================================\n");
        printf("성   명 |  생   일  | 성 별 |       메   일      | 국적 | BMI | 주스킬 | 보조스킬 | TOPIK | MBTI |\n");
        printf("================================================================================================\n");

        // 생일에서 '/'를 제거하는 부분
        char formatted_birth[11];  // YYYYMMDD 형식으로 변환된 생일을 저장할 배열
        int j = 0;
        for (int k = 0; k < 10; k++) {
            if (candidates[i].birth[k] != '/') {
                formatted_birth[j++] = candidates[i].birth[k];
            }
        }
        formatted_birth[j] = '\0';  // 문자열 끝을 나타내는 널 문자 추가

        // 성별 출력 시 'if' 문 사용
        char gender_str[3] = "?";  // 기본 값은 '?'
        if (candidates[i].gender == 'F' || candidates[i].gender == 'f') {
            snprintf(gender_str, sizeof(gender_str), "여");
        } else if (candidates[i].gender == 'M' || candidates[i].gender == 'm') {
            snprintf(gender_str, sizeof(gender_str), "남");
        }

        // 만 나이 계산
        int age = calculate_age(candidates[i].birth);

        // 출력 형식에 맞게 데이터 출력
        printf("%s(%d)  |%s | %s   | %s | %s | %.1f | %s | %s | %s | %s |\n",
            candidates[i].name,
            age,  // 만 나이 출력
            formatted_birth,  // 수정된 생일 출력
            gender_str,
            candidates[i].email,
            candidates[i].nationality,
            candidates[i].bmi,
            candidates[i].main_skill,
            candidates[i].sub_skill,
            candidates[i].korean_level,
            candidates[i].mbti
        );
        printf("---------------------------------------------------------------------------------------------\n");
        printf("%s", candidates[i].introduction);
        printf("---------------------------------------------------------------------------------------------\n");
    }
    while (getchar() != '\n');
    getchar();
    return 0;
}
