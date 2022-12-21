#include "raylib.h"

#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
class BaseCharacter
{
public:
    BaseCharacter();
    virtual void tick(float deltaTime);

    Vector2 getWorldPos() { return worldPos; }
    void undoMovement();
    Rectangle getCollisionRec();
    virtual Vector2 getScreenPos() = 0;

    bool getAlive(){ return alive;};
    void setAlive(bool isAlive){ alive = isAlive;}; 

protected:
    Texture2D texture = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D idle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D run = LoadTexture("characters/knight_run_spritesheet.png");

    Vector2 worldPos{};
    Vector2 worldPosLastFrame{worldPos};

    float rightLeft{1.f};

    float runningTime{};
    float frame{};
    int maxFrames{6};
    float updateTime{1.f / 12.f};
    float speed{4.f};
    float width{};
    float height{};
    float scale{4.f};
    Vector2 velocity{};

private:
    bool alive {true};
};

#endif
