#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>


#define ID_TIMER_1 1
#define ID_TIMER_2 2
#define ID_TIMER_3 3
#define ID_TIMER_4 4
#define ID_TIMER_5 5
#define ID_TIMER_6 6
#define ID_TIMER_7 7
#define ID_TIMER_8 8
#define ID_TIMER_9 9


static TCHAR szMainWindowClass[] = _T("MainWindowClass");
static TCHAR szFirstChildWindowClass[] = _T("FirstChildWindowClass");
static TCHAR szSecondChildWindowClass[] = _T("SecondChildWindowClass");
static TCHAR szThirdChildWindowClass[] = _T("ThirdChildWindowClass");
static TCHAR szFourthChildWindowClass[] = _T("FourthChildWindowClass");
static TCHAR szFifthChildWindowClass[] = _T("FifthChildWindowClass");
static TCHAR szSixthChildWindowClass[] = _T("SixthChildWindowClass");
static TCHAR szSeventhChildWindowClass[] = _T("SeventhChildWindowClass");
static TCHAR szEighthChildWindowClass[] = _T("EighthChildWindowClass");
static TCHAR szNinthChildWindowClass[] = _T("NinthChildWindowClass");


static TCHAR szMainWindowTitle[] = _T("MainWindow");
static TCHAR szFirstChildTitle[] = _T("First Child Window");
static TCHAR szSecondChildTitle[] = _T("Second Child Window");
static TCHAR szThirdChildTitle[] = _T("Third Child Window");
static TCHAR szFourthChildTitle[] = _T("Fourth Child Window");
static TCHAR szFifthChildTitle[] = _T("Fifth Child Window");
static TCHAR szSixthChildTitle[] = _T("Sixth Child Window");
static TCHAR szSeventhChildTitle[] = _T("Seventh Child Window");
static TCHAR szEighthChildTitle[] = _T("Eighth Child Window");
static TCHAR szNinthChildTitle[] = _T("Ninth Child Window");


HINSTANCE hInst;


UINT uFirstDeltaTime = 1000;

BOOL bControlFlag = false;

HWND hWndFirstChild;
HWND hWndSecondChild;
HWND hWndThirdChild;
HWND hWndFourthChild;
HWND hWndFifthChild;
HWND hWndSixthChild;
HWND hWndSeventhChild;
HWND hWndEighthChild;
HWND hWndNinthChild;

HBRUSH brush = NULL;


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProcChild(HWND, UINT, WPARAM, LPARAM);


