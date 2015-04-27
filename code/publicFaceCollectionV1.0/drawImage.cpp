#include "drawImage.h"


void draw_image(CvRect area, IplImage* img){

	CvPoint p1, p2;

	p1.x = area.x;

	p1.y = area.y;

	p2.x = area.x + area.width;

	p2.y = area.y + area.height;
	
	cvRectangle(img, p1, p2, CV_RGB(0, 0, 255), 1, 8, 0);
}


void draw_image(CvRect area, std::string showMsg, IplImage* img, CvScalar color){

	CvFont font;
	double hScale = 1;
	double vScale = 1;
	int lineWidth = 2;// �൱��д�ֵ�����

	CvPoint p1, p2, p3;

	p1.x = area.x;

	p1.y = area.y;

	p2.x = area.x + area.width;

	p2.y = area.y + area.height;

	p3.x = area.x;

	p3.y = area.y - 10;
	cvRectangle(img, p1, p2, CV_RGB(0, 0, 255), 1, 8, 0);

	// ��ʼ������   
	cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX | CV_FONT_ITALIC, hScale, vScale, 0, lineWidth);//��ʼ�����壬׼��д��ͼƬ�ϵ�   

	cvPutText(img, showMsg.c_str(), p3, &font, color);//��ͼƬ������ַ� 
}