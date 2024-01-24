#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

void printHelp() {

    printf("꼬들은 여섯 개의 자모로 풀어쓴 정답단어를 여섯 번의 도전 안에 맞히는 게임입니다.\n");
    printf("┌──┬──┬──┬──┬──┬──┐\n");
    printf("│ㅈ│  │  │  │  │  │\n");
    printf("└──┴──┴──┴──┴──┴──┘\n");
    printf("자음 ㅈ은 올바른 자리에 있습니다.\n");
    printf("┌──┬──┬──┬──┬──┬──┐\n");
    printf("│ㅈ│  │  │  │  │  │\n");
    printf("└──┴──┴──┴──┴──┴──┘\n");
    printf("             ㅏ     \n");
    printf("모음 ㅏ는 잘못된 자리에 있습니다.\n");
    printf("┌──┬──┬──┬──┬──┬──┐\n");
    printf("│ㅈ│  │  │  │  │  │\n");
    printf("└──┴──┴──┴──┴──┴──┘\n아무 표시 없는 것은 어느 곳에도 맞지 않습니다. \n");
    printf("┌──┬──┬──┬──┬──┬──┐\n");
    printf("│ㅈ│ㅈ│ㅣ│ㄱ│ㅏ│ㅣ│\n");
    printf("└──┴──┴──┴──┴──┴──┘\n복합모음과 쌍자음, 겹받침은 더 작은 자모들로 풀어집니다. 자모는 중복될 수 있습니다.\n");
    printf("이제 게임을 시작해 봅시다! \n\n\n");
    printf("(입력예시 : ㅇ ㅡ ㅁ ㅇ ㅜ ㄴ) ");
}
int checkAnswer(char kordle[][3], char answer[][3], int strike[]) {
    memset(strike, 0, 6 * sizeof(int));
    int sum = 0;
    for (int j = 0; j < 6; j++)
        for (int k = 0; k < 6; k++)
            if (strcmp(kordle[j], answer[k]) == 0) {
                if (j == k)
                {
                    strike[j] = 2;//스트라이크
                    sum++;
                }
                else {
                    strike[j] = strike[j] != 2 ? 1 : 2;
                }
            }
    if (sum == 6)
        return 4;
}
void printUser(int strike[], char kordle[][3], int n) {
    printf("%d번 결과\n┌──┬──┬──┬──┬──┬──┐\n│", n + 1);
    for (int i = 0; i < 6; i++) {
        if (strike[i] == 2) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
            printf("%s", kordle[i]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        else if (strike[i] == 1) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            printf("%s", kordle[i]);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        else printf("  ");
        printf("│");
    }
    printf("\n└──┴──┴──┴──┴──┴──┘\n");
    printf("\t\t\t\b\b: ");
}
void Ending(char answer[][3]) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf("%!!축하합니다!!\n┌──┬──┬──┬──┬──┬──┐\n│");
    for (int i = 0; i < 6; i++) {
        printf("%s│", answer[i]);
    }
    printf("\n└──┴──┴──┴──┴──┴──┘\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
int main(void) {
    char kordle[6][3];
    char answer[6][3] = { "ㅇ","ㅡ","ㅁ","ㅇ","ㅜ","ㄴ" };
    int strike[6] = { 0, };
    int a = 0;
    printHelp();
    printf("\t1번째 : ");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            scanf("%s", kordle[j]);
            if (**kordle == '?') {
                printHelp();
                j--;
            }
        }

        if (checkAnswer(kordle, answer, strike) == 4)
        {
            Ending(answer);
            break;
        }
        printUser(strike, kordle, i);
    }


}