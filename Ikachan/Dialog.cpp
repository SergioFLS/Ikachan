#include "Dialog.h"
#include "System.h"
#include <stdio.h>
#include <string.h>

//Options
struct OPTION
{
	int garbage; //unused and not written to
	int wnd_size;
};

const char* gOptionName = "Option.bin";

bool SaveOption(OPTION *option)
{
	//Open option file
	char path[MAX_PATH];
	sprintf(path, "%s/%s", gModulePath, gOptionName);

	FILE *fp = fopen(path, "wb");
	if (fp == NULL)
		return false;

	//Write options
	fwrite(option, sizeof(OPTION), 1, fp);
	fclose(fp);
	return true;
}

bool LoadOption(OPTION *option)
{
	//Clear option struct
	memset(option, 0, sizeof(OPTION));

	//Open option file
	char path[MAX_PATH];
	sprintf(path, "%s/%s", gModulePath, gOptionName);

	FILE *fp = fopen(path, "rb");
	if (fp == NULL)
		return false;

	//Read options
	fread(option, sizeof(OPTION), 1, fp);
	fclose(fp);
	return true;
}

#if 0
//Dialog functions
void InitDialog(HWND hDlg)
{
	//Window size labels
	const char* size_names[3] = {
		"\x83\x74\x83\x8B\x83\x58\x83\x4E\x83\x8A\x81\x5B\x83\x93",
		"\x83\x45\x83\x43\x83\x93\x83\x68\x83\x45\x33\x32\x30\x78\x32\x34\x30",
		"\x83\x45\x83\x43\x83\x93\x83\x68\x83\x45\x36\x34\x30\x2A\x34\x38\x30",
	};

	//Insert window sizes to size selector
	for (int i = 0; i < 3; i++)
		SendDlgItemMessage(hDlg, 1003, CB_ADDSTRING, 0, (LPARAM)size_names[i]);

	//Read options
	OPTION option;
	if (!LoadOption(&option))
	{
		//Default options
		option.wnd_size = WS_FULLSCREEN;
	}

	//Select options initially on dialog
	SendDlgItemMessage(hDlg, 1003, CB_SETCURSEL, (WPARAM)option.wnd_size, 0);
}

void UseDialog(HWND hDlg)
{
	//Set properties from dialog
	gWndSize = (WND_SIZE)SendDlgItemMessage(hDlg, 1003, CB_GETCURSEL, 2, 0);

	//Write options
	OPTION option;
	option.wnd_size = (int)gWndSize;
	SaveOption(&option);
}
#endif

#if 0
INT_PTR CALLBACK DlgProc(HWND hDlg, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
		case WM_INITDIALOG:
			InitDialog(hDlg);
			break;
		case WM_COMMAND:
			switch (wParam)
			{
				case 2:
					EndDialog(hDlg, 0);
					break;
				case 1:
					UseDialog(hDlg);
					EndDialog(hDlg, 1);
					break;
			}
		default:
			return false;
	}
	return true;
}
#endif