#include "Laba4Source.h"

#include <stdlib.h>
#include <time.h>
#include <cmath>

unsigned long long Powm(unsigned long long a, unsigned long long b, unsigned long long n)
{
	unsigned long long c = 1;
	while (b != 0)
	{
		if (b % 2 == 0)
		{
			b /= 2;
			a = (a * a) % n;
		}
		else
		{
			b--;
			c = (c * a) % n;
		}
	}
	return c;
}

unsigned long long RSA::_nod(unsigned long long a, unsigned long long b)
{
	while (a && b)
		if (a >= b)
			a %= b;
		else
			b %= a;

	return a | b;
}

bool RSA::_oddity(unsigned long long num)
{
	if ((num %= 2) == 1)
		return true;

	return false;
}

unsigned long long RSA::_genNum(int gen)
{
	srand(time(NULL));
	unsigned long long res;

	do
	{
		res = rand() % gen;
	} while (!_simpleNum(res));

	return res;
}

bool RSA::_simpleNum(unsigned long long num)
{
	for (unsigned long long i = 2; i <= sqrt(num); i++)
		if (num % i == 0)
			return false;

	return true;
}

unsigned long long RSA::_genN()
{
	return (this->_p * this->_q);
}

unsigned long long RSA::_genFn(unsigned long long p, unsigned long long q)
{
	return ((p - 1) * (q - 1));
}

unsigned long long RSA::_genPublE(unsigned long long res)
{
	unsigned long long result = res;

	while ((_nod(_Fn, result) != 1))
	{
		if (!_oddity(result))
			result++;
		else
			result++;
	}

	return result;
}

unsigned long long RSA::_genD(unsigned long long e, unsigned long long Fn)
{
	long double res = 0;
	unsigned long long k = 1;
	long double rem = 0;

	do
	{
		res = (double)((k * Fn) + 1) / e;
		rem = modf(res, &rem);
		k++;
	} while (rem != 0);

	return (unsigned long long)res;
}

RSA::RSA()
{
	this->_p = _genNum(2000);
	this->_q = _genNum(1999);
	this->n = _genN();
	this->_Fn = _genFn(_p, _q);
	this->e = _genPublE();
	this->_d = _genD(e, _Fn);
}

RSA::~RSA()
{ }

void RSA::Decryption(const std::string& inFile, const std::string& outFile)
{
	std::string sourse = "";
	int size = GetFileSize(inFile) / sizeof(unsigned long long);
	unsigned long long* data = new unsigned long long[size];

	data = ReadBinary(inFile);

	for (int i = 0; i < size; ++i)
		sourse += (unsigned char)Powm(data[i], _d, n);

	WriteFile(outFile, sourse);

	delete[] data;
	data = nullptr;
}

Encryptor::Encryptor(const std::string& filePath)
{
	this->_message = ReadFile(filePath);
}

Encryptor::~Encryptor()
{ }

void Encryptor::Encryption(const std::string& outFile, unsigned long long e, unsigned long long n)
{
	unsigned long long* data = new unsigned long long[_message.size()];

	for (int i = 0; i < _message.size(); ++i)
		data[i] = Powm((unsigned long long)_message[i], e, n);

	WriteBinary(outFile, data, _message.size());

	delete[] data;
	data = nullptr;
}