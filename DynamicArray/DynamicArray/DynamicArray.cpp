#include <iostream>
#include <string>
#include <array>

#define DEFAULT_SIZE 2

template<typename T>
class DynamicArray
{
private:
	T* values;
	uint32_t size = DEFAULT_SIZE;
public:
	DynamicArray(void)
	{
		values = new T[DEFAULT_SIZE](NULL);
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

	void Set(uint32_t index, T value)
	{
		values[index] = value;
	}
	
	T Get(uint32_t index)
	{
		return values[index];
	}
};

int main()
{
	return 0;
}