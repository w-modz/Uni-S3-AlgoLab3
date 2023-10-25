#include <iostream>
#include <string>
#include <array>

#define DEFAULT_SIZE 8

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

	void Append(T value)
	{
		int last_full_index = 0;
		for (int i = 0; i < size; i++)
		{
			if (Get(i) != NULL)
			{
				last_full_index = i;
			}
		}
		if (last_full_index + 1 >= size)
		{
			throw std::out_of_range("Index out of bounds");
		}
		Set(last_full_index + 1, value);
	}
};

int main()
{
	return 0;
}