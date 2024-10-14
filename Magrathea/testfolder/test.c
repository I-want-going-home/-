#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // ���� �ð� ���� �Լ� ����� ���� �߰�

#define NUM_CANDIDATES 2
const char* membercount[] = {"ù", "��", "��", "��", "�ټ�", "����"};

// �ĺ��� ������ �����ϱ� ���� ����ü ����
typedef struct {
    char name[50];            // ����
    char birth[11];           // ����
    char gender;              // ����
    char email[100];          // ���� �ּ�
    char nationality[50];     // ����
    float bmi;                // BMI
    char main_skill[50];      // �� ��ų
    char sub_skill[50];       // ���� ��ų
    char korean_level[10];    // �ѱ��� ���
    char mbti[10];            // MBTI
    char introduction[200];   // �Ұ�
    char group_name[50];      // ����� �׷��
} Candidate;

// �� ���̸� ����ϴ� �Լ�
int calculate_age(char *birth) {
    int birth_year, birth_month, birth_day;
    int current_year, current_month, current_day;
    sscanf(birth, "%4d/%2d/%2d", &birth_year, &birth_month, &birth_day);

    // ���� ��¥�� ���ϱ� ���� time.h ���̺귯�� ���
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    current_year = tm.tm_year + 1900;  // tm_year�� 1900���� �������� �ϹǷ� 1900�� ������� ��
    current_month = tm.tm_mon + 1;     // tm_mon�� 0���� �����ϹǷ� 1�� ������� ��
    current_day = tm.tm_mday;

    int age = current_year - birth_year;

    // ������ ���� ������ �ʾ����� ���̸� 1�� ���� ��
    if (current_month < birth_month || (current_month == birth_month && current_day < birth_day)) {
        age--;
    }

    return age;
}

int main() {
    Candidate candidates[NUM_CANDIDATES];  // �ĺ��� ������ ������ �迭
    int i = 0;

    // �ĺ��� �����͸� �Է¹���
    while (i < NUM_CANDIDATES) {
        printf("����� �׷��: ");
        scanf("%s", candidates[i].group_name);

        printf("####################################\n");
        printf("[%s] ����� �ĺ��� ������ �Է�\n", candidates[i].group_name);
        printf("####################################\n");
        printf("%s��° �ĺ����� ������ �Է��մϴ�.\n", membercount[i]);
        printf("---------------------------------\n");

        printf("1. ����: ");
        scanf("%s", candidates[i].name);
        getchar();  // ���� ����

        printf("2. ����(YYYY/MM/DD ����): ");
        scanf("%s", candidates[i].birth);
        getchar();  // ���� ����

        printf("3. ����(�����̸� F �Ǵ� �����̸� M): ");
        scanf(" %c", &candidates[i].gender);  // ������ �־� ���� ���
        getchar();  // ���� ����

        printf("4. ���� �ּ�: ");
        scanf("%s", candidates[i].email);
        getchar();  // ���� ����

        printf("5. ����: ");
        scanf("%s", candidates[i].nationality);
        getchar();  // ���� ����

        printf("6. BMI: ");
        scanf("%f", &candidates[i].bmi);
        getchar();  // ���� ����

        printf("7. �� ��ų: ");
        scanf("%s", candidates[i].main_skill);
        getchar();  // ���� ����

        printf("8. ���� ��ų: ");
        scanf("%s", candidates[i].sub_skill);
        getchar();  // ���� ����

        printf("9. �ѱ��� ���(TOPIK): ");
        scanf("%s", candidates[i].korean_level);
        getchar();  // ���� ����

        printf("10. MBTI: ");
        scanf("%s", candidates[i].mbti);
        getchar();  // ���� ���

        printf("11. �Ұ�: ");
        fgets(candidates[i].introduction, sizeof(candidates[i].introduction), stdin);  // �Ұ��� ���� ���� �Է��� �ޱ� ���� fgets ���

        printf("=================================\n");

        i++;  // ���� �ĺ��ڷ� �̵�
    }

    // �ĺ��� ������ ���
    for (i = 0; i < NUM_CANDIDATES; i++) {
        printf("####################################\n");
        printf("[%s] ����� �ĺ��� ������ ��ȸ\n", candidates[i].group_name);
        printf("####################################\n");
        printf("================================================================================================\n");
        printf("��   �� |  ��   ��  | �� �� |       ��   ��      | ���� | BMI | �ֽ�ų | ������ų | TOPIK | MBTI |\n");
        printf("================================================================================================\n");

        // ���Ͽ��� '/'�� �����ϴ� �κ�
        char formatted_birth[11];  // YYYYMMDD �������� ��ȯ�� ������ ������ �迭
        int j = 0;
        for (int k = 0; k < 10; k++) {
            if (candidates[i].birth[k] != '/') {
                formatted_birth[j++] = candidates[i].birth[k];
            }
        }
        formatted_birth[j] = '\0';  // ���ڿ� ���� ��Ÿ���� �� ���� �߰�

        // ���� ��� �� 'if' �� ���
        char gender_str[3] = "?";  // �⺻ ���� '?'
        if (candidates[i].gender == 'F' || candidates[i].gender == 'f') {
            snprintf(gender_str, sizeof(gender_str), "��");
        } else if (candidates[i].gender == 'M' || candidates[i].gender == 'm') {
            snprintf(gender_str, sizeof(gender_str), "��");
        }

        // �� ���� ���
        int age = calculate_age(candidates[i].birth);

        // ��� ���Ŀ� �°� ������ ���
        printf("%s(%d)  |%s | %s   | %s | %s | %.1f | %s | %s | %s | %s |\n",
            candidates[i].name,
            age,  // �� ���� ���
            formatted_birth,  // ������ ���� ���
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
