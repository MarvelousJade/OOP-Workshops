#include "Shape.h"
namespace seneca {
	Shape::~Shape() {

	}

	std::ostream& operator<<(std::ostream& os, const Shape& s) {
		s.draw(os);
		return os;
	}

	// Operator overload to handle input stream, relies on getSpecs function
	std::istream& operator>>(std::istream& is, Shape& s) {
		s.getSpecs(is);
		return is;
	}
}