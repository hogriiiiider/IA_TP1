#include <iostream>
#include "gun.h"
#include <conio.h>
#include <Windows.h>

class Game
{
	

public:
	Game();
	Gun gun;
	void  Update(float deltaTime);
	void HandleInput(char Input);

};


