#pragma once

#include <Windows.h>
#include <vector>
#include <iostream>
#include <conio.h>


class Player
{

public:
    int playerPosX;
    int playerPosY;
    int playerLives;
    bool hasShot;
    char value = 'A';
    std::vector<Bullet> bulletArray;
    Bullet b1;

    void playerSetX(int x);
    int playerGetX();
    void playerSetLives(int x);
    int playerGetLives();
    void drawPlayer();
    void shoot(char x);
    void playerMove(char x, int width);
    void updateBullet(int pos);


    Player (const int x, const int y, const int i);
        
};


