#pragma once
#include <iostream>
#include <string>
#include "FSclass.h"
#include "NTFSclass.h"
#include "Iterator.h"
class DriveClass
{
public:
	HANDLE handle;
	BYTE StartBuffer[1024];
	std::string OEM;
	DriveClass();
	~DriveClass();
	void OpenDisk();
	Iterator * GetIterator(FSclass * fs);
};

