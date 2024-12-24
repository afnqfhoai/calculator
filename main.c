#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void getCommand();
void printScreen();
char GetChar();
char c[101] = "change";
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
    printf("change 单位换算\n");
    printf("help 获取帮助\n");
    printf("about 关于开发\n");
    printf("history 历史计算数据\n");
    printf("quit 退出\n");
    printf("请输入式子或所需功能：\n");
}


char GetChar() // 输入一个字符（非空格、非回车、ASCII码大于零）
{
    char c;
    do
    {
        c = getchar();
    } while (c == '\n' || c == ' ' || c < 0);
    return c;
}

void getCommand() {
    void change();
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
    else if (strcmp(input, c) == 0){
        change();
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

void change(){
    void temperature();
    void energy();
    void velocity();
    void angle();
    void change_printScreen();
    char input;
    while(1){
    input = GetChar();  // 用于输入一个字符（非空格、非回车、ASCII码大于零）
    change_printScreen();
    if(toupper(input)=='Q')
        break;
    switch (toupper(input))
    {
    case 'A':
        angle();
        break;
    case 'B':
        temperature();
        break;
    case 'C':
        energy();
        break;
    case 'D':
        velocity();
        break;

    default:
        printf("输入错误\n\n"); // 如果输入的是其它字符，则输入错误
    }
    }

}

void change_printScreen(){
    printf("************************\n");
    printf("*********单位转换********\n");
    printf("******A:角度 B:温度******\n");
    printf("******C:能量 D:速度******\n");
    printf("**********Q:退出*********\n");
    printf("请选择需要转换的对象:\n");
}

// 角度单位转换函数
void angle()
{
    float value, result;
    char unit;
    printf("请输入角度值和当前单位（d 表示度，r 表示弧度）：\n");
    scanf("%f %c", &value, &unit);
    switch (toupper(unit))
    {
    case 'D':
        // 度转弧度
        result = value * 3.14159265358979323846 / 180.0;
        printf("%.2f deg = %.2f rad\n", value, result);
        break;
    case 'R':
        // 弧度转度
        result = value * 180.0 / 3.14159265358979323846;
        printf("%.2f rad = %.2f deg\n", value, result);
        break;
    default:
        printf("输入的单位错误，请输入 d 或 r。\n");
    }
}

// 能量单位转换函数
void energy()
{
    float value, result;
    char unit;
    printf("请输入能量值和当前单位（j 表示焦耳，cal 表示卡路里）：\n");
    scanf("%f %c", &value, &unit);
    switch (toupper(unit))
    {
    case 'J':
        // 焦耳转卡路里
        result = value / 4.184;
        printf("%.2f J = %.2f cal\n", value, result);
        break;
    case 'CAL':
        // 卡路里转焦耳
        result = value * 4.184;
        printf("%.2f cal = %.2f J\n", value, result);
        break;
    default:
        printf("输入的单位错误，请输入 J 或 cal。\n");
    }
}

// 速度单位转换函数
void velocity()
{
    float value, result;
    char unit;
    printf("请输入速度值和当前单位（m 表示米每秒，k 表示千米每小时）：\n");
    scanf("%f %c", &value, &unit);
    switch (toupper(unit))
    {
    case 'M':
        // 米每秒转千米每小时
        result = value * 3.6;
        printf("%.2f m/s = %.2f km/h\n", value, result);
        break;
    case 'K':
        // 千米每小时转米每秒
        result = value / 3.6;
        printf("%.2f km/h = %.2f m/s\n", value, result);
        break;
    default:
        printf("输入的单位错误，请输入 m 或 k。\n");
    }
}

// 温度单位转换函数
void temperature()
{
    float value, result;
    char unit;
    printf("请输入温度值和当前单位（C 表示摄氏度，F 表示华氏度，K 表示开尔文）：\n");
    scanf("%f %c", &value, &unit);
    switch (toupper(unit))
    {
    case 'C':
        // 摄氏度转华氏度
        result = value * 9.0 / 5.0 + 32.0;
        printf("%.2f C = %.2f F\n", value, result);
        // 摄氏度转开尔文
        result = value + 273.15;
        printf("%.2f C = %.2f K\n", value, result);
        break;
    case 'F':
        // 华氏度转摄氏度
        result = (value - 32.0) * 5.0 / 9.0;
        printf("%.2f F = %.2f C\n", value, result);
        // 华氏度转开尔文
        result = (value + 459.67) * 5.0 / 9.0;
        printf("%.2f F = %.2f K\n", value, result);
        break;
    case 'K':
        // 开尔文转摄氏度
        result = value - 273.15;
        printf("%.2f K = %.2f C\n", value, result);
        // 开尔文转华氏度
        result = value * 9.0 / 5.0 - 459.67;
        printf("%.2f K = %.2f F\n", value, result);
        break;
    default:
        printf("输入的单位错误，请输入 C、F 或 K。\n");
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

