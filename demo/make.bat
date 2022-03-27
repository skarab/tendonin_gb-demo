@echo off
del *.gb
call make_resources.bat
@echo building asm files...
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o vgmplayer.o src\vgmplayer.s
@echo building c files...
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o gameboy.o src\gameboy.c
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o demo.o src\demo.c
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o erase.o src\erase.c
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o shake.o src\shake.c
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o sega.o src\sega.c
@echo building c files...
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o lines.o src\lines.c
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o cube.o src\cube.c
@echo building c files...
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o noise.o src\noise.c
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o fire.o src\fire.c
@echo building c files...
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o axelay.o src\axelay.c
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o sprites_physics.o src\sprites_physics.c
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o squares_zoom.o src\squares_zoom.c
@echo building c files...
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o squares_race.o src\squares_race.c
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o rain.o src\rain.c
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o vbarrels.o src\vbarrels.c
@echo building c files...
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o kiss.o src\kiss.c
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o funky_girl.o src\funky_girl.c
@echo building c files...
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o alien_girl.o src\alien_girl.c
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o senses.o src\senses.c
..\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yt26 -c -o logo.o src\logo.c
@echo building banks...
..\gbdk\bin\bankpack -ext=.rel -v -yt19 vgmplayer.o gameboy.o demo.o shake.o erase.o sega.o lines.o cube.o noise.o fire.o axelay.o sprites_physics.o squares_zoom.o squares_race.o rain.o vbarrels.o kiss.o funky_girl.o alien_girl.o senses.o logo.o
@echo linking...
..\gbdk\bin\lcc -Wl-yo256 -Wl-ya1 -Wa-l -Wl-m -Wl-j -Wl-yt26 -o demo.gb vgmplayer.rel gameboy.rel demo.rel shake.rel erase.rel sega.rel lines.rel cube.rel noise.rel fire.rel axelay.rel sprites_physics.rel squares_zoom.rel squares_race.rel rain.rel vbarrels.rel kiss.rel funky_girl.rel alien_girl.rel senses.rel logo.rel
@echo inject music...
..\tools\inject\Debug\inject.exe tmp\music demo.gb
@echo fix checksum...
..\tools\rgbds\rgbfix.exe -f g demo.gb
@echo cleaning...
del *.map
del *.rel
del *.asm
del *.o
del *.sym
del *.ihx
del *.lst
del *.noi
