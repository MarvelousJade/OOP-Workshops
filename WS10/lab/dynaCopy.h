#ifndef SENECA_DYNACOPY_H
#define SENECA_DYNACOPY_H
#include <iostream>

namespace seneca {
   template <typename T>
   T* dynaCopy(const T* srcArrPtr, int arrSize) {
      T* newArr = new T[arrSize]; 
      int i =0;

      for (i = 0; i < arrSize; i++) newArr[i] = srcArrPtr[i];

      return newArr;
   }
   
   template <typename T>
   T* dynaCopy(T*& desArr, const T* srcArrPtr, int arrSize) {
      delete[] desArr;   
      desArr = nullptr;
      desArr = dynaCopy(srcArrPtr, arrSize);
      return desArr;
   }

   template <typename T>
   void prnArray(const T* arrPtr, int arrSize) {
      for(int i = 0; i < arrSize; i++) {
         if(i == arrSize - 1) {
            std::cout << arrPtr[i];
         } else {
            std::cout << arrPtr[i] << ", ";
         }
      }
      std::cout << std::endl;
   } 
}

#endif // !SENECA_DYNACOPY_H

