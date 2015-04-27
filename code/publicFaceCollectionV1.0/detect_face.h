#pragma once

#include "header.h"

#define MAX_FACE_COUNT_D_USTC  100 //һ֡������������

struct _Rect //����λ��
{
	int left;
	int top;
	int right;
	int bottom;
};

class FaceDetector//���������
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
