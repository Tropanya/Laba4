#include "FileUtils.h"

#include <fstream>
#include <sstream>

std::string ReadFile(const std::string& name)
{
	std::ifstream file;
	file.open(name, std::ios::binary);
	std::stringstream fileStream;
	fileStream << file.rdbuf();
	file.close();

	return fileStream.str();
}

void WriteFile(const std::string& name, const std::string& sourse)
{
	std::ofstream file;
	file.open("out_" + name, std::ios::binary);
	file << sourse;
	file.close();
}

unsigned long long* ReadBinary(const std::string& name)
{
	int size = GetFileSize(name);

	unsigned long long* data = new unsigned long long[size];

	FILE* pFile;
	pFile = fopen(name.c_str(), "rb");
	fread(data, size, 1, pFile);

	return data;
}

void WriteBinary(const std::string& name, unsigned long long* data, int size)
{
	std::ofstream file;
	file.open("out_" + name, std::ios::binary);

	for (int i = 0; i < size; i++)
		file.write((char*)&data[i], sizeof(unsigned long long));

	file.close();
}

int GetFileSize(const std::string& name)
{
	std::ifstream file;
	file.open(name, std::ios::binary);

	file.seekg(0, std::ios::end);
	int size = file.tellg();

	file.close();

	return size;
}