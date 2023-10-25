#include <stdio.h>
#include <gd.h>
#include <math.h>

void draw_roc_flag(gdImagePtr img);
void draw_white_sun(gdImagePtr img, int center_x, int center_y, int sun_radius, int white, int red, int blue);

int main() {
    // width 3: height 2
    int width = 1200;
    int height = (int)(width*2.0 / 3.0);

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_roc_flag(img);

    FILE *outputFile = fopen("./roc_flag.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        return 1;
    }
    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);
    return 0;
}

void draw_roc_flag(gdImagePtr img) {
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int red, white, blue;
    int center_x = (int)(width/4);
    int center_y = (int)(height/4);
    int sun_radius = (int)(width/8);

    // Colors for the flag
    red = gdImageColorAllocate(img, 242, 0, 0); // Red color
    white = gdImageColorAllocate(img, 255, 255, 255); // White stripes
    blue = gdImageColorAllocate(img, 0, 41, 204); // Blue

    // 繪製紅色矩形區域
    gdImageFilledRectangle(img, 0, 0, width, height, red);

    // 繪製藍色矩形區域
    gdImageFilledRectangle(img, 0, 0, (int)(width/2.0), (int)(height/2.0), blue);

    // 繪製太陽
    draw_white_sun(img, center_x, center_y, sun_radius, white, red, blue);
}
void draw_white_sun(gdImagePtr img, int center_x, int center_y, int sun_radius, int white, int red, int blue) {
    float angle = 0;
    int numRays = 12; // 光芒的數量

    gdPoint points[3]; // 三個頂點的陣列

    for (int i = 0; i < numRays; i++) {
        angle = i * (2 * M_PI / numRays);
        float x1 = center_x + cos(angle) * sun_radius;
        float y1 = center_y + sin(angle) * sun_radius;

        // 調整兩個底邊頂點的位置
      float x2 = center_x + cos(angle + 0.35) * (sun_radius * 0.5);
      float y2 = center_y + sin(angle + 0.35) * (sun_radius * 0.5);
      float x3 = center_x + cos(angle - 0.35) * (sun_radius * 0.5);
      float y3 = center_y + sin(angle - 0.35) * (sun_radius * 0.5);

        // 設定多邊形的三個頂點
        points[0].x = (int)x1;
        points[0].y = (int)y1;
        points[1].x = (int)x2;
        points[1].y = (int)y2;
        points[2].x = (int)x3;
        points[2].y = (int)y3;

        gdImageFilledPolygon(img, points, 3, white);
    }
  //外圈
  gdImageFilledEllipse(img, center_x, center_y, sun_radius * 1.2, sun_radius * 1.2, blue);

    // 繪製太陽內部
    gdImageFilledEllipse(img, center_x, center_y, sun_radius * 1.1, sun_radius * 1.1, white);
}