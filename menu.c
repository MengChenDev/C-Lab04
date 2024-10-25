// menu.c

#include <stdio.h>
#include <stdlib.h>
#include "miniPrograms.c"

// 函数声明
void Menu();
void showMenu();
int getChoice();
void route(int choice);

// Menu 菜单
void Menu()
{
    int choice;
    // 清屏
    system("cls");

    // 显示菜单
    showMenu();

    // 接收用户输入
    choice = getChoice();

    // 路由
    system("cls");
    route(choice);
    
    printf("按下任意键继续...\n");
    getchar();
    getchar();


    return;
}

// 显示菜单
void showMenu()
{
    printf("--------主菜单--------\n");
    printf("1. 计算定期存款本利之和\n");
    printf("2. 身高预测\n");
    printf("3. 体型判断\n");
    printf("4. 简单的计算器\n");
    printf("5. 判断素数\n");
    printf("6. 猜数游戏\n");
    printf("7. 退出程序\n");
    printf("请输入要操作的序号 >>");
}

// 接收用户输入
int getChoice()
{
    int choice;
    while (scanf("%d", &choice) != 1)
    {
        // 清空输入缓冲区
        while (getchar() != '\n');
        printf("输入有误，请重新输入 >>");
    }
    return choice;
}

// 路由
void route(int choice)
{
    switch (choice)
    {
    case 1:
        // 计算定期存款本利之和
        CalculateDeposit();
        break;
    case 2:
        // 身高预测
        PredictHeight();
        break;
    case 3:
        // 体型判断
        JudgeBodyShape();
        break;
    case 4:
        // 简单的计算器
        SimpleCalculator();
        break;
    case 5:
        // 判断素数
        IsPrime();
        break;
    case 6:
        // 猜数游戏
        GuessNumberGame();
        break;
    case 7:
        // 退出程序
        exit(0);
    default:
        break;
    }
    return;
}