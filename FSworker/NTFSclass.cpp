#include "pch.h"
#include "NTFSclass.h"

NTFSclass::NTFSclass(BYTE * BootRecord, HANDLE FileHandle)
{
	NTFS_BootRecord* bootRecord = (NTFS_BootRecord*)BootRecord;
	memcpy(OEM_Name, bootRecord->OEM_Name, sizeof(OEM_Name));
	DWORD BytesPerSector = *((WORD*)bootRecord->BytesPerSector);
	DWORD SectorsPerCluster = bootRecord->SectorsPerCluster;
	BytesPerCluster = SectorsPerCluster * BytesPerSector;
	TotalClusters = bootRecord->TotalSectors/ bootRecord->SectorsPerCluster;
	NTFSclass::FileHandle = FileHandle;
}

NTFSclass::~NTFSclass()
{
}

bool NTFSclass::ReadClusters(ULONGLONG startCluster, DWORD numberOfClusters, BYTE * outBuffer)
{
	ULONGLONG startOffset = startCluster * BytesPerCluster;
	DWORD bytesToRead = numberOfClusters * BytesPerCluster;
	DWORD bytesRead;
	LARGE_INTEGER sectorOffset;
	sectorOffset.QuadPart = startOffset;
	unsigned long currentPosition = SetFilePointer(
		FileHandle,
		sectorOffset.LowPart,
		&sectorOffset.HighPart,
		FILE_BEGIN
	);
	if (currentPosition != sectorOffset.LowPart)
	{
		std::cout << "Tou have error:  currentPosition != sectorOffset.LowPart" << std::endl;
		exit(1);
	}
	bool readResult = ReadFile(
		FileHandle,
		outBuffer,
		bytesToRead,
		&bytesRead,
		NULL
	);
	if (!readResult || bytesRead != bytesToRead)
	{
		std::cout << "Tou have error:  Can not read disk" << std::endl;
		exit(2);
	}
	else
	{
		int i = 0;
		while (i != bytesToRead)
		{
			Buffer.push_back(*outBuffer);
			outBuffer++;
			i++;
		}
	}
	return false;
}

void NTFSclass::PrintFS()
{
	int i = 0;
	while (i != Buffer.size()) {
		if (Buffer[i] >= 0 && Buffer[i] <= 15)
		{
			std::cout << "0" << std::hex << Buffer[i] << " ";
		}
		else
		{
			std::cout << std::hex << Buffer[i] << " ";
		}
		i++;
		if (i % 16 == 0)
		{
			std::cout << std::endl;
		}
		if (i % 8 == 0)
		{
			std::cout << "  ";
		}
	}
	Buffer.clear();
}
