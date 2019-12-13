//
//  Scene.c
//  SecondoDSAutocomplete
//
//  Created by Matteo Meluzzi on 12/12/19.
//  Copyright © 2019 Matteo Meluzzi. All rights reserved.
//

#include "Scene.h"
#include "Player.h"

#include "sprites.h"

#include <stdio.h>

Scene::Scene(int width, int heigth)
{
    this->width = width;
    this->heigth = heigth;
}

void Scene::initialize()
{
    Player *character = new Player({32,32}, (u8*)spritesTiles);
    character->animation.indexStartFrame = 0;
    character->animation.length = 107;
    character->animation.skipFrames = 10;
    addChild(character);

    Animation a;
    a.increment = -1;
    a.indexCurrentFrame = 177;
    a.indexStartFrame = 177;
    a.length = 178;
    a.skipFrames = 1;
    Sprite *character2 = new Sprite({64,64}, (u8*)spritesTiles, a);
    addChild(character2);
}

void Scene::addChild(Sprite *child)
{
    this->children.push_back(child);
    child->scene = this;
}

void Scene::removeChild(vector<Sprite *>::const_iterator index)
{
    int indexInt = index - children.begin();
    children[indexInt]->scene = nullptr;
    if (index >= children.begin() && index < children.end())
        children.erase(index);
}

void Scene::removeChild(int index)
{
    removeChild(children.begin() + index);
}

void Scene::removeChild(Sprite *child)
{
    auto index = find(children.begin(), children.end(), child);
    removeChild(index);
}

void Scene::update(int frameCount)
{
    for (Sprite *child : this->children)
    {
        child->update(frameCount);
    }
    
    int index = 0;
    for (Sprite *child: this->children)
    {
        child->draw(frameCount);
        oamSet(&oamMain, index,
               child->position.x, child->position.y,
               0, 15,
               SpriteSize_32x32,
               SpriteColorFormat_256Color,
               child->gfx,
               -1, false, false, false, false, false);
        index++;
    }
}
