#pragma once
/* 
 * DirectX drawing library. See README for more info.
 * 
 * @author      manoboy
 * @updated     2015-12-15
 * @url         http://github.com/manoboy/Drawing
 */
#define WIN32_LEAN_AND_MEAN
#define _USE_MATH_DEFINES

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

class Drawing final
{
	private:
		IDirect3DDevice9Ex *device;
		D3DCOLOR            defaultColor;
		FLOAT               defaultLineWidth;
		INT                 defaultCircleNumSides;
	
	public:
		Drawing();
		~Drawing();


		IDirect3DDevice9Ex *Device();
		VOID Device(IDirect3DDevice9Ex *);
		
		D3DCOLOR DefaultColor();
		VOID DefaultColor(D3DCOLOR);
		
		FLOAT DefaultLineWidth();
		VOID DefaultLineWidth(FLOAT);
		
		INT DefaultCircleNumSides();
		VOID DefaultCircleNumSides(INT);
		

		VOID box(D3DXVECTOR2, SIZE);
		VOID box(D3DXVECTOR2, SIZE, FLOAT);
		VOID box(D3DXVECTOR2, SIZE, FLOAT, D3DXCOLOR);

		VOID circle(D3DXVECTOR2, FLOAT);
		VOID circle(D3DXVECTOR2, FLOAT, INT);
		VOID circle(D3DXVECTOR2, FLOAT, INT, D3DCOLOR);

		VOID fill(D3DXVECTOR2, SIZE);
		VOID fill(D3DXVECTOR2, SIZE, D3DXCOLOR);

		VOID line(D3DXVECTOR2, D3DXVECTOR2);
		VOID line(D3DXVECTOR2, D3DXVECTOR2, FLOAT);
		VOID line(D3DXVECTOR2, D3DXVECTOR2, FLOAT, D3DCOLOR);
		
		VOID text(PCHAR, D3DXVECTOR2, ID3DXFont *);
		VOID text(PCHAR, D3DXVECTOR2, ID3DXFont *, D3DCOLOR);
		VOID text(PCHAR, D3DXVECTOR2, ID3DXFont *, D3DCOLOR, BOOL);

		VOID text(PWCHAR, D3DXVECTOR2, ID3DXFont *);
		VOID text(PWCHAR, D3DXVECTOR2, ID3DXFont *, D3DCOLOR);
		VOID text(PWCHAR, D3DXVECTOR2, ID3DXFont *, D3DCOLOR, BOOL);
		
		
		static CONST D3DCOLOR blackColor      = D3DCOLOR_ARGB(255, 000, 000, 000);
		static CONST D3DCOLOR blueColor       = D3DCOLOR_ARGB(255, 000, 000, 255);
		static CONST D3DCOLOR brownColor      = D3DCOLOR_ARGB(255, 165, 042, 042);
		static CONST D3DCOLOR cyanColor       = D3DCOLOR_ARGB(255, 000, 255, 255);
		static CONST D3DCOLOR goldColor       = D3DCOLOR_ARGB(255, 255, 215, 000);
		static CONST D3DCOLOR grayColor       = D3DCOLOR_ARGB(255, 128, 128, 128);
		static CONST D3DCOLOR greenColor      = D3DCOLOR_ARGB(255, 000, 128, 000);
		static CONST D3DCOLOR maroonColor     = D3DCOLOR_ARGB(255, 128, 000, 000);
		static CONST D3DCOLOR orangeColor     = D3DCOLOR_ARGB(255, 255, 165, 000);
		static CONST D3DCOLOR pinkColor       = D3DCOLOR_ARGB(255, 255, 192, 203);
		static CONST D3DCOLOR purpleColor     = D3DCOLOR_ARGB(255, 128, 000, 128);
		static CONST D3DCOLOR redColor        = D3DCOLOR_ARGB(255, 255, 000, 000);
		static CONST D3DCOLOR whiteColor      = D3DCOLOR_ARGB(255, 255, 255, 255);
		static CONST D3DCOLOR yellowColor     = D3DCOLOR_ARGB(255, 255, 255, 000);
		static CONST D3DCOLOR lightBlackColor = D3DCOLOR_ARGB(175, 000, 000, 000);
		static CONST D3DCOLOR lightBlueColor  = D3DCOLOR_ARGB(100, 000, 000, 255);
		static CONST D3DCOLOR lightRedColor   = D3DCOLOR_ARGB(100, 255, 000, 000);
		static CONST D3DCOLOR lightWhiteColor = D3DCOLOR_ARGB(100, 255, 255, 255);
};

extern Drawing *drawing;