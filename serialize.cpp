#include "pch.h"
#include <iostream>
#include <fstream>
#include "serialize.h"
#include <string>

//using namespace std;

int main()
{
	std::ofstream ofs("test.ser", std::ofstream::out | std::ofstream::binary);

	char hello[7] = "hello!";
	int boo[3] = { 1, 2, 3 };
	std::string str = "string";


	serialize(hello, ofs);
	serialize(boo, ofs);
	serialize(str, ofs);

	char hello2[7];
	int boo2[3];
	std::string str2;

	ofs.close();

	std::ifstream ifs("test.ser", std::ifstream::in | std::ofstream::binary);
	ifs >> std::noskipws;

	deserialize(hello2, ifs);
	deserialize(boo2, ifs);
	deserialize(str2, ifs);

	if (std::equal(hello, hello + 7, hello2))
		std::cout << "Hello OK!" << std::endl;

	if (std::equal(boo, boo + 3, boo2))
		std::cout << "Boo OK!" << std::endl;

	if(!str.compare(str2))
		std::cout << "str OK!" << std::endl;

	return 0;
}