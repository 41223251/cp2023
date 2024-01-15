#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* 除两个浮点数 */
int main()
{
    float this_is_a_number1, this_is_a_number2, total;

    // 提示用户输入第一个数
    printf("请输入一个数字：\n");
    scanf("%f", &this_is_a_number1); // 读取第一个数

    // 打印用户输入的第一个数
    printf("你输入了 %f\n", this_is_a_number1);

    // 提示用户输入第二个数
    printf("请输入另一个数字：\n ");
    scanf("%f", &this_is_a_number2); // 读取第二个数

    // 打印用户输入的第二个数
    printf("你输入了 %f\n", this_is_a_number2);

    // 计算两个数的商
    total = this_is_a_number1 / this_is_a_number2;

    // 打印商
    printf("商为 %f\n", total);

    return 0;
}
