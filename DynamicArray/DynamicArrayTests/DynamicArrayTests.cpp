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
			Assert::AreEqual((uint32_t) 2, size);
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
	};
}
