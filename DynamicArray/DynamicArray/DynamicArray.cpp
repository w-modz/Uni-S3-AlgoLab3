#include <iostream>
#include <string>
#include <array>

#define DEFAULT_SIZE 2

template<typename T>
class DynamicArray
{
public:
	T* values;
	uint32_t size = DEFAULT_SIZE;
public:
	DynamicArray(void)
	{
		values = new T[DEFAULT_SIZE];
	}

	~DynamicArray()
	{
		delete[] values;
		values = nullptr;
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