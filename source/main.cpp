/*---------------------------------------------------------------------------------

	Basic template code for starting a DS app

---------------------------------------------------------------------------------*/
#include <nds.h>
#include <stdio.h>

#include "Player.h"
#include "Scene.h"

#include "sprites.h"

#define spritesNumberInImage    178
#define screenWidth             256
#define screenHeigth            192

void addBackground();

int main()
{
    videoSetModeSub(MODE_0_2D);
    vramSetBankC(VRAM_C_SUB_BG);
    PrintConsole bottomScreen;
    consoleInit(&bottomScreen, 3,BgType_Text4bpp, BgSize_T_256x256, 31, 0, false, true);
    consoleSelect(&bottomScreen);
    iprintf("Hello World!");
    
    videoSetMode(MODE_0_2D);
    vramSetBankA(VRAM_A_MAIN_SPRITE);
    oamInit(&oamMain, SpriteMapping_1D_128, false);
        
    dmaCopy(spritesPal, SPRITE_PALETTE, spritesPalLen);
    
    for (int i = 0; i < spritesPalLen; i++)
    {// invert red and blue
        u16 color = SPRITE_PALETTE[i];
        u16 c1 = color & 0x1f;
        u16 c2 = color & 0x3e0;
        u16 c3 = color & 0x7c00;
        SPRITE_PALETTE[i] = (c1 << 10 | c2 | c3 >> 10);
    }
    
    Scene *gameScene = new Scene(screenWidth, screenHeigth);
    gameScene->initialize();
    
    int frame = 0;
    while(1)
    {
        ++frame;
        gameScene->update(frame);
        
        swiWaitForVBlank();
        oamUpdate(&oamMain);
    }

    return 0;
}
