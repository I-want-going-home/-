#include <stdio.h>
#include <stdlib.h>

#define NUM_CANDIDATES 2
#define ATTRIBUTES 12

int main() {
    char candidate01[200], candidate02[200], candidate03[200];
    char candidate04[200], candidate05[200], candidate06[200];
    char *candidates[NUM_CANDIDATES] = {candidate01, candidate02, candidate03, candidate04, candidate05, candidate06};

    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("����� �׷��: ");
        fgets(candidates[i], sizeof(candidate01), stdin);

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
        printf("[%s] ����� �ĺ��� ������ �Է�\n", candidates[i]);
        printf("####################################\n");

        char member_info[ATTRIBUTES][200];

        // 1. ����
        printf("1. ����: ");
        fgets(member_info[0], sizeof(member_info[0]), stdin);
        {
            int len = 0;
            while (member_info[0][len] != '\0') {
                len++;
            }
            if (len > 0 && member_info[0][len - 1] == '\n') {
                member_info[0][len - 1] = '\0';
            }
        }

        // 2. ����
        printf("2. ����(YYYY/MM/DD ����): ");
        fgets(member_info[1], sizeof(member_info[1]), stdin);
        {
            int len = 0;
            while (member_info[1][len] != '\0') {
                len++;
            }
            if (len > 0 && member_info[1][len - 1] == '\n') {
                member_info[1][len - 1] = '\0';
            }
        }

        // 3. ����
        printf("3. ����(�����̸� F �Ǵ� �����̸� M): ");
        fgets(member_info[2], sizeof(member_info[2]), stdin);
        {
            int len = 0;
            while (member_info[2][len] != '\0') {
                len++;
            }
            if (len > 0 && member_info[2][len - 1] == '\n') {
                member_info[2][len - 1] = '\0';
            }
        }

        if (member_info[2][0] == 'F') {
            snprintf(member_info[2], sizeof(member_info[2]), "��");
        } else if (member_info[2][0] == 'M') {
            snprintf(member_info[2], sizeof(member_info[2]), "��");
        }

        // 4. ����
        printf("4. ���� �ּ�: ");
        fgets(member_info[3], sizeof(member_info[3]), stdin);
        {
            int len = 0;
            while (member_info[3][len] != '\0') {
                len++;
            }
            if (len > 0 && member_info[3][len - 1] == '\n') {
                member_info[3][len - 1] = '\0';
            }
        }

        // 5. ����
        printf("5. ����: ");
        fgets(member_info[4], sizeof(member_info[4]), stdin);
        {
            int len = 0;
            while (member_info[4][len] != '\0') {
                len++;
            }
            if (len > 0 && member_info[4][len - 1] == '\n') {
                member_info[4][len - 1] = '\0';
            }
        }

        // 6. BMI
        printf("6. BMI: ");
        fgets(member_info[5], sizeof(member_info[5]), stdin);
        {
            int len = 0;
            while (member_info[5][len] != '\0') {
                len++;
            }
            if (len > 0 && member_info[5][len - 1] == '\n') {
                member_info[5][len - 1] = '\0';
            }
        }

        // 7. �� ��ų
        printf("7. �� ��ų: ");
        fgets(member_info[6], sizeof(member_info[6]), stdin);
        {
            int len = 0;
            while (member_info[6][len] != '\0') {
                len++;
            }
            if (len > 0 && member_info[6][len - 1] == '\n') {
                member_info[6][len - 1] = '\0';
            }
        }

        // 8. ���� ��ų
        printf("8. ���� ��ų: ");
        fgets(member_info[7], sizeof(member_info[7]), stdin);
        {
            int len = 0;
            while (member_info[7][len] != '\0') {
                len++;
            }
            if (len > 0 && member_info[7][len - 1] == '\n') {
                member_info[7][len - 1] = '\0';
            }
        }

        // 9. �ѱ��� ���
        printf("9. �ѱ��� ���(TOPIK): ");
        fgets(member_info[8], sizeof(member_info[8]), stdin);
        {
            int len = 0;
            while (member_info[8][len] != '\0') {
                len++;
            }
            if (len > 0 && member_info[8][len - 1] == '\n') {
                member_info[8][len - 1] = '\0';
            }
        }

        // 10. MBTI
        printf("10. MBTI: ");
        fgets(member_info[9], sizeof(member_info[9]), stdin);
        {
            int len = 0;
            while (member_info[9][len] != '\0') {
                len++;
            }
            if (len > 0 && member_info[9][len - 1] == '\n') {
                member_info[9][len - 1] = '\0';
            }
        }

        // 11. �Ұ�
        printf("11. �Ұ�: ");
        fgets(member_info[10], sizeof(member_info[10]), stdin);

        printf("=================================\n");

        // ��� ���
        printf("####################################\n");
        printf("[%s] ����� �ĺ��� ������ ��ȸ\n", candidates[i]);
        printf("####################################\n");
        printf("����: %s\n", member_info[0]);
        printf("����: %s\n", member_info[1]);
        printf("����: %s\n", member_info[2]);
        printf("����: %s\n", member_info[3]);
        printf("����: %s\n", member_info[4]);
        printf("BMI: %s\n", member_info[5]);
        printf("�� ��ų: %s\n", member_info[6]);
        printf("���� ��ų: %s\n", member_info[7]);
        printf("�ѱ��� ���: %s\n", member_info[8]);
        printf("MBTI: %s\n", member_info[9]);
        printf("�Ұ�: %s\n", member_info[10]);
        printf("=================================\n");
    }

    return 0;
}
