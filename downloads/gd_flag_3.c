#include <stdio.h>
#include <gd.h>
#include <math.h>

void draw_roc_flag(gdImagePtr img);
int findIntersection(gdImagePtr img, int x1, int y1, int x2, int y2, int cx, int cy, int r, int *inter_x, int *inter_y);

int main() {
    // width 3: height 2
    int width = 1200;
    // 國旗長寬比為 3:2
    int height = (int)(width * 2.0 / 3.0);

    gdImagePtr img = gdImageCreateTrueColor(width, height);
    gdImageAlphaBlending(img, 0);

    draw_roc_flag(img);

    FILE *outputFile = fopen("roc_flag_in_gd.png", "wb");
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
    // ... (同樣的畫圖程式碼)

    // 連接四個點
    int points[8];
    points[0] = 429;
    points[1] = 125;
    points[2] = 279;
    points[3] = 165;
    points[4] = 170;
    points[5] = 274;
    points[6] = 170;
    points[7] = 274;

    // 使用白色線條連接四個點
    gdImageLine(img, points[0], points[1], points[2], points[3], white);
    gdImageLine(img, points[2], points[3], points[4], points[5], white);
    gdImageLine(img, points[4], points[5], points[6], points[7], white);
    gdImageLine(img, points[6], points[7], points[0], points[1], white);

    // 找出白線與圓形相交的點
    int inter_x, inter_y;
    findIntersection(img, points[0], points[1], points[2], points[3], width / 4, height / 4, width / 8, &inter_x, &inter_y);
    printf("Intersection Point 1: (%d, %d)\n", inter_x, inter_y);

    findIntersection(img, points[2], points[3], points[4], points[5], width / 4, height / 4, width / 8, &inter_x, &inter_y);
    printf("Intersection Point 2: (%d, %d)\n", inter_x, inter_y);

    findIntersection(img, points[4], points[5], points[6], points[7], width / 4, height / 4, width / 8, &inter_x, &inter_y);
    printf("Intersection Point 3: (%d, %d)\n", inter_x, inter_y);

    findIntersection(img, points[6], points[7], points[0], points[1], width / 4, height / 4, width / 8, &inter_x, &inter_y);
    printf("Intersection Point 4: (%d, %d)\n", inter_x, inter_y);
}

int findIntersection(gdImagePtr img, int x1, int y1, int x2, int y2, int cx, int cy, int r, int *inter_x, int *inter_y) {
    // 將直線轉換成一般形式 Ax + By = C
    double A = y2 - y1;
    double B = x1 - x2;
    double C = A * x1 + B * y1;

    // 計算圓心到直線的距離
    double distance = fabs(A * cx + B * cy - C) / sqrt(A * A + B * B);

    // 如果距離小於半徑，表示相交
    if (distance <= r) {
        // 計算交點座標
        double d = A * A + B * B;
        *inter_x = (int)((B * (B * cx - A * cy) - A * C) / d);
        *inter_y = (int)((A * (-B * cx + A * cy) - B * C) / d);

        // 補償畫布的偏移
        *inter_x += gdImageSX(img) / 2;
        *inter_y += gdImageSY(img) / 2;

        return 1;  // 表示有相交點
    }

    return 0;  // 表示沒有相交點
}
