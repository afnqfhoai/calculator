#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void getCommand();
void printScreen();
//用于识别输入
char help[101] = "help";
char about[101] = "about";
char history[101] = "history";
char input[101] = "input";
char quit[101] = "quit";
char historyOutput[20][101];//存储历史计算过程

void printScreen()//输出主屏幕
{
    printf("********************\n");
    printf("*  输入式子以开始计算  *\n");
    printf("********************\n");
    printf("help 获取帮助\n");
    printf("about 关于开发\n");
    printf("history 历史计算数据\n");
    printf("quit 退出\n");
    printf("请输入式子或所需功能：\n");
}


void getCommand() {
    void printHelp();
    void printAbout();
    void printHistory();
    void getInput();
    double calculate(char* input);
    bool preCalculate(char* input);
    getInput();
    if (strcmp(input, help) == 0) {
        printHelp();
    }
    else if (strcmp(input, about) == 0) {
        printAbout();
    }
    else if (strcmp(input, history) == 0) {
        printHistory();
    }
    else if (strcmp(input, quit) == 0) {
        printf("感谢使用。");
        exit(1);
    }
    else {
        preCalculate(input);
        if(preCalculate(input)) {
            printf("%lf\n",calculate(input));
        }
    }
}

void printHelp() {
    printf("帮助\n");
    printf("基本功能：输入式子直接计算\n");
    printf("示例：2*3+4*6\n");
    printf("圆周率请使用pi,自然对数请使用e\n");
}

void printAbout() {
    printf("关于\n");
    printf("双鸭山大学程序设计大作业————计算器\n");
    printf("开发名单；\n");
    printf("cjl xmh\n");
    printf("fyh hzl\n");
    printf("gqh dsw\n");
    printf("版权所有 © 2024 [fengming]\n本软件由 中山大学 程序设计大作业 计算器小组 开发\n并遵守 Mozilla Public License 2.0 (MPL 2.0) 的条款发布。您可以自由使用、修改和分发本软件，但必须遵守许可证的规定。\n关于MPL 2.0 的详细信息，请参阅https://www.mozilla.org/en-US/MPL/2.0/\n");
    printf("Github仓库地址:https://github.com/fengmingmc/calculator\n");
}

void printHistory() {
    for (int i = 0; i <20; i++) {
        for (int j = 0; historyOutput[i][j] != '\0' ; j++) {
            printf("%c", historyOutput[i][j]);
        }
        printf("\n");
    }
}


void getInput() {
    scanf("%s", input);
}


double calculate(char* input) {
    double number[101];
    char operation[101];
    int nIndex = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        char charNumber[101];
        while ((input[i] >= '0' && input[i] <= '9')|| input[i] == '-') {
            int jIndex = 0;
            charNumber[jIndex] = input[i];
            jIndex++;
            i++;
            while ((input[i] >= '0' && input[i] <= '9') || input[i] == '.') {
                charNumber[jIndex] = input[i];
                jIndex++;
                i++;
            }
            charNumber[jIndex] = '\0';
            char *endptr;
            number[nIndex] = strtod(charNumber,&endptr);
            nIndex++;
        }
    }
    int oIndex = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '+'
            ||input[i] == '-'
            ||input[i] == '*'
            ||input[i] == '/')
        {
            operation[oIndex] = input[i];
            oIndex++;
        }
    }

    // for (int i = 0; operation[i] != '\0'; i++) {
    //     printf("%c\n", operation[i]);
    // }
    // for (int i = 0; number[i] != '\0'; i++) {
    //     printf("%lf\n", number[i]);
    // }

    for (int i = 0; operation[i] != '\0'; i++) {
        if (operation[i] == '*') {
            // printf("%d\n", i);
            double product = number[i] * number[i+1];
            // printf("%lf\n", product);
            number[i + 1] = product ;
            number[i] = 0;
            // printf("%lf\n", number[i]);
            // printf("%lf\n", number[i+1]);
        }
    }
    // for (int i = 0; number[i] != '\0'; i++) {
    //     printf("%lf\n", number[i]);
    // }

    double sum = 0;
    for (int i = 0; i<101; i++) {
        sum += number[i];
    }
    return sum;
}

bool preCalculate(char* input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if ((input[i] >= '0' && input[i] <= '9')
            || input[i] == '+'
            || input[i] == '-'
            || input[i] == '*'
            || input[i] == '/'
            || input[i] == '.') {
        }else {
            printf("于第%d处发现错误，请检查", i+1);
            return false;
        }
    }
    return true;
}



















int main()

{
   while (1) {
       printScreen();
       getCommand();
   }
}

