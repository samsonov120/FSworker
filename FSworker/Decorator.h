#pragma once
#include "Iterator.h"
class Decorator :
	public Iterator
{
protected:
	Iterator * IT;
	FSclass * Fs;
public:
	~Decorator();
	Decorator(Iterator * it);
	void First();
	void Next();
	bool IsDone();
	long Position();
	void Item();	

};

