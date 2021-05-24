#include "pch.h"
#include "CppUnitTest.h"
#include "../pQueue.h"
#include "../aQueue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			AQueue<int> queue(3);
			queue << 5 << 3 << 2;
			Assert::AreEqual(queue.isFull(), true);
			Assert::AreEqual(queue.queueTop(), 5);
			Assert::AreEqual(queue.remove(), 5);
			Assert::AreEqual(queue.remove(), 3);
			queue << 1 << 4;
			Assert::AreEqual(queue.remove(), 2);
			Assert::AreEqual(queue.remove(), 1);
			Assert::AreEqual(queue.remove(), 4);
			Assert::AreEqual(queue.isEmpty(), true);

		}

		
	};
}
