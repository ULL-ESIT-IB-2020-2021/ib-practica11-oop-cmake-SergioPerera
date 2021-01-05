#pragma once
#include <iostream>
#include <vector>
#include "classes_functions_complex.h"
#include <string>



int main (int argc,char *argv[]){

  Usage (argc, argv);

  std::vector<int> complex_1{};
  std::vector<int> complex_2{};
  std::vector<int> result{};
  int in_number{0};

  
  
  complex_1.emplace_back(std::stoi(argv[1]));
  complex_1.emplace_back(std::stoi(argv[2]));

  complex_2.emplace_back(std::stoi(argv[3]));
  complex_2.emplace_back(std::stoi(argv[4]));

  ComplexClass complex_result(complex_1, complex_2);

  complex_result.Add(complex_1, complex_2);
  complex_result.Print(result);
  complex_result.Sub(complex_1, complex_2);
  complex_result.Print(result);
  

}
