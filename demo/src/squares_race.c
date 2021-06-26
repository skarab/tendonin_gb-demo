#pragma bank 6
const void __at(6) __bank_squares_race;

#include "gameboy.h"

extern const unsigned int squares_zoom_tiledata_count;
extern const unsigned char squares_zoom_tiledata[];
extern const unsigned int squares_zoom_tilemap0_count;
extern const unsigned char squares_zoom_tilemap0[];
extern const unsigned int squares_zoom_tilemap1_count;
extern const unsigned char squares_zoom_tilemap1[];
extern const unsigned int squares_zoom_tilemap2_count;
extern const unsigned char squares_zoom_tilemap2[];

#define race_loop 40
#define race_divide 12
#define race_i_mul 12/8
UINT8 squares_precalc_x[72][race_loop];
UINT8 squares_precalc_y[72][race_loop];

void squares_race_precalc()
{
	for (UINT8 i = 0 ; i<race_loop ; ++i)
	{
		UINT8 old_size = ((i*race_i_mul)*(i*race_i_mul))/race_divide;
		UINT8 s = ((i*race_i_mul)/race_divide)&1;
	
		for (UINT8 j = 0 ; j<72 ; ++j)
		{
			UINT8 square_size = j*2/3 + 16;
			UINT8 p = (j+(i*race_i_mul))/race_divide;
			UINT8 psquare_size = p*p;
			
			if (psquare_size!=old_size)
			{
				old_size = psquare_size;
				s = !s;
			}
			
			UINT8 add = 0;
			if (s!=0) add = square_size;
			
			UINT8 sin = j*sintable[i*3]/64;
		
			squares_precalc_x[j][i] = (add + j + sin) % (square_size*2);
			squares_precalc_y[j][i] = (square_size - 16)*4;
		}
	}
}

UINT8 race_anim = 0;

void squares_race_vbl()
{
	++race_anim;
	if (race_anim>=race_loop)
		race_anim = 8;
}

void squares_race_lcd()
{
	UINT8 y = LY_REG;
	
	if (y<30)
	{
		UINT8 cy = 72-y*2-6;
		UINT8 ra = race_anim;
		UINT8 sx = squares_precalc_x[cy][ra];
		UINT8 sy = squares_precalc_y[cy][ra]-y;
		SCX_REG = sx;
		SCY_REG = sy;
	}
	else if (y<80)
	{
		SCY_REG = -y-10;
		SCX_REG = 0;
	}
	else
	{
		UINT8 cy = y-80;
		UINT8 ra = race_anim;
		UINT8 sx = squares_precalc_x[cy][ra];
		UINT8 sy = squares_precalc_y[cy][ra]-y;
		SCX_REG = sx;
		SCY_REG = sy;
	}
}

void Scene_SquaresRace() BANKED
{
	squares_race_precalc();
	
	disable_interrupts();
	DISPLAY_OFF;
	//mode(0);
	HIDE_WIN;
	set_palette(PALETTE(CWHITE, CSILVER, CGRAY, CBLACK));
	set_bkg_data(0, squares_zoom_tiledata_count, squares_zoom_tiledata);
	set_bkg_tiles(0, 0, 32, 8, squares_zoom_tilemap0);
	set_bkg_tiles(0, 8, 32, 8, squares_zoom_tilemap1);
	set_bkg_tiles(0, 16, 32, 6, squares_zoom_tilemap2);
	
	CRITICAL {
        STAT_REG = 0x18;
		add_VBL(squares_race_vbl);
		add_LCD(squares_race_lcd);
	}
    set_interrupts(LCD_IFLAG | VBL_IFLAG);
	
	DISPLAY_ON;
	enable_interrupts();
	
	while (1)
	{	
		wait_vbl_done();		
    }
	/*
	CRITICAL {
        remove_VBL(squares_race_vbl);
		remove_LCD(squares_race_lcd);
	}*/
}
