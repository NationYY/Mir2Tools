// PortChange.cpp : 定义控制台应用程序的入口点。
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

char szIP[128] = {};
char szServerName[128] = {};
char szServerPath[128] = {};
int nZone;
int nPort1;
int nPort2;
int nPort3;
int nPort4;
int nPort5;
int nPort6;
int nPort7;
int nPort8;
int nPort9;
int nPort10;
int nPort11;
int nPort12;
int nPort13;
int nPort14;
int nPort15;
int nPort16;
int nPort17;
bool CoverTxtFile(char* szFileName, char* szInfo, ...)
{
	char szFilePath[128] = { 0 };
	sprintf_s(szFilePath, "%s\\%s", szServerPath, szFileName);
	std::ofstream file;
	file.open(szFilePath);
	if(!file.is_open())
	{
		std::cout<<szFilePath<<"打开失败!"<<std::endl;
		return false;
	}

	char szOut[512] = { 0 };
	va_list	va;
	va_start(va, szInfo);
	_vsnprintf(szOut, 512, szInfo, va);
	va_end(va);
	file << szOut;
	file.close();
	return true;
}

bool WriteIniFile(char* szFileName, char* szAppName, char* szKeyName, char* szInfo, ...)
{
	char szFilePath[128] = { 0 };
	sprintf_s(szFilePath, "%s\\%s", szServerPath, szFileName);
	char szOut[512] = { 0 };
	va_list	va;
	va_start(va, szInfo);
	_vsnprintf(szOut, 512, szInfo, va);
	va_end(va);
	if(!WritePrivateProfileString(szAppName, szKeyName, szOut, szFilePath))
	{
		std::cout << szFilePath << "写入失败!" << std::endl;
		return false;
	}
	return true;
}
int _tmain(int argc, _TCHAR* argv[])
{
	GetPrivateProfileString("setup", "server_path", "", szServerPath, 128, "./config.ini");
	GetPrivateProfileString("setup", "server_name", "", szServerName, 128, "./config.ini");
	GetPrivateProfileString("setup", "ip", "", szIP, 128, "./config.ini");
	nZone = GetPrivateProfileInt("setup", "zone", 0, "./config.ini");
	nPort1 = GetPrivateProfileInt("setup", "port1", 0, "./config.ini");
	nPort2 = GetPrivateProfileInt("setup", "port2", 0, "./config.ini");
	nPort3 = GetPrivateProfileInt("setup", "port3", 0, "./config.ini");
	nPort4 = GetPrivateProfileInt("setup", "port4", 0, "./config.ini");
	nPort5 = GetPrivateProfileInt("setup", "port5", 0, "./config.ini");
	nPort6 = GetPrivateProfileInt("setup", "port6", 0, "./config.ini");
	nPort7 = GetPrivateProfileInt("setup", "port7", 0, "./config.ini");
	nPort8 = GetPrivateProfileInt("setup", "port8", 0, "./config.ini");
	nPort9 = GetPrivateProfileInt("setup", "port9", 0, "./config.ini");
	nPort10 = GetPrivateProfileInt("setup", "port10", 0, "./config.ini");
	nPort11 = GetPrivateProfileInt("setup", "port11", 0, "./config.ini");
	nPort12 = GetPrivateProfileInt("setup", "port12", 0, "./config.ini");
	nPort13 = GetPrivateProfileInt("setup", "port13", 0, "./config.ini");
	nPort14 = GetPrivateProfileInt("setup", "port14", 0, "./config.ini");
	nPort15 = GetPrivateProfileInt("setup", "port15", 0, "./config.ini");
	nPort16 = GetPrivateProfileInt("setup", "port16", 0, "./config.ini");
	nPort17 = GetPrivateProfileInt("setup", "port17", 0, "./config.ini");
	//txt	全内容修改
	CoverTxtFile("DBServer\\!addrtable.txt", "127.0.0.1\n%s", szIP);
	CoverTxtFile("DBServer\\!serverinfo.txt", "127.0.0.1 %s %d %s %d %s %d", szIP, nPort1+nZone-1, szIP, nPort2+nZone-1, szIP, nPort3+nZone-1);
	CoverTxtFile("LoginSrv\\!addrtable.txt", "%s Title1 127.0.0.1 127.0.0.1 %s:%d", szServerName, szIP, nPort4+nZone-1);
	CoverTxtFile("LoginSrv\\!serveraddr.txt", "127.0.0.1\n%s", szIP);
	CoverTxtFile("LoginSrv\\!UserLimit.txt", "%s %s 10000", szServerName, szServerName);
	//ini 修改服务器名字
	WriteIniFile("LoginSrv\\Logsrv.ini", "Server", "ServerName", "%s", szServerName);
	WriteIniFile("LogServer\\LogData.ini", "Setup", "ServerName", "%s", szServerName);
	WriteIniFile("DBServer\\dbsrc.ini", "Setup", "ServerName", "%s", szServerName);
	WriteIniFile("LoginGate\\Config.ini", "LoginGate", "Title", "%s", szServerName);
	WriteIniFile("Mir200\\!Setup.txt", "Server", "ServerName", "%s", szServerName);
	WriteIniFile("SelGate\\Config.ini", "SelGate", "Title", "%s", szServerName);

	//ini 修改服务器名字+端口
	WriteIniFile("RunGate\\Config.ini", "GameGate", "Title", "%s(%d)", szServerName, nPort3+nZone-1);
	WriteIniFile("RunGate\\RunGate.ini", "RunGate", "Title", "%s(%d)", szServerName, nPort3+nZone-1);
	//ini 修改服务器路径
	WriteIniFile("DBServer\\dbsrc.ini", "Setup", "MapFile", "%s\\%s", szServerPath, "Mir200\\Envir\\MapInfo.txt");
	WriteIniFile("DBServer\\dbsrc.ini", "DB", "Dir", "%s\\%s", szServerPath, "DBServer\\FDB\\");
	WriteIniFile("DBServer\\dbsrc.ini", "DB", "IdDir", "%s\\%s", szServerPath, "DBServer\\FDB\\");
	WriteIniFile("DBServer\\dbsrc.ini", "DB", "HumDir", "%s\\%s", szServerPath, "DBServer\\FDB\\");
	WriteIniFile("DBServer\\dbsrc.ini", "DB", "FeeDir", "%s\\%s", szServerPath, "DBServer\\FDB\\");
	WriteIniFile("DBServer\\dbsrc.ini", "DB", "BackupDir", "%s\\%s", szServerPath, "DBServer\\Backup\\");
	WriteIniFile("DBServer\\dbsrc.ini", "DB", "ConnectDir", "%s\\%s", szServerPath, "DBServer\\Connection\\");
	WriteIniFile("DBServer\\dbsrc.ini", "DB", "LogDir", "%s\\%s", szServerPath, "DBServer\\Log\\");
	WriteIniFile("DBServer\\dbsrc.ini", "DB", "ClearLogDir", "%s\\%s", szServerPath, "DBServer\\ClearLog\\");
	WriteIniFile("LoginSrv\\Logsrv.ini", "DB", "IdDir", "%s\\%s", szServerPath, "LoginSrv\\IDDB\\");
	WriteIniFile("LoginSrv\\Logsrv.ini", "DB", "FeedIDList", "%s\\%s", szServerPath, "LoginSrv\\FeedIDList.txt");
	WriteIniFile("LoginSrv\\Logsrv.ini", "DB", "FeedIPList", "%s\\%s", szServerPath, "LoginSrv\\FeedIPList.txt");
	WriteIniFile("LoginSrv\\Logsrv.ini", "DB", "CountLogDir", "%s\\%s", szServerPath, "LoginSrv\\CountLog\\");
	WriteIniFile("LoginSrv\\Logsrv.ini", "DB", "WebLogDir", "%s\\%s", szServerPath, "LoginSrv\\GameWFolder\\");
	WriteIniFile("LoginSrv\\Logsrv.ini", "DB", "ChrLogDir", "%s\\%s", szServerPath, "LoginSrv\\ChrLogDir\\");
	WriteIniFile("LoginSrv\\Logsrv.ini", "DB", "IdLogDir", "%s\\%s", szServerPath, "LoginSrv\\IDLogDir\\");
	WriteIniFile("LogServer\\LogData.ini", "Setup", "BaseDir", "%s\\%s", szServerPath, "LogServer\\BaseDir\\");
	WriteIniFile("Mir200\\!Setup.txt", "Server", "AccessFileName", "%s\\%s", szServerPath, "Mud2\\DB\\HeroDB.MDB");
	WriteIniFile("Mir200\\!Setup.txt", "Share", "BaseDir", "%s\\%s", szServerPath, "Mir200\\Share\\");
	WriteIniFile("Mir200\\!Setup.txt", "Share", "GuildDir", "%s\\%s", szServerPath, "Mir200\\GuildBase\\Guilds\\");
	WriteIniFile("Mir200\\!Setup.txt", "Share", "GuildFile", "%s\\%s", szServerPath, "Mir200\\GuildBase\\Guildlist.txt");
	WriteIniFile("Mir200\\!Setup.txt", "Share", "VentureDir", "%s\\%s", szServerPath, "Mir200\\ShareV\\");
	WriteIniFile("Mir200\\!Setup.txt", "Share", "ConLogDir", "%s\\%s", szServerPath, "Mir200\\ConLog\\");
	WriteIniFile("Mir200\\!Setup.txt", "Share", "LogDir", "%s\\%s", szServerPath, "Mir200\\Log\\");
	WriteIniFile("Mir200\\!Setup.txt", "Share", "CastleDir", "%s\\%s", szServerPath, "Mir200\\Castle\\");
	WriteIniFile("Mir200\\!Setup.txt", "Share", "EnvirDir", "%s\\%s", szServerPath, "Mir200\\Envir\\");
	WriteIniFile("Mir200\\!Setup.txt", "Share", "MapDir", "%s\\%s", szServerPath, "Mir200\\Map\\");
	WriteIniFile("Mir200\\!Setup.txt", "Share", "NoticeDir", "%s\\%s", szServerPath, "Mir200\\Notice\\");
	WriteIniFile("Mir200\\!Setup.txt", "Share", "CastleFile", "%s\\%s", szServerPath, "Mir200\\Castle\\List.txt");
	WriteIniFile("Mir200\\!Setup.txt", "Share", "PlugDir", "%s\\%s", szServerPath, "Mir200\\PlugClient\\");
	WriteIniFile("SelGate\\Config.ini", "SelGate", "ReadIPList", "%s\\%s", szServerPath, "Mir200\\Envir\\QuestDiary\\KickList.txt");
	//ini 修改各种端口
	WriteIniFile("DBServer\\dbsrc.ini", "Setup", "ServerPort", "%d", nPort5+nZone-1);
	WriteIniFile("DBServer\\dbsrc.ini", "Setup", "GatePort", "%d", nPort6+nZone-1);
	WriteIniFile("DBServer\\dbsrc.ini", "Server", "IDSPort", "%d", nPort7+nZone-1);
	WriteIniFile("LoginGate\\Config.ini", "LoginGate", "ServerPort", "%d", nPort8+nZone-1);
	WriteIniFile("LoginGate\\Config.ini", "LoginGate", "GatePort", "%d", nPort9+nZone-1);
	WriteIniFile("LoginGate\\Config.ini", "LoginGate", "GatePort1", "%d", nPort10+nZone-1);
	WriteIniFile("LoginSrv\\Logsrv.ini", "Server", "GatePort", "%d", nPort8+nZone-1);
	WriteIniFile("LoginSrv\\Logsrv.ini", "Server", "ServerPort", "%d", nPort7+nZone-1);
	WriteIniFile("LoginSrv\\Logsrv.ini", "Server", "MonPort", "%d", nPort11+nZone-1);
	WriteIniFile("LoginSrv\\Logsrv.ini", "Server", "DBSPort", "%d", nPort12+nZone-1);
	WriteIniFile("LoginSrv\\Logsrv.ini", "Server", "FeePort", "%d", nPort13+nZone-1);
	WriteIniFile("LoginSrv\\Logsrv.ini", "Server", "LogPort", "%d", nPort13+nZone-1);
	WriteIniFile("LoginSrv\\Logsrv.ini", "Server", "RunPort", "%d", nPort14+nZone-1);
	WriteIniFile("LoginSrv\\Logsrv.ini", "Server", "DataLogPort", "%d", nPort15+nZone-1);
	WriteIniFile("LogServer\\LogData.ini", "Setup", "Port", "%d", nPort15+nZone-1);
	WriteIniFile("Mir200\\!Setup.txt", "Server", "DBPort", "%d", nPort5+nZone-1);
	WriteIniFile("Mir200\\!Setup.txt", "Server", "IDSPort", "%d", nPort7+nZone-1);
	WriteIniFile("Mir200\\!Setup.txt", "Server", "LogServerPort", "%d", nPort15+nZone-1);
	WriteIniFile("Mir200\\!Setup.txt", "Server", "MsgSrvPort", "%d", nPort16+nZone-1);
	WriteIniFile("Mir200\\!Setup.txt", "Server", "GatePort", "%d", nPort17+nZone-1);
	WriteIniFile("RunGate\\Config.ini", "GameGate", "GatePort", "%d", nPort3+nZone-1);
	WriteIniFile("RunGate\\Config.ini", "GameGate", "LsvServerPort", "%d", nPort14+nZone-1);
	WriteIniFile("RunGate\\Config.ini", "GameGate", "ServerPort", "%d", nPort17+nZone-1);
	WriteIniFile("RunGate\\RunGate.ini", "RunGate", "ServerPort", "%d", nPort17+nZone-1);
	WriteIniFile("RunGate\\RunGate.ini", "RunGate", "GatePort", "%d", nPort3+nZone-1);
	WriteIniFile("SelGate\\Config.ini", "SelGate", "GatePort", "%d", nPort4+nZone-1);
	WriteIniFile("SelGate\\Config.ini", "SelGate", "ServerPort", "%d", nPort6+nZone-1);
	WriteIniFile("SelGate\\Config.ini", "SelGate", "LsvServerPort", "%d", nPort14+nZone-1);


	WriteIniFile("Config.ini", "GameConf", "GameDirectory", "%s\\", szServerPath);
	WriteIniFile("Config.ini", "GameConf", "GameName", "%s", szServerName);
	WriteIniFile("Config.ini", "GameConf", "ExtIPaddr", "%s", szIP);

	WriteIniFile("Config.ini", "M2Server", "GatePort", "%d", nPort17+nZone-1);
	WriteIniFile("Config.ini", "M2Server", "MsgSrvPort", "%d", nPort16+nZone-1);

	WriteIniFile("Config.ini", "RunGate", "GatePort1", "%d", nPort1+nZone-1);
	WriteIniFile("Config.ini", "RunGate", "GatePort2", "%d", nPort2+nZone-1);
	WriteIniFile("Config.ini", "RunGate", "GatePort3", "%d", nPort3+nZone-1);

	WriteIniFile("Config.ini", "LoginGate", "GatePort", "%d", nPort9+nZone-1);
	WriteIniFile("Config.ini", "LoginGate", "GatePort1", "%d", nPort10+nZone-1);
	
	WriteIniFile("Config.ini", "SelGate", "GatePort", "%d", nPort4+nZone-1);

	WriteIniFile("Config.ini", "LoginServer", "GatePort", "%d", nPort8+nZone-1);
	WriteIniFile("Config.ini", "LoginServer", "ServerPort", "%d", nPort7+nZone-1);
	WriteIniFile("Config.ini", "LoginServer", "MonPort", "%d", nPort11+nZone-1);
	WriteIniFile("Config.ini", "LoginServer", "RunPort", "%d", nPort14+nZone-1);

	WriteIniFile("Config.ini", "DBServer", "GatePort", "%d", nPort6+nZone-1);
	WriteIniFile("Config.ini", "DBServer", "ServerPort", "%d", nPort10+nZone-1);
	std::cout<<"处理完毕!"<<std::endl;
	system("pause");
	return 0;
}

