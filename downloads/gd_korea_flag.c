#include <stdio.h>
#include <gd.h>
#include <math.h>

#define WHITE 255, 255, 255
#define RED 205, 0, 0
#define BLUE 0, 56, 168

void draw_korean_flag(gdImagePtr img);

int main() {
    int width = 600;  // 國旗寬度
    int height = 400; // 國旗高度

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_korean_flag(img);

    FILE *outputFile = fopen("korean_flag.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }

    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);

    return 0;
}

void draw_korean_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);

    // 繪製白色背景
    gdImageFilledRectangle(img, 0, 0, width, height, gdImageColorAllocate(img, WHITE));

    // 繪製藍色矩形
    gdImageFilledRectangle(img, width / 4, 0, width / 2, height, gdImageColorAllocate(img, BLUE));

    // 繪製紅色矩形
    gdImageFilledRectangle(img, width / 2, 0, 3 * width / 4, height, gdImageColorAllocate(img, RED));
}
