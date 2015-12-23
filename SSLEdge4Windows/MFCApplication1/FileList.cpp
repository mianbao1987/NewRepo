// FileList.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "FileList.h"
#include "afxdialogex.h"


// FileList 对话框

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
