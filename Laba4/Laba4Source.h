#ifndef LABA4SOURSE_H
#define LABA4SOURSE_H

#include <string>

#include "FileUtils.h"

unsigned long long Powm(unsigned long long a, unsigned long long b, unsigned long long n);

class RSA
{
private:
	unsigned long long _p, _q, _Fn, _d;
private:
	unsigned long long _nod(unsigned long long a, unsigned long long b);
	bool _oddity(unsigned long long num);
	unsigned long long _genNum(int gen);
	bool _simpleNum(unsigned long long num);
	unsigned long long _genN();
	unsigned long long _genFn(unsigned long long p, unsigned long long q);
	unsigned long long _genPublE(unsigned long long res = 200);
	unsigned long long _genD(unsigned long long e, unsigned long long Fn);
public:
	unsigned long long n, e;
public:
	RSA();
	~RSA();

	void Decryption(const std::string& inFile, const std::string& outFile);
};

class Encryptor
{
private:
	std::string _message;
public:
	Encryptor(const std::string& filePath);
	~Encryptor();

	void Encryption(const std::string& outFile, unsigned long long e, unsigned long long n);
};

#endif // LABA4SOURSE_H