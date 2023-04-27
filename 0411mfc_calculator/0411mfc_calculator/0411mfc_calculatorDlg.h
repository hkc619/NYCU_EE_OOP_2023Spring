
// 0411mfc_calculatorDlg.h: 標頭檔
//

#pragma once


// CMy0411mfccalculatorDlg 對話方塊
class CMy0411mfccalculatorDlg : public CDialogEx
{
// 建構
public:
	CMy0411mfccalculatorDlg(CWnd* pParent = nullptr);	// 標準建構函式

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY0411MFC_CALCULATOR_DIALOG };
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
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClickedpoint();
	afx_msg void OnBnClickede();
	afx_msg void OnBnClickedp();
	afx_msg void OnBnClickeds();
	afx_msg void OnBnClickedm();
	afx_msg void OnBnClickedD();
//	CEdit m_Edit;
	CString m_edit1;
	afx_msg void OnBnClickedCe();
	afx_msg void OnBnClickedleft();
	afx_msg void OnBnClickedright();
	afx_msg void OnBnClickedroot();
};
