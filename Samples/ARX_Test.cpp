
// G910_SAMPLE.cpp : Defines the class behaviors for the application.
//
#include <iostream>
#include <ostream>
#include <string>

#pragma comment(lib, "LogitechGArxControlLib.lib")
#include <stdio.h>
#include <stdlib.h>
#include "LogitechGArxControlLib.h" 
#include <windows.h>
#include <time.h>

using namespace std;

void onCallback(int eventType, int eventValue, wchar_t * eventArg, void *context);
void OutputDebugStringAndErrorCode(wchar_t *string);


int main()
{
	logiArxCbContext callbackStruct;
	
	callbackStruct.arxContext = GetCurrentProcess();
	callbackStruct.arxCallBack = (logiArxCb)onCallback;

	if( !LogiArxInit(L"com.test", L"hello arx", &callbackStruct) )
	{
		OutputDebugStringAndErrorCode(L"Could not initialize ARX Control SDK");
		return -1;
	}
	std::cout<<"Logi Arx initialize successful" << std::endl;

	//make sure Resources/index.html and application is in same directory
	if( !LogiArxAddFileAs(L"Resources/index.html",L"index.html",L"text/html") )
	{
		OutputDebugStringAndErrorCode(L"Could not send file");
		return -1;
	}

	if( !LogiArxSetIndex(L"index.html") )
	{
		OutputDebugStringAndErrorCode(L"Could not set index");		
	}
	cout << "Press Any Key To Exit...";
	getchar();
	

	LogiArxShutdown();
}

void OutputDebugStringAndErrorCode(wchar_t *string)
{
	int lastError = LogiArxGetLastError();
	wchar_t debStr[128];
	wchar_t errorStr[128];
	switch(lastError)
	{
	case 0: 
		{
			wsprintf(errorStr,L"SUCCESS");
		}
		break;
	case 1:
		{
			wsprintf(errorStr,L"WRONG PARAMETER FORMAT");
		}
		break;
	case 2:
		{
			wsprintf(errorStr,L"NULL PARAMETER NOT SUPPORTED");
		}
		break;
	case 3:
		{
			wsprintf(errorStr,L"WRONG FILEPATH");
		}
		break;
	case 4:
		{
			wsprintf(errorStr,L"SDK NOT INITIALIZED");
		}
		break;
	case 5:
		{
			wsprintf(errorStr,L"SDK ALREADY INITIALIZED");
		}
		break;
	case 6:
		{
			wsprintf(errorStr,L"CONNECTION WITH LGS BROKEN");
		}
		break;
	case 7:
		{
			wsprintf(errorStr,L"COULDN'T CREATE WORKER THREAD");
		}
		break;
	case 8:
		{
			wsprintf(errorStr,L"MEMORY COPY FAIL");
		}
		break;
	default:
		{
			wsprintf(errorStr,L"UNKOWN ERROR");
		}
		break;
	}
	wsprintf(debStr, L"%ls with error : %d ( %ls )\n",string, lastError, errorStr);
	wcout << debStr << endl;
	OutputDebugString(debStr);

}

void onCallback(int eventType, int eventValue, wchar_t * eventArg, void *context)
{
	printf( "\n[Arx] callback called with: event_type=%d, event_value=%d, event_arg=%S\n",
        eventType, eventValue, eventArg);
	
	switch(eventType)
	{

	case  LOGI_ARX_EVENT_FOCUS_INACTIVE:
		{
			OutputDebugString(L"applet focus inactive \n");
			wcout << L"applet focus inactive"<< endl;
			
		}
		break;

	case  LOGI_ARX_EVENT_FOCUS_ACTIVE:
		{
			if(eventValue == LOGI_ARX_ORIENTATION_PORTRAIT)
			{
				OutputDebugString(L"applet focus active in portrait mode\n");
				wcout << L"applet focus active in portrait mode"<< endl;
			}
			if(eventValue == LOGI_ARX_ORIENTATION_LANDSCAPE)
			{
				OutputDebugString(L"applet focus active in landscape mode\n");
				wcout << L"applet focus active in landscape mode"<< endl;

			}
			break;
		}

	case  LOGI_ARX_EVENT_MOBILEDEVICE_ARRIVAL:
		{
			OutputDebugString(L"mobile device arrival\n");
			wcout << L"mobile device arrival"<< endl;
			break;
		}

	case  LOGI_ARX_EVENT_MOBILEDEVICE_REMOVAL:
		{
			OutputDebugString(L"mobile device removal\n");
			wcout << L"mobile device removal"<< endl;
			break;
		}
	case  LOGI_ARX_EVENT_TAP_ON_TAG:
		{	
			OutputDebugString(L"click on tag with id : ");
			if(eventArg)
			{			
				wcout << L"User Tapped on tag with id :"<< eventArg << endl;
				OutputDebugString(eventArg);
				OutputDebugString(L"\n");

			}
			else
			{
				wcout << L"User Tapped on tag with id NULL"<< endl;
				OutputDebugString(L"NULL\n");
			}
			break;
		}

	default:
		printf("unknown message %d:%d", eventType, eventValue);
		break;
	}
}