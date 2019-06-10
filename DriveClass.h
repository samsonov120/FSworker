#pragma once
#include <iostream>
#include <string>
#include "FSclass.h"
#include "NTFSclass.h"
#include "Iterator.h"
class DriveClass
{
public:
	DriveClass();
	~DriveClass();
	Iterator * GetIterator(FSclass * fs);
};