#pragma once

/*
	EDUCATIONAL PURPOSES ONLY!!!
	DO NOT USE IT FOR HARM
*/


#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#pragma comment(lib, "winmm.lib")



#include "windows.h"
#include "resource.h"


//#define MUSIC_PATH "C:\\Users\\R\source\repos\MBR-Eater\music.wav"
#define _CRT_SECURE_NO_WARNINGS
#define MBR_SIZE 512


HBRUSH hbrBackgroundBrush = nullptr;


int CALLBACK wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR szCmdLine, int nCmdShow);