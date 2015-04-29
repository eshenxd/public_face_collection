#ifndef _DRAW_IMAGE_H_
#define _DRAW_IMAGE_H_

#include "header.h"

void draw_image(CvRect area, IplImage* img);//»­¾ØÐÎ

void draw_image(CvRect area, std::string showMsg, IplImage* img, CvScalar color=CV_RGB(0, 0, 255));//Ð´×Ö&»­¾ØÐÎ

#endif