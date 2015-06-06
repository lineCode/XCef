#pragma once
#include "XCefCallback.h"



class XWinCallback : public XCefCallback
{
	DECLARE_XV8()
public:
	// callback methods

	// ���ܺ���
	// �����϶�����
	static bool set_title_areas(
		XCefV8Handler *				pthis_handle,
		CefRefPtr<CefV8Value>		object,
		const CefV8ValueList &		arguments,
		CefRefPtr<CefV8Value> &		retval,
		CefString &					exception
		);
	static bool close(
		XCefV8Handler *				pthis_handle,
		CefRefPtr<CefV8Value>		object,
		const CefV8ValueList &		arguments,
		CefRefPtr<CefV8Value> &		retval,
		CefString &					exception
		);
	static bool quit(
		XCefV8Handler *				pthis_handle,
		CefRefPtr<CefV8Value>		object,
		const CefV8ValueList &		arguments,
		CefRefPtr<CefV8Value> &		retval,
		CefString &					exception
		);


	// ���Ժ���
	static bool		title(
		XCefV8Handler *				pthis_handle,
		CefRefPtr<CefV8Value>		object,
		const CefV8ValueList &		arguments,
		CefRefPtr<CefV8Value> &		retval,
		CefString &					exception
		);
	static bool		async_title(
		XAsyncBrowserHandler *			pthis_handle,
		CefRefPtr<CefBrowser>			browser,
		CefRefPtr<CefFrame>				frame,
		int64							query_id,
		const CefString &				request,
		bool							persistent,
		CefRefPtr<BrowserCallback>		callback,
		XRPC_INFO &						rpc_info
		);
	// ����Զ����̻߳ص� js callback
	static bool		native_thread_callback(
		XCefV8Handler *				pthis_handle,
		CefRefPtr<CefV8Value>		object,
		const CefV8ValueList &		arguments,
		CefRefPtr<CefV8Value> &		retval,
		CefString &					exception
		);

	static bool   async_get_hwnd(
		XAsyncBrowserHandler *			pthis_handle,
		CefRefPtr<CefBrowser>			browser,
		CefRefPtr<CefFrame>				frame,
		int64							query_id,
		const CefString &				request,
		bool							persistent,
		CefRefPtr<BrowserCallback>		callback,
		XRPC_INFO &						rpc_info
		);

	static bool   cache_hwnd(
		XCefV8Handler *				pthis_handle,
		CefRefPtr<CefV8Value>		object,
		const CefV8ValueList &		arguments,
		CefRefPtr<CefV8Value> &		retval,
		CefString &					exception
		);
};

