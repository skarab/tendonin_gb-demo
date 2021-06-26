include "include/hUGE.inc"

SECTION "Song Data", ROMX

ryukenden::
db 6
dw order_cnt
dw order1, order2, order3, order4
dw duty_instruments, wave_instruments, noise_instruments
dw routines
dw waves

order_cnt: db 24
order1: dw P0,P0,P0,P0,P12,P14,P0,P0,P0,P0,P12,P14
order2: dw P1,P1,P8,P8,P13,P15,P1,P1,P8,P8,P13,P15
order3: dw P2,P4,P4,P4,P11,P16,P17,P17,P17,P17,P11,P16
order4: dw P3,P6,P6,P6,P6,P6,P18,P3,P6,P6,P6,P6

P0:
 dn B_4,1,$000
 dn B_4,1,$C03
 dn E_5,1,$000
 dn E_5,1,$C03
 dn B_4,1,$000
 dn B_4,1,$C03
 dn G_5,1,$000
 dn G_5,1,$C03
 dn E_5,1,$000
 dn E_5,1,$C03
 dn F#5,1,$000
 dn F#5,1,$C03
 dn D_5,1,$000
 dn D_5,1,$C03
 dn A_4,1,$000
 dn A_4,1,$C03
 dn C#5,1,$000
 dn C#5,1,$C03
 dn E_5,1,$000
 dn E_5,1,$C03
 dn C#5,1,$000
 dn C#5,1,$C03
 dn B_4,1,$000
 dn B_4,1,$C03
 dn D#5,1,$000
 dn D#5,1,$C03
 dn F#5,1,$000
 dn F#5,1,$C03
 dn D#5,1,$000
 dn D#5,1,$C03
 dn ___,0,$000
 dn ___,0,$000
 dn B_4,1,$000
 dn B_4,1,$C03
 dn E_5,1,$000
 dn E_5,1,$C03
 dn B_4,1,$000
 dn B_4,1,$C03
 dn G_5,1,$000
 dn G_5,1,$C03
 dn E_5,1,$000
 dn E_5,1,$C03
 dn F#5,1,$000
 dn F#5,1,$C03
 dn D_5,1,$000
 dn D_5,1,$C03
 dn A_4,1,$000
 dn A_4,1,$C03
 dn C#5,1,$000
 dn C#5,1,$C03
 dn E_5,1,$000
 dn E_5,1,$C03
 dn C#5,1,$000
 dn C#5,1,$C03
 dn B_4,1,$000
 dn B_4,1,$C03
 dn D#5,1,$000
 dn D#5,1,$C03
 dn F#5,1,$000
 dn F#5,1,$C03
 dn D#5,1,$000
 dn D#5,1,$C03
 dn ___,0,$000
 dn ___,0,$000

P1:
 dn ___,0,$E00
 dn ___,0,$000
 dn ___,0,$000
 dn B_4,1,$C07
 dn B_4,1,$C02
 dn E_5,1,$C07
 dn E_5,1,$C02
 dn B_4,1,$C07
 dn B_4,1,$C02
 dn G_5,1,$C07
 dn G_5,1,$C02
 dn E_5,1,$C07
 dn E_5,1,$C02
 dn F#5,1,$C07
 dn F#5,1,$C02
 dn D_5,1,$C07
 dn D_5,1,$C02
 dn A_4,1,$C07
 dn A_4,1,$C02
 dn C#5,1,$C07
 dn C#5,1,$C02
 dn E_5,1,$C07
 dn E_5,1,$C02
 dn C#5,1,$C07
 dn C#5,1,$C02
 dn B_4,1,$C07
 dn B_4,1,$C02
 dn D#5,1,$C07
 dn D#5,1,$C02
 dn F#5,1,$C07
 dn F#5,1,$C02
 dn D#5,1,$C07
 dn D#5,1,$C02
 dn ___,0,$C07
 dn ___,0,$C02
 dn B_4,1,$C07
 dn B_4,1,$C02
 dn E_5,1,$C07
 dn E_5,1,$C02
 dn B_4,1,$C07
 dn B_4,1,$C02
 dn G_5,1,$C07
 dn G_5,1,$C02
 dn E_5,1,$C07
 dn E_5,1,$C02
 dn F#5,1,$C07
 dn F#5,1,$C02
 dn D_5,1,$C07
 dn D_5,1,$C02
 dn A_4,1,$C07
 dn A_4,1,$C02
 dn C#5,1,$C07
 dn C#5,1,$C02
 dn E_5,1,$C07
 dn E_5,1,$C02
 dn C#5,1,$C07
 dn C#5,1,$C02
 dn B_4,1,$C07
 dn B_4,1,$C02
 dn D#5,1,$C07
 dn D#5,1,$C02
 dn F#5,1,$C07
 dn F#5,1,$C02
 dn D#5,1,$C07

