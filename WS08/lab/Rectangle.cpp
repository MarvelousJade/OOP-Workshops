#include <iomanip>
#include <string>
#include "Rectangle.h"
#include "LblShape.h"
#include "Utils.h"
using namespace std;
namespace seneca {
   Rectangle::Rectangle() {
      m_width = 0;
      m_height = 0;
   }
   Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label){
      m_width = width;
      m_height = height;
   }
   void Rectangle::getSpecs(std::istream& is) {
      LblShape::getSpecs(is);
      is >> m_width;
      char comma;
      is >> comma;
      is >> m_height;
      is.ignore(999, '\n');
   } 
   void Rectangle::draw(std::ostream& os) const {
      if (m_width > 0 && m_height > 0) {
         os << "+";
         if (m_width > ut.strlen(label())) {
             os << setfill('-') << setw(m_width - 1);
         }
         else {
             os << setfill('-') << setw(9);
         }
         os << "+" << '\n';

         os << "|";
         os << label();
         os << setfill(' ') << setw(m_width - 1 - ut.strlen(label()));
         os << "|" << '\n';
         for(int i = 0; i < m_height - 3; i++) {
            os << "|";
            os << setfill(' ') << setw(m_width - 1);
            os << "|" << '\n';
         }

         os << "+";
         if (m_width > ut.strlen(label())) {
             os << setfill('-') << setw(m_width - 1);
         }
         else {
             os << setfill('-') << setw(9);
         }
         os << "+";
      }
   }
}
