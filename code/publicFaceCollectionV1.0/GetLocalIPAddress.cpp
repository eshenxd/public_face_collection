/**************************************
      ���ܣ���ȡ����IP
	  ʱ�䣺2014��9��12��
	  ���ߣ�Ethan
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



