#include "save_image.h"
#include "config.h"



using namespace std;



bool save_para::inti_para(){

	FILE *stream;
	if ((stream = fopen("../config/setfile_1.ini", "r")) == NULL)
	{
		cout << "打开setfile_1.ini失败！" << endl;
		return false;
	}
	else
	{

		fscanf(stream, "%s", &Setfile);
		fclose(stream);

	}

	if ((stream = fopen("../config/filesum_1.ini", "r")) == NULL)
	{
		cout << "打开filesum_1.ini失败！" << endl;
		return false;
	}
	else
	{

		fscanf(stream, "%d", &filesum);
		fclose(stream);

	}
	
	
	return true;
}

bool save_para::write_para(){

	FILE *stream;

	stream = fopen("../config/filesum_1.ini", "w");
	
	fprintf(stream, "%d", filesum);

	fclose(stream);

	return true;
}



string creatSavePath(int flag){

	save_para para;

	para.inti_para();

	string savePath = para.Setfile;

	_mkdir(savePath.c_str());

	IP _ip;

	para.ip = _ip.getIP();
	
	savePath = savePath + para.ip+"/";

	_mkdir(savePath.c_str());

	char tmp[10];
	
	_itoa(para.filesum, tmp, 10);

	savePath = savePath + tmp + "/";

	_mkdir(savePath.c_str());

	if (flag == 13)
	{
		para.filesum++;

		para.write_para();
	}

	return savePath;

}


void saveImage(IplImage* image, CvRect area,int saveNum){

	string path;

	char	 s_date[70];

	SYSTEMTIME sys;
	
	path = creatSavePath(saveNum);

	IplImage* ImageSave = cvCreateImage(cvSize(area.width, area.height), image->depth, image->nChannels);

	cvSetImageROI(image, area);

	cvCopy(image, ImageSave);

	cvResetImageROI(image);

	GetLocalTime(&sys);

	sprintf(s_date, "%d-%d-%d-%d-%d-%d-%d", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute
			, sys.wSecond, sys.wMilliseconds);

	path = path + s_date + ".jpg";

	cvSaveImage(path.c_str(), ImageSave);
	
}

void deletePic(){

	save_para para;

	para.inti_para();

	IP _ip;

	para.ip = _ip.getIP();

	char tmp[10];

	_itoa(para.filesum, tmp, 10);

	string path = para.Setfile + para.ip +"/"+ tmp+"/";

	vector<string>filenames;

	getFiles(path, filenames);

	if (filenames.size() < 10&&filenames.size()!=1)
	{
		for (unsigned int ix = 0; ix < filenames.size(); ix++)
		{
			remove(filenames[ix].c_str());
		}
	}

	


}

void detectAddFile(Config& config){

	
	//string FoldPath = "D:/photo";//配置身份证存储路径
	string FoldPath=config.card_photo_path;

	//string savePath = creatSavePath(0);
	string savePath_copy=config.copy_path;
	string savePath_copy_H=config.copy_path;

	vector<string>files;

	files.clear();

	getFiles(FoldPath, files);

	if (files.size() ==2)
	{
		string savePath = creatSavePath(0);

		char _filename[40];

		_splitpath(files[0].c_str(), NULL, NULL, _filename, NULL);

		savePath = savePath + _filename + ".jpg";
		savePath_copy = savePath_copy+ +"/"+_filename + ".jpg";
		savePath_copy_H = savePath_copy_H + "/" + _filename + "_H.jpg";

		CopyFile(files[0].c_str(),savePath.c_str(),false);
		CopyFile(files[0].c_str(),savePath_copy.c_str(),false);
		CopyFile(files[1].c_str(),savePath_copy_H.c_str(),false);

		remove(files[0].c_str());
		remove(files[1].c_str());

		config.begin_flag = true;
		
	}

	
}