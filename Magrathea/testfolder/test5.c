#include <stdio.h>
#include <stdlib.h>

#define CANDIDATES_COUNT 6
#define FINAL_MEMBERS_COUNT 4

// ���ڿ� �� �Լ� (strcmp ��ü)
int my_strcmp(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int main() {
    struct {
        int Candidates_ID;            // ���� ID
        int Music;                    // ���� �Ҿ�
        int Dance;                    // ��
        int Vocal;                    // ����
        int Visual;                   // ���־�
        int Transmitted_Forces;       // ���޷�
        int Total_score;              // ����
    } sheet[CANDIDATES_COUNT];

    struct {
        char Name[100];               // �̸�
        int Candidates_ID;            // ���� ID
    } candidates[CANDIDATES_COUNT];

    int id_array[CANDIDATES_COUNT] = {0}; // ���� ID �ߺ� Ȯ�ο� �迭
    char reviewer_name[100];               // �ɻ��� �̸�
    char speciality[100];                  // ���� �о�
    int score;

    printf("####################################\n");
    printf("#       ����� �ɻ� ��� �Է�       #\n");
    printf("####################################\n");

    printf("> �ɻ��� �̸�: ");
    scanf("%s", reviewer_name);
    printf("> ���� �о�: ");
    scanf("%s", speciality);

    // �� �ĺ��ڿ� ���� �̸��� ���� �Է�
    for (int i = 0; i < CANDIDATES_COUNT; i++) {
        printf("\n�ĺ��� %d�� �̸�: ", i + 1);
        scanf("%s", candidates[i].Name);

        // ���� ID ����
        int new_id, duplicate;
        do {
            new_id = rand() % 900000 + 100000; // 6�ڸ� ���� ���� ����
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

        // �� ���� �о߿� ���� ���� �Է�
        if (my_strcmp(speciality, "����") == 0) {
            while (1) {
                printf("���� �Ҿ� (10~100): ");
                scanf("%d", &score);
                if (score >= 10 && score <= 100) {
                    sheet[i].Music = score;
                    break;
                }
                printf("�߸��� �����Դϴ�. �ٽ� �Է��ϼ���.\n");
            }
        }

        // �ٸ� ���� �о߿� ���� ���� �Է� ó�� �߰� ����
        // ���� ��� Dance, Vocal ��...
        
        // ���� ��� (����� ���� ������ ����)
        sheet[i].Total_score = sheet[i].Music; // ���� ���
    }

    // �Է� �Ϸ� �� ��� ���
    printf("\n�Է��� ��� �Ϸ��߽��ϴ�.\n�Է��Ͻ� ������ �����ϼ���!\n");
    printf("------------------------------------\n");
    for (int i = 0; i < CANDIDATES_COUNT; i++) {
        printf("%s (ID: %d): ���� %d\n", candidates[i].Name, candidates[i].Candidates_ID, sheet[i].Total_score);
    }

    // ���� ���� Ȯ��
    char confirm;
    printf("�����Ͻðڽ��ϱ�? (Y/N): ");
    getchar(); // ���� ����
    scanf("%c", &confirm);

    if (confirm == 'Y' || confirm == 'y') {
        printf("***���� ������ �Ϸ��߽��ϴ�.***\n");
    } else {
        printf("�ٽ� ó������ �Է��մϴ�.\n");
    }

    return 0;
}
