#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
   Account::operator bool() const { 
       int digitCount = 1;
       int n = m_number;

       while (n!= 0) {
           n = n / 10;
           ++n;
       }

       return n =5 && m_balance >= 0; 
   }
   bool Account::operator~() {
       return m_number == 0;
    }
   Account& Account::operator+=(double balance) {
       if (*this) m_balance += balance;
       return *this;
   }
   Account& Account::operator-=(double balance) {
       if (*this && m_balance >= balance && balance > 0) m_balance -= balance;
       return *this;
   }
   Account& Account::operator=(int number) {
       int n = number;

       while (n!= 0) {
           n = n / 10;
           ++n;
       }     
       if (n != 5 && m_number == 0) m_number = -1;
       if(n == 5 && m_number == 0) m_number = number;

       return *this;
   }
   Account& Account::operator=(Account& newAccount) {
       if (m_number == 0 && newAccount) {
		   m_number = newAccount.m_number;
		   m_balance = newAccount.m_balance;
		   newAccount.m_number = 0;
		   newAccount.m_balance = 0;
       }
       return *this;
   }
   Account& Account::operator<<(Account& rightAccount) {
       if (*this && rightAccount && m_number != rightAccount.m_number) {
           m_balance += rightAccount.m_balance;
           rightAccount.m_balance = 0;
       }
       return *this;
   }
   Account& Account::operator>>(Account& rightAccount) {
       if (*this && rightAccount && m_number != rightAccount.m_number) {
           rightAccount.m_balance += m_balance;
            m_balance = 0;
       }
       return *this;
   }
   double operator+(Account& leftAccount, Account& rightAccount) {
       double sum;
       if (leftAccount && rightAccount && leftAccount.m_number != rightAccount.m_number) {
           sum = leftAccount.m_balance + rightAccount.m_balance;
       }
       return sum;
   }
}