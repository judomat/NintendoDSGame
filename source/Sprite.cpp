//
//  Sprite.c
//  SecondoDSAutocomplete
//
//  Created by Matteo Meluzzi on 12/12/19.
//  Copyright © 2019 Matteo Meluzzi. All rights reserved.
//

#include "Sprite.h"

Sprite::Sprite()
{
    this->gfx = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
}


Sprite::Sprite(const Vec2 &position, u8* gfx_frame) : Sprite()
{
    this->position = position;
    this->gfx_frame = gfx_frame;
}

Sprite::Sprite(const Vec2 &position, u8 *gfx_frame, const Animation &animation) : Sprite(position, gfx_frame)
{    
    this->animation = animation;
}

void Sprite::draw(int frameCount)
{
    dmaCopy(this->gfx_frame + this->animation.indexCurrentFrame * 32*32, this->gfx, spritesTilesLen);
    if (frameCount % (this->animation.skipFrames + 1) != 0)
        return;
    this->animation.indexCurrentFrame += this->animation.increment;
    if (abs(this->animation.indexCurrentFrame - this->animation.indexStartFrame) >= this->animation.length)
        this->animation.indexCurrentFrame = this->animation.indexStartFrame;
}