P2:
 dn ___,0,$E00
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08

P3:
 dn ___,0,$8ED
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn A#6,1,$000
 dn ___,0,$E00
 dn ___,0,$000
 dn A#6,1,$000
 dn A#6,1,$000
 dn G#6,2,$000
 dn ___,0,$E00

P4:
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn A_3,5,$000
 dn ___,0,$C08
 dn A_3,5,$000
 dn ___,0,$C08
 dn A_3,5,$000
 dn ___,0,$C08
 dn A_3,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn A_3,5,$000
 dn ___,0,$C08
 dn A_3,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn A_4,5,$000
 dn ___,0,$C08
 dn D#4,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn F#4,5,$000
 dn ___,0,$C08
 dn B_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08

P6:
 dn C_8,4,$000
 dn F#7,5,$000
 dn G#6,3,$000
 dn ___,0,$000
 dn C_8,4,$000
 dn F#7,5,$000
 dn G#5,2,$000
 dn ___,0,$000
 dn C_8,4,$000
 dn F#7,5,$000
 dn G#6,3,$000
 dn ___,0,$000
 dn C_8,4,$000
 dn F#7,5,$000
 dn G#5,2,$000
 dn ___,0,$000
 dn C_8,4,$000
 dn F#7,5,$000
 dn G#6,3,$000
 dn ___,0,$000
 dn C_8,4,$000
 dn F#7,5,$000
 dn G#5,2,$000
 dn ___,0,$000
 dn C_8,4,$000
 dn F#7,5,$000
 dn G#6,3,$000
 dn ___,0,$000
 dn C_8,4,$000
 dn F#7,5,$000
 dn G#5,2,$000
 dn ___,0,$000
 dn C_8,4,$000
 dn F#7,5,$000
 dn G#6,3,$000
 dn ___,0,$000
 dn C_8,4,$000
 dn F#7,5,$000
 dn G#5,2,$000
 dn ___,0,$000
 dn C_8,4,$000
 dn F#7,5,$000
 dn G#6,3,$000
 dn ___,0,$000
 dn C_8,4,$000
 dn F#7,5,$000
 dn G#5,2,$000
 dn ___,0,$000
 dn C_8,4,$000
 dn F#7,5,$000
 dn G#6,3,$000
 dn ___,0,$000
 dn C_8,4,$000
 dn F#7,5,$000
 dn G#5,2,$000
 dn ___,0,$000
 dn C_8,4,$000
 dn F#7,5,$000
 dn G#6,3,$000
 dn ___,0,$000
 dn C_8,4,$000
 dn F#7,5,$000
 dn G#5,2,$000
 dn ___,0,$000

P8:
 dn E_6,9,$07C
 dn ___,0,$E00
 dn B_5,9,$8FF
 dn ___,0,$E00
 dn ___,0,$000
 dn ___,0,$000
 dn B_5,9,$000
 dn ___,0,$E00
 dn ___,0,$000
 dn ___,0,$000
 dn B_5,9,$000
 dn ___,0,$E00
 dn E_6,9,$000
 dn ___,0,$E00
 dn ___,0,$000
 dn ___,0,$000
 dn A_5,9,$07C
 dn ___,0,$E00
 dn E_6,9,$000
 dn ___,0,$E00
 dn C#6,9,$000
 dn ___,0,$E00
 dn B_5,9,$07C
 dn ___,0,$E00
 dn ___,0,$000
 dn ___,0,$000
 dn A_5,9,$000
 dn ___,0,$E00
 dn B_5,9,$000
 dn ___,0,$E00
 dn ___,0,$000
 dn ___,0,$000
 dn E_6,9,$07C
 dn ___,0,$E00
 dn B_5,9,$000
 dn ___,0,$E00
 dn ___,0,$000
 dn ___,0,$000
 dn B_5,9,$000
 dn ___,0,$E00
 dn ___,0,$000
 dn ___,0,$000
 dn B_5,9,$000
 dn ___,0,$E00
 dn E_6,9,$000
 dn ___,0,$E00
 dn ___,0,$000
 dn ___,0,$000
 dn A_5,9,$07C
 dn ___,0,$E00
 dn E_6,9,$000
 dn ___,0,$E00
 dn D#6,9,$000
 dn ___,0,$E00
 dn B_5,9,$07C
 dn ___,0,$E00
 dn ___,0,$000
 dn ___,0,$000
 dn D#6,9,$000
 dn ___,0,$E00
 dn B_5,9,$000
 dn ___,0,$E00
 dn ___,0,$000
 dn ___,0,$000

