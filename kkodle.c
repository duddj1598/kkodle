#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

void printHelp() {

    printf("������ ���� ���� �ڸ�� Ǯ� ����ܾ ���� ���� ���� �ȿ� ������ �����Դϴ�.\n");
    printf("��������������������������������������\n");
    printf("������  ��  ��  ��  ��  ��\n");
    printf("��������������������������������������\n");
    printf("���� ���� �ùٸ� �ڸ��� �ֽ��ϴ�.\n");
    printf("��������������������������������������\n");
    printf("������  ��  ��  ��  ��  ��\n");
    printf("��������������������������������������\n");
    printf("             ��     \n");
    printf("���� ���� �߸��� �ڸ��� �ֽ��ϴ�.\n");
    printf("��������������������������������������\n");
    printf("������  ��  ��  ��  ��  ��\n");
    printf("��������������������������������������\n�ƹ� ǥ�� ���� ���� ��� ������ ���� �ʽ��ϴ�. \n");
    printf("��������������������������������������\n");
    printf("�����������Ӧ����������Ӧ�\n");
    printf("��������������������������������������\n���ո����� ������, ���ħ�� �� ���� �ڸ��� Ǯ�����ϴ�. �ڸ�� �ߺ��� �� �ֽ��ϴ�.\n");
    printf("���� ������ ������ ���ô�! \n\n\n");
    printf("(�Է¿��� : �� �� �� �� �� ��) ");
}
int checkAnswer(char kordle[][3], char answer[][3], int strike[]) {
    memset(strike, 0, 6 * sizeof(int));
    int sum = 0;
    for (int j = 0; j < 6; j++)
        for (int k = 0; k < 6; k++)
            if (strcmp(kordle[j], answer[k]) == 0) {
                if (j == k)
                {
                    strike[j] = 2;//��Ʈ����ũ
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
    printf("%d�� ���\n��������������������������������������\n��", n + 1);
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
        printf("��");
    }
    printf("\n��������������������������������������\n");
    printf("\t\t\t\b\b: ");
}
void Ending(char answer[][3]) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    printf("%!!�����մϴ�!!\n��������������������������������������\n��");
    for (int i = 0; i < 6; i++) {
        printf("%s��", answer[i]);
    }
    printf("\n��������������������������������������\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
int main(void) {
    char kordle[6][3];
    char answer[6][3] = { "��","��","��","��","��","��" };
    int strike[6] = { 0, };
    int a = 0;
    printHelp();
    printf("\t1��° : ");
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