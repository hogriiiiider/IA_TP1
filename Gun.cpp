// Projet IA exo.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
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



// Ex�cuter le programme�: Ctrl+F5 ou menu D�boguer�> Ex�cuter sans d�bogage
// D�boguer le programme�: F5 ou menu D�boguer�> D�marrer le d�bogage

// Astuces pour bien d�marrer�: 
//   1. Utilisez la fen�tre Explorateur de solutions pour ajouter des fichiers et les g�rer.
//   2. Utilisez la fen�tre Team Explorer pour vous connecter au contr�le de code source.
//   3. Utilisez la fen�tre Sortie pour voir la sortie de la g�n�ration et d'autres messages.
//   4. Utilisez la fen�tre Liste d'erreurs pour voir les erreurs.
//   5. Acc�dez � Projet�> Ajouter un nouvel �l�ment pour cr�er des fichiers de code, ou � Projet�> Ajouter un �l�ment existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, acc�dez � Fichier�> Ouvrir�> Projet et s�lectionnez le fichier .sln.
