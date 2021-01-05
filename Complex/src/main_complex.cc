#pragma once
#include <iostream>
#include <vector>
#include "complex.h"

int main (){

  std::cout << "Introduce las coordenadas de los números complejos una a una: " << std::endl;
  std::vector<int> complex_1{};
  std::vector<int> complex_2{};
  std::vector<int> result{};
  int in_number{0};
  
  for(int i{0}; i < 2; i++){               //Este bucle es para solicitar las coordenadas del primer número complejo
    std::cout << "Introduce las coordenada número " << i << " del primer número complejo: " << std::endl;
    std::cin >> in_number;
    complex_1.emplace_back(in_number);
  }
  for(int i{0}; i < 2; i++){               //Este bucle es para solicitar las coordenadas del segundo número complejo
    std::cout << "Introduce las coordenada número " << i << " del segundo número complejo: " << std::endl;
    std::cin >> in_number;
    complex_2.emplace_back(in_number);
  }

  ComplexClass complex_result(complex_1, complex_2);

  complex_result.Add(complex_1, complex_2);
  complex_result.Print(result);
  complex_result.Sub(complex_1, complex_2);
  complex_result.Print(result);
  

}
