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
    printf("�̸�: ");
    fgets(judge->name, MAX_NAME_LENGTH, stdin);
    judge->name[strcspn(judge->name, "\n")] = '\0'; // ���� ���� ����

    printf("����: ");
    fgets(judge->gender, MAX_GENDER_LENGTH, stdin);
    judge->gender[strcspn(judge->gender, "\n")] = '\0';

    printf("�Ҽ�: ");
    fgets(judge->affiliation, MAX_AFFILIATION_LENGTH, stdin);
    judge->affiliation[strcspn(judge->affiliation, "\n")] = '\0';

    printf("����: ");
    fgets(judge->title, MAX_TITLE_LENGTH, stdin);
    judge->title[strcspn(judge->title, "\n")] = '\0';

    printf("���� �о�: ");
    fgets(judge->expertise, MAX_EXPERTISE_LENGTH, stdin);
    judge->expertise[strcspn(judge->expertise, "\n")] = '\0';

    printf("����: ");
    fgets(judge->email, MAX_EMAIL_LENGTH, stdin);
    judge->email[strcspn(judge->email, "\n")] = '\0';

    printf("��ȭ: ");
    fgets(judge->phone, MAX_PHONE_LENGTH, stdin);
    judge->phone[strcspn(judge->phone, "\n")] = '\0';
}

void printJudgeInfo(Judge judge) {
    printf("�̸�: %s\n", judge.name);
    printf("����: %s\n", judge.gender);
    printf("�Ҽ�: %s\n", judge.affiliation);
    printf("����: %s\n", judge.title);
    printf("���� �о�: %s\n", judge.expertise);
    printf("����: %s\n", judge.email);
    printf("��ȭ: %s\n", judge.phone);
}

int main() {
    Judge judges_array[MAX_JUDGES];
    int judge_count = 0;
    char project_name[100];

    // ������Ʈ �̸� �Է�
    printf("���� ������Ʈ: ");
    fgets(project_name, sizeof(project_name), stdin);
    project_name[strcspn(project_name, "\n")] = '\0'; // ���� ���� ����

    printf("�ɻ� Ǯ �ο�: %d\n", MAX_JUDGES);
    printf("���� ��� ��: 4\n");
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("5���� �ɻ��� ���� �Է��� �����մϴ�.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    while (judge_count < MAX_JUDGES) {
        printf("*�ɻ��� %d: ", judge_count + 1);
        inputJudgeInfo(&judges_array[judge_count]);

        // �Է��� ������ ��� üũ
        if (strlen(judges_array[judge_count].name) == 0 ||
            strlen(judges_array[judge_count].gender) == 0 ||
            strlen(judges_array[judge_count].affiliation) == 0 ||
            strlen(judges_array[judge_count].title) == 0 ||
            strlen(judges_array[judge_count].expertise) == 0 ||
            strlen(judges_array[judge_count].email) == 0 ||
            strlen(judges_array[judge_count].phone) == 0) {
            printf("�Է� �׸��� ��Ȯ���� �ʽ��ϴ�. �ٽ� �Է����ּ���.\n");
            continue; // ������ ��� �ٽ� �Է�
        }

        judge_count++;
    }

    printf("\n++++++++++++++++++++++++++++++++++++\n");
    printf("�ɻ��� Ǯ �Է��� �������ϴ�.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    // �ɻ��� Ǯ Ȯ�� ����
    char confirm;
    printf("���ɻ��� Ǯ�� Ȯ���ұ��?�� �޽����� ����ϰ� Y �Ǵ� N �Է�: ");
    scanf_s(" %c", &confirm);
    getchar(); // ���� ����

    if (confirm == 'Y') {
        printf("####################################\n");
        printf("#       �ɻ��� Ǯ ������ ���       #\n");
        printf("####################################\n");

        for (int i = 0; i < MAX_JUDGES; i++) {
            printf("[�ɻ��� %d]\n", i + 1);
            printJudgeInfo(judges_array[i]);
            printf("-----------------------------------\n");
        }
    }
    else {
        printf("���α׷��� �����մϴ�.\n");
    }

    while (getchar() != '\n');
    getchar();

    return 0;
}