int CALLBACK WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szMainWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    hInst = hInstance;

    HWND hWnd = CreateWindow(
        szMainWindowClass,
        szMainWindowTitle,
        WS_OVERLAPPEDWINDOW,
        0, 0,
        700, 500,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Windows Desktop Guided Tour"),
            NULL);

        return 1;
    }

    ShowWindow(hWnd,
        nCmdShow);
    UpdateWindow(hWnd);

    SetTimer(hWnd, ID_TIMER_1, uFirstDeltaTime, NULL);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_TIMER:
        switch (wParam) {
        case ID_TIMER_1: {

            KillTimer(hWnd, ID_TIMER_1);

            WNDCLASSEX wcexFirstChild;

            wcexFirstChild.cbSize = sizeof(WNDCLASSEX);
            wcexFirstChild.style = CS_HREDRAW | CS_VREDRAW;
            wcexFirstChild.lpfnWndProc = WndProcChild;
            wcexFirstChild.cbClsExtra = 0;
            wcexFirstChild.cbWndExtra = 0;
            wcexFirstChild.hInstance = hInst;
            wcexFirstChild.hIcon = LoadIcon(hInst, IDI_APPLICATION);
            wcexFirstChild.hCursor = LoadCursor(NULL, IDC_ARROW);
            wcexFirstChild.hbrBackground = CreateSolidBrush(RGB(204, 255, 204));
            wcexFirstChild.lpszMenuName = NULL;
            wcexFirstChild.lpszClassName = szFirstChildWindowClass;
            wcexFirstChild.hIconSm = LoadIcon(wcexFirstChild.hInstance, IDI_APPLICATION);

            if (!RegisterClassEx(&wcexFirstChild))
            {
                MessageBox(NULL,
                    _T("Call to RegisterClassEx failed! (wcexFirstChild)"),
                    _T("Windows Desktop Guided Tour"),
                    NULL);

                return 1;
            }


            hWndFirstChild = CreateWindow(
                szFirstChildWindowClass,
                szFirstChildTitle,
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                50, 100,
                200, 100,
                hWnd,
                NULL,
                hInst,
                NULL
            );

            if (!hWndFirstChild)
            {
                MessageBox(NULL,
                    _T("Call to CreateWindow failed! (hWndFirstChild)"),
                    _T("Windows Desktop Guided Tour"),
                    NULL);

                return 1;
            }

            CreateWindow(TEXT("STATIC"), TEXT("1"),
                WS_VISIBLE | WS_CHILD,
                0, 0, 20, 20,
                hWndFirstChild, (HMENU)NULL, NULL, NULL);

            SetParent(hWndFirstChild, hWnd);

            SetTimer(hWnd, ID_TIMER_2, uFirstDeltaTime, NULL);

            break;
        }
        case ID_TIMER_2: {

            KillTimer(hWnd, ID_TIMER_2);

            WNDCLASSEX wcexSecondChild;

            wcexSecondChild.cbSize = sizeof(WNDCLASSEX);
            wcexSecondChild.style = CS_HREDRAW | CS_VREDRAW;
            wcexSecondChild.lpfnWndProc = WndProcChild;
            wcexSecondChild.cbClsExtra = 0;
            wcexSecondChild.cbWndExtra = 0;
            wcexSecondChild.hInstance = hInst;
            wcexSecondChild.hIcon = LoadIcon(hInst, IDI_APPLICATION);
            wcexSecondChild.hCursor = LoadCursor(NULL, IDC_ARROW);
            wcexSecondChild.hbrBackground = CreateSolidBrush(RGB(204, 255, 204));
            wcexSecondChild.lpszMenuName = NULL;
            wcexSecondChild.lpszClassName = szSecondChildWindowClass;
            wcexSecondChild.hIconSm = LoadIcon(wcexSecondChild.hInstance, IDI_APPLICATION);

            if (!RegisterClassEx(&wcexSecondChild))
            {
                MessageBox(NULL,
                    _T("Call to RegisterClassEx failed! (wcexSecondChild)"),
                    _T("Windows Desktop Guided Tour"),
                    NULL);

                return 1;
            }


            hWndSecondChild = CreateWindow(
                szSecondChildWindowClass,
                szSecondChildTitle,
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                250, 100,
                200, 100,
                hWnd,
                NULL,
                hInst,
                NULL
            );

            if (!hWndSecondChild)
            {
                MessageBox(NULL,
                    _T("Call to CreateWindow failed! (hWndSecondChild)"),
                    _T("Windows Desktop Guided Tour"),
                    NULL);

                return 1;
            }

            CreateWindow(TEXT("STATIC"), TEXT("2"),
                WS_VISIBLE | WS_CHILD,
                0, 0, 20, 20,
                hWndSecondChild, (HMENU)NULL, NULL, NULL);

            SetParent(hWndSecondChild, hWnd);

            SetTimer(hWnd, ID_TIMER_3, uFirstDeltaTime, NULL);

            break;
        }
        case ID_TIMER_3: {

            KillTimer(hWnd, ID_TIMER_3);

            WNDCLASSEX wcexThirdChild;

            wcexThirdChild.cbSize = sizeof(WNDCLASSEX);
            wcexThirdChild.style = CS_HREDRAW | CS_VREDRAW;
            wcexThirdChild.lpfnWndProc = WndProcChild;
            wcexThirdChild.cbClsExtra = 0;
            wcexThirdChild.cbWndExtra = 0;
            wcexThirdChild.hInstance = hInst;
            wcexThirdChild.hIcon = LoadIcon(hInst, IDI_APPLICATION);
            wcexThirdChild.hCursor = LoadCursor(NULL, IDC_ARROW);
            wcexThirdChild.hbrBackground = CreateSolidBrush(RGB(204, 255, 204));
            wcexThirdChild.lpszMenuName = NULL;
            wcexThirdChild.lpszClassName = szThirdChildWindowClass;
            wcexThirdChild.hIconSm = LoadIcon(wcexThirdChild.hInstance, IDI_APPLICATION);

            if (!RegisterClassEx(&wcexThirdChild))
            {
                MessageBox(NULL,
                    _T("Call to RegisterClassEx failed! (wcexThirdChild)"),
                    _T("Windows Desktop Guided Tour"),
                    NULL);

                return 1;
            }


            hWndThirdChild = CreateWindow(
                szThirdChildWindowClass,
                szThirdChildTitle,
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                450, 100,
                200, 100,
                hWnd,
                NULL,
                hInst,
                NULL
            );

            if (!hWndThirdChild)
            {
                MessageBox(NULL,
                    _T("Call to CreateWindow failed! (hWndThirdChild)"),
                    _T("Windows Desktop Guided Tour"),
                    NULL);

                return 1;
            }

            CreateWindow(TEXT("STATIC"), TEXT("3"),
                WS_VISIBLE | WS_CHILD,
                0, 0, 20, 20,
                hWndThirdChild, (HMENU)NULL, NULL, NULL);

            SetParent(hWndThirdChild, hWnd);

            SetTimer(hWnd, ID_TIMER_4, uFirstDeltaTime, NULL);

            break;
        }
        case ID_TIMER_4: {
            KillTimer(hWnd, ID_TIMER_4);

            WNDCLASSEX wcexFourthChild;

            wcexFourthChild.cbSize = sizeof(WNDCLASSEX);
            wcexFourthChild.style = CS_HREDRAW | CS_VREDRAW;
            wcexFourthChild.lpfnWndProc = WndProcChild;
            wcexFourthChild.cbClsExtra = 0;
            wcexFourthChild.cbWndExtra = 0;
            wcexFourthChild.hInstance = hInst;
            wcexFourthChild.hIcon = LoadIcon(hInst, IDI_APPLICATION);
            wcexFourthChild.hCursor = LoadCursor(NULL, IDC_ARROW);
            wcexFourthChild.hbrBackground = CreateSolidBrush(RGB(204, 255, 204));
            wcexFourthChild.lpszMenuName = NULL;
            wcexFourthChild.lpszClassName = szFourthChildWindowClass;
            wcexFourthChild.hIconSm = LoadIcon(wcexFourthChild.hInstance, IDI_APPLICATION);

            if (!RegisterClassEx(&wcexFourthChild))
            {
                MessageBox(NULL,
                    _T("Call to RegisterClassEx failed! (wcexFourthChild)"),
                    _T("Windows Desktop Guided Tour"),
                    NULL);

                return 1;
            }


            hWndFourthChild = CreateWindow(
                szFourthChildWindowClass,
                szFourthChildTitle,
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                50, 200,
                200, 100,
                hWnd,
                NULL,
                hInst,
                NULL
            );

            if (!hWndFourthChild)
            {
                MessageBox(NULL,
                    _T("Call to CreateWindow failed! (hWndFourthChild)"),
                    _T("Windows Desktop Guided Tour"),
                    NULL);

                return 1;
            }

            CreateWindow(TEXT("STATIC"), TEXT("4"),
                WS_VISIBLE | WS_CHILD,
                0, 0, 20, 20,
                hWndFourthChild, (HMENU)NULL, NULL, NULL);

            SetParent(hWndFourthChild, hWnd);

            SetTimer(hWnd, ID_TIMER_5, uFirstDeltaTime, NULL);

            break;
        }
        case ID_TIMER_5: {

            KillTimer(hWnd, ID_TIMER_5);

            WNDCLASSEX wcexFifthChild;

            wcexFifthChild.cbSize = sizeof(WNDCLASSEX);
            wcexFifthChild.style = CS_HREDRAW | CS_VREDRAW;
            wcexFifthChild.lpfnWndProc = WndProcChild;
            wcexFifthChild.cbClsExtra = 0;
            wcexFifthChild.cbWndExtra = 0;
            wcexFifthChild.hInstance = hInst;
            wcexFifthChild.hIcon = LoadIcon(hInst, IDI_APPLICATION);
            wcexFifthChild.hCursor = LoadCursor(NULL, IDC_ARROW);
            wcexFifthChild.hbrBackground = CreateSolidBrush(RGB(204, 255, 204));
            wcexFifthChild.lpszMenuName = NULL;
            wcexFifthChild.lpszClassName = szFifthChildWindowClass;
            wcexFifthChild.hIconSm = LoadIcon(wcexFifthChild.hInstance, IDI_APPLICATION);

            if (!RegisterClassEx(&wcexFifthChild))
            {
                MessageBox(NULL,
                    _T("Call to RegisterClassEx failed! (wcexFifthChild)"),
                    _T("Windows Desktop Guided Tour"),
                    NULL);

                return 1;
            }


            hWndFifthChild = CreateWindow(
                szFifthChildWindowClass,
                szFifthChildTitle,
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                250, 200,
                200, 100,
                hWnd,
                NULL,
                hInst,
                NULL
            );

            if (!hWndFifthChild)
            {
                MessageBox(NULL,
                    _T("Call to CreateWindow failed! (hWndFifthChild)"),
                    _T("Windows Desktop Guided Tour"),
                    NULL);

                return 1;
            }

            CreateWindow(TEXT("STATIC"), TEXT("5"),
                WS_VISIBLE | WS_CHILD,
                0, 0, 20, 20,
                hWndFifthChild, (HMENU)NULL, NULL, NULL);

            SetParent(hWndFifthChild, hWnd);

            SetTimer(hWnd, ID_TIMER_6, uFirstDeltaTime, NULL);

            break;
        }
        case ID_TIMER_6: {

            KillTimer(hWnd, ID_TIMER_6);

            WNDCLASSEX wcexSixthChild;

            wcexSixthChild.cbSize = sizeof(WNDCLASSEX);
            wcexSixthChild.style = CS_HREDRAW | CS_VREDRAW;
            wcexSixthChild.lpfnWndProc = WndProcChild;
            wcexSixthChild.cbClsExtra = 0;
            wcexSixthChild.cbWndExtra = 0;
            wcexSixthChild.hInstance = hInst;
            wcexSixthChild.hIcon = LoadIcon(hInst, IDI_APPLICATION);
            wcexSixthChild.hCursor = LoadCursor(NULL, IDC_ARROW);
            wcexSixthChild.hbrBackground = CreateSolidBrush(RGB(204, 255, 204));
            wcexSixthChild.lpszMenuName = NULL;
            wcexSixthChild.lpszClassName = szSixthChildWindowClass;
            wcexSixthChild.hIconSm = LoadIcon(wcexSixthChild.hInstance, IDI_APPLICATION);

            if (!RegisterClassEx(&wcexSixthChild))
            {
                MessageBox(NULL,
                    _T("Call to RegisterClassEx failed! (wcexSixthChild)"),
                    _T("Windows Desktop Guided Tour"),
                    NULL);

                return 1;
            }


            hWndSixthChild = CreateWindow(
                szSixthChildWindowClass,
                szSixthChildTitle,
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                450, 200,
                200, 100,
                hWnd,
                NULL,
                hInst,
                NULL
            );

            if (!hWndSixthChild)
            {
                MessageBox(NULL,
                    _T("Call to CreateWindow failed! (hWndSixthChild)"),
                    _T("Windows Desktop Guided Tour"),
                    NULL);

                return 1;
            }

            CreateWindow(TEXT("STATIC"), TEXT("6"),
                WS_VISIBLE | WS_CHILD,
                0, 0, 20, 20,
                hWndSixthChild, (HMENU)NULL, NULL, NULL);

            SetParent(hWndSixthChild, hWnd);

            SetTimer(hWnd, ID_TIMER_7, uFirstDeltaTime, NULL);

            break;
        }
        case ID_TIMER_7: {

            KillTimer(hWnd, ID_TIMER_7);

            WNDCLASSEX wcexSeventhChild;

            wcexSeventhChild.cbSize = sizeof(WNDCLASSEX);
            wcexSeventhChild.style = CS_HREDRAW | CS_VREDRAW;
            wcexSeventhChild.lpfnWndProc = WndProcChild;
            wcexSeventhChild.cbClsExtra = 0;
            wcexSeventhChild.cbWndExtra = 0;
            wcexSeventhChild.hInstance = hInst;
            wcexSeventhChild.hIcon = LoadIcon(hInst, IDI_APPLICATION);
            wcexSeventhChild.hCursor = LoadCursor(NULL, IDC_ARROW);
            wcexSeventhChild.hbrBackground = CreateSolidBrush(RGB(204, 255, 204));
            wcexSeventhChild.lpszMenuName = NULL;
            wcexSeventhChild.lpszClassName = szSeventhChildWindowClass;
            wcexSeventhChild.hIconSm = LoadIcon(wcexSeventhChild.hInstance, IDI_APPLICATION);

            if (!RegisterClassEx(&wcexSeventhChild))
            {
                MessageBox(NULL,
                    _T("Call to RegisterClassEx failed! (wcexSeventhChild)"),
                    _T("Windows Desktop Guided Tour"),
                    NULL);

                return 1;
            }


            hWndSeventhChild = CreateWindow(
                szSeventhChildWindowClass,
                szSeventhChildTitle,
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                50, 300,
                200, 100,
                hWnd,
                NULL,
                hInst,
                NULL
            );

            if (!hWndSeventhChild)
            {
                MessageBox(NULL,
                    _T("Call to CreateWindow failed! (hWndSeventhChild)"),
                    _T("Windows Desktop Guided Tour"),
                    NULL);

                return 1;
            }

            CreateWindow(TEXT("STATIC"), TEXT("7"),
                WS_VISIBLE | WS_CHILD,
                0, 0, 20, 20,
                hWndSeventhChild, (HMENU)NULL, NULL, NULL);

            SetParent(hWndSeventhChild, hWnd);

            SetTimer(hWnd, ID_TIMER_8, uFirstDeltaTime, NULL);

            break;
        }
        case ID_TIMER_8: {

            KillTimer(hWnd, ID_TIMER_8);

            WNDCLASSEX wcexEighthChild;

            wcexEighthChild.cbSize = sizeof(WNDCLASSEX);
            wcexEighthChild.style = CS_HREDRAW | CS_VREDRAW;
            wcexEighthChild.lpfnWndProc = WndProcChild;
            wcexEighthChild.cbClsExtra = 0;
            wcexEighthChild.cbWndExtra = 0;
            wcexEighthChild.hInstance = hInst;
            wcexEighthChild.hIcon = LoadIcon(hInst, IDI_APPLICATION);
            wcexEighthChild.hCursor = LoadCursor(NULL, IDC_ARROW);
            wcexEighthChild.hbrBackground = CreateSolidBrush(RGB(204, 255, 204));
            wcexEighthChild.lpszMenuName = NULL;
            wcexEighthChild.lpszClassName = szEighthChildWindowClass;
            wcexEighthChild.hIconSm = LoadIcon(wcexEighthChild.hInstance, IDI_APPLICATION);

            if (!RegisterClassEx(&wcexEighthChild))
            {
                MessageBox(NULL,
                    _T("Call to RegisterClassEx failed! (wcexEighthChild)"),
                    _T("Windows Desktop Guided Tour"),
                    NULL);

                return 1;
            }


            hWndEighthChild = CreateWindow(
                szEighthChildWindowClass,
                szEighthChildTitle,
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                250, 300,
                200, 100,
                hWnd,
                NULL,
                hInst,
                NULL
            );

            if (!hWndEighthChild)
            {
                MessageBox(NULL,
                    _T("Call to CreateWindow failed! (hWndEighthChild)"),
                    _T("Windows Desktop Guided Tour"),
                    NULL);

                return 1;
            }

            CreateWindow(TEXT("STATIC"), TEXT("8"),
                WS_VISIBLE | WS_CHILD,
                0, 0, 20, 20,
                hWndEighthChild, (HMENU)NULL, NULL, NULL);

            SetParent(hWndEighthChild, hWnd);

            SetTimer(hWnd, ID_TIMER_9, uFirstDeltaTime, NULL);

            break;
        }
        case ID_TIMER_9: {

            KillTimer(hWnd, ID_TIMER_9);

            WNDCLASSEX wcexNinthChild;

            wcexNinthChild.cbSize = sizeof(WNDCLASSEX);
            wcexNinthChild.style = CS_HREDRAW | CS_VREDRAW;
            wcexNinthChild.lpfnWndProc = WndProcChild;
            wcexNinthChild.cbClsExtra = 0;
            wcexNinthChild.cbWndExtra = 0;
            wcexNinthChild.hInstance = hInst;
            wcexNinthChild.hIcon = LoadIcon(hInst, IDI_APPLICATION);
            wcexNinthChild.hCursor = LoadCursor(NULL, IDC_ARROW);
            wcexNinthChild.hbrBackground = CreateSolidBrush(RGB(204, 255, 204));
            wcexNinthChild.lpszMenuName = NULL;
            wcexNinthChild.lpszClassName = szNinthChildWindowClass;
            wcexNinthChild.hIconSm = LoadIcon(wcexNinthChild.hInstance, IDI_APPLICATION);

            if (!RegisterClassEx(&wcexNinthChild))
            {
                MessageBox(NULL,
                    _T("Call to RegisterClassEx failed! (wcexNinthChild)"),
                    _T("Windows Desktop Guided Tour"),
                    NULL);

                return 1;
            }


            hWndNinthChild = CreateWindow(
                szNinthChildWindowClass,
                szNinthChildTitle,
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                450, 300,
                200, 100,
                hWnd,
                NULL,
                hInst,
                NULL
            );

            if (!hWndNinthChild)
            {
                MessageBox(NULL,
                    _T("Call to CreateWindow failed! (hWndNinthChild)"),
                    _T("Windows Desktop Guided Tour"),
                    NULL);

                return 1;
            }

            CreateWindow(TEXT("STATIC"), TEXT("9"),
                WS_VISIBLE | WS_CHILD,
                0, 0, 20, 20,
                hWndNinthChild, (HMENU)NULL, NULL, NULL);

            SetParent(hWndNinthChild, hWnd);

            break;
        }
        default:
            break;
        }
        break;

    case WM_KEYDOWN:

        switch (wParam) {

        case VK_CONTROL:
            bControlFlag = true;
            break;

        case 0x31:      // 1
            if (bControlFlag) {
                SendMessage(hWndFirstChild, WM_CLOSE, 0, 0);
                bControlFlag = false;
            }
            break;

        case 0x32:      // 2
            if (bControlFlag) {
                SendMessage(hWndSecondChild, WM_CLOSE, 0, 0);
                bControlFlag = false;
            }
            break;

        case 0x33:      // 3
            if (bControlFlag) {
                SendMessage(hWndThirdChild, WM_CLOSE, 0, 0);
                bControlFlag = false;
            }
            break;

        case 0x34:      // 4
            if (bControlFlag) {
                SendMessage(hWndFourthChild, WM_CLOSE, 0, 0);
                bControlFlag = false;
            }
            break;
        case 0x35:      // 5
            if (bControlFlag) {
                SendMessage(hWndFifthChild, WM_CLOSE, 0, 0);
                bControlFlag = false;
            }
            break;

        case 0x36:      // 6
            if (bControlFlag) {
                SendMessage(hWndSixthChild, WM_CLOSE, 0, 0);
                bControlFlag = false;
            }
            break;

        case 0x37:      // 7
            if (bControlFlag) {
                SendMessage(hWndSeventhChild, WM_CLOSE, 0, 0);
                bControlFlag = false;
            }
            break;

        case 0x38:      // 8
            if (bControlFlag) {
                SendMessage(hWndEighthChild, WM_CLOSE, 0, 0);
                bControlFlag = false;
            }
            break;

        case 0x39:      // 9
            if (bControlFlag) {
                SendMessage(hWndNinthChild, WM_CLOSE, 0, 0);
                bControlFlag = false;
            }
            break;

        default:
            break;
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }

    return 0;
}




LRESULT CALLBACK WndProcChild(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_LBUTTONUP:
            SetClassLongPtr(hWnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(255, 255, 0)));
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        case WM_RBUTTONUP:
            SetClassLongPtr(hWnd, GCL_HBRBACKGROUND, (LONG)CreateSolidBrush(RGB(0, 0, 167)));
            InvalidateRect(hWnd, NULL, TRUE);
            break;

        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
            break;
    }

    return 0;
}