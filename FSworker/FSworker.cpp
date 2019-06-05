// FSworker.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "FSclass.h"
#include "NTFSclass.h"
#include "FAT32class.h"
#include "exFATclass.h"
#include "Iterator.h"
#include "DriveClass.h"
#include "Decorator.h"
int main()
{
	DriveClass *newFs = new DriveClass();
	newFs->OpenDisk();
	FSclass * fs = FSclass::createFSclass(newFs->OEM, newFs->handle, newFs->StartBuffer);
	std::cout << "Enter number of clusters for research with decorator: ";
	long NumberOfClusters;
	std::cin >> NumberOfClusters;
	Decorator * decorator = new Decorator(newFs->GetIterator(fs));
	for (decorator->First(); decorator->Position() < NumberOfClusters; decorator->Next()) {
		decorator->Item();
	}
	fs->Close();
	system("pause");
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
