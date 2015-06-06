#pragma once
#include "XCefCallback.h"
#include "client_app.h"
#include "client_handler.h"



struct XManifestUtil{
	struct
	{
		// ʹ�� url ���ػ��� html �ַ�������
		bool						is_url_or_html_;
		// html �ַ���
		CefString					str_html_;
		CefString					str_url_;
		// ������Ⱦ
		bool						is_off_screen_rendering_;
	}browser;

	struct
	{
		// �Զ��崰����������Ϣѭ��
		bool						has_host_hwnd_;	// �д�����
		// ʹ��win32���Ƶ�less����
		bool						win32less_;
		int							show_state_;
		BYTE						opacity_;
	}window;
	



	static XManifestUtil& Instance() {
		static XManifestUtil manifest;
		return manifest;
	}
	XManifestUtil(){	Clear();	}
	void			Clear()
	{
		browser.is_url_or_html_ = true;
		browser.is_off_screen_rendering_ = false;

		window.has_host_hwnd_ = false;
		window.win32less_ = false/*true*/;
		window.show_state_ = -1;
		window.opacity_ = 255;
	}

	void			LoadHtml(CefString html, CefString url = CefString(L"about:blank") )
	{ 
		browser.is_url_or_html_ = true;
		browser.str_html_ = html;
		browser.str_url_ = url;
	}
	void			LoadUrl(CefString url)
	{
		browser.is_url_or_html_ = true;
		browser.str_url_ = url;
		browser.str_html_.clear();
	}
	void			EnableOffScreenRendering()
	{
		browser.is_off_screen_rendering_ = true;
	}

	void			SetWin32less()
	{
		window.win32less_ = true;
	}
	void			SetWin32Normal()
	{
		window.win32less_ = false;
	}
	void			Maximize()
	{
		window.show_state_ = SW_SHOW;
	}
};

class XCefAppManage
{
public:
	XCefAppManage();
	~XCefAppManage();

	int		RunSingle(HINSTANCE hInstance);

	// Ψһʵ��
	static  CefRefPtr<XCefAppManage>		Instance();

	int		Init(HINSTANCE hInstance, int nCmdShow = SW_SHOW);
	BOOL	Loop(HINSTANCE hInstance);	
	void    Shutdown();
	void    PreLoop(HINSTANCE hInstance);
	BOOL	PreTranslateMessage(MSG* pMsg);

	// cef
	static CefString				GetModuleCurrentDirectory();
	static CefString				GetWorkingDirectory();
	void							InitCommandLine(int argc, const char* const* argv);
	void							InitCefSettings(__out CefSettings & settings);
	void							InitBrowserSettings(__out CefBrowserSettings & settings);
	void							CreateBrowser(HWND hwnd_parent);
	void							QuitMessageLoop();
	void							QuitMessageLoopByChildProcess();
	bool							IsOffScreenRenderingEnabled();


	// callback
	void							RigisterCallback(XCefCallback * cb);
	void							ClearCallback();
	void							CallbackLoad(CefRefPtr<CefV8Value> window, CefRefPtr<CefV8Context> context);
	void							AnsycCallbackLoad(MessageHandlerSet & msg_handle_set);

	// get and set
	inline CefRefPtr<CefCommandLine>	GetCefCommandLine(){ return command_line_; }
	inline CefSettings &				GetCefSettings(){ return settings_; }
	inline CefRefPtr<ClientHandler>		GetClient(){ return client_; }
	inline void							SetClient(CefRefPtr<ClientHandler> client){ client_ = client; }
	inline void							SetClientHostHandle(CefWindowHandle hwnd){ client_host_hwnd_ = hwnd; }
	inline CefWindowHandle				GetClientHostHandle(){ return client_host_hwnd_; }

public:
	// ���洰�ھ�� - XWinCallback::async_cache_hwnd ��ֵ(�д��ϳ���
	HWND							cache_browser_hwnd_;

	HWND							message_wnd__;
private:
	static char						working_dir_[MAX_PATH];  // The current working directory

	CefRefPtr<CefCommandLine>		command_line_;
	CefSettings						settings_;
	CefRefPtr<CefApp>				app_;
	// �����-����������
	CefRefPtr<ClientHandler>		client_;
	// �����������
	CefWindowHandle					client_host_hwnd_;
	
	// ͬ�����첽�ص�
	std::vector<XCefCallback*>		cb_vector_;

	IMPLEMENT_REFCOUNTING(XCefAppManage);
};
typedef CefRefPtr<XCefAppManage>	XCefAppManagePtr;

