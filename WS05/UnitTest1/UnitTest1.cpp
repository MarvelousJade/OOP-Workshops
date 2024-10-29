#include "pch.h"
#include "CppUnitTest.h"
#include "Account.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace seneca;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            seneca::Account newAccount = {0, 0};
            bool expected = true;

			
            // Call main() in your test

            // Test
            Assert::AreEqual(expected, ~*this);
		}
	};
}
