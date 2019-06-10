#pragma once
#include "FSclass.h"
#include <windows.h>
class Iterator
{
public:
protected:	
	FSclass * fs;
public:
	ULONGLONG position;
	FSclass * FS;
	Iterator(FSclass* fs);
	void First();
	void Next();
	bool IsDone();
	void Item();
	~Iterator();
};