P11:
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn D#4,5,$000
 dn ___,0,$C08
 dn D#4,5,$000
 dn ___,0,$C08
 dn D#4,5,$000
 dn ___,0,$C08
 dn D#4,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn G_3,5,$000
 dn ___,0,$C08
 dn G_3,5,$000
 dn ___,0,$C08
 dn G_3,5,$000
 dn ___,0,$C08
 dn G_3,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn D#4,5,$000
 dn ___,0,$C08
 dn D#4,5,$000
 dn ___,0,$C08
 dn D#4,5,$000
 dn ___,0,$C08
 dn D#4,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn G_3,5,$000
 dn ___,0,$C08
 dn G_3,5,$000
 dn ___,0,$C08
 dn G_3,5,$000
 dn ___,0,$C08
 dn G_3,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08

P12:
 dn B_4,12,$000
 dn E_5,12,$000
 dn D#4,12,$000
 dn A_4,12,$000
 dn D#5,12,$000
 dn F#5,12,$000
 dn D#5,12,$000
 dn B_4,12,$000
 dn F#4,12,$000
 dn D#4,12,$000
 dn B_3,12,$000
 dn D#4,12,$000
 dn F#4,12,$000
 dn B_4,12,$000
 dn G_4,12,$000
 dn E_4,12,$000
 dn G_4,12,$000
 dn B_4,12,$000
 dn F#5,12,$000
 dn E_5,12,$000
 dn B_4,12,$000
 dn G_4,12,$000
 dn B_4,12,$000
 dn E_5,12,$000
 dn E_5,12,$000
 dn G_5,12,$000
 dn G_5,12,$000
 dn B_5,12,$000
 dn B_5,12,$000
 dn E_6,12,$000
 dn E_4,12,$000
 dn G_4,12,$000
 dn B_4,12,$000
 dn E_5,12,$000
 dn D#4,12,$000
 dn A_4,12,$000
 dn D#5,12,$000
 dn F#5,12,$000
 dn D#5,12,$000
 dn B_4,12,$000
 dn F#4,12,$000
 dn D#4,12,$000
 dn B_3,12,$000
 dn D#4,12,$000
 dn F#4,12,$000
 dn B_4,12,$000
 dn G_4,12,$000
 dn E_4,12,$000
 dn G_4,12,$000
 dn B_4,12,$000
 dn F#5,12,$000
 dn E_5,12,$000
 dn B_4,12,$000
 dn G_4,12,$000
 dn B_4,12,$000
 dn E_5,12,$000
 dn E_5,12,$000
 dn G_5,12,$000
 dn G_5,12,$000
 dn B_5,12,$000
 dn B_5,12,$000
 dn E_6,12,$000
 dn E_4,12,$000
 dn G_4,12,$000

