#include "getLocalIP.h"


using namespace std;

void doit(string& ip) 
{ 
	char host_name[255]; 
	//��ȡ������������ 
	gethostname(host_name, sizeof(host_name));

	//�����������ݿ��еõ���Ӧ�ġ������� 
	struct hostent *phe = gethostbyname(host_name); 

	struct in_addr addr;
	memcpy(&addr, phe->h_addr_list[0], sizeof(struct in_addr));
	
	ip = (string)inet_ntoa(addr);

	return; 
} 

void get_local_ip()
{
	string ip;
	WSAData wsaData; 
	if (WSAStartup(MAKEWORD(1, 1), &wsaData) != 0) { 
		return ; 
	} 

	doit(ip); 

	WSACleanup();

	ofstream fp;
	fp.open("2.txt",ios::in|ios::trunc);
	fp<<ip.c_str();
	fp.close();

	return;
}