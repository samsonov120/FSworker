#pragma once
#include "FSclass.h"
#include <iostream>
class FAT32class :
	public FSclass
{
public:
	std::vector<int> Buffer;
	FAT32class(BYTE* BootRecord, HANDLE FileHandle);
	~FAT32class();
	virtual bool ReadClusters(ULONGLONG startCluster, DWORD numberOfClusters, BYTE* dataBuffer);
	virtual void PrintFS();
};

typedef struct
{
	BYTE Padding1[3];
	BYTE OEM_Name[8];
	BYTE BytesPerSector[2];
	BYTE SectorsPerCluster;
	BYTE Padding2[18];
	ULONGLONG TotalSectors;
} FAT32_BootRecord;


