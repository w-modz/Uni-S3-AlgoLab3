#include "pch.h"
#include "CppUnitTest.h"
#include "../DynamicArray/DynamicArray.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynamicArrayTests
{
	TEST_CLASS(DynamicArrayTests)
	{
	public:
		TEST_METHOD(InitializesDynamicArray)
		{
			DynamicArray<int>* array = new(DynamicArray<int>);
			uint32_t size = array->GetSize();
			uint32_t expected = 2;
			Assert::AreEqual(expected, size);
			Assert::IsNotNull(array->values);
			delete array;
		}

		TEST_METHOD(SetsElementAtIndex)
		{
			DynamicArray<int>* array = new(DynamicArray<int>);
			int element = 42;
			array->Set(1, element);
			Assert::AreEqual(element, array->values[1]);
			delete array;
		}
	};
}
