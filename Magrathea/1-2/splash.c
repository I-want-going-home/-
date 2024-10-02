#include <stdio.h>
#include <stdlib.h>

void displaySplashScreen(char name[], char date[]) {
    
    int year, month, day;

    year = atoi(date);
    month = atoi(date + 5);
    day = atoi(date + 8);
    
    const char* lines[] = {
        "                           [���׶��׾� ver 0.1]                                 ",
        "         Ǯ �� ���� ���� Ȳ�������� ��¦�̴� �༺�� ����� �� ���׶��׾�,       ",
        "      ������� ���� ���ϴ� ������� ã�� �������� �ձ��� ���� ������ ������ ��, ",
        "                      ���׶��׾ƿ� ���Ű� ȯ���մϴ�.                           ",
        "                                                                                "
    };

    const char* stars[] = { "*****", "****", "***", "**", "*", "" };

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    for (int i = 0; i < 5; i++) {
        printf("%s%s%s\n", stars[4 - i], lines[i], stars[i]);
    }
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("[�����] : %s                               [���� �ð�] : %d�� %d�� %d�� \n", name, year, month, day);
    printf("======================================================================================\n");
}

int main() {
    char name[20], date[11];

    printf("��¥�� 'yyyy-mm-dd' �������� �Է��ϼ���: ");
    scanf("%s", date);
    
    printf("�̸��� �Է��ϼ���: ");
    scanf("%s", name);
    printf("**�Է��� ���������� ó���Ǿ����ϴ�.**\n");

    _sleep(3000);

    system("cls");

    displaySplashScreen(name, date);

    while (getchar() != '\n');
    getchar();

    return 0;
}
