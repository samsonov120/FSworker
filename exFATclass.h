#pragma once
#include "FSclass.h"
#include <iostream>
class exFATclass :
	public FSclass
{
public:
	std::vector<int> Buffer;
	exFATclass(BYTE* BootRecord, HANDLE FileHandle);
	~exFATclass();
	virtual bool ReadClusters(ULONGLONG startCluster, DWORD numberOfClusters, BYTE* dataBuffer);
	virtual void PrintFS();
};

typedef struct
{
	BYTE Padding1[3];
	BYTE OEM_Name[8];
	BYTE Padding2[0x3D];
	DWORD TotalSectors;
	DWORD FAT_StartSector;
	DWORD FAT_Size;
	DWORD FirstDataSector;
	DWORD TotalClusters;
	DWORD RootDirCluster;
	BYTE Padding3[8];
	BYTE SectorFactor;
	BYTE ClusterFactor;
} exFAT_BootRecord;


