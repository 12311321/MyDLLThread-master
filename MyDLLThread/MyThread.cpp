#include "pch.h"
#include "SV_Country.h"
#include "MyThread.h"
#include <json/json.h>
#include <thread>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

bool thread_exit = false;
bool thread_run = false;
bool isInit = false;

SV_Country* KOR;
std::string jsonDocument;
Json::Value root;
Json::StreamWriterBuilder wbuilder;

void SV_WriteJson();

//thread 실행 함수
//수정
void SV_Run()
{
	std::cout << "SV_Run()" << std::endl;
	thread_run = true;

	while (!thread_exit)
	{
		Sleep(2000);
		KOR->CollectTaxes();
		//KOR->PrintState();
		SV_WriteJson();
	}
}

void SV_WriteJson()
{
	//ofstream outFile;
	//outFile.open("test.json", ios::out);
	//if(!outFile.is_open()){
	//	cout << "file has failed open." << endl;
	//	return ;
	//}
	//cout << "file out." << endl;
	root["name"] = KOR->name;
	root["budget"] = KOR->budget;
	root["gdp"] = KOR->gdp;
	root["taxRate"] = KOR->taxRate;
	root["policyCost"] = KOR->policyCost;
	jsonDocument = Json::writeString(wbuilder, root);
	//std::cout << jsonDocument << std::endl;
	//outFile << jsonDocument;
	//outFile.close();
}

void SV_Interface_InitGame()
{
	std::cout << "SV_Interface_InitGame()" << std::endl;
	//SV_WriteJson();

	KOR = new SV_Country();
	thread_exit = false;
	thread_run = false;
	isInit = true;
}

void SV_Interface_PlayGame()
{
	if (!isInit)
		return;

	if (thread_run) 
		return;
	
//	std::cout << "SV_Interface_PlayGame()" << std::endl;

	std::thread model(SV_Run);
	model.detach();	
}
LPCTSTR SV_Interface_GetData()
{
//	std::cout << "SV_Interface_GetData()" << std::endl;
	SV_WriteJson();

	return (LPCTSTR)jsonDocument.c_str();
}


LPCTSTR SV_Interface_EnforcePolicy()
{
//	std::cout << "SV_Interface_EnforcePolicy()" << std::endl;

	if (!isInit)
		return nullptr;
	if (!thread_run)
		return nullptr;
	
	KOR->EnforcePolicy();

	return SV_Interface_GetData();
}



void SV_Interface_EndGame()
{
//	std::cout << "SV_Interface_EndGame()" << std::endl;

	thread_exit = true;
}
