#ifndef CONVENIENCE_H
#define CONVENIENCE_H

#include <assert.h>
#include "DXError.h"

#define ReleaseMacro( x ) { if ( x ) { x->Release(); x = nullptr; } }

#if defined( DEBUG ) | defined( _DEBUG )
#ifndef ErrorCheck
#define ErrorCheck( x )											\
{																\
	HRESULT hr = ( x );											\
	if ( FAILED( hr ) )											\
	{															\
		DXTrace( __FILEW__, (DWORD)__LINE__, hr, L#x, true );	\
		PostQuitMessage( 0 );									\
	}															\
}
#endif
#else
#ifndef ErrorCheck
#define ErrorCheck( x ) ( x )
#endif
#endif

#endif