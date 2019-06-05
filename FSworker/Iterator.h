#pragma once
#include "FSclass.h"
#include <windows.h>
class Iterator
{
public:
protected:
	ULONGLONG position;
	FSclass * fs;
public:
	FSclass * FS;
	Iterator(FSclass* fs);
	void First();
	void Next();
	bool IsDone();
	long Position();
	void Item();
	~Iterator();
};

