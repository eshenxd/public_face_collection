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
	//�ļ�����ʱ��
	int fyear;
	int fmonth;
	int fday;

	int fhour;
	int fminute;
	int fsecond;

	//����ʱ��
	int lyear;
	int lmonth;
	int lday;

	int lhour;
	int lminute;
	int lsecond;

	void getTime(std::string filename);//��ȡ���ļ����½�ʱ��
	void getTime();//��ȡ����ʱ��
private:
	char buf[65];
	FILE *stream; 
};

#endif