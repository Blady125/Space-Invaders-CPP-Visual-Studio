#pragma once

#include <Windows.h>

class Bullet
{

public:
    Bullet();
    Bullet(int pX, int pY, int sX, int sY);
    int bulletPosX;
    int bulletPosY;
    int bulletSpeedX;
    int bulletSpeedY;
    char value;

    void bulletSetPosX(int x);
    void bulletSetPosY(int y);
    int bulletGetPosX();
    int bulletGetPosY();
    void bulletSetSpeedX(int x);
    void bulletSetSpeedY(int y);
    int bulletGetSpeedX();
    int bulletGetSpeedY();

    void drawBullet();
    void moveBullet();
};


