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

	// increment the orientation
	// determine new orientaion
	switch (devmode.dmDisplayOrientation)
	{
	case DMDO_DEFAULT:
		devmode.dmDisplayOrientation = DMDO_270;
		break;
	case DMDO_270:
		devmode.dmDisplayOrientation = DMDO_180;
		break;
	case DMDO_180:
		devmode.dmDisplayOrientation = DMDO_90;
		break;
	case DMDO_90:
		devmode.dmDisplayOrientation = DMDO_DEFAULT;
		break;
	default:
		// unknown orientation value
		// add exception handling here
		break;
	}

	LONG result = ChangeDisplaySettings(&devmode, 0);
	
	return 0;
}


