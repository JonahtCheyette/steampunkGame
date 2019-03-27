#pragma once
#include "stdafx.h"

class Player : public physicsApplied {
public:
    Player(SDL_Renderer* renderer, Draw draw);
    void move(SDL_Event& e, Level l, Object::Camera c, std::vector<Object::Tile> tileGrid, int &which, int maxLevel);
    void moveHook(std::vector<Object::Point> a);
    void grapple(Object::Point b, std::vector<Object::Tile> tileGrid, Object::Camera c);
    void changeHooks(std::vector<Object:: Point> b, int change, Object::Camera c);
    void draw(Object::Camera b, SDL_Renderer* renderer);

    //force to be applied in when moving the character using A and D
    float acceleration;
    //distance variables for applying extra force when your farther away than when you were last frame
    float distance;
    float pDistance;
    //general variables for grappling (i use them for multiple different things)
    float gX;
    float gY;
    //how fast the grapple moves
    float grappleSpeed;
    //what hook you have selected
    int selectedHook;
    //store what hook you have selected in case you switch mid grapple
    int selectedHookHolder;
    
    //save what state the player is in
    bool grappling;
    //slingshot or rope
    bool rope;
    //make sure that grappling is handled in the correct order
    int hookState;
    //make it so that changehooks isn't called every frame the key os held down
    bool changedHook;
    //makes it so utton presses activate Once
    bool clicked;
    
    float grapplerange = 700;
    
    //where thegrapple is aiming
    Object::Point target;
    //where the end of the grapple is
    Object::Point grappleHead;
    //the CUBE
    SDL_Texture* player;
};
