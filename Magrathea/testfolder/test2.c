#include <stdio.h>
#include <stdlib.h>

#define NUM_CANDIDATES 6
#define ATTRIBUTES 12

int main() {
    char candidate01[200], candidate02[200], candidate03[200], candidate04[200], candidate05[200], candidate06[200];
    char *candidates[NUM_CANDIDATES] = {candidate01, candidate02, candidate03, candidate04, candidate05, candidate06};
    char member_info[NUM_CANDIDATES][ATTRIBUTES][200]; // 모든 후보자의 속성을 저장할 배열

    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("오디션 그룹명: ");
        fgets(candidates[i], sizeof(candidate01), stdin);

        // 새줄 제거
        {
            int len = 0;
            while (candidates[i][len] != '\0') {
                len++;
            }
            if (len > 0 && candidates[i][len - 1] == '\n') {
                candidates[i][len - 1] = '\0';
            }
        }

        printf("####################################\n");
        printf("[%s] 오디션 후보자 데이터 입력\n", candidates[i]);
        printf("####################################\n");

        int j = 0;
        while (j < ATTRIBUTES) {
            switch (j) {
                case 0:
                    printf("1. 성명: ");
                    break;
                case 1:
                    printf("2. 생일(YYYY/MM/DD 형식): ");
                    break;
                case 2:
                    printf("3. 성별(여성이면 F 또는 남성이면 M): ");
                    break;
                case 3:
                    printf("4. 메일 주소: ");
                    break;
                case 4:
                    printf("5. 국적: ");
                    break;
                case 5:
                    printf("6. BMI: ");
                    break;
                case 6:
                    printf("7. 주 스킬: ");
                    break;
                case 7:
                    printf("8. 보조 스킬: ");
                    break;
                case 8:
                    printf("9. 한국어 등급(TOPIK): ");
                    break;
                case 9:
                    printf("10. MBTI: ");
                    break;
                case 10:
                    printf("11. 소개: ");
                    break;
                default:
                    break;
            }

            fgets(member_info[i][j], sizeof(member_info[i][j]), stdin);

            // 새줄 제거
            {
                int len = 0;
                while (member_info[i][j][len] != '\0') {
                    len++;
                }
                if (len > 0 && member_info[i][j][len - 1] == '\n') {
                    member_info[i][j][len - 1] = '\0';
                }
            }

            j++;
        }

        // 성별 변환
        if (member_info[i][2][0] == 'F') {
            snprintf(member_info[i][2], sizeof(member_info[i][2]), "여");
        } else if (member_info[i][2][0] == 'M') {
            snprintf(member_info[i][2], sizeof(member_info[i][2]), "남");
        }
    }

    // 데이터 출력
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("####################################\n");
        printf("[%s] 오디션 후보자 데이터 조회\n", candidates[i]);
        printf("####################################\n");
        printf("성   명 |  생   일  | 성 별 |       메   일      | 국적 | BMI | 주스킬 | 보조스킬 | TOPIK | MBTI |\n");
        printf("================================================================================================\n");

        // 생일에서 나이 계산
        int birth_year, birth_month, birth_day;
        sscanf(member_info[i][1], "%d/%d/%d", &birth_year, &birth_month, &birth_day);

        // 현재 날짜를 __DATE__ 매크로로 가져옴
        char current_date[12]; // "Mmm dd yyyy" 형식
        snprintf(current_date, sizeof(current_date), "%s", __DATE__);

        int current_year, current_month, current_day;
        sscanf(current_date, "%*s %d %d", &current_day, &current_year);
        current_month = 0; // 현재 월을 문자열에서 파싱
        char *month_names[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                               "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

        for (int j = 0; j < 12; j++) {
            if (current_date[0] == month_names[j][0]) {
                current_month = j + 1;
                break;
            }
        }

        // 나이 계산
        int age = current_year - birth_year;
        if (birth_month > current_month || (birth_month == current_month && birth_day > current_day)) {
            age--;
        }

        printf("%s(%d)  | %s | %s | %s | %s | %s | %s | %s | %s | %s |\n",
            member_info[i][0], age, member_info[i][1], member_info[i][2], 
            member_info[i][3], member_info[i][4], member_info[i][5], 
            member_info[i][6], member_info[i][7], member_info[i][8], 
            member_info[i][9]);
        printf("---------------------------------------------------------------------------------------------\n");
        printf("%s\n", member_info[i][10]);
        printf("---------------------------------------------------------------------------------------------\n");
    }
    while (getchar() != '\n');
    getchar();
    return 0;
}
