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
	void PrintState();

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
};


