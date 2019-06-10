#pragma once
#include "windows.h"
#include <iostream>
#include <vector>
class FSclass
{
protected:
	HANDLE FileHandle;
	DWORD TotalClusters;
	DWORD BytesPerCluster;
	BYTE * OEM_Name[8];
public:
	FSclass();
	~FSclass();
	static FSclass* createFSclass();
	DWORD GetTotalClusters() const;
	DWORD GetBytesPerCluster() const;
	BYTE* GetOemName() const;
	virtual bool ReadClusters(ULONGLONG startCluster, DWORD numberOfClusters, BYTE *outBuffer) = 0;
	void Close();
	virtual void PrintFS() = 0;
	std::vector<int> Buffer;
};

typedef struct
{
	BYTE Padding1[3];
	BYTE OEM_Name[8];
} OEM_NAME;

