//
//  Scene.h
//  SecondoDSAutocomplete
//
//  Created by Matteo Meluzzi on 12/12/19.
//  Copyright © 2019 Matteo Meluzzi. All rights reserved.
//

#ifndef Scene_h
#define Scene_h

#include <nds.h>
#include <vector>
#include <algorithm>    // std::find

#include "Updatable.h"

using namespace std;

class Sprite;

class Scene: public Updatable
{
private:
    int width, heigth;
    vector<Sprite *> children;
public:
    Scene(int width, int heigth);
    
    void initialize();
    
    void addChild(Sprite *child);
    void removeChild(Sprite *child);
    void removeChild(vector<Sprite *>::const_iterator index);
    void removeChild(int index);
    
    virtual void update(int frameCount);
};

#endif /* Scene_h */
