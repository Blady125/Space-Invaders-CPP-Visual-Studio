#include "Bullet.h"
#include <iostream>

int bulletPosX;
int bulletPosY;
int bulletSpeedX;
int bulletSpeedY;

//SETTERS ---------------------------------------------
void Bullet::bulletSetPosX(int x)
{
    bulletPosX = x;
}

void Bullet::bulletSetPosY(int y)
{
    bulletPosY = y;
}

void Bullet::bulletSetSpeedX(int x)
{
    bulletSpeedX = x;
}

void Bullet::bulletSetSpeedY(int y)
{
    bulletSpeedY = y;
}

//GETTERS ---------------------------------------------
int Bullet::bulletGetPosX()
{
    return bulletPosX;
}

int Bullet::bulletGetPosY()
{
    return bulletPosY;
}

int Bullet::bulletGetSpeedX()
{
    return bulletSpeedX;
}

int Bullet::bulletGetSpeedY()
{
    return bulletSpeedY;
}

char value;
//CONSTRUCTORS ---------------------------------------------
Bullet::Bullet() 
{
    bulletPosX = 0;
    bulletPosY = 0;
    bulletSpeedX = 0;
    bulletSpeedY = -1;
    value = '.';
}
Bullet::Bullet(int pX, int pY, int sX, int sY)
{
    bulletPosX = pX;
    bulletPosY = pY;
    bulletSpeedX = sX;
    bulletSpeedY = sY;
    value = '.';
}

//FUNCTIONS -----------------------------------------------

void Bullet::drawBullet()
{
    std::cout << value;
}

void Bullet::moveBullet()
{
    bulletPosY--;
}
