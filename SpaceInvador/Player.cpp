#include "Bullet.h"
#include "Player.h"
#include <vector>
#include <conio.h>
#include <iostream>

int playerPosX;
int playerPosY;
int playerLives;
bool hasShot;
std::vector<Bullet> bulletArray;
Bullet b1;

Player::Player(const int x, const int y, const int i) {
    playerPosX = x;
    playerPosY = y;
    playerLives = i;
    hasShot = false;
}

//SETTERS ---------------------------------------------
void Player::playerSetX(int x)
{
    playerPosX = x;
}

void Player::playerSetLives(int x)
{
    playerLives = x;
}

int Player::playerGetX()
{
    return playerPosX;
}

int Player::playerGetLives()
{
    return playerLives;
}

void Player::drawPlayer()
{
    std::cout << 'A';
}

void Player::shoot(char x)
{
    if (x == 'f') 
    {
        bulletArray.push_back(Bullet(playerPosX, playerPosY - 1, 0, -1));
    }
}

void Player::playerMove(char x, int width)
{
    if (x == 'a' && playerPosX > 1)
    {
        playerPosX--;
    }
    else if (x == 'd' && playerPosX < width - 2)
    {
        playerPosX++;
    }
}

void Player::updateBullet(int pos) 
{
    bulletArray.erase(bulletArray.begin()+pos);
}