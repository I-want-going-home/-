#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JUDGES 5
#define MAX_NAME_LENGTH 50
#define MAX_GENDER_LENGTH 10
#define MAX_AFFILIATION_LENGTH 100
#define MAX_TITLE_LENGTH 100
#define MAX_EXPERTISE_LENGTH 100
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char gender[MAX_GENDER_LENGTH];
    char affiliation[MAX_AFFILIATION_LENGTH];
    char title[MAX_TITLE_LENGTH];
    char expertise[MAX_EXPERTISE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Judge;

void inputJudgeInfo(Judge* judge) {
    printf("이름: ");
    fgets(judge->name, MAX_NAME_LENGTH, stdin);
    judge->name[strcspn(judge->name, "\n")] = '\0'; // 개행 문자 제거

    printf("성별: ");
    fgets(judge->gender, MAX_GENDER_LENGTH, stdin);
    judge->gender[strcspn(judge->gender, "\n")] = '\0';

    printf("소속: ");
    fgets(judge->affiliation, MAX_AFFILIATION_LENGTH, stdin);
    judge->affiliation[strcspn(judge->affiliation, "\n")] = '\0';

    printf("직함: ");
    fgets(judge->title, MAX_TITLE_LENGTH, stdin);
    judge->title[strcspn(judge->title, "\n")] = '\0';

    printf("전문 분야: ");
    fgets(judge->expertise, MAX_EXPERTISE_LENGTH, stdin);
    judge->expertise[strcspn(judge->expertise, "\n")] = '\0';

    printf("메일: ");
    fgets(judge->email, MAX_EMAIL_LENGTH, stdin);
    judge->email[strcspn(judge->email, "\n")] = '\0';

    printf("전화: ");
    fgets(judge->phone, MAX_PHONE_LENGTH, stdin);
    judge->phone[strcspn(judge->phone, "\n")] = '\0';
}

void printJudgeInfo(Judge judge) {
    printf("이름: %s\n", judge.name);
    printf("성별: %s\n", judge.gender);
    printf("소속: %s\n", judge.affiliation);
    printf("직함: %s\n", judge.title);
    printf("전문 분야: %s\n", judge.expertise);
    printf("메일: %s\n", judge.email);
    printf("전화: %s\n", judge.phone);
}

int main() {
    Judge judges_array[MAX_JUDGES];
    int judge_count = 0;
    char project_name[100];

    // 프로젝트 이름 입력
    printf("참여 프로젝트: ");
    fgets(project_name, sizeof(project_name), stdin);
    project_name[strcspn(project_name, "\n")] = '\0'; // 개행 문자 제거

    printf("심사 풀 인원: %d\n", MAX_JUDGES);
    printf("선발 멤버 수: 4\n");
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("5명의 심사자 정보 입력을 시작합니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    while (judge_count < MAX_JUDGES) {
        printf("*심사자 %d: ", judge_count + 1);
        inputJudgeInfo(&judges_array[judge_count]);

        // 입력이 누락된 경우 체크
        if (strlen(judges_array[judge_count].name) == 0 ||
            strlen(judges_array[judge_count].gender) == 0 ||
            strlen(judges_array[judge_count].affiliation) == 0 ||
            strlen(judges_array[judge_count].title) == 0 ||
            strlen(judges_array[judge_count].expertise) == 0 ||
            strlen(judges_array[judge_count].email) == 0 ||
            strlen(judges_array[judge_count].phone) == 0) {
            printf("입력 항목이 정확하지 않습니다. 다시 입력해주세요.\n");
            continue; // 누락된 경우 다시 입력
        }

        judge_count++;
    }

    printf("\n++++++++++++++++++++++++++++++++++++\n");
    printf("심사자 풀 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 심사자 풀 확인 여부
    char confirm;
    printf("“심사자 풀을 확인할까요?” 메시지를 출력하고 Y 또는 N 입력: ");
    scanf_s(" %c", &confirm);
    getchar(); // 버퍼 비우기

    if (confirm == 'Y') {
        printf("####################################\n");
        printf("#       심사자 풀 데이터 출력       #\n");
        printf("####################################\n");

        for (int i = 0; i < MAX_JUDGES; i++) {
            printf("[심사자 %d]\n", i + 1);
            printJudgeInfo(judges_array[i]);
            printf("-----------------------------------\n");
        }
    }
    else {
        printf("프로그램을 종료합니다.\n");
    }

    while (getchar() != '\n');
    getchar();

    return 0;
}