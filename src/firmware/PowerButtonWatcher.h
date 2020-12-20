#pragma once

class PowerButtonWatcher
{
public:

	PowerButtonWatcher();
	void update(int dt);
	void updateConfig();

private:

	int _pwdLevel = 0;
	int _digitInputPeriod = 3000;
	int _digit[3];

	int _timer = 0;
	int _counter = 0;
	int _currentDigit;
	bool _isWatching = false;
	bool _isPressed = false;
};

