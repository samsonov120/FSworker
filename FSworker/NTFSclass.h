#pragma once
#include "FSclass.h"
#include <iostream>
class NTFSclass :
	public FSclass
{
public:
	std::vector<int> Buffer;
	NTFSclass(BYTE* BootRecord, HANDLE FileHandle);
	~NTFSclass();
	virtual bool ReadClusters(ULONGLONG startCluster, DWORD numberOfClusters, BYTE* dataBuffer);
	virtual void PrintFS();
};

typedef struct
{
	BYTE Padding1[3];
	BYTE OEM_Name[8];
	BYTE BytesPerSector[2];
	BYTE SectorsPerCluster;
	BYTE Padding2[26];
	ULONGLONG TotalSectors;
} NTFS_BootRecord;


