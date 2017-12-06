#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <string>

std::string ReadFile(const std::string& name);
void WriteFile(const std::string& name, const std::string& sourse);

unsigned long long* ReadBinary(const std::string& name);
void WriteBinary(const std::string& name, unsigned long long* data, int size);

int GetFileSize(const std::string& name);

#endif // FILEUTILS_H