
#include "camera_process.h"

#include "video_camera.h"
#include "drawImage.h"
#include "detect_face.h"
#include "save_image.h"

bool Camera_process::process_para_inti(int index){
	
	if (!open_camera(index))
	{
		std::cout << "无摄像头输入！" << std::endl;

		return false;
	}

	frame = NULL;

	show_img = NULL;

	area = cvRect(0, 0, 0, 0);

	region = cvRect(0, 0, 0, 0);

	frame_count = 0;

	return true;

}

void Camera_process::process_operate(Config& config,IplImage* img){

	if(!(WinExec("get_IP.bat", SW_HIDE) > 31))return;
	
	frame = img;

	show_img = cvCreateImage(cvSize(img->width, img->height), img->depth, img->nChannels);

	cvCopy(img, show_img);
	

	bool flag_up = false;
	bool flag_delete = false;

	flag_up = config.up_time_same();
	flag_delete = config.delete_time_same();

	if (flag_up&&config.time_flag_up == false)
	{
		config.time_flag_up = true;
		WinExec("上传服务器1.bat", SW_HIDE);//上传文件至主机
		Sleep(1000);
	}
	if (flag_delete&&config.time_flag_delete == false)
	{
		config.time_flag_delete = true;
		WinExec("删除本地文件1.bat", SW_HIDE);//上传文件至主机
		Sleep(1000);
	}
	
	area.x = cvRound(frame->width*config.window_scale);
	area.y = cvRound(frame->height*config.window_scale);

	area.width = cvRound(frame->width*(1 - config.window_scale * 2));
	area.height = cvRound(frame->height*(1 - config.window_scale * 2));


	draw_image(area,"AI", show_img);

	/*
	   检测目录文件夹下的文件数量
	*/
	detectAddFile(config);

	//config.begin_flag = true;

	if (config.begin_flag == true){

		IplImage* img_Gray = cvCreateImage(cvSize(frame->width, frame->height), 8, 1);

		cvCvtColor(frame, img_Gray, CV_RGB2GRAY);
		
		IplImage *img_ROI = cvCreateImage(cvSize(area.width, area.height), img_Gray->depth, img_Gray->nChannels);

		cvSetImageROI(img_Gray, area);

		cvCopy(img_Gray, img_ROI);

		cvResetImageROI(img_Gray);

		/*    facedetect      */
		FaceDetector FD(img_ROI);

		FD.runFaceDetector();

		int num = FD.getDetectFaceCount();

		int pos[4] = {0};

		if (num == 1)
		{
			frame_count++;

			FD.getDetectFacePos(0, pos);

			region.x = pos[0] + area.x;
			region.y = pos[1] + area.y;
			region.width = pos[2] - pos[0];
			region.height = pos[3] - pos[1];

			if (frame_count>0&&frame_count<4)
				draw_image(region, "Prepare...", show_img, CV_RGB(0, 255, 255));

			if (frame_count >= 4 && frame_count < 14){
				
				draw_image(region, "Begin...", show_img, CV_RGB(0, 255, 0));

				saveImage(frame, area,frame_count);
			}
				

			if (frame_count >= 14&&frame_count<18)
			{
				draw_image(region, "OK...", show_img, CV_RGB(255, 0, 0));

			}

			if (frame_count == 18)
				{
					frame_count=0;
					config.begin_flag = false;
			    }
		}
		else
		{
			frame_count = 0;

			deletePic();
		}

		
		/*    facedetect      */

		cvReleaseImage(&img_ROI);

		cvReleaseImage(&img_Gray);
	}
	
	

	cvShowImage("SHOW", show_img);
	cvWaitKey(1);

	cvReleaseImage(&show_img);
}


