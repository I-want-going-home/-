#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JUDGE_LENGTH 512

int main() {
    int num_judges;
    int selected_members;

    printf("####################################\n");
    printf("#       �ɻ��� Ǯ ������ �Է�      #\n");
    printf("####################################\n");

    char project_name[200];
    printf("> ���� ������Ʈ: ");
    fgets(project_name, sizeof(project_name), stdin);
    project_name[strcspn(project_name, "\n")] = '\0'; // ���� ����
    
    printf("> �ɻ� Ǯ �ο�: ");
    scanf("%d", &num_judges);
    getchar();  // ���� ���� ����

    printf("> ���� ��� ��: ");
    scanf("%d", &selected_members);
    getchar();  // ���� ���� ����


    // 1���� �迭�� �ɻ��� ������ ������ ���� �Ҵ�
    char judges_array[num_judges * MAX_JUDGE_LENGTH]; // 1���� �迭
    memset(judges_array, 0, sizeof(judges_array)); // �迭 �ʱ�ȭ

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d���� �ɻ��� ���� �Է��� �����մϴ�.\n", num_judges);
    printf("++++++++++++++++++++++++++++++++++++\n");

    for (int i = 0; i < num_judges; i++) {
        printf("*�ɻ��� %d: ", i + 1);
        fgets(judges_array + (i * MAX_JUDGE_LENGTH), MAX_JUDGE_LENGTH, stdin);

        // ���� ����
        size_t len = strlen(judges_array + (i * MAX_JUDGE_LENGTH));
        if (len > 0 && judges_array[i * MAX_JUDGE_LENGTH + len - 1] == '\n') {
            judges_array[i * MAX_JUDGE_LENGTH + len - 1] = '\0';
        }
    }

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("�ɻ��� Ǯ �Է��� �������ϴ�.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    char confirm;
    printf("[ %s ] �ɻ��� Ǯ�� Ȯ���ұ��? Y/N: ", project_name);
    scanf(" %c", &confirm); // confirm �տ� ���� �߰��� ���� �Է¿��� ���๮�� ����

    if (confirm == 'Y' || confirm == 'y') {
        printf("####################################\n");
        printf("#       �ɻ��� Ǯ ������ ���      #\n");
        printf("####################################\n");

        for (int i = 0; i < num_judges; i++) {
            printf("[�ɻ��� %d]\n", i + 1);
            // JSON ���Ŀ��� �����͸� �Ľ��Ͽ� ���
            char name[50], gender[10], affiliation[100], position[100], specialty[100], email[100], phone[20];
            sscanf(judges_array + (i * MAX_JUDGE_LENGTH), "�̸�:%[^,],����:%[^,],�Ҽ�:%[^,],����:%[^,],�����о�:%[^,],����:%[^,],��ȭ:%s",
                   name, gender, affiliation, position, specialty, email, phone);
            printf("�̸�: %s\n", name);
            printf("����: %s\n", gender);
            printf("�Ҽ�: %s\n", affiliation);
            printf("����: %s\n", position);
            printf("�����о�: %s\n", specialty);
            printf("����: %s\n", email);
            printf("��ȭ: %s\n", phone);
            printf("-----------------------------------\n");
        }
    }

    // JSON ���� ����
    FILE *file = fopen("judges.json", "w");
    if (file) {
        fprintf(file, "{\n\t\"project\": \"%s\",\n\t\"judges\": [\n", project_name);
        for (int i = 0; i < num_judges; i++) {
            fprintf(file, "\t\t\"%s\"", judges_array + (i * MAX_JUDGE_LENGTH));
            if (i < num_judges - 1) {
                fprintf(file, ",");
            }
            fprintf(file, "\n");
        }
        fprintf(file, "\t]\n}");
        fclose(file);
        printf("�ɻ��� ������ JSON ���Ϸ� ����Ǿ����ϴ�: judges.json\n");
    } else {
        printf("������ ������ �� �����ϴ�.\n");
    }
    while (getchar() != '\n');
    getchar();

    return 0;
}
