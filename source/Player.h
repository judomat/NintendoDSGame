//
//  Player.h
//  SecondoDSAutocomplete
//
//  Created by Matteo Meluzzi on 12/12/19.
//  Copyright © 2019 Matteo Meluzzi. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include "Sprite.h"

class Player: public Sprite
{
public:
    virtual void update(int frameCount) override
    {
        Sprite::update(frameCount);
    }
    
    /*virtual void draw(int frameCount) override
    {
        dmaCopy(this->gfx_frame + 2*32*32, this->gfx, spritesTilesLen);
    }*/
    
    Player() : Sprite(){};
    
    Player(Vec2 position, u8* gfx_frame) : Sprite(position, gfx_frame){
    }
    
    Player(Vec2 position, u8* gfx_frame, Animation animation): Sprite(position, gfx_frame, animation) {
    }


};

#endif /* Player_h */
