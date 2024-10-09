#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool() const;
      bool operator~() const;
      Account& operator+=(double balance);
      Account& operator-=(double balance);
      Account& operator=(int number);
      Account& operator=(Account&);
   };


}
#endif // SENECA_ACCOUNT_H_