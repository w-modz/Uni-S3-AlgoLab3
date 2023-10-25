#include <iostream>
#include <string>

template<typename T>
class DynamicArray
{
public:
	T* values;
	uint32_t size;
public:
	DynamicArray(void)
	{
		
	}

	std::string HelloWorld()
	{
		return "Hello\n";
	}
	uint32_t GetSize()
	{
		return size;
	}
};

int main()
{
	return 0;
}