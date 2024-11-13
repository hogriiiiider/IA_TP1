// Projet IA exo.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "gun.h"
#include "game.h"

Gun::Gun(int Capacity, float ReloadTime, float ShootTime) : mAmmo(Capacity), mCapacity(Capacity), mIsReloading(false), mIsShooting(false), ReloadTime(ReloadTime), ShootTime(ShootTime), mReloadProgress(0.0f), mShootProgress(0.0f) {

}



void Gun::Shoot()
{
    if (!mIsReloading && !mIsShooting && mAmmo > 0) {
        mAmmo--;
        mIsShooting = true;
        std::cout << "I am shooting\n";
    }

}

void Gun::Reload()
{
    if (!mIsShooting && !mIsReloading && mAmmo < mCapacity) {
        mAmmo = mCapacity;
        mIsReloading = true;
        std::cout << "Reloading...\n";
    }
}

bool Gun::SetState(State to)
{
    if (TransitionTo(to)) {
        mState = to;
        return true;
    }
    return false;
}

bool Gun::TransitionTo(State newState) {
    if (mTransitions[(int)mState][(int)newState] == 1) {
        return true;
    }
    return false;
}


}


void Gun::PrintState() {
    switch (mState) {
    case State::Idle:
        std::cout << "State: Idle\n";
        break;
    case State::Shoot:
        std::cout << "State: Shoot\n";
        break;
    case State::Reload:
        std::cout << "State: Reload\n";
        break;
    case State::Empty:
        std::cout << "State: Empty\n";
        break;
    default:
        break;
    }

}



// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