P13:
 dn ___,0,$8ED
 dn E_4,12,$C07
 dn G_4,12,$C07
 dn B_4,12,$C07
 dn E_5,12,$C07
 dn D#4,12,$C07
 dn A_4,12,$C07
 dn D#5,12,$C07
 dn F#5,12,$C07
 dn D#5,12,$C07
 dn B_4,12,$C07
 dn F#4,12,$C07
 dn D#4,12,$C07
 dn B_3,12,$C07
 dn D#4,12,$C07
 dn F#4,12,$C07
 dn B_4,12,$C07
 dn G_4,12,$C07
 dn E_4,12,$C07
 dn G_4,12,$C07
 dn B_4,12,$C07
 dn F#5,12,$C07
 dn E_5,12,$C07
 dn B_4,12,$C07
 dn G_4,12,$C07
 dn B_4,12,$C07
 dn E_5,12,$C07
 dn E_5,12,$C07
 dn G_5,12,$C07
 dn G_5,12,$C07
 dn ___,0,$E00
 dn ___,0,$000
 dn ___,0,$8ED
 dn E_4,12,$C07
 dn G_4,12,$C07
 dn B_4,12,$C07
 dn E_5,12,$C07
 dn D#4,12,$C07
 dn A_4,12,$C07
 dn D#5,12,$C07
 dn F#5,12,$C07
 dn D#5,12,$C07
 dn B_4,12,$C07
 dn F#4,12,$C07
 dn D#4,12,$C07
 dn B_3,12,$C07
 dn D#4,12,$C07
 dn F#4,12,$C07
 dn B_4,12,$C07
 dn G_4,12,$C07
 dn E_4,12,$C07
 dn G_4,12,$C07
 dn B_4,12,$C07
 dn F#5,12,$C07
 dn E_5,12,$C07
 dn B_4,12,$C07
 dn G_4,12,$C07
 dn B_4,12,$C07
 dn E_5,12,$C07
 dn E_5,12,$C07
 dn G_5,12,$C07
 dn G_5,12,$C07
 dn ___,0,$E00
 dn ___,0,$000

P14:
 dn B_4,12,$000
 dn E_5,12,$000
 dn D#4,12,$000
 dn A_4,12,$000
 dn D#5,12,$000
 dn F#5,12,$000
 dn D#5,12,$000
 dn B_4,12,$000
 dn F#4,12,$000
 dn D#4,12,$000
 dn B_3,12,$000
 dn D#4,12,$000
 dn F#4,12,$000
 dn B_4,12,$000
 dn G_4,12,$000
 dn E_4,12,$000
 dn G_4,12,$000
 dn B_4,12,$000
 dn F#5,12,$000
 dn E_5,12,$000
 dn B_4,12,$000
 dn G_4,12,$000
 dn B_4,12,$000
 dn E_5,12,$000
 dn E_5,12,$000
 dn G_5,12,$000
 dn G_5,12,$000
 dn B_5,12,$000
 dn B_5,12,$000
 dn E_6,12,$000
 dn E_4,12,$000
 dn G_4,12,$000
 dn B_4,12,$000
 dn E_5,12,$000
 dn D#4,12,$000
 dn A_4,12,$000
 dn D#5,12,$000
 dn F#5,12,$000
 dn D#5,12,$000
 dn B_4,12,$000
 dn F#4,12,$000
 dn D#4,12,$000
 dn B_3,12,$000
 dn D#4,12,$000
 dn F#4,12,$000
 dn B_4,12,$000
 dn G_4,12,$000
 dn E_4,12,$000
 dn G_4,12,$000
 dn B_4,12,$000
 dn F#5,12,$000
 dn E_5,12,$000
 dn B_4,12,$000
 dn G_4,12,$000
 dn B_4,12,$000
 dn E_5,12,$000
 dn E_5,12,$000
 dn B_4,12,$000
 dn B_4,12,$000
 dn G_4,12,$000
 dn G_4,12,$000
 dn E_4,12,$000
 dn ___,0,$000
 dn ___,0,$E00

