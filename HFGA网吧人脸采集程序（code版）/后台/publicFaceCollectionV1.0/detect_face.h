#pragma once

#include "header.h"

#define MAX_FACE_COUNT_D_USTC  100 //一帧中最多的人脸数

struct _Rect //人脸位置
{
	int left;
	int top;
	int right;
	int bottom;
};

class FaceDetector//人脸检测器
{
public:
	FaceDetector(IplImage*);
	~FaceDetector();

	int runFaceDetector();
	int getDetectFaceCount();
	int getDetectFacePos(int faceIndex, int pos[4]);

protected:

private:
	int width;
	int height;

	IplImage* Frame;
	IplImage* grayFrame;
	IplImage* small_img;

	_Rect* facePos;

	int faceCount;
	double scale;

	CvMemStorage* storage_faces;
    CvHaarClassifierCascade* cascade_faces;
};
