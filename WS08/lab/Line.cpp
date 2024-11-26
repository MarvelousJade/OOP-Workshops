#include <iomanip>
#include <ostream>
#include "Line.h"
#include "LblShape.h"
#include "Utils.h"
using namespace std;
namespace seneca {
   Line::Line() {
      m_length = 0;
   }
   Line::Line(const char* label, int length) : LblShape(label) {
      m_length = length;
      if (m_length < ut.strlen(label)) m_length = ut.strlen(label);
   }
   void Line::getSpecs(istream & is) {
      LblShape::getSpecs(is);
      is >> m_length;
      is.ignore(999, '\n');
   }
   void Line::draw(ostream& os) const {
      if (m_length > 0 && label() != nullptr) {
         os << label() << '\n';
         for (int i = 0; i < m_length; i++) {
            os << "=";
         }
      }
   }
}
