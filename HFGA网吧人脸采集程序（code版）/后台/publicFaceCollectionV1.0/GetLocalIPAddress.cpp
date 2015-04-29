/**************************************
      功能：获取本机IP
	  时间：2014年9月12日
	  作者：Ethan
**************************************/
#include "GetLocalIPAddress.h"



#define _WINSOCK_DEPRECATED_NO_WARNINGS

string IP::getIP()
{
	ifstream fp;
	fp.open("2.txt",ios::in);
	fp>>ipAddress;
	fp.close();

	return ipAddress;
}



