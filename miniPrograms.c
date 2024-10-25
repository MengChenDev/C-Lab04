// miniPrograms.c

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// 1. 计算定期存款本利之和
void CalculateDeposit()
{
    float rate;
    int n;
    int capital;
    printf("请输入年利率rate（%%）：");
    scanf("%f", &rate);
    printf("请输入存款期n（年）：");
    scanf("%d", &n);
    printf("请输入存款本金capital（元）：");
    scanf("%d", &capital);
    float ratio = 1 + rate / 100;
    float deposit = capital * pow(ratio, n);
    printf("本利之和为：%.2f元\n", deposit);
}

// 2. 身高预测
void PredictHeight()
{
    char sex, sports, diet;
    float faHeight, moHeight, predictedHeight;
    printf("请输入性别（F表示女性，M表示男性）：");
    scanf(" %c", &sex);
    printf("请输入父亲身高：");
    scanf("%f", &faHeight);
    printf("请输入母亲身高：");
    scanf("%f", &moHeight);
    printf("是否喜爱体育锻炼（Y表示是，N表示否）：");
    scanf(" %c", &sports);
    printf("是否有良好的饮食习惯（Y表示是，N表示否）：");
    scanf(" %c", &diet);
    if (sex == 'M')
    {
        predictedHeight = (faHeight + moHeight) * 0.54;
    }
    else if (sex == 'F')
    {
        predictedHeight = (faHeight * 0.923 + moHeight) / 2;
    }
    if ((sports == 'Y' && diet == 'Y'))
    {
        predictedHeight *= 1.02;
    }
    else if (sports == 'Y' || diet == 'Y')
    {
        predictedHeight *= 1.015;
    }
    printf("预测成年时身高为：%.2f cm\n", predictedHeight);
}

// 3. 体型判断
void JudgeBodyShape()
{
    float weight, height, bmi;
    printf("请输入您的身高（米）：");
    scanf("%f", &height);
    printf("请输入您的体重（公斤）：");
    scanf("%f", &weight);
    bmi = weight / (height * height);
    if (bmi < 18)
    {
        printf("低体重\n");
    }
    else if (bmi >= 18 && bmi < 25)
    {
        printf("正常体重\n");
    }
    else if (bmi >= 25 && bmi < 27)
    {
        printf("超重体重\n");
    }
    else
    {
        printf("肥胖\n");
    }
}

// 4. 简单的计算器
void SimpleCalculator()
{
    double data1, data2;
    char op;
    char continueCalc = 'y';
    while (continueCalc == 'y' || continueCalc == 'Y')
    {
        printf("Please enter the expression: ");
        scanf("%lf %c%lf", &data1, &op, &data2);
        switch (op)
        {
        case '+':
            printf("%lf + %lf = %lf\n", data1, data2, data1 + data2);
            break;
        case '-':
            printf("%lf - %lf = %lf\n", data1, data2, data1 - data2);
            break;
        case '*':
            printf("%lf * %lf = %lf\n", data1, data2, data1 * data2);
            break;
        case '/':
            if (fabs(data2) < 1e-6)
            {
                printf("Division by zero!\n");
            }
            else
            {
                printf("%lf / %lf = %lf\n", data1, data2, data1 / data2);
            }
            break;
        default:
            printf("Unknown operator!\n");
        }
        printf("Do you want to continue(Y/N or y/n)? ");
        scanf(" %c", &continueCalc);
    }
    printf("Goodbye!\n");
}

// 5. 判断素数
void IsPrime()
{
    int number, i;
    printf("请输入一个整数：");
    scanf("%d", &number);
    if (number <= 1)
    {
        printf("%d 不是一个素数\n", number);
        return;
    }
    for (i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            printf("%d 不是一个素数\n", number);
            return;
        }
    }
    printf("%d 是一个素数\n", number);
}

// 6. 猜数游戏
void GuessNumberGame()
{
    int secretNumber, guess, attempts = 0;
    int maxAttempts = 10;
    char continuePlaying = 'y';

    while (continuePlaying == 'y')
    {
        srand(time(0));
        secretNumber = rand() % 100 + 1;
        attempts = 0;

        printf("我已经想好了一个1到100之间的数。\n");
        do
        {
            if (attempts >= maxAttempts)
            {
                printf("You have reached the maximum number of attempts. The number was %d.\n", secretNumber);
                break;
            }

            printf("请输入你的猜测：");
            scanf("%d", &guess);
            attempts++;
            if (guess > secretNumber)
            {
                printf("Wrong! Too high!\n");
            }
            else if (guess < secretNumber)
            {
                printf("Wrong! Too low!\n");
            }
            else
            {
                printf("Right! The number was %d. You guessed it in %d attempts.\n", secretNumber, attempts);
            }
        } while (guess != secretNumber && attempts < maxAttempts);

        if (attempts == maxAttempts && guess != secretNumber)
        {
            printf("Game over! The correct number was %d.\n", secretNumber);
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &continuePlaying);
    }

    printf("Thank you for playing!\n");
}