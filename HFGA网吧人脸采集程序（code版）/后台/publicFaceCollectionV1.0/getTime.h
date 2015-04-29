#ifndef _GET_TIME_H_
#define _GET_TIME_H_

#include <io.h>
#include <sys\stat.h> 
#include <stdio.h> 
#include <time.h> 
#include <iostream>

class GETTIME
{
public:
	//文件创建时间
	int fyear;
	int fmonth;
	int fday;

	int fhour;
	int fminute;
	int fsecond;

	//本地时间
	int lyear;
	int lmonth;
	int lday;

	int lhour;
	int lminute;
	int lsecond;

	void getTime(std::string filename);//获取打开文件的新建时间
	void getTime();//获取本机时间
private:
	char buf[65];
	FILE *stream; 
};

#endif