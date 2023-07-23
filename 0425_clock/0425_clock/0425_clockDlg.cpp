
// 0425_clockDlg.cpp: 實作檔案
//

#include "pch.h"
#include "framework.h"
#include "0425_clock.h"
#include "0425_clockDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy0425clockDlg 對話方塊



CMy0425clockDlg::CMy0425clockDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY0425_CLOCK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy0425clockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy0425clockDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy0425clockDlg::OnBnClickedButton1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMy0425clockDlg 訊息處理常式

BOOL CMy0425clockDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定

	//取得繪圖視窗代碼
	hdc = ::GetDC(m_hWnd);
	SetTimer(1234, 1000, 0);

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CMy0425clockDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CMy0425clockDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CMy0425clockDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMy0425clockDlg::line(int x1, int y1, int x2, int y2, int color, int w)
{
	//1.設定顏色color ,寬度w
	CPen p1(PS_SOLID, w, RGB((color >> 16) & 0xFF, (color >> 8) & 0xFF, (color >> 0) & 0xFF));
	//                    高位元                   中位元                  低位元
	SelectObject(hdc, p1);
	//2.畫線
	MoveToEx(hdc, x1, y1, 0);
	LineTo(hdc, x2, y2);
}

void CMy0425clockDlg::OnBnClickedButton1()
{
	//line(100, 100, 500, 500, 0x00FF, 20);
	//rect(100, 100, 500, 500, 0x00FF00, 5);
	
	// TODO: 在此加入控制項告知處理常式程式碼
	//1.取得時間
	int h, m, s;
	char s1[200];
	CTime T = CTime::GetCurrentTime();
	h = T.GetHour();
	m = T.GetMinute();
	s = T.GetSecond();
	sprintf_s(s1, 200, "%02d:%02d:%02d", h, m, s);
	SetWindowText(s1);

	//2. 繪出時鐘
	//2.1 外框
	int cx = 300, cy = 300;
	int r = 250;
	rect(cx - r, cy - r, cx + r, cy + r, 0xF0F0F0, 1, 1);
	circle(cx, cy, r, r, 0xAA, 10);

	//2.2 時分秒刻度
	int x1, y1, x2, y2, w;
	float r1,r2;
	for (int i = 0; i < 360; i += 6)
	{
		r1 = (float)i * 3.1415926 / 180;
		x1 = cx + (int)((float)r * cos(r1) * 0.95 + 0.5);
		y1 = cy + (int)((float)r * sin(r1) * 0.95 + 0.5);
		if ((i % 30) == 0)
		{
			r2 = 0.8;
			w = 6;
		}
		else
		{
			r2 = 0.85; 
			w = 2;
		}
		x2 = cx + (int)((float)r * cos(r1) * r2 + 0.5);
		y2 = cy + (int)((float)r * sin(r1) * r2 + 0.5);
		line(x1, y1, x2, y2, 0x00, w);
	}

	//2.3 時刻度
	for (int i = 0; i < 360; i += 30)
	{
		r1 = (float)i * 3.1415926 / 180;
		x1 = cx + (int)((float)r * cos(r1) * 0.95 + 0.5);
		y1 = cy + (int)((float)r * sin(r1) * 0.95 + 0.5);
		x2 = cx + (int)((float)r * cos(r1) * 0.75 + 0.5);
		y2 = cy + (int)((float)r * sin(r1) * 0.75 + 0.5);
		line(x1, y1, x2, y2, 0xFF99, 10);
	}

	//2.4.時針

	float rh = ((float)(h * 30 - 90)+ (float)(m * 0.5)) * 3.1415926 / 180;
	x1 = cx + (int)((float)r * cos(rh) * 0.55 + 0.5);
	y1 = cy + (int)((float)r * sin(rh) * 0.55 + 0.5);
	x2 = cx + (int)((float)r * cos(rh) * (-0.2) + 0.5);
	y2 = cy + (int)((float)r * sin(rh) * (-0.2) + 0.5);
	line(x1, y1, x2, y2, 0x1255, 10);
	//2.5.分針
	float rm = (float)(m * 6 - 90) * 3.1415926 / (float)180;
	x1 = cx + (int)((float)r * cos(rm) * 0.7 + 0.5);
	y1 = cy + (int)((float)r * sin(rm) * 0.7 + 0.5);
	x2 = cx + (int)((float)r * cos(rm) * (-0.1) + 0.5);
	y2 = cy + (int)((float)r * sin(rm) * (-0.1) + 0.5);
	line(x1, y1, x2, y2, 0x0055, 5);
	//2.6.秒針
	float rs = (float)(s * 6 - 90) * 3.1415926 / (float)180;
	x1 = cx + (int)((float)r * cos(rs) * 0.85 + 0.5);
	y1 = cy + (int)((float)r * sin(rs) * 0.85 + 0.5);
	x2 = cx + (int)((float)r * cos(rs) * (-0.05) + 0.5);
	y2 = cy + (int)((float)r * sin(rs) * (-0.05) + 0.5);
	line(x1, y1, x2, y2, 0xFF0000, 2);


}

void CMy0425clockDlg::rect(int x1, int y1, int x2, int y2, int color, int w, int f)
{
	//1.設定顏色color ,寬度w
	CPen p1(PS_SOLID, w, RGB((color >> 16) & 0xFF, (color >> 8) & 0xFF, (color >> 0) & 0xFF));
	//                    高位元                   中位元                  低位元
	SelectObject(hdc, p1);
	//2.畫線
	if (f == 0)
	{
		MoveToEx(hdc, x1, y1, 0);
		LineTo(hdc, x1, y2);
		LineTo(hdc, x2, y2);
		LineTo(hdc, x2, y1);
		LineTo(hdc, x1, y1);
	}
	else
	{
		for (int y = y1; y < y2; y++)
		{
			MoveToEx(hdc, x1, y, 0);
			LineTo(hdc, x2, y);
		}
	}
}
	

void CMy0425clockDlg::circle(int cx, int cy, int rx, int ry, int color, int w)
{
	//1.設定顏色color ,寬度w
	CPen p1(PS_SOLID, w, RGB((color >> 16) & 0xFF, (color >> 8) & 0xFF, (color >> 0) & 0xFF));
	//                    高位元                   中位元                  低位元
	SelectObject(hdc, p1);
	int r, x, y;
	float r1;
	for (r = 0; r < 360; r++)
	{
		r1 = (float)r * 3.1415926 / 180;//角度r轉徑度r1
		x = cx + (int)((float)rx * cos(r1)+0.5);
		y = cy + (int)((float)ry * sin(r1)+0.5);
		if (r == 0)
		{
			MoveToEx(hdc, x, y, 0);
		}
		LineTo(hdc, x, y);
	}
	
}



void CMy0425clockDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	if (nIDEvent == 1234)
	{
		OnBnClickedButton1();
	}
	CDialogEx::OnTimer(nIDEvent);
}
