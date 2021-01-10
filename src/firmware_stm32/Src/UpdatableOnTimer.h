#pragma once

class UpdatableOnTimer
{
public:
	
	UpdatableOnTimer(int period);
	
	void updateOnTimer(int dt);
	static void updateAll(int dt);
	
protected:
	
	bool isTimerExpired() const;
	void resetTimer();
	
private:
	
	int _period;
	bool _isTimerExpired = false;
	int _counter = 0;
	static UpdatableOnTimer* _first;
	UpdatableOnTimer* _next = nullptr;
};