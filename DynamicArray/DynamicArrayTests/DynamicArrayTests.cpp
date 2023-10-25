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
				Assert::AreEqual(NULL, array->Get(i));
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

		TEST_METHOD(ClearsArray)
		{
			DynamicArray<int>* array = new(DynamicArray<int>);
			for (int i = 0; i < array->GetSize(); i++)
			{
				array->Set(i, i * 2);
			}
			array->Clear();
			for (int i = 0; i < array->GetSize(); i++)
			{
				Assert::AreEqual(NULL, array->Get(i));
			}
			delete array;
		}

		TEST_METHOD(DoesNotChangeSortedArray)
		{
			DynamicArray<int>* array = new(DynamicArray<int>);
			array->Set(0, 1);
			array->Set(1, 2);
			array->Set(2, 3);
			array->Set(3, 4);
			array->Set(4, 5);
			array->Set(5, 6);
			array->Set(6, 7);
			array->Set(7, 8);

			array->Sort();

			Assert::AreEqual(1, array->Get(0));
			Assert::AreEqual(2, array->Get(1));
			Assert::AreEqual(3, array->Get(2));
			Assert::AreEqual(4, array->Get(3));
			Assert::AreEqual(5, array->Get(4));
			Assert::AreEqual(6, array->Get(5));
			Assert::AreEqual(7, array->Get(6));
			Assert::AreEqual(8, array->Get(7));
		}

		TEST_METHOD(DoesNotChangeSortedArrayWithNulls)
		{
			DynamicArray<int>* array = new(DynamicArray<int>);
			array->Set(0, 1);
			array->Set(1, 2);
			array->Set(2, 3);
			array->Set(3, 4);
			array->Set(4, 5);

			array->Sort();

			Assert::AreEqual(1, array->Get(0));
			Assert::AreEqual(2, array->Get(1));
			Assert::AreEqual(3, array->Get(2));
			Assert::AreEqual(4, array->Get(3));
			Assert::AreEqual(5, array->Get(4));
			Assert::AreEqual(NULL, array->Get(5));
			Assert::AreEqual(NULL, array->Get(6));
			Assert::AreEqual(NULL, array->Get(7));
		}

		TEST_METHOD(SortsArray)
		{
			DynamicArray<int>* array = new(DynamicArray<int>);
			array->Set(1, 7);
			array->Set(2, 4);
			array->Set(6, 13);
			array->Set(7, 2);

			array->Sort();

			Assert::AreEqual(2, array->Get(0));
			Assert::AreEqual(4, array->Get(1));
			Assert::AreEqual(7, array->Get(2));
			Assert::AreEqual(13, array->Get(3));
			Assert::AreEqual(NULL, array->Get(4));
			Assert::AreEqual(NULL, array->Get(5));
			Assert::AreEqual(NULL, array->Get(6));
			Assert::AreEqual(NULL, array->Get(7));
			delete array;
		}

		TEST_METHOD(ExpandsArray)
		{
			DynamicArray<int>* array = new(DynamicArray<int>);
			array->Set(7, 1);
			int element = 5;
			array->Append(element);
			Assert::AreEqual(element,array->Get(8));
			Assert::AreEqual((uint32_t) 16, array->GetSize());
			delete array;
		}

		TEST_METHOD(ExpandsArrayWithCorrectCopying)
		{
			DynamicArray<int>* array = new(DynamicArray<int>);
			array->Set(0, 1);
			array->Set(1, 2);
			array->Set(2, 3);
			array->Set(3, 4);
			array->Set(4, 5);
			array->Set(5, 6);
			array->Set(6, 7);
			array->Set(7, 8);

			int element = 5;
			array->Append(element);
			Assert::AreEqual(1, array->Get(0));
			Assert::AreEqual(2, array->Get(1));
			Assert::AreEqual(3, array->Get(2));
			Assert::AreEqual(4, array->Get(3));
			Assert::AreEqual(5, array->Get(4));
			Assert::AreEqual(6, array->Get(5));
			Assert::AreEqual(7, array->Get(6));
			Assert::AreEqual(8, array->Get(7));
			Assert::AreEqual(element, array->Get(8));
			Assert::AreEqual((uint32_t)16, array->GetSize());
			delete array;
		}

		TEST_METHOD(PrintsCorrectArrayString)
		{
			DynamicArray<int>* array = new(DynamicArray<int>);
			array->Set(0, 1);
			array->Set(1, 2);
			array->Set(2, 3);
			array->Set(3, 4);
			array->Set(4, 5);
			array->Set(5, 6);
			array->Set(6, 7);
			array->Set(7, 8);
			std::string expected = "[1, 2, 3, 4, 5, 6, 7, 8]\n";
			Assert::AreEqual(expected, array->ToString(8));
			delete array;
		}

		TEST_METHOD(PrintsArrayWhenNull)
		{
			DynamicArray<int>* array = new(DynamicArray<int>);
			std::string expected = "[NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL]\n";
			Assert::AreEqual(expected, array->ToString(8));
			delete array;
		}
	};
}
