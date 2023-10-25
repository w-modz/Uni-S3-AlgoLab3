#include "pch.h"
#include "CppUnitTest.h"
#include "../DynamicArray/DynamicArray.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynamicArrayTests
{
	TEST_CLASS(DynamicArrayTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			DynamicArray<int> array = DynamicArray<int>();
			std::string expected = "Hello\n";
			Assert::AreEqual(expected, array.HelloWorld());
		}

		TEST_METHOD(InitializesDynamicArray)
		{
			DynamicArray<int> array = DynamicArray<int>();
			uint32_t size = array.GetSize();
			uint32_t expected = 0;
			Assert::AreEqual(expected, size);
		}
	};
}
