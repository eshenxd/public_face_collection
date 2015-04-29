#ifndef _SAVE_IMAGE_H
#define _SAVE_IMAGE_H

#include "header.h"
#include "GetLocalIPAddress.h"
#include "config.h"
#include <stdlib.h>

#include "getFiles.h"




#include <direct.h>


#pragma comment(lib,"ws2_32.lib")

struct save_para
{
	char Setfile[50];
	int filesum;
	string ip;

	bool inti_para();
	bool write_para();
};

void saveImage(IplImage* image, CvRect area,int saveNum);

void deletePic();

void detectAddFile(Config& config);

#endif