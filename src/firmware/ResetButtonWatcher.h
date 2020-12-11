#pragma once
class ResetButtonWatcher
{
public:

	ResetButtonWatcher();
	void update();

private:

	bool _isPressed = false;
};

