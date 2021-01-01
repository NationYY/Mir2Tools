// PortChange.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream> 
#include <fstream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <list>
using namespace std;
struct SPortChangeInfo
{
	char szPortPath[128];
	char szPortName[128];
	char szAppName[128];
	int nPortDefault;
};

int _tmain(int argc, _TCHAR* argv[])
{
	char szBuffer[128] = { 0 };
	list<SPortChangeInfo> listAllPortInfo;
	int nZone = GetPrivateProfileInt("�䶯", "��", 0, "./config.ini");
	for(int i=1; i<100; ++i)
	{
		
		SPortChangeInfo info;
		sprintf_s(szBuffer, "port_path%d", i);
		GetPrivateProfileString("�˿�", szBuffer, "", info.szPortPath, 128, "./config.ini");
		sprintf_s(szBuffer, "port_name%d", i);
		GetPrivateProfileString("�˿�", szBuffer, "", info.szPortName, 128, "./config.ini");
		sprintf_s(szBuffer, "port_defult%d", i);
		info.nPortDefault = GetPrivateProfileInt("�˿�", szBuffer, 0, "./config.ini");
		sprintf_s(szBuffer, "port_appname%d", i);
		GetPrivateProfileString("�˿�", szBuffer, "", info.szAppName, 128, "./config.ini");
		listAllPortInfo.push_back(info);
	}
	list<SPortChangeInfo>::iterator itB = listAllPortInfo.begin();
	list<SPortChangeInfo>::iterator itE = listAllPortInfo.end();
	while(itB != itE)
	{
		char szBuffer[128] = { 0 };
		sprintf_s(szBuffer, "%d", itB->nPortDefault + nZone - 1);
		WritePrivateProfileString(itB->szAppName, itB->szPortName, szBuffer, itB->szPortPath);
		++itB;
	}
	std::cout<<"�������!"<<std::endl;
	system("pause");
	return 0;
}

