#include "game.h"
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



void Game::Update(float deltaTime)
{
    if (gun.mIsReloading) {
        gun.mReloadProgress += deltaTime;
        if (gun.mReloadProgress >= gun.ReloadTime) {
            gun.mReloadProgress = 0.0f;
            gun.mIsReloading = false;
            std::cout << "Reload complete ! Ammo = " << gun.mAmmo << std::endl;
        }
        else {
            std::cout << "Wait to reload... " << gun.mAmmo << std::endl;
        }

    }
    if (gun.mIsShooting) {
        gun.mShootProgress += deltaTime;
        if (gun.mShootProgress >= gun.ShootTime) {
            gun.mShootProgress = 0.0f;
            gun.mIsShooting = false;
            std::cout << " Shoot !  Ammo = " << gun.mAmmo << std::endl;

        }
        else {
            std::cout << "Already shooting!" << gun.mAmmo << std::endl;
        }
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