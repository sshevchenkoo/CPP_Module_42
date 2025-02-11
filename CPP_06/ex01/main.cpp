#include "Serializer.hpp"

int main()
{

	Data data = {42, "test"};

	uintptr_t raw = Serializer::serialize(&data);
	Data *serialized = Serializer::deserialize(raw);

	std::cout << serialized->name << std::endl;
	std::cout << serialized->id << std::endl;

	return (0);
}