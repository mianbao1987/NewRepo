
// MFCApplication1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <afx.h>  
#include <tlhelp32.h>  
using namespace std;

// CMFCApplication1Dlg �Ի���
class CMFCApplication1Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	
	LRESULT OnShowTask(WPARAM wParam, LPARAM lParam);

public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CComboBox FileList;
	CButton check1;
	afx_msg void OnBnClickedCheck1();
	CEdit edit1;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	void setSSLEdge(CString file, CString port);
	void write2file(CString file, CString port);
	DWORD GetProcessHandle(TCHAR *processname);
	bool searchmap(DWORD id);

private:
	
public:
	CComboBox combo2;
	CEdit edit2;
	afx_msg void OnBnClickedCheck2();
	CButton check2;
	map<string, DWORD> m_handlemap;
	NOTIFYICONDATA m_nid;
};
