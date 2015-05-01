#ifndef WINDOW_H
#define WINDOW_H

#include <Windows.h>
#include "DataTypes.h"

typedef struct
{
	HINSTANCE	HInstance;
	u16			Width;
	u16			Height;
	LPCWSTR		Name;
	WNDPROC		WndProcedure;
} WindowParams;

class Window
{
public:
	const u16 width( void ) const;
	const u16 height( void ) const;
	const f32 aspectRatio( void ) const;
	const bool isMinimized( void ) const;
	const bool isMaximized( void ) const;
	const bool isResizing( void ) const;
	const bool isPaused( void ) const;

protected:
	HWND	m_HWindow;

	u16		m_Width;
	u16		m_Height;
	f32		m_AspectRatio;

	bool	m_Minimized	: 1;
	bool	m_Maximized : 1;
	bool	m_Resizing	: 1;
	bool	m_Paused	: 1;

	Window( const WindowParams* const params );
	void onResize( const u16 width, const u16 height );

};

#endif