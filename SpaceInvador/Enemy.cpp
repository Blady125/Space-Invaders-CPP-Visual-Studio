#include "enemy.h"
#include <iostream>

bool enemyAlive;
int enemyPosX;
int enemyPosY;
int enemySpeedX;
int enemySpeedY;
int enemyHealth;
char icon;

Enemy::Enemy(int x, int y, int speedX, int speedY, int health, char i)
{
    enemyPosX = x;
    enemyPosY = y;
    enemySpeedX = speedX;
    enemySpeedY = speedY;
    enemyHealth = health;
    icon = i;
}
//SETTERS ---------------------------------------------
void Enemy::enemySetX(int x)
{
    enemyPosX = x;
}

void Enemy::enemySetY(int y)
{
    enemyPosY = y;
}

//GETTERS --------------------------------------------

int Enemy::enemyGetX()
{
    return enemyPosX;
}

int Enemy::enemyGetY()
{
    return enemyPosY;
}

//Functions -------------------------------------------

void Enemy::resetEnemy(int width) 
{
    enemySetX(1 + (rand() % (width - 2)));
    enemySetY(0);
}

void Enemy::drawEnemy()
{
    std::cout << icon;
}

void Enemy::moveEnemy()
{
    enemyPosY += 1;
}
