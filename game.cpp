#include "game.h"
#include "Gun.h"
#include <iostream>


Game::Game() : gun(10, 0.2f, 0.5f){}

void Game::HandleInput(char input)
{
    if (input == 's') {
        gun.Shoot();
    }
        
    if (input == 'r') {
        gun.Reload();
    }
}


int main()
{
    Game game;
    bool running = true;
    float deltaTime = 0.1f;
        while (running)
        {
            if (_kbhit())
            {
                char key = _getch();
                std::cout << "Touche pressée : " << key << std::endl;
                
                if (key == 27)
                {
                    running = false;
                }
                else {
                    game.HandleInput(key);
                }

            }
            game.Update(deltaTime);
            Sleep(500);
        }
    return 0;
}