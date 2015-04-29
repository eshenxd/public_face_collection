#include "config.h"

#include <iostream>
#include <fstream>
#include <vector>
#include<windows.h>

#include "getFiles.h"




using namespace std;



bool Config::inti_config(){

	bool flag = read_configFiles();

	if (!flag)
	{
		cout << "read config files fail !" << endl;
	}

	begin_flag = false;

	//string FoldPath = "D:/photo";

	//vector<string>files;

	//getFiles(FoldPath, files);

	//begin_photo_count = files.size();

	year = month = day = hour = minute = second = 0;

	return flag;
}


bool Config::read_configFiles(){

	char tmp[100]="";

	ifstream fp;
	fp.open("../config/cardphotopath.ini",ios::in);
	fp.getline(tmp,100);
	string pathTemp = tmp;
	card_photo_path = pathTemp;
	fp.close();

	fp.open("../config/copypath.ini",ios::in);
	fp.getline(tmp,100);
	pathTemp = tmp;
	copy_path = pathTemp;
	fp.close();
	
	FILE *stream;

	if ((stream = fopen("../config/up_hour.ini", "r")) == NULL)
	{
		cout << "��up_hour.iniʧ�ܣ�" << endl;
		return false;
	}
	else
	{
		
		fscanf(stream, "%d", &up_hour);
		fclose(stream);
		
	}


	if ((stream = fopen("../config/up_minute.ini", "r")) == NULL)
	{
		cout << "��up_minute.iniʧ�ܣ�" << endl;
		return false;
	}
	else
	{
		fscanf(stream, "%d", &up_minute);
		fclose(stream);
	}

	if ((stream = fopen("../config/up_second.ini", "r")) == NULL)
	{
		cout << "��up_second.iniʧ�ܣ�" << endl;
		return false;
	}
	else
	{
		fscanf(stream, "%d", &up_second);
		fclose(stream);
	}


	if ((stream = fopen("../config/delete_hour.ini", "r")) == NULL)
	{
		cout << "��delete_hour.iniʧ�ܣ�" << endl;
		return false;
	}
	else
	{
		//hour=0;
		fscanf(stream, "%d", &delete_hour);
		fclose(stream);
		//config->hour=hour;
	}


	if ((stream = fopen("../config/delete_minute.ini", "r")) == NULL)
	{
		cout << "��delete_minute.iniʧ�ܣ�" << endl;
		return false;
	}
	else
	{
		fscanf(stream, "%d", &delete_minute);
		fclose(stream);
	}

	if ((stream = fopen("../config/delete_second.ini", "r")) == NULL)
	{
		cout << "��delete_second.iniʧ�ܣ�" << endl;
		return false;
	}
	else
	{
		fscanf(stream, "%d", &delete_second);
		fclose(stream);
	}




	if ((stream = fopen("../config/Windows_scale.ini", "r")) == NULL)
	{
		cout << "��Windows_scale.iniʧ�ܣ�" << endl;
		return false;
	}
	else
	{
		fscanf(stream, "%f", &window_scale);
		fclose(stream);
	}

	

	if ((stream = fopen("../config/FD_iterations.ini", "r")) == NULL)
	{
		cout << "��FD_iterations.iniʧ�ܣ�" << endl;
		return false;
	}
	else
	{
		fscanf(stream, "%d", &FD_iterations);
		fclose(stream);
	}

	if ((stream = fopen("../config/show_width.ini", "r")) == NULL)
	{
		cout << "��show_width.iniʧ�ܣ�" << endl;
		return false;
	}
	else
	{
		fscanf(stream, "%d", &show_width);
		fclose(stream);
	}
	if ((stream = fopen("../config/show_height.ini", "r")) == NULL)
	{
		cout << "��show_height.iniʧ�ܣ�" << endl;
		return false;
	}
	else
	{
		fscanf(stream, "%d", &show_height);
		fclose(stream);
	}
	if ((stream = fopen("../config/Align_iterations.ini", "r")) == NULL)
	{
		cout << "��Align_iterations.iniʧ�ܣ�" << endl;
		return false;
	}
	else
	{
		fscanf(stream, "%d", &Align_iterations);
		fclose(stream);
	}

	if ((stream = fopen("../config/pic_width.ini", "r")) == NULL)
	{
		cout << "��pic_width.iniʧ�ܣ�" << endl;
		return false;
	}
	else
	{
		fscanf(stream, "%d", &pic_width);
		fclose(stream);
	}
	if ((stream = fopen("../config/pic_height.ini", "r")) == NULL)
	{
		cout << "��pic_height.iniʧ�ܣ�" << endl;
		return false;
	}
	else
	{
		fscanf(stream, "%d", &pic_height);
		fclose(stream);
	}

	return true;
}

bool Config::up_time_same(){
	
	SYSTEMTIME sys;

	GetLocalTime(&sys);

	if (((sys.wHour == up_hour) && (sys.wMinute == up_minute)/*&&(sys.wSecond==P_para->up_second)*/))
	{

		return true;
	}
	else
	{
		time_flag_up = false;
		return false;
	}
}

bool Config::delete_time_same()
{
	SYSTEMTIME sys;

	GetLocalTime(&sys);

	if (((sys.wHour == delete_hour) && (sys.wMinute == delete_minute)/*&&(sys.wSecond==P_para->delete_second)*/))
	{

		return true;
	}
	else
	{
		time_flag_delete = false;
		return false;
	}
}