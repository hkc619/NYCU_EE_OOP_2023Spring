
// 0411mfc_calculatorDlg.cpp: 實作檔案
//

#include "pch.h"
#include "framework.h"
#include "0411mfc_calculator.h"
#include "0411mfc_calculatorDlg.h"
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


// CMy0411mfccalculatorDlg 對話方塊



CMy0411mfccalculatorDlg::CMy0411mfccalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY0411MFC_CALCULATOR_DIALOG, pParent)
	, m_edit1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy0411mfccalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, m_Edit);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
}

BEGIN_MESSAGE_MAP(CMy0411mfccalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_0, &CMy0411mfccalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_1, &CMy0411mfccalculatorDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CMy0411mfccalculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CMy0411mfccalculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CMy0411mfccalculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CMy0411mfccalculatorDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CMy0411mfccalculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CMy0411mfccalculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CMy0411mfccalculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CMy0411mfccalculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_point, &CMy0411mfccalculatorDlg::OnBnClickedpoint)
	ON_BN_CLICKED(IDC_e, &CMy0411mfccalculatorDlg::OnBnClickede)
	ON_BN_CLICKED(IDC_p, &CMy0411mfccalculatorDlg::OnBnClickedp)
	ON_BN_CLICKED(IDC_s, &CMy0411mfccalculatorDlg::OnBnClickeds)
	ON_BN_CLICKED(IDC_m, &CMy0411mfccalculatorDlg::OnBnClickedm)
	ON_BN_CLICKED(IDC_D, &CMy0411mfccalculatorDlg::OnBnClickedD)
	ON_BN_CLICKED(IDC_CE, &CMy0411mfccalculatorDlg::OnBnClickedCe)
	ON_BN_CLICKED(IDC_left, &CMy0411mfccalculatorDlg::OnBnClickedleft)
	ON_BN_CLICKED(IDC_right, &CMy0411mfccalculatorDlg::OnBnClickedright)
	ON_BN_CLICKED(IDC_root, &CMy0411mfccalculatorDlg::OnBnClickedroot)
END_MESSAGE_MAP()


// CMy0411mfccalculatorDlg 訊息處理常式

BOOL CMy0411mfccalculatorDlg::OnInitDialog()
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

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CMy0411mfccalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy0411mfccalculatorDlg::OnPaint()
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
HCURSOR CMy0411mfccalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

double Eval2(char* expr, char** end) {
	double Eval0(char*, char**);
	double res = 0;
	if (*(*end = expr) == '(') {
		res = Eval0(*end + 1, end);
		if (**end == ')')++* end;
	}
	else { res = strtod(*end, end); }
	return res;
}

double Eval1(char* expr, char** end) {
	double res = Eval2(expr, end);
	while (**end == '*' || **end == '/')
		(**end == '*') ? (res *= Eval2(*end + 1, end)) : (res /= Eval2(*end + 1, end));
	return res;
}

double Eval0(char* expr, char** end) {
	double res = Eval1(expr, end);
	while (**end == '+' || **end == '-')
		res += (**end == '+') ? Eval1(*end + 1, end) : -Eval1(*end + 1, end);
	return res;
}



