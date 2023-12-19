#include <stdio.h>
#include <gd.h>
#include <math.h>

void draw_uk_flag(gdImagePtr img);
void fillTriangle(gdImagePtr img, int x1, int y1, int x2, int y2, int x3, int y3, int color);

int main() {
    // 設置國旗的寬和高
    int width = 1200;
    int height = width / 2;

    // 創建圖像
    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    // 繪製英國國旗
    draw_uk_flag(img);

    // 將圖像保存到文件
    FILE *outputFile = fopen("uk_flag.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "打開輸出文件時發生錯誤。\n");
        return 1;
    }
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);

    return 0;
}

void draw_uk_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);

    int red, white, blue;
    red = gdImageColorAllocate(img, 204, 0, 0);    // 紅色
    white = gdImageColorAllocate(img, 255, 255, 255); // 白色
    blue = gdImageColorAllocate(img, 0, 32, 91);     // 藍色

    gdImageFilledRectangle(img, 0, 0, width, height, blue);

    int line_thickness = 100;
    gdImageSetThickness(img, line_thickness);

    // 繪製白色斜線
    gdImageLine(img, 0, height, width, 0, white);
    gdImageLine(img, 0, 0, width, height, white);

    line_thickness = 33;
    gdImageSetThickness(img, line_thickness);

    // 繪製紅色斜線
    gdImageLine(img, 566, 300, 1166, 0, red);
    gdImageLine(img, 1233, height, 633, 300, red);
    gdImageLine(img, 566, 300, -33, 0, red);
    gdImageLine(img, 600, 316.5, 0, 616.5, red);

    line_thickness = 33;
    gdImageSetThickness(img, line_thickness);

    // 繪製斜線
    gdImageLine(img, 0, height, width, 0, red);
    gdImageLine(img, width, 16.5, 600, 316.5, white);
    gdImageLine(img, 0, 583.5, 600, 283.5, white);

    // 繪製白色十字
    int cross_width = width / 32;
    int cross_arm_width = width / 32;
    int center_x = width / 2;
    int center_y = height / 2;

    gdImageFilledRectangle(img, center_x + 2.7 * cross_width, 0, center_x - 2.7 * cross_width, height, white);
    gdImageFilledRectangle(img, 0, center_y + 2.7 * cross_arm_width, width, center_y - 2.7 * cross_arm_width, white);

    // 繪製紅色十字
    gdImageFilledRectangle(img, center_x + 1.5 * cross_width, 0, center_x - 1.5 * cross_width, height, red);
    gdImageFilledRectangle(img, 0, center_y + 1.5 * cross_arm_width, width, center_y - 1.5 * cross_arm_width, red);
}
