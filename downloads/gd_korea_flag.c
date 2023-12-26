#include <gd.h>
#include <math.h>

#define WHITE 255, 255, 255
#define RED 255, 0, 0
#define BLUE 0, 0, 255

void draw_japanese_flag(gdImagePtr img);

int main() {
    int width = 600;  // 圖片寬度
    int height = 400; // 圖片高度

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_japanese_flag(img);

    FILE *outputFile = fopen("japanese_flag.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }

    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);

    return 0;
}

void draw_japanese_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);

    // 繪製白色背景
    gdImageFilledRectangle(img, 0, 0, width, height, gdImageColorAllocate(img, WHITE));

    // 計算圓的半徑和中心座標
    int radius = height / 4;
    int center_x = width / 2;
    int center_y = height / 2;

    // 繪製上半圓（紅色）
    gdImageFilledArc(img, center_x, center_y, radius * 2, radius * 2, 180, 360, gdImageColorAllocate(img, RED), gdArc);

    // 繪製下半圓（藍色）
    gdImageFilledArc(img, center_x, center_y, radius * 2, radius * 2, 0, 180, gdImageColorAllocate(img, BLUE), gdArc);
}

