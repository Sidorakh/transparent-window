// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "wingdi.h"
#include "winuser.h"

#define dllx extern "C" __declspec(dllexport)

dllx double set_color_key(void* hwnd_ptr, double red, double green, double blue) {
	HWND hwnd = (HWND)hwnd_ptr;
	long flags = GetWindowLongPtr(hwnd, GWL_EXSTYLE);
	flags |= WS_EX_LAYERED;
	SetWindowLongPtr(hwnd, GWL_EXSTYLE, flags);
	bool result = SetLayeredWindowAttributes(hwnd, RGB((int)red, (int)green, (int)blue), 255, LWA_COLORKEY);
	//HDC hdc = CreateCompatibleDC(NULL);
	//BLENDFUNCTION blend = { AC_SRC_OVER,0,255,AC_SRC_ALPHA };
	//bool result = UpdateLayeredWindow(hwnd, NULL, NULL, NULL, hdc, NULL, RGB(red, green, blue), &blend, ULW_ALPHA);
	if (result == true) {
		return 0;
	}
	return GetLastError();
}

dllx double get_error() {
	DWORD err = GetLastError();
	return (double) err;
}