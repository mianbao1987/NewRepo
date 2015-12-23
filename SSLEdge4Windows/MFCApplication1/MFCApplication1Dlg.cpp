
// MFCApplication1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define WM_SHOWTASK (WM_USER +1)

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCApplication1Dlg �Ի���



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, FileList);
	DDX_Control(pDX, IDC_CHECK1, check1);
	DDX_Control(pDX, IDC_EDIT1, edit1);
	DDX_Control(pDX, IDC_COMBO2, combo2);
	DDX_Control(pDX, IDC_EDIT2, edit2);
	DDX_Control(pDX, IDC_CHECK2, check2);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDOK, &CMFCApplication1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFCApplication1Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCApplication1Dlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CMFCApplication1Dlg::OnBnClickedCheck2)
	ON_MESSAGE(WM_SHOWTASK, OnShowTask)
END_MESSAGE_MAP()


// CMFCApplication1Dlg ��Ϣ�������

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	FileList.InsertString(0, "ssledge-tls-hk");
	FileList.InsertString(1, "ssledge-tls-jp");
	FileList.InsertString(2, "ssledge-tls-kr");
	FileList.InsertString(3, "ssledge-tls-sg");
	FileList.InsertString(4, "ssledge-tls-tw");
	FileList.InsertString(5, "ssledge-tls-socks");
	FileList.SetCurSel(0);
	edit1.SetWindowTextA("16808");

	combo2.InsertString(0, "ssledge-tls-hk");
	combo2.InsertString(1, "ssledge-tls-jp");
	combo2.InsertString(2, "ssledge-tls-kr");
	combo2.InsertString(3, "ssledge-tls-sg");
	combo2.InsertString(4, "ssledge-tls-tw");
	combo2.InsertString(5, "ssledge-tls-socks");
	combo2.SetCurSel(1);
	edit2.SetWindowTextA("16809");

	//---------------------------������ʾ---------------------------------//
	m_nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
	m_nid.hWnd = this->m_hWnd;
	m_nid.uID = IDR_MAINFRAME;
	m_nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	m_nid.uCallbackMessage = WM_SHOWTASK;             // �Զ������Ϣ����
	m_nid.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
	strcpy_s(m_nid.szTip,12,"SSLEdge");                // ��Ϣ��ʾ��Ϊ"����������"��VS2008 UNICODE������wcscpy_s()����
	Shell_NotifyIcon(NIM_ADD, &m_nid);                // �����������ͼ��

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->OnSize(SIZE_MINIMIZED, 0, 0);
}


void CMFCApplication1Dlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	system("taskkill /F /IM ssledge-term.exe");
	Shell_NotifyIcon(NIM_DELETE, &m_nid);
	CDialogEx::OnCancel();
}


void CMFCApplication1Dlg::OnBnClickedCheck1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (!check1.GetCheck())
	{
		FileList.EnableWindow(true);
		edit1.EnableWindow(true);
		map<string, DWORD>::iterator iter = m_handlemap.find("check1");
		if (iter != m_handlemap.end())
		{
			CString tmp = "";
			int a = (int)iter->second;
			tmp.Format("%d", a);
			tmp = "taskkill /pid " + tmp + " /f";
			system(tmp.GetBuffer());
		}
	}
	else
	{
		FileList.EnableWindow(false);
		edit1.EnableWindow(false);
		CString tmp = "";
		int i = FileList.GetCurSel();
		FileList.GetLBText(i, tmp);
		CString filename = tmp;
		edit1.GetWindowTextA(tmp);
		CString port = tmp;
		setSSLEdge(filename, port);
		Sleep(100);
		m_handlemap["check1"] = GetProcessHandle("ssledge-term.exe");
		//min size
		this->OnSize(SIZE_MINIMIZED,0,0);
	}
}


void CMFCApplication1Dlg::setSSLEdge(CString file, CString port)
{
	CString filename = ".conf";
	CString argv = " -D";
	HMODULE module = GetModuleHandle(0);
	CHAR buf[MAX_PATH];
	GetModuleFileName(module, buf, sizeof buf);

	CString a;
	a = buf;
	string tmp = (char*)a.GetBuffer();
	tmp = tmp.substr(0, tmp.find_last_of("\\"));
	filename = file + filename;
	a = tmp.c_str();
	CString fullfilepath = a + "\\" + filename;
	a.Append(" & ssledge-term.exe -f ");
	
	//д�ļ�
	write2file(fullfilepath,port);
	///////////////////
	a += filename;
	a += argv;
	a = "cd " + a;
	system(a.GetBuffer());
}

