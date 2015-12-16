#include "Drawing.h"

#pragma region Constructor & Destructor
Drawing::Drawing()
{
	this->device                = NULL;
	this->defaultColor          = Drawing::whiteColor;
	this->defaultLineWidth      = 1.0f;
	this->defaultCircleNumSides = 10;
}

Drawing::~Drawing()
{
	if (device)
		delete device;
}
#pragma endregion

#pragma region Properties
IDirect3DDevice9Ex *Drawing::Device()
{
	return this->device;
}

VOID Drawing::Device(IDirect3DDevice9Ex *device)
{
	this->device = device;
}


D3DCOLOR Drawing::DefaultColor()
{
	return this->defaultColor;
}

VOID Drawing::DefaultColor(D3DCOLOR defaultColor)
{
	this->defaultColor = defaultColor;
}


FLOAT Drawing::DefaultLineWidth()
{
	return this->defaultLineWidth;
}

VOID Drawing::DefaultLineWidth(FLOAT defaultLineWidth)
{
	this->defaultLineWidth = defaultLineWidth;
}


INT Drawing::DefaultCircleNumSides()
{
	return this->defaultCircleNumSides;
}

VOID Drawing::DefaultCircleNumSides(INT defaultCircleNumSides)
{
	this->defaultCircleNumSides = defaultCircleNumSides;
}
#pragma endregion

#pragma region Public Methods
VOID Drawing::box(D3DXVECTOR2 p1, SIZE size)
{
	this->box(p1, size, this->defaultLineWidth, this->defaultColor);
}

VOID Drawing::box(D3DXVECTOR2 p1, SIZE size, FLOAT lineWidth)
{
	this->box(p1, size, lineWidth, this->defaultColor);
}

VOID Drawing::box(D3DXVECTOR2 p1, SIZE size, FLOAT lineWidth, D3DXCOLOR color)
{
	D3DXVECTOR2 vertexList[5];
	vertexList[0] = p1;
	vertexList[1] = D3DXVECTOR2(p1.x + size.cx, p1.y);
	vertexList[2] = D3DXVECTOR2(p1.x + size.cx, p1.y + size.cy);
	vertexList[3] = D3DXVECTOR2(p1.x, p1.y + size.cy);
	vertexList[4] = p1;

	LPD3DXLINE line;
	D3DXCreateLine(this->device, &line);

	line->SetWidth(lineWidth);

	line->Begin();
	line->Draw(vertexList, 5, color);
	line->End();
	line->Release();
}


VOID Drawing::circle(D3DXVECTOR2 p1, FLOAT radius)
{
	this->circle(p1, radius, this->defaultCircleNumSides);
}

VOID Drawing::circle(D3DXVECTOR2 p1, FLOAT radius, INT numSides)
{
	this->circle(p1, radius, numSides, this->defaultColor);
}

VOID Drawing::circle(D3DXVECTOR2 p1, FLOAT radius, INT numSides, D3DCOLOR color)
{
	D3DXVECTOR2 vertexList[128];
	FLOAT step = (M_PI * 2.0) / numSides;
	INT count = 0;
	for (FLOAT i = 0; i < M_PI * 2.0; i += step)
	{
		vertexList[count].x = radius * cos(i) + p1.x;
		vertexList[count].y = radius * sin(i) + p1.y;
		vertexList[count + 1].x = radius * cos(i + step) + p1.x;
		vertexList[count + 1].y = radius * sin(i + step) + p1.y;
		count += 2;
	}

	LPD3DXLINE line;
	D3DXCreateLine(this->device, &line);

	line->Begin();
	line->Draw(vertexList, count, color);
	line->End();
	line->Release();
}


VOID Drawing::fill(D3DXVECTOR2 p1, SIZE size)
{
	this->fill(p1, size, this->defaultColor);
}

VOID Drawing::fill(D3DXVECTOR2 p1, SIZE size, D3DXCOLOR color)
{
	D3DXVECTOR2 vertexList[2];
	vertexList[0] = D3DXVECTOR2(p1.x + size.cx / 2, p1.y);
	vertexList[1] = D3DXVECTOR2(p1.x + size.cx / 2, p1.y + size.cy);
	
	LPD3DXLINE line;
	D3DXCreateLine(this->device, &line);

	line->SetWidth(size.cx);

	line->Begin();
	line->Draw(vertexList, 2, color);
	line->End();
	line->Release();
}


VOID Drawing::line(D3DXVECTOR2 p1, D3DXVECTOR2 p2)
{
	this->line(p1, p2, this->defaultLineWidth, this->defaultColor);
}

VOID Drawing::line(D3DXVECTOR2 p1, D3DXVECTOR2 p2, FLOAT lineWidth)
{
	this->line(p1, p2, lineWidth, this->defaultColor);
}

