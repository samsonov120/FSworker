#include "pch.h"
#include "Decorator.h"

Decorator::~Decorator()
{
}

Decorator::Decorator(Iterator * it):Iterator(NULL)
{
	IT = it;
	Fs = IT->FS;
}

void Decorator::First()
{
	IT->First();
}

void Decorator::Next()
{
	char filebyte[8] = "FILE0";
	int i = 0;
	DWORD bufferSize = Fs->GetBytesPerCluster();
	BYTE * outBuffer = new BYTE[bufferSize];
	Fs->ReadClusters(IT->position, 1, outBuffer);
	char *value = (char*)outBuffer;
	while (*value != *filebyte) {	
		IT->Next();
		Fs->ReadClusters(IT->position, 1, outBuffer);
		char *value = (char*)outBuffer;		
	}
	IT->Next();
}

bool Decorator::IsDone()
{
	return IT->IsDone();
}

void Decorator::Item()
{
	IT->Item();
	std::cout << "Decorator found file" << std::endl;
}