P15:
 dn ___,0,$8ED
 dn E_4,12,$C07
 dn G_4,12,$C07
 dn B_4,12,$C07
 dn E_5,12,$C07
 dn D#4,12,$C07
 dn A_4,12,$C07
 dn D#5,12,$C07
 dn F#5,12,$C07
 dn D#5,12,$C07
 dn B_4,12,$C07
 dn F#4,12,$C07
 dn D#4,12,$C07
 dn B_3,12,$C07
 dn D#4,12,$C07
 dn F#4,12,$C07
 dn B_4,12,$C07
 dn G_4,12,$C07
 dn E_4,12,$C07
 dn G_4,12,$C07
 dn B_4,12,$C07
 dn F#5,12,$C07
 dn E_5,12,$C07
 dn B_4,12,$C07
 dn G_4,12,$C07
 dn B_4,12,$C07
 dn E_5,12,$C07
 dn E_5,12,$C07
 dn G_5,12,$C07
 dn G_5,12,$C07
 dn ___,0,$E00
 dn ___,0,$000
 dn ___,0,$8ED
 dn E_4,12,$C07
 dn G_4,12,$C07
 dn B_4,12,$C07
 dn E_5,12,$C07
 dn D#4,12,$C07
 dn A_4,12,$C07
 dn D#5,12,$C07
 dn F#5,12,$C07
 dn D#5,12,$C07
 dn B_4,12,$C07
 dn F#4,12,$C07
 dn D#4,12,$C07
 dn B_3,12,$C07
 dn D#4,12,$C07
 dn F#4,12,$C07
 dn B_4,12,$C07
 dn G_4,12,$C07
 dn E_4,12,$C07
 dn G_4,12,$C07
 dn B_4,12,$C07
 dn F#5,12,$C07
 dn E_5,12,$C07
 dn B_4,12,$C07
 dn G_4,12,$C07
 dn B_4,12,$C07
 dn E_5,12,$C07
 dn E_5,12,$C07
 dn B_4,12,$C07
 dn B_4,12,$C07
 dn ___,0,$000
 dn ___,0,$E00

P16:
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn D#4,5,$000
 dn ___,0,$C08
 dn D#4,5,$000
 dn ___,0,$C08
 dn D#4,5,$000
 dn ___,0,$C08
 dn D#4,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn G_3,5,$000
 dn ___,0,$C08
 dn G_3,5,$000
 dn ___,0,$C08
 dn G_3,5,$000
 dn ___,0,$C08
 dn G_3,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn D#4,5,$000
 dn ___,0,$C08
 dn D#4,5,$000
 dn ___,0,$C08
 dn D#4,5,$000
 dn ___,0,$C08
 dn D#4,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn B_3,5,$000
 dn ___,0,$C08
 dn G_3,5,$E04
 dn B_3,5,$E04
 dn G_3,5,$E04
 dn E_4,5,$E04
 dn B_3,5,$E04
 dn E_4,5,$E04
 dn B_3,5,$E04
 dn G_4,5,$E04
 dn E_4,5,$000
 dn ___,0,$C08

P17:
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn E_4,5,$000
 dn ___,0,$C08
 dn G_4,5,$000
 dn ___,0,$C08
 dn ___,0,$C06
 dn ___,0,$C04
 dn ___,0,$C02
 dn ___,0,$C00
 dn G_4,5,$000
 dn ___,0,$C08
 dn A_4,5,$000
 dn ___,0,$C08
 dn ___,0,$C06
 dn ___,0,$C04
 dn ___,0,$C02
 dn ___,0,$C00
 dn A_4,5,$000
 dn ___,0,$C08
 dn B_4,5,$000
 dn ___,0,$C08
 dn ___,0,$000
 dn B_4,5,$000
 dn ___,0,$C08
 dn ___,0,$000
 dn B_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn E_4,5,$000
 dn ___,0,$C08
 dn G_4,5,$000
 dn ___,0,$C08
 dn ___,0,$C06
 dn ___,0,$C04
 dn ___,0,$C02
 dn ___,0,$C00
 dn G_4,5,$000
 dn ___,0,$C08
 dn A_4,5,$000
 dn ___,0,$C08
 dn ___,0,$C06
 dn ___,0,$C04
 dn ___,0,$C02
 dn ___,0,$C00
 dn A_4,5,$000
 dn ___,0,$C08
 dn B_4,5,$000
 dn ___,0,$C08
 dn ___,0,$000
 dn B_4,5,$000
 dn ___,0,$C08
 dn ___,0,$000
 dn B_4,5,$000
 dn ___,0,$C08
 dn E_4,5,$000
 dn ___,0,$C08

P18:
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000
 dn ___,0,$000

duty_instruments:
itSquareinst1: db 8,128,240,128
itSquareinst2: db 8,64,240,128
itSquareinst3: db 8,128,240,128
itSquareinst4: db 8,192,240,128
itSquareinst5: db 8,0,241,128
itSquareinst6: db 8,64,241,128
itSquareinst7: db 8,128,241,128
itSquareinst8: db 8,192,241,128
itSquareinst9: db 8,192,240,128
itSquareinst10: db 8,128,240,128
itSquareinst11: db 8,128,240,128
itSquareinst12: db 8,128,241,128
itSquareinst13: db 8,128,240,128
itSquareinst14: db 8,128,240,128
itSquareinst15: db 8,128,240,128


