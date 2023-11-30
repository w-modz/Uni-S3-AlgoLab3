// ALGO2 IS1 221A LAB02
// Wiktor Modzelewski
// mw53766@zut.edu.pl
#include <iostream>
#include <string>
#include <array>
#include <ctime>
#include <random>

#define DEFAULT_SIZE 8
#define EXPANSION_MULTIPLIER 2

template<typename T>
class DynamicArray
{
private:
	T* values;
	uint32_t size = DEFAULT_SIZE;
	uint32_t actual_size = 0;
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

	uint32_t GetActualSize()
	{
		return actual_size;
	}
	void Set(uint32_t index, T value)
	{
		if (index > actual_size)
		{
			throw std::out_of_range("Index out of bounds");
		}
		values[index] = value;
	}
	T Get(uint32_t index)
	{
		if (index >= actual_size)
		{
			throw std::out_of_range("Index out of bounds");
		}
		return values[index];
	}

	void Append(T value)
	{
		if (actual_size + 1 > size)
		{
			Expand();
		}
		Set(actual_size, value);
		actual_size++;
	}

	void Clear()
	{
		delete[] values;
		actual_size = 0;
		T* new_values = new T[size];
		values = new_values;
	}

	// The sorting method assumes existance of valid ">" operator overload for given datatype
	void Sort()
	{
		for (int i = 0; i < actual_size - 1; i++)
		{
			for (int j = 0; j < actual_size - i - 1; j++)
			{
				if (values[j] > values[j + 1])
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
		else if (actual_size == 0)
		{
			return "[]";
		}
		else if (actual_size < number_to_print)
		{
			throw std::out_of_range("Index out of bounds");
		}
		std::ostringstream output_stream;
		output_stream << "[" << values[0];
		for (int i = 1; i < number_to_print; i++)
		{
			output_stream << ", " << values[i];
		}
		output_stream << "]\n";
		return output_stream.str();
	}

private:
	void Expand()
	{
		const uint32_t new_size = size * EXPANSION_MULTIPLIER;
		T* new_values = new T[new_size];
		for (int i = 0; i < actual_size; i++)
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
	std::default_random_engine gen(time(nullptr));
	std::uniform_int_distribution<int> dist(-5, 5);

	DynamicArray<std::pair<int,char>>* da = new DynamicArray<std::pair<int,char>>;
	const int order = 7; // maximum order of data input (in powers of 10)
	const int n = pow(10, order); // data sample size
	// appending to table
	clock_t t1 = clock();
	double max_time_per_element = 0.0;

	for (int i = 0; i < n; i++) 
	{
		clock_t t1_element = clock();
		da->Append(std::make_pair(rand(), (char) rand() ));
		clock_t t2_element = clock();
		double time_per_element = t2_element - t1_element;
		if (time_per_element > max_time_per_element)
		{
			max_time_per_element = time_per_element;
			std::cout << max_time_per_element << " ms \n";
		}
	}
	clock_t t2 = clock();

	// display of number of elements added, calculation of total time taken and average time per element
	std::cout << "Array lenght: " << da->GetSize() << "\n";
	std::cout << "Array actual lenght: " << da->GetActualSize() << "\n";
	std::cout << "Total time of appending = " << ((t2 - t1) / (double)CLOCKS_PER_SEC) * 1000 << "ms\n";
	std::cout << "Average time of appending = " << ((t2 - t1) / (double)CLOCKS_PER_SEC) * 1000 / n << "ms\n";
	std::cout << "Worst time of appending = " << max_time_per_element << "ms\n";
	da->Clear();
	delete da;

	return 0;
}