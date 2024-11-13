#include <iostream>
#include <sstream>

class Gun
{
public:
	int mAmmo;
	int mCapacity;
	bool mIsReloading = false;
	bool mIsShooting = false;
	float ReloadTime;
	float ShootTime;
	float mReloadProgress;
	float mShootProgress;

public:
	Gun(int mCapacity, float ReloadTime, float ShootTime);
	void Reload();
	void Shoot();

	enum class State
	{
		Idle,
		Shoot,
		Reload,
		Empty,

		StateCount
	};

	static const int STATE_COUNT = (int)State::StateCount;

private:
	State mState = State::Idle;
	int mTransitions[STATE_COUNT][STATE_COUNT] =
	{
		// Idle,  Shoot,  Reload,   Empty
		{	0,	  1,	  1,        1}, //Idle
		{	1,	  0,	  1,	    1}, //Shoot
		{	1,	  1,	  0,	    0}, //Reload
		{	1,	  1,	  0,	    0,} //Empty
	};

public:

	bool SetState(State to);
	bool TransitionTo(State newState);

	   case State::Shoot:
		   // The shooting action is being handled in the Shoot() function
		   break;

	   case State::Reload:
		   // The reload action is being handled in the Reload() function
		   break;

	   case State::Empty:
		   // If the gun is empty, we need to either reload or stay empty
		   if (mAmmo == 0) {
			   // Gun stays in Empty state, just wait for reload
			   SetState(State::Reload);
		   }
		   break;

	   default:
		   break;

};


