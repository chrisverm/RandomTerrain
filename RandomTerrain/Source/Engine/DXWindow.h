#ifndef DX_WINDOW_H
#define DX_WINDOW_H

#include <d3d11.h>
#include "Window.h"

class DXWindow : public Window
{
public:
	DXWindow( const WindowParams* const params );
	~DXWindow( void );

private:
	union MSAA
	{
		u32						Quality;
		bool					Enabled;
	} m_MSAA;

	ID3D11Device*				m_Device;
	ID3D11DeviceContext*		m_DeviceContext;
	IDXGISwapChain*				m_SwapChain;
	ID3D11Texture2D*			m_DepthStencilBuffer;
	ID3D11DepthStencilView*		m_DepthStencilView;
	ID3D11RenderTargetView*		m_RenderTargetView;

	void onResize( void );

};

#endif