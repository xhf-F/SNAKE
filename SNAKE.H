#ifndef SNAKE_H
#define SNAKE_H

#include<iostream>
#include<iomanip>
#include<cmath>
#include<ctime> //for sleep using
#include<string>
#include<cstdlib> //for rand() using
#include<cstdio>
#include<conio.h> //for keyboard control input


bool gameover; // control start/end the game
const int width = 20;
const int height = 20; // the size of the wall
int x, y, fruitX, fruitY; //coordinates of head, fruit
int score; 
int tailX[50], tailY[50]; //coordinates (array) of tails
int numtail; //the number of tails 

enum eDirection {STOP, LEFT, RIGHT, UP, DOWN};
eDirection dir;


void Setup() {
	gameover = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = std::rand() % (width-1) + 1;
	fruitY = std::rand() % (height-1) + 1;
	score = 0;
	
}	

void Draw() {

	system("clear");
	for (int j = 0; j < height; j++) {
		
		for (int i = 0; i < width; i++) {
			if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
				std::cout << "#"; //draw the wall
			}
			else {  if (i == x && j == y) {std::cout << "0";} //draw the head
			
				else if (i == fruitX && j == fruitY) {std::cout << "*";} //draw fruit
				else {
					bool ifprint = false;
					for (int k = 0; k < numtail; k++) {
						
						if (tailX[k] == i && tailY[k] == j) {
							std::cout << "o"; //draw the tails
							ifprint = true;
						}
						
					}
					if (!ifprint) {std::cout << " ";} //otherwise, draw empty background
				}
			}
			
		}
		std::cout << std::endl;
		
	}
	std::cout << "SCORE: " << score << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << "Control  Key" << std::endl;
	std::cout << "UP:      i/I" << std::endl;
	std::cout << "DOWN:    k/K" << std::endl;
	std::cout << "LEFT:    j/J" << std::endl;
	std::cout << "RIGHT:   l/L" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "Please press any key above to start..." << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "Press e/E/q/Q to exit." << std::endl;
	//std::cout << "Press s/S to stop." << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	
}

void Input() {

	if (kbhit()) {
		switch (getch()) {
			case 'j':
			case 'J':
				dir = LEFT;
				break;
			case 'l':
			case 'L':
				dir = RIGHT;
				break;
			case 'i':
			case 'I':
				dir = UP;
				break;
			case 'k':
			case 'K':
				dir = DOWN;
				break;
			//case 's':
			//case 'S':
			//	dir = STOP;
			//	break;
			case 'e':
			case 'E':
			case 'q':
			case 'Q':
				gameover = true;
				std::cout << std::endl;
				std::cout << "Exit. See you next time!" << std::endl;
				break;
			//
			//	gameover = true;	
			//	break;
		}
	}
}

int renew() {
	fruitX = std::rand() % (width-1) + 1; 
	fruitY = std::rand() % (height-1) + 1;
	return fruitX, fruitY;
}



void Logic() {
	
	int prevTx = tailX[0];
	int prevTy = tailY[0];
	int prev2x, prev2y;
	tailX[0] = x;
	tailY[0] = y;

///
/// tails follow the one before them, the first tail follows the head
///
	//if (dir != STOP) {
	for (int k = 1; k < numtail; k++) {
		prev2x = tailX[k];
		tailX[k] = prevTx;
		prevTx = prev2x; 
		prev2y = tailY[k];
		tailY[k] = prevTy;
		prevTy = prev2y; 
	
	}
	//}


	switch (dir) {
		//case STOP:
			//x = x;
			//y = y; //I am trying to fix the STOP bug and we can use the STOP function.
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



///
/// head hits the wall and then gameover --version 1
///
	//if (x > width || x < 0 || y > height || y < 0) {std::cout << std::endl; std::cout << "Hit the wall!! Gameover:(" << std::endl; gameover = true;}

///
/// head hits the wall and then appears from the other side --version 2
///
	if (x > width) x = 0; else if (x < 0) x = width -1;
	if (y > height) y = 0; else if (y < 0) y = height -1;

///
/// head hits its tails and then gameover
///
	for (int k = 0; k < numtail; k++) {
		if (tailX[k] == x && tailY[k] == y) {
			std::cout << std::endl;
			std::cout << "Hit the tail!! Gameover:(" << std::endl; 
			gameover = true;
		}
	}



///
/// eat the fruit and then renew the position of the fruit
///
	if (x == fruitX && y == fruitY) {
		score += 10;
		//fruitX, fruitY = renew();
		numtail++;
		bool fruitsnake = true;
		while (fruitsnake) {fruitX, fruitY = renew(); fruitsnake = false;}
		//while (fruitsnake) {
		//	fruitX, fruitY = renew();
		//	for (int k = 0; k < numtail; k++) {
		//		if (tailX[k] == fruitX && tailY[k] == fruitY) {fruitsnake = true; fruitX, fruitY = renew();}
		//		else {fruitsnake = false;}
		//	}
		//} //this trys to fix the bug that the new fruit appears within the snake body.
		
	
	}
}

#endif
