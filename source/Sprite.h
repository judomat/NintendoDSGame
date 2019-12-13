//
//  Sprite.h
//  SecondoDSAutocomplete
//
//  Created by Matteo Meluzzi on 12/12/19.
//  Copyright © 2019 Matteo Meluzzi. All rights reserved.
//

#ifndef Sprite_h
#define Sprite_h

#include "utils.h"
#include "Updatable.h"
#include "Drawable.h"

#include "sprites.h"

#include <stdio.h>

class Scene;

typedef struct
{
    int indexStartFrame = 0;
    int indexCurrentFrame = 0;
    int length = 0;
    int skipFrames = 0;
    int increment = 1;
} Animation;

class Sprite : public Updatable, public Drawable
{
public:
    Vec2 position;
    u16* gfx; // oam GFX
    u8* gfx_frame;
    
    Scene *scene;
    Animation animation;
        
    virtual void update(int frameCount) override{}
    
    virtual void draw(int frameCount) override;

    Sprite();
    Sprite(const Vec2 &position, u8* gfx_frame);
    Sprite(const Vec2 &position, u8* gfx_frame, const Animation &animation);
};

#endif /* Sprite_h */
