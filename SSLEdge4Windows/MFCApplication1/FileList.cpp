// FileList.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "FileList.h"
#include "afxdialogex.h"


// FileList �Ի���

IMPLEMENT_DYNAMIC(FileList, CDialogEx)

FileList::FileList(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	
}

FileList::~FileList()
{
}

void FileList::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FileList, CDialogEx)
	ON_WM_SIZE()
//	ON_WM_DESTROY()
END_MESSAGE_MAP()
