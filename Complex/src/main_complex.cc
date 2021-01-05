#pragma once
#include <iostream>
#include <vector>
#include "classes_complex.h"

int main (){

  std::cout << "Introduce las coordenadas de los números complejos una a una: " << std::endl;
  std::vector<int> complex_1{};
  std::vector<int> complex_2{};
  std::vector<int> result{};
  int in_number{0};
  
  InCoordenates();

  ComplexClass complex_result(complex_1, complex_2);

  complex_result.Add(complex_1, complex_2);
  complex_result.Print(result);
  complex_result.Sub(complex_1, complex_2);
  complex_result.Print(result);
  

}
