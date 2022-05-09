#include<iostream>
#include<ctime>
#include<unistd.h>

#include"SNAKE.H"

int main() {
	

	Setup();
	while (!gameover) {
		
		Draw();
		sleep(1);
		Input();
		Logic();
		//sleep(1);	
	}
	
	return 0;

}
