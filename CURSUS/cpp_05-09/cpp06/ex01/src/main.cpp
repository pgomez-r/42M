
#include "Serializer.hpp"

/**
 * TODO: include 42header
 */
int main()
{
	Data test;
	test.n = 42;
	test.f = 42.42f;
	test.str = "42 Málaga\n";
	std::cout << "[0]Original data: " << &data << std::endl;

	uintptr_t	serialized = Serializer::serialize(&data);
	std::cout << "[1]Serialized data: " << serialized << std::endl;
	std::cout << "[1]Original data: " << &data << std::endl;

	Data*	deserialized = Serializer::deserialize(serialized);
	std::cout << "[2]Deserialized data: " << deserialized << std::endl;
	std::cout << "[2]Deserialized data->id: " << deserialized->id << std::endl;
	std::cout << "[2]Original data: " << &data << std::endl;

	return (0);
}
