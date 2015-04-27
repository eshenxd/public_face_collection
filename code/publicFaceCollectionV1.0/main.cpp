/*  
 *  代码功能：合肥公安公共场所（网吧）
 *            人脸采集系统V1.0
 *  编写时间：2015年4月8日
 *  修改时间：2015年4月27日
 *  代码作者：Ethan
 *  存在问题：
 *  修    改：（1）修改了网吧控制台的匹配文件目录，目录的更改在配置文件cardphotopath.ini和copypath.ini中设置
              （2）增加了上传文件和删除本地文件的操作
			  （3）后期需要更改的是延长每一个人脸的采集时间
 */


#include "header.h"
#include "config.h"
#include "camera_process.h"
#include "video_camera.h"
#include "getFiles.h"
#include "save_image.h"
#include "getLocalIP.h"

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

using namespace std;

int main()
{
	
	
    
	vector<string>cardphotoname;


	cvNamedWindow("SHOW",1);
	

	//if(!(WinExec("getlocalip.bat", SW_HIDE) > 31))return -1;
	get_local_ip();

	Config config;
	if(!config.inti_config())return -1;

	/*
	   开始运行，保存控制台身份证照片存储文件下的图片并清空
	*/

	_mkdir(config.copy_path.c_str());

	getFiles(config.card_photo_path,cardphotoname);
	for(unsigned int ix=0;ix<cardphotoname.size();ix++)
	{
		char _filename[30];

		_splitpath(cardphotoname[ix].c_str(), NULL, NULL, _filename, NULL);

		string copy_path_tmp = config.copy_path +"/" + _filename + ".jpg";

		CopyFile(cardphotoname[ix].c_str(),copy_path_tmp.c_str(),false);

		remove(cardphotoname[ix].c_str());
	}



	Camera_process camera;
	if(!camera.process_para_inti())return -1;

	IplImage* image = NULL;

	while(true)
	{
		image=read_from_camera();
		camera.process_operate(config,image);
	}

	system("pause");


	return 0;
}