#include <gd.h>
#include <stdio.h>
#include <math.h>

int main() {
    gdImagePtr im;
    FILE *output;
    int white, red, blue, black;

    im = gdImageCreateTrueColor(600, 400);
    white = gdImageColorAllocate(im, 255, 255, 255);
    red = gdImageColorAllocate(im, 225, 0, 0);
    blue = gdImageColorAllocate(im, 0, 0, 225);
    black = gdImageColorAllocate(im, 0, 0, 0);

    // 填充白色背景
    gdImageFilledRectangle(im, 0, 0, 599, 399, white);

    // 在中間添加紅藍各一半的圓，將紅色移到上方，藍色移到下方
    int centerX = 300;
    int centerY = 200;
    int radius = 200;

    gdImageFilledArc(im, centerX, centerY, radius, radius, 0, 180, blue, gdPie);
    gdImageFilledArc(im, centerX, centerY - 1, radius, radius, 180, 360, red, gdPie);

    // 在中間添加向右偏移49的直徑為100的藍色圓
    int blueCircleRadius = 50; // 半徑為50
    int offsetX = 49;
    gdImageFilledEllipse(im, centerX + offsetX, centerY, blueCircleRadius * 2, blueCircleRadius * 2, blue);

    // 在中間添加向左偏移50的直徑為100的紅色圓
    int redCircleRadius = 50; // 半徑為50
    gdImageFilledEllipse(im, centerX - 49, centerY, redCircleRadius * 2, redCircleRadius * 2, red);

    // 將中間的圖形順時針旋轉104度
    double angle = 104.0;
    gdImagePtr rotated_im = gdImageCreateTrueColor(600, 400);
    gdImageFilledRectangle(rotated_im, 0, 0, 599, 399, white);

    // 複製原始圖像
    gdImageCopy(rotated_im, im, 0, 0, 0, 0, 600, 400);

    // 逆時針旋轉的角度
    double rotationAngle = 25.0; 

    // 繪製斜直的長方形
    int rectWidth = 15;   // 長方形寬度
    int rectHeight = 120;  // 長方形高度
    int rectSpacing = 10;  // 長方形間隔

    // 計算三個長方形的左上角座標
    int rect1X = 139 - rectWidth - rectSpacing;  // 第一個長方形
    int rect1Y = 206 - rectHeight / 2;
    int rect2X = rect1X - rectWidth - rectSpacing;  // 第二個長方形
    int rect2Y = rect1Y;
    int rect3X = rect2X - rectWidth - rectSpacing;  // 第三個長方形
    int rect3Y = rect1Y;

    gdPoint points1[4];
    points1[0].x = (int)(rect1X - centerX) * cos(rotationAngle * M_PI / 180) - (rect1Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
    points1[0].y = (int)(rect1X - centerX) * sin(rotationAngle * M_PI / 180) + (rect1Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
    points1[1].x = (int)((rect1X + rectWidth) - centerX) * cos(rotationAngle * M_PI / 180) - (rect1Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
    points1[1].y = (int)((rect1X + rectWidth) - centerX) * sin(rotationAngle * M_PI / 180) + (rect1Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
    points1[2].x = (int)((rect1X + rectWidth) - centerX) * cos(rotationAngle * M_PI / 180) - ((rect1Y + rectHeight) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
    points1[2].y = (int)((rect1X + rectWidth) - centerX) * sin(rotationAngle * M_PI / 180) + ((rect1Y + rectHeight) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
    points1[3].x = (int)(rect1X - centerX) * cos(rotationAngle * M_PI / 180) - ((rect1Y + rectHeight) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
    points1[3].y = (int)(rect1X - centerX) * sin(rotationAngle * M_PI / 180) + ((rect1Y + rectHeight) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;

    gdPoint points2[4];
    points2[0].x = (int)(rect2X - centerX) * cos(rotationAngle * M_PI / 180) - (rect2Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
    points2[0].y = (int)(rect2X - centerX) * sin(rotationAngle * M_PI / 180) + (rect2Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
    points2[1].x = (int)((rect2X + rectWidth) - centerX) * cos(rotationAngle * M_PI / 180) - (rect2Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
    points2[1].y = (int)((rect2X + rectWidth) - centerX) * sin(rotationAngle * M_PI / 180) + (rect2Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
    points2[2].x = (int)((rect2X + rectWidth) - centerX) * cos(rotationAngle * M_PI / 180) - ((rect2Y + rectHeight) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
    points2[2].y = (int)((rect2X + rectWidth) - centerX) * sin(rotationAngle * M_PI / 180) + ((rect2Y + rectHeight) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
    points2[3].x = (int)(rect2X - centerX) * cos(rotationAngle * M_PI / 180) - ((rect2Y + rectHeight) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
    points2[3].y = (int)(rect2X - centerX) * sin(rotationAngle * M_PI / 180) + ((rect2Y + rectHeight) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;

    gdPoint points3[4];
    points3[0].x = (int)(rect3X - centerX) * cos(rotationAngle * M_PI / 180) - (rect3Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
    points3[0].y = (int)(rect3X - centerX) * sin(rotationAngle * M_PI / 180) + (rect3Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
    points3[1].x = (int)((rect3X + rectWidth) - centerX) * cos(rotationAngle * M_PI / 180) - (rect3Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
    points3[1].y = (int)((rect3X + rectWidth) - centerX) * sin(rotationAngle * M_PI / 180) + (rect3Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
    points3[2].x = (int)((rect3X + rectWidth) - centerX) * cos(rotationAngle * M_PI / 180) - ((rect3Y + rectHeight) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
    points3[2].y = (int)((rect3X + rectWidth) - centerX) * sin(rotationAngle * M_PI / 180) + ((rect3Y + rectHeight) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
    points3[3].x = (int)(rect3X - centerX) * cos(rotationAngle * M_PI / 180) - ((rect3Y + rectHeight) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
    points3[3].y = (int)(rect3X - centerX) * sin(rotationAngle * M_PI / 180) + ((rect3Y + rectHeight) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;

    gdImageFilledPolygon(rotated_im, points1, 4, black);
    gdImageFilledPolygon(rotated_im, points2, 4, black);
    gdImageFilledPolygon(rotated_im, points3, 4, black);


  {// 添加新的黑色斜形
  gdPoint rect4Points[4];
  int rect4X = 70;  // 第四個長方形
  int rect4Y = 185;
  rect4Points[0].x = (int)(rect4X - centerX) * cos(rotationAngle * M_PI / 180) + (rect4Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4Points[0].y = (int)(rect4X - centerX) * (-sin(rotationAngle * M_PI / 180)) + (rect4Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  int rect4Width = rectWidth;  // 假設 rectWidth 已經定義
  int rect4Height = rectHeight;  // 假設 rectHeight 已經定義
  rect4Points[1].x = (int)((rect4X + rect4Width) - centerX) * cos(rotationAngle * M_PI / 180) + (rect4Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4Points[1].y = (int)((rect4X + rect4Width) - centerX) * (-sin(rotationAngle * M_PI / 180)) + (rect4Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect4Points[2].x = (int)((rect4X + rect4Width) - centerX) * cos(rotationAngle * M_PI / 180) + ((rect4Y + rect4Height) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4Points[2].y = (int)((rect4X + rect4Width) - centerX) * (-sin(rotationAngle * M_PI / 180)) + ((rect4Y + rect4Height) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect4Points[3].x = (int)(rect4X - centerX) * cos(rotationAngle * M_PI / 180) + ((rect4Y + rect4Height) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4Points[3].y = (int)(rect4X - centerX) * (-sin(rotationAngle * M_PI / 180)) + ((rect4Y + rect4Height) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;

  gdImageFilledPolygon(rotated_im, rect4Points, 4, black);

  // 修改第五個斜形
  gdPoint rect5Points[4];
  int rect5X = rect4X + rect4Width + rectSpacing;  // 第五個長方形
  int rect5Y = rect4Y;
  int middleRectWidth = 15;    // 中間長方形寬度
  int middleRectHeight = 55;   // 中間長方形高度
  int middleRectSpacing = 10;  // 中間長方形上下間隔
  rect5Points[0].x = (int)(rect5X - centerX) * cos(rotationAngle * M_PI / 180) + (rect5Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect5Points[0].y = (int)(rect5X - centerX) * (-sin(rotationAngle * M_PI / 180)) + (rect5Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect5Points[1].x = (int)((rect5X + middleRectWidth) - centerX) * cos(rotationAngle * M_PI / 180) + (rect5Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect5Points[1].y = (int)((rect5X + middleRectWidth) - centerX) * (-sin(rotationAngle * M_PI / 180)) + (rect5Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect5Points[2].x = (int)((rect5X + middleRectWidth) - centerX) * cos(rotationAngle * M_PI / 180) + ((rect5Y + middleRectHeight) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect5Points[2].y = (int)((rect5X + middleRectWidth) - centerX) * (-sin(rotationAngle * M_PI / 180)) + ((rect5Y + middleRectHeight) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect5Points[3].x = (int)(rect5X - centerX) * cos(rotationAngle * M_PI / 180) + ((rect5Y + middleRectHeight) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect5Points[3].y = (int)(rect5X - centerX) * (-sin(rotationAngle * M_PI / 180)) + ((rect5Y + middleRectHeight) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;

  gdImageFilledPolygon(rotated_im, rect5Points, 4, black);

  // 添加位於第五個斜形下方的新的黑色斜形
  gdPoint rectBelow5Points[4];
  int rectBelow5X = rect5X;
  int rectBelow5Y = rect5Y + middleRectHeight + middleRectSpacing;
  rectBelow5Points[0].x = (int)(rectBelow5X - centerX) * cos(rotationAngle * M_PI / 180) + (rectBelow5Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rectBelow5Points[0].y = (int)(rectBelow5X - centerX) * (-sin(rotationAngle * M_PI / 180)) + (rectBelow5Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rectBelow5Points[1].x = (int)((rectBelow5X + middleRectWidth) - centerX) * cos(rotationAngle * M_PI / 180) + (rectBelow5Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rectBelow5Points[1].y = (int)((rectBelow5X + middleRectWidth) - centerX) * (-sin(rotationAngle * M_PI / 180)) + (rectBelow5Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rectBelow5Points[2].x = (int)((rectBelow5X + middleRectWidth) - centerX) * cos(rotationAngle * M_PI / 180) + ((rectBelow5Y + middleRectHeight) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rectBelow5Points[2].y = (int)((rectBelow5X + middleRectWidth) - centerX) * (-sin(rotationAngle * M_PI / 180)) + ((rectBelow5Y + middleRectHeight) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rectBelow5Points[3].x = (int)(rectBelow5X - centerX) * cos(rotationAngle * M_PI / 180) + ((rectBelow5Y + middleRectHeight) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rectBelow5Points[3].y = (int)(rectBelow5X - centerX) * (-sin(rotationAngle * M_PI / 180)) + ((rectBelow5Y + middleRectHeight) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;

  gdImageFilledPolygon(rotated_im, rectBelow5Points, 4, black);

  // 添加新的黑色斜形
  gdPoint rect6Points[4];
  int rect6X = rect5X + middleRectWidth + rectSpacing;  // 第六個長方形
  int rect6Y = rect4Y;
  rect6Points[0].x = (int)(rect6X - centerX) * cos(rotationAngle * M_PI / 180) + (rect6Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6Points[0].y = (int)(rect6X - centerX) * (-sin(rotationAngle * M_PI / 180)) + (rect6Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  int rect6Width = rectWidth;  // 假設 rectWidth 已經定義
  int rect6Height = rectHeight;  // 假設 rectHeight 已經定義
  rect6Points[1].x = (int)((rect6X + rect6Width) - centerX) * cos(rotationAngle * M_PI / 180) + (rect6Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6Points[1].y = (int)((rect6X + rect6Width) - centerX) * (-sin(rotationAngle * M_PI / 180)) + (rect6Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect6Points[2].x = (int)((rect6X + rect6Width) - centerX) * cos(rotationAngle * M_PI / 180) + ((rect6Y + rect6Height) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6Points[2].y = (int)((rect6X + rect6Width) - centerX) * (-sin(rotationAngle * M_PI / 180)) + ((rect6Y + rect6Height) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect6Points[3].x = (int)(rect6X - centerX) * cos(rotationAngle * M_PI / 180) + ((rect6Y + rect6Height) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6Points[3].y = (int)(rect6X - centerX) * (-sin(rotationAngle * M_PI / 180)) + ((rect6Y + rect6Height) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;

  gdImageFilledPolygon(rotated_im, rect6Points, 4, black);}

  {// 添加新的黑色斜形（第四個，上半部分）
  gdPoint rect4aPoints[4];
  int rect4aX = 460;  // 第四個長方形（上半部分）
  int rect4aY = 139;
  rect4aPoints[0].x = (int)(rect4aX - centerX) * cos(rotationAngle * M_PI / 180) + (rect4aY - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4aPoints[0].y = (int)(rect4aX - centerX) * (-sin(rotationAngle * M_PI / 180)) + (rect4aY - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect4aPoints[1].x = (int)((rect4aX + 15) - centerX) * cos(rotationAngle * M_PI / 180) + (rect4aY - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4aPoints[1].y = (int)((rect4aX + 15) - centerX) * (-sin(rotationAngle * M_PI / 180)) + (rect4aY - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect4aPoints[2].x = (int)((rect4aX + 15) - centerX) * cos(rotationAngle * M_PI / 180) + ((rect4aY + 55) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4aPoints[2].y = (int)((rect4aX + 15) - centerX) * (-sin(rotationAngle * M_PI / 180)) + ((rect4aY + 55) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect4aPoints[3].x = (int)(rect4aX - centerX) * cos(rotationAngle * M_PI / 180) + ((rect4aY + 55) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4aPoints[3].y = (int)(rect4aX - centerX) * (-sin(rotationAngle * M_PI / 180)) + ((rect4aY + 55) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;

  gdImageFilledPolygon(rotated_im, rect4aPoints, 4, black);

  // 添加新的黑色斜形（第四個，下半部分）
  gdPoint rect4bPoints[4];
  int rect4bX = 460;  // 第四個長方形（下半部分）
  int rect4bY = 139 + 55 + 10;  // 上半部分的 Y 座標 + 上半部分的高度 + 間隔
  rect4bPoints[0].x = (int)(rect4bX - centerX) * cos(rotationAngle * M_PI / 180) + (rect4bY - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4bPoints[0].y = (int)(rect4bX - centerX) * (-sin(rotationAngle * M_PI / 180)) + (rect4bY - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect4bPoints[1].x = (int)((rect4bX + 15) - centerX) * cos(rotationAngle * M_PI / 180) + (rect4bY - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4bPoints[1].y = (int)((rect4bX + 15) - centerX) * (-sin(rotationAngle * M_PI / 180)) + (rect4bY - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect4bPoints[2].x = (int)((rect4bX + 15) - centerX) * cos(rotationAngle * M_PI / 180) + ((rect4bY + 55) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4bPoints[2].y = (int)((rect4bX + 15) - centerX) * (-sin(rotationAngle * M_PI / 180)) + ((rect4bY + 55) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect4bPoints[3].x = (int)(rect4bX - centerX) * cos(rotationAngle * M_PI / 180) + ((rect4bY + 55) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4bPoints[3].y = (int)(rect4bX - centerX) * (-sin(rotationAngle * M_PI / 180)) + ((rect4bY + 55) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;

  gdImageFilledPolygon(rotated_im, rect4bPoints, 4, black);

  // 修改第五個斜形（長度為 120）
  gdPoint rect5Points[4];
  int rect5X = rect4aX + 15 + rectSpacing;  // 第五個長方形
  int rect5Y = rect4aY;
  rect5Points[0].x = (int)(rect5X - centerX) * cos(rotationAngle * M_PI / 180) + (rect5Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect5Points[0].y = (int)(rect5X - centerX) * (-sin(rotationAngle * M_PI / 180)) + (rect5Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect5Points[1].x = (int)((rect5X + 15) - centerX) * cos(rotationAngle * M_PI / 180) + (rect5Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect5Points[1].y = (int)((rect5X + 15) - centerX) * (-sin(rotationAngle * M_PI / 180)) + (rect5Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect5Points[2].x = (int)((rect5X + 15) - centerX) * cos(rotationAngle * M_PI / 180) + ((rect5Y + 120) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect5Points[2].y = (int)((rect5X + 15) - centerX) * (-sin(rotationAngle * M_PI / 180)) + ((rect5Y + 120) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect5Points[3].x = (int)(rect5X - centerX) * cos(rotationAngle * M_PI / 180) + ((rect5Y + 120) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect5Points[3].y = (int)(rect5X - centerX) * (-sin(rotationAngle * M_PI / 180)) + ((rect5Y + 120) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;

  gdImageFilledPolygon(rotated_im, rect5Points, 4, black);

  // 添加新的黑色斜形（第六個，上半部分）
  gdPoint rect6aPoints[4];
  int rect6aX = rect5X + 15 + rectSpacing;  // 第六個長方形（上半部分）
  int rect6aY = rect5Y;
  rect6aPoints[0].x = (int)(rect6aX - centerX) * cos(rotationAngle * M_PI / 180) + (rect6aY - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6aPoints[0].y = (int)(rect6aX - centerX) * (-sin(rotationAngle * M_PI / 180)) + (rect6aY - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect6aPoints[1].x = (int)((rect6aX + 15) - centerX) * cos(rotationAngle * M_PI / 180) + (rect6aY - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6aPoints[1].y = (int)((rect6aX + 15) - centerX) * (-sin(rotationAngle * M_PI / 180)) + (rect6aY - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect6aPoints[2].x = (int)((rect6aX + 15) - centerX) * cos(rotationAngle * M_PI / 180) + ((rect6aY + 55) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6aPoints[2].y = (int)((rect6aX + 15) - centerX) * (-sin(rotationAngle * M_PI / 180)) + ((rect6aY + 55) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect6aPoints[3].x = (int)(rect6aX - centerX) * cos(rotationAngle * M_PI / 180) + ((rect6aY + 55) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6aPoints[3].y = (int)(rect6aX - centerX) * (-sin(rotationAngle * M_PI / 180)) + ((rect6aY + 55) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;

  gdImageFilledPolygon(rotated_im, rect6aPoints, 4, black);

  // 添加新的黑色斜形（第六個，下半部分）
  gdPoint rect6bPoints[4];
  int rect6bX = rect5X + 15 + rectSpacing;  // 第六個長方形（下半部分）
  int rect6bY = rect5Y + 55 + 10;  // 上半部分的 Y 座標 + 上半部分的高度 + 間隔
  rect6bPoints[0].x = (int)(rect6bX - centerX) * cos(rotationAngle * M_PI / 180) + (rect6bY - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6bPoints[0].y = (int)(rect6bX - centerX) * (-sin(rotationAngle * M_PI / 180)) + (rect6bY - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect6bPoints[1].x = (int)((rect6bX + 15) - centerX) * cos(rotationAngle * M_PI / 180) + (rect6bY - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6bPoints[1].y = (int)((rect6bX + 15) - centerX) * (-sin(rotationAngle * M_PI / 180)) + (rect6bY - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect6bPoints[2].x = (int)((rect6bX + 15) - centerX) * cos(rotationAngle * M_PI / 180) + ((rect6bY + 55) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6bPoints[2].y = (int)((rect6bX + 15) - centerX) * (-sin(rotationAngle * M_PI / 180)) + ((rect6bY + 55) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect6bPoints[3].x = (int)(rect6bX - centerX) * cos(rotationAngle * M_PI / 180) + ((rect6bY + 55) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6bPoints[3].y = (int)(rect6bX - centerX) * (-sin(rotationAngle * M_PI / 180)) + ((rect6bY + 55) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;

  gdImageFilledPolygon(rotated_im, rect6bPoints, 4, black);}


  // 添加新的黑色斜形（第四個，上半部分）
  gdPoint rect4aPoints[4];
  int rect4aX = 460;  // 第四個長方形（上半部分）
  int rect4aY =185;
  rect4aPoints[0].x = (int)(rect4aX - centerX) * cos(rotationAngle * M_PI / 180) - (rect4aY - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4aPoints[0].y = (int)(rect4aX - centerX) * sin(rotationAngle * M_PI / 180) + (rect4aY - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect4aPoints[1].x = (int)((rect4aX + 15) - centerX) * cos(rotationAngle * M_PI / 180) - (rect4aY - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4aPoints[1].y = (int)((rect4aX + 15) - centerX) * sin(rotationAngle * M_PI / 180) + (rect4aY - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect4aPoints[2].x = (int)((rect4aX + 15) - centerX) * cos(rotationAngle * M_PI / 180) - ((rect4aY + 55) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4aPoints[2].y = (int)((rect4aX + 15) - centerX) * sin(rotationAngle * M_PI / 180) + ((rect4aY + 55) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect4aPoints[3].x = (int)(rect4aX - centerX) * cos(rotationAngle * M_PI / 180) - ((rect4aY + 55) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4aPoints[3].y = (int)(rect4aX - centerX) * sin(rotationAngle * M_PI / 180) + ((rect4aY + 55) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;

  gdImageFilledPolygon(rotated_im, rect4aPoints, 4, black);

  // 添加新的黑色斜形（第四個，下半部分）
  gdPoint rect4bPoints[4];
  int rect4bX = rect4aX;  // 使用与上半部分相同的X坐标
  int rect4bY = rect4aY + 55 + 10;  // 上半部分的 Y 座標 + 上半部分的高度 + 間隔
  rect4bPoints[0].x = (int)(rect4bX - centerX) * cos(rotationAngle * M_PI / 180) - (rect4bY - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4bPoints[0].y = (int)(rect4bX - centerX) * sin(rotationAngle * M_PI / 180) + (rect4bY - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect4bPoints[1].x = (int)((rect4bX + 15) - centerX) * cos(rotationAngle * M_PI / 180) - (rect4bY - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4bPoints[1].y = (int)((rect4bX + 15) - centerX) * sin(rotationAngle * M_PI / 180) + (rect4bY - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect4bPoints[2].x = (int)((rect4bX + 15) - centerX) * cos(rotationAngle * M_PI / 180) - ((rect4bY + 55) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4bPoints[2].y = (int)((rect4bX + 15) - centerX) * sin(rotationAngle * M_PI / 180) + ((rect4bY + 55) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect4bPoints[3].x = (int)(rect4bX - centerX) * cos(rotationAngle * M_PI / 180) - ((rect4bY + 55) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect4bPoints[3].y = (int)(rect4bX - centerX) * sin(rotationAngle * M_PI / 180) + ((rect4bY + 55) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;

  gdImageFilledPolygon(rotated_im, rect4bPoints, 4, black);

  // 修改第五個斜形（在上方添加）
  gdPoint rect5Points[4];
  int rect5X = rect4aX + 15 + rectSpacing;  // 第五個長方形
  int rect5Y = rect4aY;
  int middleRectWidth = 15;    // 中間長方形寬度
  int middleRectHeight = 55;   // 中間長方形高度
  int middleRectSpacing = 10;  // 中間長方形上下間隔
  rect5Points[0].x = (int)(rect5X - centerX) * cos(rotationAngle * M_PI / 180) - (rect5Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect5Points[0].y = (int)(rect5X - centerX) * sin(rotationAngle * M_PI / 180) + (rect5Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect5Points[1].x = (int)((rect5X + middleRectWidth) - centerX) * cos(rotationAngle * M_PI / 180) - (rect5Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect5Points[1].y = (int)((rect5X + middleRectWidth) - centerX) * sin(rotationAngle * M_PI / 180) + (rect5Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect5Points[2].x = (int)((rect5X + middleRectWidth) - centerX) * cos(rotationAngle * M_PI / 180) - ((rect5Y + middleRectHeight) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect5Points[2].y = (int)((rect5X + middleRectWidth) - centerX) * sin(rotationAngle * M_PI / 180) + ((rect5Y + middleRectHeight) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect5Points[3].x = (int)(rect5X - centerX) * cos(rotationAngle * M_PI / 180) - ((rect5Y + middleRectHeight) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect5Points[3].y = (int)(rect5X - centerX) * sin(rotationAngle * M_PI / 180) + ((rect5Y + middleRectHeight) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;

  gdImageFilledPolygon(rotated_im, rect5Points, 4, black);


  // 添加位於第五個斜形下方的新的黑色斜形
  gdPoint rectBelow5Points[4];
  int rectBelow5X = rect5X;
  int rectBelow5Y = rect5Y + middleRectHeight + middleRectSpacing;
  rectBelow5Points[0].x = (int)(rectBelow5X - centerX) * cos(rotationAngle * M_PI / 180) - (rectBelow5Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rectBelow5Points[0].y = (int)(rectBelow5X - centerX) * sin(rotationAngle * M_PI / 180) + (rectBelow5Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rectBelow5Points[1].x = (int)((rectBelow5X + middleRectWidth) - centerX) * cos(rotationAngle * M_PI / 180) - (rectBelow5Y - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rectBelow5Points[1].y = (int)((rectBelow5X + middleRectWidth) - centerX) * sin(rotationAngle * M_PI / 180) + (rectBelow5Y - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rectBelow5Points[2].x = (int)((rectBelow5X + middleRectWidth) - centerX) * cos(rotationAngle * M_PI / 180) - ((rectBelow5Y + middleRectHeight) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rectBelow5Points[2].y = (int)((rectBelow5X + middleRectWidth) - centerX) * sin(rotationAngle * M_PI / 180) + ((rectBelow5Y + middleRectHeight) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rectBelow5Points[3].x = (int)(rectBelow5X - centerX) * cos(rotationAngle * M_PI / 180) - ((rectBelow5Y + middleRectHeight) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rectBelow5Points[3].y = (int)(rectBelow5X - centerX) * sin(rotationAngle * M_PI / 180) + ((rectBelow5Y + middleRectHeight) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;

  gdImageFilledPolygon(rotated_im, rectBelow5Points, 4, black);

  // 第六個斜形（上半部分）
  gdPoint rect6aPoints[4];
  int rect6aX = rect5X + 15 + 10;  // 第六個長方形（上半部分）
  int rect6aY = rect5Y;
  rect6aPoints[0].x = (int)(rect6aX - centerX) * cos(rotationAngle * M_PI / 180) - (rect6aY - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6aPoints[0].y = (int)(rect6aX - centerX) * sin(rotationAngle * M_PI / 180) + (rect6aY - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect6aPoints[1].x = (int)((rect6aX + 15) - centerX) * cos(rotationAngle * M_PI / 180) - (rect6aY - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6aPoints[1].y = (int)((rect6aX + 15) - centerX) * sin(rotationAngle * M_PI / 180) + (rect6aY - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect6aPoints[2].x = (int)((rect6aX + 15) - centerX) * cos(rotationAngle * M_PI / 180) - ((rect6aY + 55) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6aPoints[2].y = (int)((rect6aX + 15) - centerX) * sin(rotationAngle * M_PI / 180) + ((rect6aY + 55) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect6aPoints[3].x = (int)(rect6aX - centerX) * cos(rotationAngle * M_PI / 180) - ((rect6aY + 55) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6aPoints[3].y = (int)(rect6aX - centerX) * sin(rotationAngle * M_PI / 180) + ((rect6aY + 55) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;

  gdImageFilledPolygon(rotated_im, rect6aPoints, 4, black);

  // 第六個斜形（下半部分）
  gdPoint rect6bPoints[4];
  int rect6bX = rect6aX;  // 第六個長方形（下半部分）
  int rect6bY = rect6aY + 55 + 10;  // 上半部分的 Y 座標 + 上半部分的高度 + 間隔
  rect6bPoints[0].x = (int)(rect6bX - centerX) * cos(rotationAngle * M_PI / 180) - (rect6bY - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6bPoints[0].y = (int)(rect6bX - centerX) * sin(rotationAngle * M_PI / 180) + (rect6bY - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect6bPoints[1].x = (int)((rect6bX + 15) - centerX) * cos(rotationAngle * M_PI / 180) - (rect6bY - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6bPoints[1].y = (int)((rect6bX + 15) - centerX) * sin(rotationAngle * M_PI / 180) + (rect6bY - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect6bPoints[2].x = (int)((rect6bX + 15) - centerX) * cos(rotationAngle * M_PI / 180) - ((rect6bY + 55) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6bPoints[2].y = (int)((rect6bX + 15) - centerX) * sin(rotationAngle * M_PI / 180) + ((rect6bY + 55) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;
  rect6bPoints[3].x = (int)(rect6bX - centerX) * cos(rotationAngle * M_PI / 180) - ((rect6bY + 55) - centerY) * sin(rotationAngle * M_PI / 180) + centerX;
  rect6bPoints[3].y = (int)(rect6bX - centerX) * sin(rotationAngle * M_PI / 180) + ((rect6bY + 55) - centerY) * cos(rotationAngle * M_PI / 180) + centerY;

  gdImageFilledPolygon(rotated_im, rect6bPoints, 4, black);

    output = fopen("output.png", "wb");
    gdImagePng(rotated_im, output);
    fclose(output);

    gdImageDestroy(im);
    gdImageDestroy(rotated_im);

    return 0;
}