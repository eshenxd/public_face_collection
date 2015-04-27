#ifndef _CAMERA_PROCESS_H_
#define _CAMERA_PROCESS_H_

#include "header.h"
#include "config.h"

class Camera_process
{
public:
	bool process_para_inti(int index=0);//indexΪ����ͷ�ı�ţ�Ĭ��Ϊ0
	void process_operate(Config& config,IplImage* image);
	bool process_release();
protected:
private:
	CvCapture* capture;

	IplImage* frame;
	IplImage* show_img;

	CvRect area;
	CvRect region;

	int frame_count;

};

#endif