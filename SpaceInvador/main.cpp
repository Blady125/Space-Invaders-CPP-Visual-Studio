#include <iostream>
#include <vector>
#include "bullet.h"
#include "enemy.h"
#include "player.h"

bool gameOver = false;
bool fire;
const int width = 20;
const int height = 10;
int score;
unsigned long clock = 0;

// Vector for set of enemies
std::vector<Enemy> enemies;

void draw(Player p1)
{
	// Clear the terminal
	system("cls");
	// Top "border"
	for (int i = 0; i < width; i++)
	{
		std::cout << "#";
	}

	// Print new line
	std::cout << '\n';

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width + 3; j++)
		{
			// Left border
			if (j == 0)
				std::cout << '#';

			if (j > 0 && j < width - 1)
			{
				//Print Vector of bullets
				for (int k = 0; k < p1.bulletArray.size(); k++)
				{
					Bullet B = p1.bulletArray[k];
					if ((i == B.bulletGetPosY()) && (j == B.bulletGetPosX()))
					{
						B.drawBullet();
						goto skip;
					}
				}

				// Prints enemyies
				for (int n = 0; n < enemies.size(); n++)
				{
					// Enemy E = enemies[n];
					if ((i == enemies[n].enemyGetY()) && (j == enemies[n].enemyGetX()))
					{
						enemies[n].drawEnemy();
						goto skip;
					}
				}

				// Prints player
				if (i == height - 1 && j == p1.playerGetX())
				{
					p1.drawPlayer();
				}

				else
					std::cout << ' ';
			}
		skip:;
			// Right border
			if (j == width + 2)
				std::cout << "#";
		}
		std::cout << "\n";
	}
	// Bottom Border
	for (int i = 0; i < width; i++)
	{
		std::cout << "#";
	}
	// Score printed at the start of every "iteration"
	std::cout << "\n\nScore: " << score << "\n";

	// Lives printed at the start of every "iteration"
	std::cout << "\nLives: " << p1.playerGetLives() << "\n";
}

void input(Player *p1)
{
	// _kbhit - keyboard hit - returns 0 only if key is in keyboard buffer.
	if (_kbhit())
	{
		// Attempt to move player
		char inputChar = _getch();
		if (inputChar == 'a' || inputChar == 'd')
		{
			p1->playerMove(inputChar, width);
		}
		// Attempt to shoot
		if (inputChar == 'f')
		{
			fire = true;
			p1->shoot(inputChar);
		}
	}
}

void logic(Player *p1)
{
	// If player has 0 lives left, end the game.
	if (p1->Player::playerGetLives() <= 0)
	{
		gameOver = true;
	}

	// Move the bullet
	if (fire == true)
	{
		for (int r = 0; r < p1->bulletArray.size(); r++)
		{

			p1->bulletArray[r].moveBullet();
			if (p1->bulletArray[r].bulletGetPosY() > height)
			{
				p1->updateBullet(r);
			}
		}
	}
	// Destroy bullet and enemy on contact with something else.
	for (int k = 0; k < p1->bulletArray.size(); k++)
	{
		for (int l = 0; l < enemies.size(); l++)
		{
			Bullet B = p1->bulletArray[k];
			if ((B.bulletGetPosX() == enemies[l].enemyGetX()) && (B.bulletGetPosY() == enemies[l].enemyGetY()))
			{
				score += 10;
				enemies[l].resetEnemy(width);
				p1->updateBullet(k);
			}
		}
	}

	//Player contact with Enemy
	for (int k = 0; k < enemies.size(); k++)
	{
		if (enemies[k].enemyGetY() == height - 1 && p1->playerGetX() == enemies[k].enemyGetX())
		{
			score += 10;
			//enemyB = false;
			p1->Player::playerSetLives(p1->Player::playerGetLives() - 1);

			// enemy function that kill enemy object
			enemies[k].resetEnemy(width);
		}
	}

	//move enemy
	if (clock % 5 == 0)
	{
		for (int m = 0; m < enemies.size(); m++)
		{
			enemies[m].moveEnemy();
		}
	}

	//End game if enemy crosses bottom border
	for (int i = 0; i < enemies.size(); i++)
	{
		// Enemy ex = enemies[i];
		if (enemies[i].enemyGetY() == height)
		{
			gameOver = true;
			std::cout << "You died a horrific death";
			Sleep(1000);
		}
	}

	// // Add more enemies to the vector at time interval.
	if (clock % 100 == 0 && clock != 0)
	{
		enemies.push_back(Enemy(5, 0, 1, 1, 1, 'Q'));
	}

}

int main()
{	
	// Initial enemy
	enemies.push_back(Enemy(10, 0, 1, 1, 1, 'Q'));

	Player P1(width / 2 + 1, height - 1, 3);
	Player *p1_p = &P1;
	while (!gameOver)
	{
		draw(P1);
		input(p1_p);
		logic(p1_p);
		clock++;
		Sleep(100);
	}
}