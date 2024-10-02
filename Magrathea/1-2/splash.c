#include <stdio.h>
#include <stdlib.h>

void displaySplashScreen(char name[], char date[]) {
    
    int year, month, day;

    year = atoi(date);
    month = atoi(date + 5);
    day = atoi(date + 8);
    
    const char* lines[] = {
        "                           [마그라테아 ver 0.1]                                 ",
        "         풀 한 포기 없는 황무지에서 반짝이는 행성을 만드는 곳 마그라테아,       ",
        "      사람들이 보지 못하는 잠재력을 찾고 전문가의 손길을 더해 보석을 빛나는 곳, ",
        "                      마그라테아에 오신걸 환영합니다.                           ",
        "                                                                                "
    };

    const char* stars[] = { "*****", "****", "***", "**", "*", "" };

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    for (int i = 0; i < 5; i++) {
        printf("%s%s%s\n", stars[4 - i], lines[i], stars[i]);
    }
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("[사용자] : %s                               [실행 시간] : %d년 %d월 %d일 \n", name, year, month, day);
    printf("======================================================================================\n");
}

int main() {
    char name[20], date[11];

    printf("날짜를 'yyyy-mm-dd' 형식으로 입력하세요: ");
    scanf("%s", date);
    
    printf("이름을 입력하세요: ");
    scanf("%s", name);
    printf("**입력이 정상적으로 처리되었습니다.**\n");

    _sleep(3000);

    system("cls");

    displaySplashScreen(name, date);

    while (getchar() != '\n');
    getchar();

    return 0;
}
