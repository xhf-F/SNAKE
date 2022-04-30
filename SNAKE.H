#ifndef SNAKE_H
#define SNAKE_H

#include<iostream>
#include<cmath>
#include<ctime>
#include<string>
#include<cstdlib> ///for rand() using
#include<cstdio>
#include<conio.h>
///#include<ncurses.h>

bool gameover;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[50], tailY[50];
int numtail;
//int sec;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;


void Setup() {
	gameover = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = std::rand() % width;
	fruitY = std::rand() % height;
	score = 0;
	
}	

void Draw() {

	system("clear");
	for (int j = 0; j < height; j++) {
		
		for (int i = 0; i < width; i++) {
			if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
				std::cout << "#";
			}
			else {  if (i == x && j == y) {std::cout << "0";}
			
				else if (i == fruitX && j == fruitY) {std::cout << "*";}
				else {
					bool ifprint = false;
					for (int k = 0; k < numtail; k++) {
						
						if (tailX[k] == i && tailY[k] == j) {
							std::cout << "o";
							ifprint = true;
						}
						
					}
					if (!ifprint) {std::cout << " ";}
				}
			}
			
		}
		std::cout << std::endl;
		
	}
	std::cout << "score: " << score << std::endl;
}

void Input() {

	if (kbhit()) {
		switch (getch()) {
			case 'j':
				dir = LEFT;
				break;
			case 'l':
				dir = RIGHT;
				break;
			case 'i':
				dir = UP;
				break;
			case 'k':
				dir = DOWN;
				break;
			case 'e':
				gameover = true;
				break;
			case 'q':
				gameover = true;
				break;
		}
	}
}

void Logic() {
	
	int prevTx = tailX[0];
	int prevTy = tailY[0];
	int prev2x, prev2y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < numtail; i++) {
		prev2x = tailX[i];
		tailX[i] = prevTx;
		prevTx = prev2x; 
		prev2y = tailY[i];
		tailY[i] = prevTy;
		prevTy = prev2y; 
	
	}
	switch (dir) {
		//case STOP:
		//	break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;
	}
	if (x > width || x < 0 || y > height || y < 0) {gameover = true;}
	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = std::rand() % (width-1) + 1;
		fruitY = std::rand() % (height-1) + 1;
		numtail++;
	}
}

#endif
