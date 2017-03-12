#pragma once

class task								// класс задачи
{
private:
	unsigned int reqClock;				// - необходимая тактовая частота
public:
	task(unsigned int _reqClock = 1);
	unsigned int getClock();			// - вернуть необходимую тактовую частоту							
};