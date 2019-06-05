#include "pch.h"
#include "DriveClass.h"

DriveClass::DriveClass()
{
}


DriveClass::~DriveClass()
{
}

void DriveClass::OpenDisk()
{
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
	OEM_Name* bootRecord = (OEM_Name*)StartBuffer;
	std::string OEMname((char *)bootRecord->OEM_Name, 8);
	OEM = OEMname;
}

Iterator * DriveClass::GetIterator(FSclass * fs)
{
	Iterator* it = new Iterator(fs);
	return it;
}