wave_instruments:
itWaveinst1: db 0,32,0,128
itWaveinst2: db 0,32,1,128
itWaveinst3: db 0,32,2,128
itWaveinst4: db 0,32,3,128
itWaveinst5: db 0,32,4,128
itWaveinst6: db 0,32,5,128
itWaveinst7: db 0,32,6,128
itWaveinst8: db 0,32,7,128
itWaveinst9: db 0,32,8,128
itWaveinst10: db 0,32,9,128
itWaveinst11: db 0,32,10,128
itWaveinst12: db 0,32,11,128
itWaveinst13: db 0,32,12,128
itWaveinst14: db 0,32,13,128
itWaveinst15: db 0,32,14,128


noise_instruments:
itNoiseinst1: db 241,30,-5,-3,1,2,1,4
itNoiseinst2: db 241,0,14,5,2,-2,-4,4
itNoiseinst3: db 241,0,-14,9,10,10,10,10
itNoiseinst4: db 161,0,0,0,0,0,0,0
itNoiseinst5: db 65,0,0,0,0,0,0,0
itNoiseinst6: db 240,0,0,0,0,0,0,0
itNoiseinst7: db 240,0,0,0,0,0,0,0
itNoiseinst8: db 240,0,0,0,0,0,0,0
itNoiseinst9: db 240,0,0,0,0,0,0,0
itNoiseinst10: db 240,0,0,0,0,0,0,0
itNoiseinst11: db 240,0,0,0,0,0,0,0
itNoiseinst12: db 240,0,0,0,0,0,0,0
itNoiseinst13: db 240,0,0,0,0,0,0,0
itNoiseinst14: db 240,0,0,0,0,0,0,0
itNoiseinst15: db 240,0,0,0,0,0,0,0


routines:
__hUGE_Routine_0:

__end_hUGE_Routine_0:
ret

__hUGE_Routine_1:

__end_hUGE_Routine_1:
ret

__hUGE_Routine_2:

__end_hUGE_Routine_2:
ret

__hUGE_Routine_3:

__end_hUGE_Routine_3:
ret

__hUGE_Routine_4:

__end_hUGE_Routine_4:
ret

__hUGE_Routine_5:

__end_hUGE_Routine_5:
ret

__hUGE_Routine_6:

__end_hUGE_Routine_6:
ret

__hUGE_Routine_7:

__end_hUGE_Routine_7:
ret

__hUGE_Routine_8:

__end_hUGE_Routine_8:
ret

__hUGE_Routine_9:

__end_hUGE_Routine_9:
ret

__hUGE_Routine_10:

__end_hUGE_Routine_10:
ret

__hUGE_Routine_11:

__end_hUGE_Routine_11:
ret

__hUGE_Routine_12:

__end_hUGE_Routine_12:
ret

__hUGE_Routine_13:

__end_hUGE_Routine_13:
ret

__hUGE_Routine_14:

__end_hUGE_Routine_14:
ret

__hUGE_Routine_15:

__end_hUGE_Routine_15:
ret

waves:
wave0: db 0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255
wave1: db 0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255
wave2: db 0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255
wave3: db 0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255
wave4: db 0,1,18,35,52,69,86,103,120,137,154,171,188,205,222,239
wave5: db 254,220,186,152,118,84,50,16,18,52,86,120,154,188,222,255
wave6: db 122,205,219,117,33,19,104,189,220,151,65,1,71,156,221,184
wave7: db 15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15
wave8: db 254,252,250,248,246,244,242,240,242,244,246,248,250,252,254,255
wave9: db 238,221,204,187,169,136,118,101,68,50,17,0,0,0,0,0
wave10: db 132,17,97,237,87,71,90,173,206,163,23,121,221,32,3,71
wave11: db 197,125,122,123,227,83,25,229,152,226,81,189,185,1,22,221
wave12: db 157,59,28,129,99,51,105,235,235,68,124,113,123,155,42,234
wave13: db 165,153,117,225,59,33,234,137,116,54,151,113,179,217,162,179
wave14: db 93,49,59,139,172,2,149,222,24,108,116,58,216,218,194,51
wave15: db 212,116,28,212,106,161,211,136,83,209,75,153,160,94,73,58

