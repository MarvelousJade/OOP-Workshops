#include "LblShape.h"
#include "Utils.h"
#include <string>
using namespace std;
namespace seneca {
   LblShape::LblShape() {
      m_label = nullptr;
   }
   LblShape::LblShape(const char* label) {
      m_label = ut.alocpy(label); 
   }
   LblShape::~LblShape() {
      delete[] m_label;
   }
   const char* LblShape::label() const {
      return m_label;
   }
   void LblShape::getSpecs(istream& is) {
      char string[81];
      is.getline(string, 80, ',');
      ut.alocpy(m_label,string);
   }
}
