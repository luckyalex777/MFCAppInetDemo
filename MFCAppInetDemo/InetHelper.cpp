#include "pch.h"
#include "InetHelper.h"

#include <afxinet.h>

bool
InetHelper::Parse()
{
	DWORD dwServiceType;
	CString strServer;
	CString strObject;
	INTERNET_PORT nPort;
	LPCTSTR urlStr = L"https://NOVAD241WEB.rd.allscripts.com/POH/NOVA_DEV_241/";
	int rc = AfxParseURL(urlStr, dwServiceType, strServer, strObject, nPort);
	return rc == 1;
}

bool
InetHelper::Combine()
{
	LPCWSTR baseUrlStr = L"https://NOVAD241WEB.rd.allscripts.com/POH/NOVA_DEV_241/";
	LPCWSTR serviceUrlStr = L"POHBusinessServices/ReferenceLabWebApi/health";
	wchar_t buffer[MAX_PATH];
	DWORD bufferLength;
	DWORD flags = ICU_NO_ENCODE;
	int rc = InternetCombineUrlW(baseUrlStr, serviceUrlStr, buffer, &bufferLength, flags);
	return rc == 1;
}
