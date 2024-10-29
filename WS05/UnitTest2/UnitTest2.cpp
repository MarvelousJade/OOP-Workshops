#include "pch.h"
#include "CppUnitTest.h"
#include "Account.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			seneca::Account newAccount; // Should be a new account (m_number == 0)

			// Act
			bool isNew = ~newAccount;

			// Assert
			Assert::IsTrue(isNew, L"operator~ should return true for new accounts (m_number == 0)");
		}
	};
}
