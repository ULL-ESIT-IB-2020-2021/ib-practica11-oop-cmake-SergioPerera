#include <iostream>
#include "classes_complex.h"
#include "complex.h"
#include <vector>

std::vector<int> InCoordenates(){

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
  //ComplexClass returned_value(complex_1, complex_2);

  return(complex_1, complex_2);

  
}