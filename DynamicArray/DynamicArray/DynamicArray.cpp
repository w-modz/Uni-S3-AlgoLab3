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
	void Set(uint32_t index, T value)
	{
		if (index >= size)
		{
			throw std::out_of_range("Index out of bounds");
		}
		values[index] = value;
	}
	T Get(uint32_t index)
	{
		if (index >= size)
		{
			throw std::out_of_range("Index out of bounds");
		}
		return values[index];
	}

	void Append(T value)
	{
		int last_non_null_index = 0;
		for (int i = 0; i < size; i++)
		{
			if (Get(i) != NULL)
			{
				last_non_null_index = i;
			}
		}
		if (last_non_null_index + 1 >= size)
		{
			Expand();
		}
		Set(last_non_null_index + 1, value);
	}

	void Clear()
	{
		for (int i = 0; i < size; i++)
		{
			Set(i, NULL);
		}
	}

	// The sorting method assumes existance of valid ">" operator overload for given datatype
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

	std::string ToString(uint32_t number_to_print)
	{
		if (number_to_print == 0)
		{
			return "[]";
		}
		else if (size == 0)
		{
			return "[]";
		}
		else if (size < number_to_print)
		{
			throw std::out_of_range("Index out of bounds");
		}
		std::ostringstream output_stream;
		if (values[0] == NULL)
		{
			output_stream << "[NULL";
		}
		else
		{
			output_stream << "[" << values[0];
		}
		for (int i = 1; i < number_to_print; i++)
		{
			if (values[i] == NULL)
			{
				output_stream << ", NULL";
			}
			else
			{
				output_stream << ", " << values[i];
			}
		}
		output_stream << "]\n";
		return output_stream.str();
	}

private:
	void Expand()
	{
		const uint32_t new_size = size * EXPANSION_MULTIPLIER;
		T* new_values = new T[new_size](NULL);
		for (int i = 0; i < size; i++)
		{
			new_values[i] = values[i];
		}
		delete[] values;
		values = new_values;
		size = new_size;
	}
};

int main()
{
	return 0;
}