void CMy0411mfccalculatorDlg::OnBnClicked0()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(1);
	m_edit1 += '0';
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClicked1()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(1);
	m_edit1 += '1';
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClicked2()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(1);
	m_edit1 += '2';
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClicked3()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(1);
	m_edit1 += '3';
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClicked4()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(1);
	m_edit1 += '4';
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClicked5()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(1);
	m_edit1 += '5';
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClicked6()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(1);
	m_edit1 += '6';
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClicked7()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(1);
	m_edit1 += '7';
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClicked8()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(1);
	m_edit1 += '8';
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClicked9()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(1);
	m_edit1 += '9';
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClickedpoint()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(1);
	m_edit1 += '.';
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClickede()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	/*
	UpdateData(1);
	m_edit1 += '=';
	UpdateData(0);
	*/
	//1.取得運算式
	char s[100];
	UpdateData(1);
	sprintf_s(s, sizeof(s), "%s", m_edit1);
	//2.取得A B及運算符號
	UpdateData(0);
	int A, B, i ,D;
	float C;
	char op;
	char * pos = 0;
	//printf("Exp : ");
	//scanf("%s", s);
	//printf("Ans : %f\n", Eval0(s, &pos));
	//sscanf_s(s, "%d%c%d", &A, &op, &B);
	//3.計算答案
	/*
	if ((i = sscanf_s(s, "%d+%d", &A, &B)) == 2)
		C = A + B;
	else if ((i = sscanf_s(s, "%d-%d", &A, &B)) == 2)
		C = A - B;
	else if ((i = sscanf_s(s, "%d*%d", &A, &B)) == 2)
		C = A * B;
	else if ((i = sscanf_s(s, "%d/%d", &A, &B)) == 2)
		C = (float)A / (float)B;
	if ((i = sscanf_s(s, "%d+%d+%d", &A, &B, &D)) == 3)//+
		C = A + B + D;
	else if ((i = sscanf_s(s, "%d+%d-%d", &A, &B, &D)) == 3)
		C = A + B - D;
	else if ((i = sscanf_s(s, "%d+%d*%d", &A, &B, &D)) == 3)
		C = A + (B * D);
	else if ((i = sscanf_s(s, "%d+%d/%d", &A, &B, &D)) == 3)
		C = (float)A + ((float)B / (float)D);
	else if ((i = sscanf_s(s, "%d-%d+%d", &A, &B, &D)) == 3)//-
		C = A - B + D;
	else if ((i = sscanf_s(s, "%d-%d-%d", &A, &B, &D)) == 3)
		C = A - B - D;
	else if ((i = sscanf_s(s, "%d-%d*%d", &A, &B, &D)) == 3)
		C = A - (B * D);
	else if ((i = sscanf_s(s, "%d-%d/%d", &A, &B, &D)) == 3)
		C = (float)A - ((float)B / (float)D);
	else if ((i = sscanf_s(s, "%d*%d+%d", &A, &B, &D)) == 3)//*
		C = A * B + D;
	else if ((i = sscanf_s(s, "%d*%d-%d", &A, &B, &D)) == 3)
		C = A * B - D;
	else if ((i = sscanf_s(s, "%d*%d*%d", &A, &B, &D)) == 3)
		C = A * B * D;
	else if ((i = sscanf_s(s, "%d*%d/%d", &A, &B, &D)) == 3)
		C = (float)(A * B) / (float)D;
	else if ((i = sscanf_s(s, "%d/%d+%d", &A, &B, &D)) == 3)///
		C = (float)A / (float)B + (float)D;
	else if ((i = sscanf_s(s, "%d/%d-%d", &A, &B, &D)) == 3)
		C = (float)A / (float)B - (float)D;
	else if ((i = sscanf_s(s, "%d/%d*%d", &A, &B, &D)) == 3)
		C = (float)A / (float)B * (float)D;
	else if ((i = sscanf_s(s, "%d/%d/%d", &A, &B, &D)) == 3)
		C = (float)A / (float)B / (float)D;
	*/

	//4.顯示結果
	C = Eval0(s, &pos);
	sprintf_s(s, sizeof(s), "%f", C);//c
	UpdateData(1);
	m_edit1 = s;
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClickedp()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(1);
	m_edit1 += '+';
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClickeds()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(1);
	m_edit1 += '-';
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClickedm()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(1);
	m_edit1 += '*';
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClickedD()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(1);
	m_edit1 += '/';
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClickedCe()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(1);
	m_edit1 = "";
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClickedleft()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(1);
	m_edit1 += '(';
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClickedright()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(1);
	m_edit1 += ')';
	UpdateData(0);
}


void CMy0411mfccalculatorDlg::OnBnClickedroot()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	char s[100];
	int i;
	float A, C;
	sprintf_s(s, sizeof(s), "%s", m_edit1);
	sscanf_s(s, "%f", &A);
	C = sqrt(A);
	sprintf_s(s, sizeof(s), "%f", C);//c
	UpdateData(1);
	m_edit1 = s;
	UpdateData(0);
}
