#include <iostream>
#include <string>

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

	uint32_t GetSize()
	{
		return size;
	}
};

int main()
{
	return 0;
}