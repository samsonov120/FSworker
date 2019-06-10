#include "pch.h"
#include "FSclass.h"
#include "NTFSclass.h"
#include "FAT32class.h"
#include "exFATclass.h"
#include <iostream>
#include <string>

FSclass::FSclass()
{
}


FSclass::~FSclass()
{
}

FSclass * FSclass::createFSclass()
{
	HANDLE handle;
	BYTE StartBuffer[1024];
	DWORD bytesRead;
	std::cout << "Enter disk (C, D, etc): ";
	std::wstring Disk;
	std::wcin >> Disk;
	std::wstring fileName1 = L"\\\\.\\" + Disk + L":";
	WCHAR * fileName = &fileName1[0];
	handle = CreateFileW(
		fileName,
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (handle == INVALID_HANDLE_VALUE) {
		std::wcout << "Can not open disk " << Disk << std::endl;
		exit(GetLastError());
	}
	bool readResult = ReadFile(
		handle,
		StartBuffer,
		512,
		&bytesRead,
		NULL
	);
	if (!readResult) {
		std::cout << "Reading of the disk cause error" << std::endl;
		exit(GetLastError());
	}

	OEM_NAME* bootRecord = (OEM_NAME*)StartBuffer;
	std::string OEMname((char *)bootRecord->OEM_Name, 8);
	std::string NTFS = "NTFS    ";
	FSclass * p;
	if (OEMname == NTFS) {
		p = new NTFSclass(StartBuffer, handle);
		return p;
	}
	else if (OEMname == "MSDOS5.0")
	{
		p = new FAT32class(StartBuffer, handle);
		return p;
	}
	else if (OEMname == "EXFAT   ")
	{
		p = new exFATclass(StartBuffer, handle);
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
