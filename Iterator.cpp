#include "pch.h"
#include "Iterator.h"

Iterator::Iterator(FSclass * fs)
{
	FS = fs;
}

void Iterator::First()
{
	position = 0;
}

void Iterator::Next()
{
	position++;
}

bool Iterator::IsDone()
{
	return position <= FS->GetTotalClusters();
}

void Iterator::Item()
{
	DWORD bufferSize = FS->GetBytesPerCluster();
	BYTE * outBuffer = new BYTE[bufferSize];
	FS->ReadClusters(position, 1, outBuffer);
	FS->PrintFS();
}

Iterator::~Iterator()
{
}
