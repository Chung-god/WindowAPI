//To get Divice context
//Code by HyunChung Park

#include <Windows.h>
#include <TCHAR.H>
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow) {
	HWND hwnd;
	MSG msg;
	WNDCLASS wndclass;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = _T("Window Class Name");
	RegisterClass(&wndclass);
	hwnd = CreateWindow(_T("Window Class Name"),
		_T("HyunChung Window"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	HDC hdc;//HDC Type manages memory section and can store attribute value about display section from memory section
	PAINTSTRUCT ps;//structure to store information about output section
	RECT rect;

	switch (iMsg)
	{
	case WM_CREATE://run when it is made window first 
		break;
	case WM_PAINT://run when window show
		hdc = BeginPaint(hwnd, &ps);
		rect.left = 50;//X1
		rect.top = 40;//Y1
		rect.right = 200;//X2
		rect.bottom = 120;//Y2
		DrawText(hdc, _T("HelloWorld"), 10, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		TextOut(hdc, 100, 100, _T("Hello �ȳ�"), _tcslen(_T("Hello �ȳ�")));
		EndPaint(hwnd, &ps); // you must call this if you call BeginPaint function
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

