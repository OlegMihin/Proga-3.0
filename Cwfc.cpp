#include "pch.h"
#include "Cwfc.h"
#include <Windows.h>
#include "resource.h"

void DrowFrame(CDC* odc) 
 {

}

HINSTANCE hInst;
HBITMAP hBitmap;
HWND hPic;

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
  {
	  hInst = hInstance
	  DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (DlgProc), 0);
	  return 0;
  }

BOOL CALLBACK DlgProc(HWND hwmd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
 switch (uMsg) 
 {
	 case WM_INITDIALOG: 
	 hBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
	 if (hBitmap == NULL)
	 {
		 MessageBox(hwnd, "Not Picture", "ERROR", NULL);
		 break;
	 }
	 hPic = GetDlgItem(HWND, IDC_PICTURE);
	 break;
	 case WM_COMMAND:
	  {
		  switch (LOWORD(wParam))
		  {
		  case IDOK:
		  {

		  }
			  break;
		  }
	  }
		  break;
	  case IDCANCEL:
	  {
		  EndDialog(hwmd, 0);
		  return TRUE;
	  }
	  break;
	  case WM_PAINT:
	  {
		  BITMAP bm;
		  PAINTSTRUCT ps;

		  HDC hdc = BeginPaint(hPic, &ps);
		  HDC hdcMem = CreateCompatibleDC(hdc);
		  HGDIOBJ hbmOld = SelectObject(hdcMem, hBitmap);
		  GetObject(hBitmap, sizeof(bm), &bm);
		  BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
		  SelectObject(hdcMem, hbmOld);
		  DeleteDC(hdcMem);
		  EndPaint(hPic, &ps);
	  }
	  break;
	  case WM_CLOSE:
	  {
		  EndDialog(hwnd, 0);
		  return TRUE;
	  }
	  break;
 }
 return FALSE;
 }

