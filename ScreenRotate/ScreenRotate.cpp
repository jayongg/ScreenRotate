// ScreenRotate.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	DEVMODE devmode = { 0 };
	devmode.dmSize = sizeof(devmode);
	if (!EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devmode))
		return -1;

	LPCTSTR pszCurrent = L"TBD";

	// increment the orientation
	// determine new orientaion
	switch (devmode.dmDisplayOrientation)
	{
	case DMDO_DEFAULT:
		pszCurrent = L"default";
		devmode.dmDisplayOrientation = DMDO_270;
		break;
	case DMDO_270:
		pszCurrent = L"270";
		devmode.dmDisplayOrientation = DMDO_180;
		break;
	case DMDO_180:
		pszCurrent = L"180";
		devmode.dmDisplayOrientation = DMDO_90;
		break;
	case DMDO_90:
		pszCurrent = L"90";
		devmode.dmDisplayOrientation = DMDO_DEFAULT;
		break;
	default:
		// unknown orientation value
		// add exception handling here
		break;
	}

	OutputDebugString(pszCurrent);
	DWORD dwValue = devmode.dmPelsWidth;
	devmode.dmPelsWidth = devmode.dmPelsHeight;
	devmode.dmPelsHeight = dwValue;

	LONG result = ChangeDisplaySettings(&devmode, 0);
	
	return 0;
}


