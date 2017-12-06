#include "Laba4Source.h"

int main()
{
	RSA a;
	Encryptor b("TextForIP.txt");

	b.Encryption("Encryption.txt", a.e, a.n);
	a.Decryption("out_Encryption.txt", "Decryption.txt");

	return 0;
}