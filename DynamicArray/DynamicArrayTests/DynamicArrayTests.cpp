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
			Assert::AreEqual((uint32_t) 8, size);
			for (int i = 0; i < size; i++)
			{
				Assert::AreEqual(array->Get(i), NULL);
			}
			delete array;
		}

		TEST_METHOD(GetsSetsElementAtIndex)
		{
			DynamicArray<int>* array = new(DynamicArray<int>);
			int element = 42;
			array->Set(1, element);
			Assert::AreEqual(element, array->Get(1));
			delete array;
		}

		TEST_METHOD(AppendsToArray)
		{
			DynamicArray<int>* array = new(DynamicArray<int>);
			int element = 42;
			array->Set(0, 2);
			array->Set(3, 5);
			array->Append(element);
			Assert::AreEqual(element, array->Get(4));
			delete array;
		}
	};
}
