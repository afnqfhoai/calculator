#include <stdio.h>
#include <string.h>

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
    printf("请输入所需功能：");
}


void getCommand() {
    void printHelp();
    void printAbout();
    void printHistory();
    void getInput();
    getInput();
    if (strcmp(input, help) == 0) {
        printHelp();
    }
    if (strcmp(input, about) == 0) {
        printAbout();
    }
    if (strcmp(input, history) == 0) {
        printHistory();
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






















int main()

{
   while (1) {
       printScreen();
       getCommand();
       if (strcmp(input,quit) == 0) {
           return 0;
       }
   }
}

