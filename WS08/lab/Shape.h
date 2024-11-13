#ifndef SENECA_SHAPE_H
#define SENECA_SHAPE_H
#include <iostream>
#include <istream>
#include <strstream>

namespace seneca {

   class Shape {
   public:
      // Pure virtual function to draw the shape, implemented in derived classes
      virtual void draw(std::ostream&);
      // Pure virtual function to get specifications of the shape, implemented in derived classes
      virtual void getSpecs(std::istream&);

      // Virtual destructor to ensure proper cleanup of derived class objects
      ~Shape();
   };

   // Operator overload to handle output stream, relies on draw function
   std::ostrstream& operator<<(std::ostream& os, const Shape& s);  

   // Operator overload to handle input stream, relies on getSpecs function
   std::istrstream& operator>>(std::istream& is, Shape& s);  
}

#endif // !SENECA_SHAPE_H
