#include "pch.h"
#include "FSclass.h"
#include "NTFSclass.h"
#include "FAT32class.h"
#include "exFATclass.h"
#include <iostream>

FSclass::FSclass()
{
}


FSclass::~FSclass()
{
}

FSclass * FSclass::createFSclass(std::string OEM, HANDLE FileHandle, BYTE * BootRecord)
{
	std::string NTFS = "NTFS    ";
	FSclass * p;
	if (OEM == NTFS) {
		p = new NTFSclass(BootRecord, FileHandle);
		return p;
	}
	else if (OEM == "MSDOS5.0")
	{
		p = new FAT32class(BootRecord, FileHandle);
		return p;
	}
	else if (OEM == "EXFAT   ")
	{
		p = new exFATclass(BootRecord, FileHandle);
		return p;
	}
	else
	{		
		exit(404);
	}
}

DWORD FSclass::GetTotalClusters() const
{
	return TotalClusters;
}

DWORD FSclass::GetBytesPerCluster() const
{
	return BytesPerCluster;
}

BYTE * FSclass::GetOemName() const
{
	return * OEM_Name;
}

void FSclass::Close()
{
	CloseHandle(FileHandle);
}
