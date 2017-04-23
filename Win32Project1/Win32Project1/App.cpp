
#include<Windows.h>
#include<tchar.h>
#include"resource.h"

#define MAX_PASSWORD 50

/* �Ի�����Ϣ���������� */
LRESULT CALLBACK DialogFunc(
	HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam
);

/* ������֤���� */
void VerifyPassword(
	HWND hDlg
);

/* WinMain���� */
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd
)
{
	MSG msg;
	HWND hWnd = CreateDialog( // ����Դ�д����Ի���
		hInstance,
		MAKEINTRESOURCE(IDD_DIALOG1),
		NULL,
		(DLGPROC)DialogFunc);
	ShowWindow(hWnd, SW_SHOWNORMAL); // ��ʾ�Ի���
	while (GetMessage(&msg, NULL, 0, 0)) // ��Ϣ����ѭ��
	{
		if (!IsDialogMessage(hWnd, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return 0;
}


/* ���ڴ����� */
LRESULT CALLBACK DialogFunc(
	HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam
)
{
	switch (message)
	{
	case WM_COMMAND: // ������Ϣ
		switch (LOWORD(wParam)) // wParam�ĵ�λ��ʾ�ؼ�ID
		{
		case IDC_BUTTON1: // ��֤��ť
			VerifyPassword(hWnd);
			break;
		}
		break;
	case WM_CLOSE: // ����ر���Ϣ
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY: // ����������Ϣ
		PostQuitMessage(0);
		break;
	}
	return FALSE;
}

/* У����������� */
void VerifyPassword(
	HWND hDlg
)
{
	TCHAR lpString[MAX_PASSWORD] = TEXT("");
	TCHAR lpRightPassword[MAX_PASSWORD] = TEXT("abc123"); // ��ȷ������

	GetDlgItemTextW(hDlg, IDC_EDIT_PASSWORD, lpString, MAX_PASSWORD); // ��ȡ�༭���ֵ
	if (0 == _tcscmp( // �Ƚϱ༭���е��������ȷ����
		lpString,
		lpRightPassword))
	{
		MessageBox(NULL, TEXT("��ϲ�㣬������ȷ��"), TEXT("��Ϣ"), MB_OK);
	}
	else
	{
		MessageBox(NULL, TEXT("��������ټӰѾ���"), TEXT("��Ϣ"), MB_OK);
	}
}
