#pragma once

#include <Windows.h>

class Enemy
{

public:
    bool enemyAlive;
    int enemyPosX;
    int enemyPosY;
    int enemySpeedX;
    int enemySpeedY;
    int enemyHealth;
    char enemyIcon;

    void enemySetX(int x);
    void enemySetY(int y);
    int enemyGetX();
    int enemyGetY();
    void resetEnemy(int width);

    void drawEnemy();
    void moveEnemy();

    //CONSTRUCTORS ---------------------------------------------
    Enemy(int x, int y, int speedX, int speedY, int health, char i);
};