VOID Drawing::line(D3DXVECTOR2 p1, D3DXVECTOR2 p2, FLOAT lineWidth, D3DCOLOR color)
{
	D3DXVECTOR2 vertexList[] = { p1, p2 };

	LPD3DXLINE line;
	D3DXCreateLine(this->device, &line);

	line->SetWidth(lineWidth);

	line->Begin();
	line->Draw(vertexList, 2, color);
	line->End();
	line->Release();
}


VOID Drawing::text(PCHAR text, D3DXVECTOR2 origin, ID3DXFont *font)
{
	this->text(text, origin, font, this->defaultColor, FALSE);
}

VOID Drawing::text(PCHAR text, D3DXVECTOR2 origin, ID3DXFont *font, D3DCOLOR color)
{
	this->text(text, origin, font, color, FALSE);
}

VOID Drawing::text(PCHAR text, D3DXVECTOR2 origin, ID3DXFont *font, D3DCOLOR color, BOOL withShadow)
{
	SIZE_T size = strlen(text);

	if (withShadow)
	{
		RECT shadowRect1;
		shadowRect1.left = origin.x + 1;
		shadowRect1.top = origin.y;

		RECT shadowRect2;
		shadowRect2.left = origin.x - 1;
		shadowRect2.top = origin.y;

		RECT shadowRect3;
		shadowRect3.left = origin.x;
		shadowRect3.top = origin.y + 1;

		RECT shadowRect4;
		shadowRect4.left = origin.x;
		shadowRect4.top = origin.y - 1;

		D3DCOLOR shadowColor = D3DCOLOR_ARGB(255, 1, 1, 1);

		font->DrawTextA(0, text, size, &shadowRect4, DT_NOCLIP, shadowColor);
		font->DrawTextA(0, text, size, &shadowRect3, DT_NOCLIP, shadowColor);
		font->DrawTextA(0, text, size, &shadowRect2, DT_NOCLIP, shadowColor);
		font->DrawTextA(0, text, size, &shadowRect1, DT_NOCLIP, shadowColor);
	}

	RECT rect;
	rect.left = origin.x;
	rect.top = origin.y;

	font->DrawTextA(0, text, size, &rect, DT_NOCLIP, color);
}


VOID Drawing::text(PWCHAR text, D3DXVECTOR2 origin, ID3DXFont *font)
{
	this->text(text, origin, font, this->defaultColor, FALSE);
}

VOID Drawing::text(PWCHAR text, D3DXVECTOR2 origin, ID3DXFont *font, D3DCOLOR color)
{
	this->text(text, origin, font, color, FALSE);
}

VOID Drawing::text(PWCHAR text, D3DXVECTOR2 origin, ID3DXFont *font, D3DCOLOR color, BOOL withShadow)
{
	SIZE_T size = wcslen(text);

	if (withShadow)
	{
		RECT shadowRect1;
		shadowRect1.left = origin.x + 1;
		shadowRect1.top = origin.y;

		RECT shadowRect2;
		shadowRect2.left = origin.x - 1;
		shadowRect2.top = origin.y;

		RECT shadowRect3;
		shadowRect3.left = origin.x;
		shadowRect3.top = origin.y + 1;

		RECT shadowRect4;
		shadowRect4.left = origin.x;
		shadowRect4.top = origin.y - 1;

		D3DCOLOR shadowColor = D3DCOLOR_ARGB(255, 1, 1, 1);
		
		font->DrawTextW(0, text, size, &shadowRect4, DT_NOCLIP, shadowColor);
		font->DrawTextW(0, text, size, &shadowRect3, DT_NOCLIP, shadowColor);
		font->DrawTextW(0, text, size, &shadowRect2, DT_NOCLIP, shadowColor);
		font->DrawTextW(0, text, size, &shadowRect1, DT_NOCLIP, shadowColor);
	}

	RECT rect;
	rect.left = origin.x;
	rect.top = origin.y;

	font->DrawTextW(0, text, size, &rect, DT_NOCLIP, color);
}
#pragma endregion

#pragma region Colors
CONST D3DCOLOR Drawing::blackColor;
CONST D3DCOLOR Drawing::blueColor;
CONST D3DCOLOR Drawing::brownColor;
CONST D3DCOLOR Drawing::cyanColor;
CONST D3DCOLOR Drawing::goldColor;
CONST D3DCOLOR Drawing::grayColor;
CONST D3DCOLOR Drawing::greenColor;
CONST D3DCOLOR Drawing::maroonColor;
CONST D3DCOLOR Drawing::orangeColor;
CONST D3DCOLOR Drawing::pinkColor;
CONST D3DCOLOR Drawing::purpleColor;
CONST D3DCOLOR Drawing::redColor;
CONST D3DCOLOR Drawing::whiteColor;
CONST D3DCOLOR Drawing::yellowColor;
CONST D3DCOLOR Drawing::lightBlackColor;
CONST D3DCOLOR Drawing::lightBlueColor;
CONST D3DCOLOR Drawing::lightRedColor;
CONST D3DCOLOR Drawing::lightWhiteColor;
#pragma endregion

Drawing *drawing = new Drawing();