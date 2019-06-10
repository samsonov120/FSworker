#include "pch.h"
#include "DriveClass.h"

DriveClass::DriveClass()
{
}


DriveClass::~DriveClass()
{
}

Iterator * DriveClass::GetIterator(FSclass * fs)
{
	Iterator* it = new Iterator(fs);
	return it;
}