#include <stdio.h>
#include <gd.h>
#include <math.h>

#define WHITE 255, 255, 255
#define RED 255, 0, 0

void draw_japan_flag(gdImagePtr img);

int main() {
    int width = 600;  // 國旗寬度
    int height = 400; // 國旗高度

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_japan_flag(img);

    FILE *outputFile = fopen("./../images/japan_flag.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }

    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);

    return 0;
}

void draw_japan_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);

    // Draw white background
    gdImageFilledRectangle(img, 0, 0, width, height, gdImageColorAllocate(img, WHITE));

    // Draw red circle
    int circle_radius = height / 4;
    int circle_x = width / 2;
    int circle_y = height / 2;

    gdImageFilledEllipse(img, circle_x, circle_y, circle_radius * 2, circle_radius * 2, gdImageColorAllocate(img, RED));
}
