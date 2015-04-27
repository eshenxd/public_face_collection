/*  
 *  ���빦�ܣ��Ϸʹ����������������ɣ�
 *            �����ɼ�ϵͳV1.0
 *  ��дʱ�䣺2015��4��8��
 *  �޸�ʱ�䣺2015��4��27��
 *  �������ߣ�Ethan
 *  �������⣺
 *  ��    �ģ���1���޸������ɿ���̨��ƥ���ļ�Ŀ¼��Ŀ¼�ĸ����������ļ�cardphotopath.ini��copypath.ini������
              ��2���������ϴ��ļ���ɾ�������ļ��Ĳ���
			  ��3��������Ҫ���ĵ����ӳ�ÿһ�������Ĳɼ�ʱ��
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
	   ��ʼ���У��������̨���֤��Ƭ�洢�ļ��µ�ͼƬ�����
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