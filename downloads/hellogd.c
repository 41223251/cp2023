#include <stdio.h>
#include <gd.h>
#include <math.h>

int main() {
    int width = 800;
    int height = 600;

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    FILE *outputFile = fopen("hellogd.png", "wb");
    if (outputFile == NULL) {

fprintf(stderr, "Error opening the output file.\n");

return 1;
    }

    int red = gdImageColorAllocate(img, 255, 0, 0);
    int blue = gdImageColorAllocate(img, 0, 0, 255);
    int black = gdImageColorAllocate(img, 0, 0, 0);
    int white = gdImageColorAllocate(img, 255, 255, 255);
    // 長方形塗色
    gdImageFilledRectangle(img, 0, 0, width, height, white);
    gdImageFilledRectangle(img, 0, 0, (int)width/4, (int)height/4, blue);
    // 橢圓形塗色
    gdImageFilledEllipse(img, (int)width*3/4, (int)height/4, (int)width/4, (int)width/4, red);
    // 橢圓形畫線
    gdImageEllipse(img, (int)width*3/4, (int)height*3/4, (int)width/4, (int)width/4, red);
    // 畫直線
    gdImageLine(img, (int)width/2, (int)height/2, (int)width/2, (int)height/2 + 100, blue);

    // 多邊形畫線
    gdPoint points[4];
    points[0].x = (int)width/4;
    points[0].y = (int)height*3/4;
    points[1].x = points[0].x + 100;
    points[1].y = points[0].y;
    points[2].x = points[1].x;
    points[2].y = points[1].y + 100;
    points[3].x = points[2].x - 100;
    points[3].y = points[2].y;
    gdImagePolygon(img, points, 4, black);

    // 多邊形塗色
    gdPoint points2[4];
    points2[0].x = (int)width/3;
    points2[0].y = (int)height/2;
    points2[1].x = points2[0].x + 100;
    points2[1].y = points2[0].y;
    points2[2].x = points2[1].x;
    points2[2].y = points2[1].y + 100;
    points2[3].x = points2[2].x - 150;
    points2[3].y = points2[2].y;
    gdImageFilledPolygon(img, points2, 4, red);

    gdImagePngEx(img, outputFile, 9);
    fclose(outputFile);
    gdImageDestroy(img);
    return 0;
}