#pragma once


// FileList �Ի���

class FileList : public CDialogEx
{
	DECLARE_DYNAMIC(FileList)

public:
	FileList(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FileList();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:

};
