#include <iostream>
#include <string>
#include <array>

#define DEFAULT_SIZE 8
#define EXPANSION_MULTIPLIER 2

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
	// TODO: check for out of bounds index
	void Set(uint32_t index, T value)
	{
		values[index] = value;
	}
	// TODO: check for out of bounds index
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
			Expand();
		}
		Set(last_full_index + 1, value);
	}

	void Clear()
	{
		for (int i = 0; i < size; i++)
		{
			Set(i, NULL);
		}
	}

	void Sort()
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (values[j] == NULL && values[j + 1] == NULL)
				{
				}
				else if (values[j] == NULL && values[j + 1] != NULL)
				{
					values[j] = values[j + 1];
					values[j + 1] = NULL;
				}
				else if (values[j] != NULL && values[j+1] == NULL)
				{
				}
				else if (values[j] > values[j + 1])
				{
					int temp = values[j + 1];
					values[j + 1] = values[j];
					values[j] = temp;
				}
			}
		}
	}

private:
	void Expand()
	{
		const uint32_t new_size = size * EXPANSION_MULTIPLIER;
		T* new_values = new T[new_size](NULL);
		std::memcpy(new_values, values, sizeof(values));
		delete[] values;
		values = new_values;
		size = new_size;
	}
};

int main()
{
	return 0;
}