#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace seneca {

  
   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   }

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
         sort();
      }
   }
   
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }

   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }
   Numbers::~Numbers() {
      save();
   	  delete[] m_numbers;
	  delete[] m_filename;
   }
   Numbers::Numbers(const Numbers& src) {
      setEmpty();
      m_isOriginal = false;
      *this = src;
   }
   Numbers& Numbers::operator=(const Numbers& src) {
       if (this != &src) {
           delete[] m_numbers;
           m_numbers = new double[src.m_numCount];
           m_numbers = src.m_numbers;
           m_numCount = src.m_numCount;
           return *this;
       }
   }
   int Numbers::numberCount() const {
       int lineCount = 0;
       char ch;
       ifstream fin(m_filename);

       while (fin.is_open()) {
           while (fin.get(ch)) {
               if (ch == '\n') {
                   lineCount++;
               }
           }
           fin.close();
       }
       return lineCount;
   }
   bool Numbers::load() {
       if (m_numCount > 0) {
           ifstream fin(m_filename);
           int numOfread = 0;
           m_numbers = new double[m_numCount];

           while (fin.is_open()) {
               double number;
               for (int i = 0; i < m_numCount; i++) {
                   fin >> number;
                    m_numbers[i] = number;
                    numOfread++;
               }
               fin.close();
           }
            
           if (numOfread != m_numCount) {
               delete[] m_filename;
               delete[] m_numbers;
               setEmpty();

               return false;
           }
           if (numOfread == m_numCount) {
               return true;
           }
       }
   }
   void Numbers::save() const {
       if (m_isOriginal && !isEmpty()) {
           ofstream fout(m_filename);

           while (fout.is_open()) {
               for (int i = 0; i < m_numCount; i++) {
                   fout << m_numbers[i] << "\n" << endl;
               }
           }
       }
   }
   Numbers& Numbers::operator+=(double value) {
       double* tempPtr = new double[m_numCount +1];

       for (int i = 0; i < m_numCount; i++) {
           tempPtr[i] = m_numbers[i];
       }
       m_numCount += 1;
       tempPtr[m_numCount - 1] = value;
       delete[] m_numbers;
       m_numbers = tempPtr;
       sort();

       return *this;
   }
   ostream& Numbers::display(ostream& ostr) const {
       if (isEmpty()) ostr << "Empty list" << endl;
       if (!isEmpty()) {
           ostr.setf(ios::fixed);
           ostr.precision(2);
           ostr << "=========================" << endl;
           if (m_isOriginal) {
               ostr << m_filename << endl;
           }
           else {
               ostr << "*** COPY ***" << endl;
           }
           for (int i = 0; i < m_numCount; i++) {
               if (i == m_numCount - 1) {
                   ostr << m_numbers[i];
               }
               else {
                   ostr << m_numbers[i] << ", ";
               }
           }
           ostr << endl;
           ostr << "-------------------------" << endl;
           ostr << "Total of " << m_numCount << " number(s)" << endl;
           ostr << "Largest number:  " << max() << endl;
           ostr << "Smallest number: " << min() <<  endl;
           ostr << "Average:         " << average() << endl;
           ostr << "=========================";
       }
       return ostr;
   }
   ostream& operator<<(ostream& os, const Numbers& N) {
       N.display(os);
       return os;
   }
   istream& operator>>(istream& istr, Numbers& N) {
       double value;
       istr >> value;
       N += value;
       return istr;
   }
}
