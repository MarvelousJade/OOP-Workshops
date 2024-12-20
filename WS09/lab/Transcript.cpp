/***********************************************************************
// OOP244 workshop 9, Transcript module
//
// File	Transcript.coo
// Version 1.0
// Date 2024-11-18
// started by Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Transcript.h"
#include "Utils.h"
using namespace std;
namespace seneca {
   Transcript::Transcript(const char* studentName, size_t studentNumber) {
      ut.alocpy(m_studentName, studentName);  
      m_studentNumber = studentNumber;
   }
   
   Transcript::Transcript(const Transcript& other) : Marks(other) {
      ut.alocpy(m_studentName, other.m_studentName);  
      m_studentNumber = other.m_studentNumber;
   }

   Transcript& Transcript::operator=(const Transcript& other){
      if (this != &other) {
      Marks::operator=(other);
         delete[] m_studentName;
         m_studentName = nullptr;
         ut.alocpy(m_studentName, other.m_studentName);  
         m_studentNumber = other.m_studentNumber;
      }
      return *this;
   }
   Transcript::~Transcript() {
      delete[] m_studentName;
      m_studentName = nullptr;
      m_studentNumber = 0;
   }
   ostream& Transcript::display(ostream& ostr) const{
      ostr << m_studentName << " (" << m_studentNumber << ")" << "\n"
      << "--------------------------------------------------------------------------" << endl;
      Marks::display(ostr);
      return ostr;
   }
}
