#pragma bank 3
const void __at(3) __bank_lines;

#include "gameboy.h"
#include <gb/drawing.h>

void Scene_Lines() BANKED
{
	LCDC_REG = 0xD1;
	
	set_default_palette();
	
	const short int minx = 0;
	const short int maxx = 159;
	short int miny = 0;
	const short int maxy = 142;
	
	short int x0s[7] = { minx, 0, 0, 0 };
	short int y0s[7] = { miny, 0, 0, 0 };
	short int x1s[7] = { maxx, 0, 0, 0 };
	short int y1s[7] = { miny, 0, 0, 0 };
	INT8 i = 0;
	
	short int dx0 = 0;
	short int dy0 = 4;
	short int dx1 = 0;
	short int dy1 = 4;
	
	unsigned int sync = 0;

	const INT8 max_length = 40;
	INT8 w, h;
	UINT8 col_max = 6;
	
	while (1)
	{
		++sync;
		if (sync==100)
		{
			col_max = 7;
			set_palette(0);
		}
		else if (sync==101)
		{
			set_palette(PALETTE(CBLACK, CGRAY, CSILVER, CWHITE));
		}
		else if (sync==205)
		{
			dx0 = -4;
			dy0 = 3;
			dx1 = 2;
			dy1 = -3;
		}
		else if (sync==270)
		{
			set_palette(PALETTE(CWHITE, CSILVER, CGRAY, CBLACK));
		}
		else if (sync==380)
		{
			set_palette(PALETTE(CBLACK, CGRAY, CSILVER, CWHITE));
			break;
		}
		
		short int x0 = x0s[i];
		short int y0 = y0s[i];
		short int x1 = x1s[i];
		short int y1 = y1s[i];
		
		if (x0+dx0<minx || x0+dx0>maxx) dx0 = -dx0; x0 += dx0;
		if (y0+dy0<miny || y0+dy0>maxy) dy0 = -dy0; y0 += dy0;
		if (x1+dx1<minx || x1+dx1>maxx) dx1 = -dx1; x1 += dx1;
		if (y1+dy1<miny || y1+dy1>maxy) dy1 = -dy1; y1 += dy1;
		
		if (sync>300)
		{
			w = abs(x0-x1);
			h = abs(y0-y1);
			
			if (w>max_length) x1 = x0 + (x1-x0)*max_length/w;
			if (h>max_length) y1 = y0 + (y1-y0)*max_length/h;
		}
		
		i = (i+1)%7;
		x0s[i] = x0;
		y0s[i] = y0;
		x1s[i] = x1;
		y1s[i] = y1;
		
		for (INT8 j=i-6 ; j<=i ; ++j)
		{
			INT8 col = 3-(((i-j)%7)*3/col_max);
			INT8 id = mod(j, 7);
			color(col, 0, SOLID);
			line(x0s[id], y0s[id], x1s[id], y1s[id]);
		}
	}
			
	for (int k=0 ; k<144 ; k += 2)
	{
		miny = k+1;
		
		short int x0 = x0s[i];
		short int y0 = y0s[i];
		short int x1 = x1s[i];
		short int y1 = y1s[i];
		
		if (x0+dx0<minx || x0+dx0>maxx) dx0 = -dx0; x0 += dx0;
		if (y0+dy0<miny || y0+dy0>maxy) dy0 = -dy0; y0 += dy0;
		if (x1+dx1<minx || x1+dx1>maxx) dx1 = -dx1; x1 += dx1;
		if (y1+dy1<miny || y1+dy1>maxy) dy1 = -dy1; y1 += dy1;
		
		w = abs(x0-x1);
		h = abs(y0-y1);
		
		if (w>max_length) x1 = x0 + (x1-x0)*max_length/w;
		if (h>max_length) y1 = y0 + (y1-y0)*max_length/h;
		
		i = (i+1)%7;
		x0s[i] = x0;
		y0s[i] = y0;
		x1s[i] = x1;
		y1s[i] = y1;
		
		for (INT8 j=i-6 ; j<=i ; ++j)
		{
			INT8 col = 3-(((i-j)%7)*3/7);
			INT8 id = mod(j, 7);
			color(col, 0, SOLID);
			if (y0s[id]>k && y1s[id] >k)
			{
				line(x0s[id], y0s[id], x1s[id], y1s[id]);
			}
		}
		
		color(BLACK, 0, SOLID);
		line(0, k, 159, k);
		line(0, k+1, 159, k+1);
	}
}
