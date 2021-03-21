#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Data.hpp"

void*	serialize(void)
{
	char*			data = new char[sizeof(std::string) * 2 + sizeof(int)];
	std::string*	s1 = reinterpret_cast<std::string*>(data);
	std::string*	s2 = reinterpret_cast<std::string*>(data + sizeof(std::string) + sizeof(int));
	int*			n = reinterpret_cast<int*>(data + sizeof(std::string));
	char			alphanum[63] =
		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	//	strings need to be constructed
	::new (reinterpret_cast<void*>(s1)) std::string();
	::new (reinterpret_cast<void*>(s2)) std::string();

	size_t		strsize;
	strsize = size_t(std::rand() % 40 + 2);
	for (size_t i = 0; i < strsize; i++)
		s1->push_back(alphanum[std::rand() % 62]);
	*n = std::rand();
	strsize = size_t(std::rand() % 40 + 2);
	for (size_t i = 0; i < strsize; i++)
		s2->push_back(alphanum[std::rand() % 62]);

	std::cout << "s1:\t" << *s1 << std::endl;
	std::cout << "n:\t" << *n << std::endl;
	std::cout << "s2:\t" << *s2 << std::endl;

	return (reinterpret_cast<void*>(data));
}

Data*	deserialize(void* raw)
{
	char*	rawbytes = reinterpret_cast<char*>(raw);
	Data*	data = new Data;

	data->s1 = *(reinterpret_cast<std::string*>(rawbytes));
	data->n = *(reinterpret_cast<int*>(rawbytes + sizeof(std::string)));
	data->s2 = *(reinterpret_cast<std::string*>(rawbytes + sizeof(std::string) + sizeof(int)));
	return (data);
}

int		main(void)
{
	void*	rawptr;
	Data*	datastrptr;

	std::srand(std::time(NULL));

	std::cout << "Serializing data" << std::endl;
	rawptr = serialize();

	std::cout << "\nData after deserialization" << std::endl;
	datastrptr = deserialize(rawptr);
	std::cout << "s1:\t" << datastrptr->s1 << std::endl;
	std::cout << "n:\t" << datastrptr->n << std::endl;
	std::cout << "s2:\t" << datastrptr->s2 << std::endl;

	char*	rawbytes = reinterpret_cast<char*>(rawptr);
	typedef	std::string		string;
	//	^ silencing vscode error: invalid destructor name for type string
	reinterpret_cast<std::string*>(rawbytes)->~string();
	reinterpret_cast<std::string*>(rawbytes + sizeof(std::string) + sizeof(int))->~string();
	//	^ strings need to be destroyed
	delete[] (rawbytes);
	delete (datastrptr);
	return (0);
}