int ReplaceSSLText(CString StrFileName, CString StrFind, CString StrReplace)
{

	CStdioFile TempFile, File;
	int Count = 0;
	if (!File.Open(StrFileName, CFile::modeRead))
		return -1;
	CString StrTempFileName = File.GetFileTitle() + ".tmp";
	if (!TempFile.Open(StrTempFileName, CFile::modeCreate | CFile::modeReadWrite))
		return -1;
	CString Str;
	while (File.ReadString(Str))
	{

		//Count += Str.Replace(StrFind, StrReplace);
		if (Str.Find(StrFind, 0) != -1)
		{
			Str = "\t" + StrFind + StrReplace;
			Count++;
		}
		TempFile.WriteString(Str + "\n");

	}
	File.Close();
	TempFile.Close();
	CFile::Remove(StrFileName);
	CFile::Rename(StrTempFileName, StrFileName);
	return Count;

}

bool CMFCApplication1Dlg::searchmap(DWORD id)
{
	for (map<string, DWORD>::const_iterator iter = m_handlemap.begin(); iter != m_handlemap.end(); ++iter)
	{
		if (id == iter->second)
		{
			return true;
		}
	}
	return false;
}

void CMFCApplication1Dlg::write2file(CString file, CString port)
{
	ReplaceSSLText(file,"bind 127.0.0.1:",port);
}

DWORD CMFCApplication1Dlg::GetProcessHandle(TCHAR * processname)
{
	if (processname == NULL)
	{
		return NULL;
	}

	HANDLE proc = NULL;
	PROCESSENTRY32 pe;
	DWORD id = 0;
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	pe.dwSize = sizeof(PROCESSENTRY32);
	if (!Process32First(hSnapshot, &pe))
		return NULL;
	while (1)
	{
		pe.dwSize = sizeof(PROCESSENTRY32);
		if (Process32Next(hSnapshot, &pe) == FALSE)
			break;
		if (lstrcmpi(pe.szExeFile, processname) == 0)
		{
			id = pe.th32ProcessID;
			if (!searchmap(id))
			{
				return id;
			}
			else
			{
				continue;
			}
			break;
		}
	}

	return 0;
}




void CMFCApplication1Dlg::OnBnClickedCheck2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (!check2.GetCheck())
	{
		combo2.EnableWindow(true);
		edit2.EnableWindow(true);
		map<string, DWORD>::iterator iter = m_handlemap.find("check2");
		if (iter != m_handlemap.end())
		{
			CString tmp = "";
			int a = (int)iter->second;
			tmp.Format("%d", a);
			tmp = "taskkill /pid " + tmp + " /f";
			system(tmp.GetBuffer());
		}
	}
	else
	{
		combo2.EnableWindow(false);
		edit2.EnableWindow(false);
		CString tmp = "";
		int i = combo2.GetCurSel();
		combo2.GetLBText(i, tmp);
		CString filename = tmp;
		edit2.GetWindowTextA(tmp);
		CString port = tmp;
		setSSLEdge(filename, port);
		Sleep(100);
		m_handlemap["check2"] = GetProcessHandle("ssledge-term.exe");
		this->OnSize(SIZE_MINIMIZED, 0, 0);
	}
}


LRESULT CMFCApplication1Dlg::OnShowTask(WPARAM wParam, LPARAM lParam)
{
	if (wParam != IDR_MAINFRAME)
		return 1;
	switch (lParam)
	{
	case WM_RBUTTONUP:                                        // �Ҽ�����ʱ�����˵�
		{
			LPPOINT lpoint = new tagPOINT;
			::GetCursorPos(lpoint);                    // �õ����λ��
			CMenu menu;
			menu.CreatePopupMenu();                    // ����һ������ʽ�˵�
			menu.AppendMenu(MF_STRING, WM_DESTROY, "�ر�");
			menu.TrackPopupMenu(TPM_LEFTALIGN, lpoint->x, lpoint->y, this);
			HMENU hmenu = menu.Detach();
			menu.DestroyMenu();
			delete lpoint;
		}
		break;
	case WM_LBUTTONDBLCLK:                                 // ˫������Ĵ���
		{
			this->ShowWindow(SW_SHOWNORMAL);         // ��ʾ������
		}
		break;
	}
	return 0;
}

void CMFCApplication1Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	// TODO: Add your message handler code here
	if (nType == SIZE_MINIMIZED)
	{
		ShowWindow(SW_HIDE); // ����С���У�����������              
	}
}
