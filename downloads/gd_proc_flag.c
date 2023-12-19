#include <stdio.h>
#include <easyx.h>
#include <math.h>
#include <graphics.h>        // 引用图形库头文件
#include <conio.h>
#include<time.h>
#define PI 3.14
void fivePointedStar(int radius, double startAngle)//  角星的外接圆半径和起始角度作为参数，由调用者决定
{
    double delta = 2 * PI / 5;      //  增量为一个圆的5分之一
    POINT points[5];                //  长度为5的POINT数组，用于存储5个点
    for (int i = 0; i < 5; i++)
    {
        points[i].x = cos(startAngle + i * delta * 2) * radius;   //  计算x坐标 
        points[i].y = sin(startAngle + i * delta * 2) * radius;   //  计算y坐标
    }
    solidpolygon(points, 5);
}
int main(void)
{
    int width = 900;
    int height = width / 3 * 2;    //  高度为宽度的2/3
    int grid = width / 3 / 15;    //  网格宽度
    initgraph(800, 420);    //  创建窗体设置背景色
    setbkcolor(BLACK);
    cleardevice();
setcolor(YELLOW);  //  文本颜色
setbkcolor(BLACK);  //  文本背景色
settextstyle(100,0,"楷体");  //  文本高度和字体
outtextxy(600, 10, "喜");  //  文本位置和内容
outtextxy(600, 110, "迎");  //  文本位置和内容
outtextxy(600, 210, "国");  //  文本位置和内容
outtextxy(600, 310, "庆");  //  文本位置和内容
outtextxy(700, 10, "举");  //  文本位置和内容
outtextxy(700, 110, "国");  //  文本位置和内容
outtextxy(700, 210, "欢");  //  文本位置和内容
outtextxy(700, 310, "庆");  //  文本位置和内容
setcolor(YELLOW);
setbkcolor(BLACK);
settextstyle(20,0,"楷体");
outtextxy(650, 400, "Dotcpp.com");
    setfillcolor(RED);
solidrectangle(10,10,600,400);
    setaspectratio(1, -1);    //  翻转坐标轴，设置填充颜色为黄色
    setfillcolor(YELLOW);
    setpolyfillmode(WINDING);
    setorigin(grid * 5, grid * 5);    //  大五角星
    fivePointedStar(grid * 3, PI / 2);
    setorigin(grid * 10, grid * 2);    //  小五角星1
    double startAngle = atan(3.0 / 5.0) + PI;
    fivePointedStar(grid, startAngle);
    setorigin(grid * 12, grid * 4);    //  小五角星2
    startAngle = atan(1.0 / 7.0) + PI;
    fivePointedStar(grid, startAngle);
    setorigin(grid * 12, grid * 7);    //  小五角星3
    startAngle = -atan(2.0 / 7.0) + PI;
    fivePointedStar(grid, startAngle);
    setorigin(grid * 10, grid * 9);    //  小五角星4
    startAngle = -atan(4.0 / 5.0) + PI;
    fivePointedStar(grid, startAngle);
    getchar();
    closegraph();
    return 0;
}
