#include "LblShape.h"
#include "Utils.h"
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
   LblShape::getSpecs(istreeam& is) {
      
   }
}
