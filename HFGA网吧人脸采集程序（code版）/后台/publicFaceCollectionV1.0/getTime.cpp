#include "getTime.h"


using namespace std;


void GETTIME::getTime(string filename){

	struct stat statbuf; 

	if((stream=fopen(filename.c_str(),"r+"))==NULL)
	{
		fprintf(stderr, "Cannot open output file.\n"); 
	}

	stat(filename.c_str(),&statbuf);

	fclose(stream);

	struct   tm*   t=localtime(&statbuf.st_ctime); 

	fyear=t->tm_year+1900;
	fmonth=t->tm_mon+1;
	fday=t->tm_mday;

	fhour=t->tm_hour;
	fminute=t->tm_min;
	fsecond=t->tm_sec;
}

void GETTIME::getTime(){

	struct tm *tm;

	time_t now;

	now=time(NULL);

	tm=localtime(static_cast<const time_t*>(&now));

	lyear=tm->tm_year+1900;
	lmonth=tm->tm_mon+1;
	lday=tm->tm_mday;

	lhour=tm->tm_hour;
	lminute=tm->tm_min;
	lsecond=tm->tm_sec;
}


//int main()
//{
//	GETTIME ftime,ltime;
//
//	string filename="d:/test.txt";
//
//	ftime.getTime(filename);
//
//	ftime.getTime();
//
//	return 0;
//}