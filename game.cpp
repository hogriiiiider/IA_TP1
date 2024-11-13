#include "game.h"
#include "Gun.h"
#include <iostream>
#include <>

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

void Update(float deltaTime) {
    switch (mState) {
    case State::Idle:
        // Check if we can shoot or reload
        if (mAmmo <= 0) {
            SetState(State::Empty);
        }
        else {
            // Can shoot or reload
            if (mIsShooting) {
                mShootProgress += deltaTime;
                if (mShootProgress >= ShootTime) {
                    mAmmo--;
                    mIsShooting = false;
                    mShootProgress = 0.0f;
                    SetState(State::Idle);
                }
            }
            else if (mIsReloading) {
                mReloadProgress += deltaTime;
                if (mReloadProgress >= ReloadTime) {
                    mAmmo = mCapacity;
                    mIsReloading = false;
                    mReloadProgress = 0.0f;
                    SetState(State::Idle);
                }
            }
        }
        break;

    case State::Shoot:
        Shoot();
        break;

    case State::Reload:
        Reload();
        break;

    case State::Empty:
        if (mAmmo == 0) {
            SetState(State::Reload);
        }
        break;

    default:
        break;
    }

int main()
{
    Game game;
    Gun gun;
    bool running = true;
    float deltaTime = 0.1f;
        while (running)
        {
            if (_kbhit())
            {
                char key = _getch();
                std::cout << "Touche pressée : " << key << std::endl;
                gun.PrintState();
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