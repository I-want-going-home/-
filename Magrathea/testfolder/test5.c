#include <stdio.h>
#include <stdlib.h>

#define CANDIDATES_COUNT 6
#define FINAL_MEMBERS_COUNT 4

// 문자열 비교 함수 (strcmp 대체)
int my_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int main() {
    struct {
        int Candidates_ID;            // 고유 ID
        int Music;                    // 음악 소양
        int Dance;                    // 댄스
        int Vocal;                    // 보컬
        int Visual;                   // 비주얼
        int Transmitted_Forces;       // 전달력
        int Total_score;              // 총점
    } sheet[CANDIDATES_COUNT];

    struct {
        char Name[100];               // 이름
        int Candidates_ID;            // 고유 ID
    } candidates[CANDIDATES_COUNT];

    int id_array[CANDIDATES_COUNT] = {0}; // 고유 ID 중복 확인용 배열
    char reviewer_name[100];               // 심사자 이름
    char speciality[100];                  // 전문 분야
    int score;

    printf("####################################\n");
    printf("#       오디션 심사 결과 입력       #\n");
    printf("####################################\n");

    printf("> 심사자 이름: ");
    scanf("%s", reviewer_name);
    printf("> 전문 분야: ");
    scanf("%s", speciality);

    // 각 후보자에 대해 이름과 점수 입력
    for (int i = 0; i < CANDIDATES_COUNT; i++) {
        printf("\n후보자 %d의 이름: ", i + 1);
        scanf("%s", candidates[i].Name);

        // 고유 ID 생성
        int new_id, duplicate;
        do {
            new_id = rand() % 900000 + 100000; // 6자리 임의 정수 생성
            duplicate = 0;
            for (int j = 0; j < i; j++) {
                if (id_array[j] == new_id) {
                    duplicate = 1;
                    break;
                }
            }
        } while (duplicate);

        candidates[i].Candidates_ID = new_id;
        id_array[i] = new_id;
        sheet[i].Candidates_ID = new_id;

        // 각 전문 분야에 대한 점수 입력
        if (my_strcmp(speciality, "음악") == 0) {
            while (1) {
                printf("음악 소양 (10~100): ");
                scanf("%d", &score);
                if (score >= 10 && score <= 100) {
                    sheet[i].Music = score;
                    break;
                }
                printf("잘못된 점수입니다. 다시 입력하세요.\n");
            }
        }

        // 다른 전문 분야에 대한 점수 입력 처리 추가 가능
        // 예를 들어 Dance, Vocal 등...
        
        // 총점 계산 (현재는 음악 점수만 계산됨)
        sheet[i].Total_score = sheet[i].Music; // 총점 계산
    }

    // 입력 완료 후 결과 출력
    printf("\n입력을 모두 완료했습니다.\n입력하신 내용을 검토하세요!\n");
    printf("------------------------------------\n");
    for (int i = 0; i < CANDIDATES_COUNT; i++) {
        printf("%s (ID: %d): 총점 %d\n", candidates[i].Name, candidates[i].Candidates_ID, sheet[i].Total_score);
    }

    // 제출 여부 확인
    char confirm;
    printf("제출하시겠습니까? (Y/N): ");
    getchar(); // 버퍼 비우기
    scanf("%c", &confirm);

    if (confirm == 'Y' || confirm == 'y') {
        printf("***최종 제출을 완료했습니다.***\n");
    } else {
        printf("다시 처음부터 입력합니다.\n");
    }

    return 0;
}
