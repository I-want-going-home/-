#include <stdio.h>
#include <stdlib.h>

#define MAX_JUDGES 100    // �ִ� �ɻ��� ��
#define MAX_STRING 1000   // ���ڿ� �ִ� ����

int main() {
    char project[50];                          // ������Ʈ��
    int judge_num, select_num;                 // �ɻ��� ��, ���� �ο�
    char *judges_array[MAX_JUDGES];            // ������ �迭�� ����
    char check;                                // Ȯ�� �Է¿�

    // ���α׷� ���� �� �⺻ ���� �Է�
    printf("####################################\n");
    printf("#       �ɻ��� Ǯ ������ �Է�      #\n");
    printf("####################################\n");

    printf("���� ������Ʈ: ");
    scanf("%s", project);

    printf("�ɻ� Ǯ �ο�: ");
    scanf("%d", &judge_num);

    printf("���� ��� ��: ");
    scanf("%d", &select_num);

    // �ɻ��� ���� �Է� ����
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d���� �ɻ��� ���� �Է��� �����մϴ�.\n", judge_num);
    printf("++++++++++++++++++++++++++++++++++++\n");

    // �� �ɻ����� ������ �޸��� �����Ͽ� �� �ٷ� �Է¹ޱ�
    for (int i = 0; i < judge_num; i++) {
        char name[50], gender[10], company[50], position[50];
        char expertise[50], email[50], phone[20];
        char input_line[MAX_STRING];
        int valid_input = 0;

        while (!valid_input) {
            printf("\n�ɻ��� %d�� ����: ", i + 1);
            scanf(" %[^\n]s", input_line);

            // " ����
            int j = 0, k = 0;
            while (input_line[j]) {
                if (input_line[j] != '"') {
                    input_line[k++] = input_line[j];
                }
                j++;
            }
            input_line[k] = '\0';

            // �޸��� ���е� �Է��� �и�
            int fields = sscanf(input_line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                                name, gender, company, position, expertise, email, phone);

            if (fields == 7 &&
                name[0] != '\0' && gender[0] != '\0' && company[0] != '\0' &&
                position[0] != '\0' && expertise[0] != '\0' && email[0] != '\0' &&
                phone[0] != '\0') {
                valid_input = 1;
            } else {
                printf("Error: ��� �ʵ带 �Է����ּ��� (�̸�,����,�Ҽ�,����,�����о�,�̸���,��ȭ��ȣ)\n");
            }
        }

        // ���� �޸� �Ҵ����� ����
        judges_array[i] = (char *)malloc(MAX_STRING * sizeof(char));
        sprintf(judges_array[i],
                "{\"name\":\"%s\",\"gender\":\"%s\",\"company\":\"%s\","
                "\"position\":\"%s\",\"expertise\":\"%s\",\"email\":\"%s\",\"phone\":\"%s\"}",
                name, gender, company, position, expertise, email, phone);
    }

    // ������ Ȯ�� ���� üũ
    printf("\n[%s] �ɻ��� Ǯ�� Ȯ���ұ��? (y/n): ", project);
    scanf(" %c", &check);

    // ������ ���
    if (check == 'y' || check == 'Y') {
        printf("\n####################################\n");
        printf("#       �ɻ��� Ǯ ������ ���      #\n");
        printf("####################################\n");

        for (int i = 0; i < judge_num; i++) {
            printf("\n[�ɻ��� %d]\n", i + 1);
            char name[50], gender[10], company[50], position[50];
            char expertise[50], email[50], phone[20];

            // JSON ���ڿ����� �� �ʵ��� ���� ����
            sscanf(judges_array[i],
                   "{\"name\":\"%[^\"]\",\"gender\":\"%[^\"]\",\"company\":\"%[^\"]\","
                   "\"position\":\"%[^\"]\",\"expertise\":\"%[^\"]\",\"email\":\"%[^\"]\",\"phone\":\"%[^\"]\"}",
                   name, gender, company, position, expertise, email, phone);

            printf("%s\n", name);
            printf("%s\n", gender);
            printf("%s\n", company);
            printf("%s\n", position);
            printf("%s\n", expertise);
            printf("%s\n", email);
            printf("%s\n", phone);
            printf("----------------------------------\n");
        }
    } else {
        printf("���α׷��� �����մϴ�.\n");
    }

    // ���α׷� ���� �� �޸� ����
    for (int i = 0; i < judge_num; i++) {
        free(judges_array[i]);
    }

    while (getchar() != '\n');
    getchar();

    return 0;
}
