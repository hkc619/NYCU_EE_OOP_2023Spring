
// 0425_clockDlg.h: 標頭檔
//

#pragma once


// CMy0425clockDlg 對話方塊
class CMy0425clockDlg : public CDialogEx
{
// 建構
public:
	CMy0425clockDlg(CWnd* pParent = nullptr);	// 標準建構函式

	//成員變數
	HDC hdc;

	//成員函式
	void line(int x1, int y1, int x2, int y2, int color, int w);
	void rect(int x1, int y1, int x2, int y2, int color, int w, int f);
	void circle(int x1, int y1, int x2, int y2, int color, int w);

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY0425_CLOCK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
