#include "Window.h"

Window::Window( const WindowParams* const params )
{
	WNDCLASS window;
	window.style = CS_HREDRAW | CS_VREDRAW;
	window.lpfnWndProc = params->WndProcedure;
	window.cbClsExtra = 0;
	window.cbWndExtra = 0;
	window.hInstance = params->HInstance;
	window.hIcon = LoadIcon( 0, IDI_APPLICATION );
	window.hCursor = LoadCursor( 0, IDC_ARROW );
	window.hbrBackground = (HBRUSH)GetStockObject( NULL_BRUSH );
	window.lpszMenuName = 0;
	window.lpszClassName = params->Name;
	if ( !RegisterClass( &window ) )
	{
		MessageBox( 0, L"Failed to register window.", L"Window Error", 0 );
		return;
	}

	RECT rect = { 0, 0, m_Width, m_Height };
	AdjustWindowRect( &rect, WS_OVERLAPPEDWINDOW, true );
	int rWidth = rect.right - rect.left;
	int rHeight = rect.bottom - rect.top;

	m_HWindow = CreateWindowEx( 0, params->Name, L"Window", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, rWidth, rHeight, 0, 0, params->HInstance, 0 );
	if ( !m_HWindow )
	{
		MessageBox( 0, L"Failed to create window.", L"Window Error", 0 );
		return;
	}

	ShowWindow( m_HWindow, SW_SHOW );
	UpdateWindow( m_HWindow );

	onResize( params->Width, params->Height );
}

void Window::onResize( u16 width, u16 height )
{
	m_Width = width;
	m_Height = height;
	m_AspectRatio = (f32)m_Width / (f32)m_Height;
}

const u16 Window::width( void ) const
{
	return m_Width;
}

const u16 Window::height( void ) const
{
	return m_Height;
}

const f32 Window::aspectRatio( void ) const
{
	return m_AspectRatio;
}

const bool Window::isMinimized( void ) const
{
	return m_Minimized;
}

const bool Window::isMaximized( void ) const
{
	return m_Maximized;
}

const bool Window::isResizing( void ) const
{
	return m_Resizing;
}

const bool Window::isPaused( void ) const
{
	return m_Paused;
}