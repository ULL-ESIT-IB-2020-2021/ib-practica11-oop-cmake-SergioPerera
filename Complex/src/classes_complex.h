#include <iostream>
#include <vector>
#include "main_complex.cc"
#include <tools.h>
#include <cstdlib>
#ifndef COMPLEX_H
#define COMPLEX_H

class ComplexClass {
 private:
/*std::vector<int> result_;
  std::vector<int> complex_1_;
  std::vector<int> complex_2_; */

 public:
  ComplexClass( std::vector<int>, std::vector<int> );
  void Add(std::vector<int>, std::vector<int>);
  void Sub(std::vector<int>, std::vector<int>);
  void Print(std::vector<int>);

  std::vector<int> result_;
  std::vector<int> complex_1_;
  std::vector<int> complex_2_;

};
ComplexClass::ComplexClass(std::vector<int> complex_1, std::vector<int>complex_2){
  complex_1_ = complex_1;
  complex_2_ = complex_2;
};
void ComplexClass::Add(std::vector<int>, std::vector<int>){
  result_.emplace_back (complex_1_[0] + complex_2_[0]);
  result_.emplace_back (complex_1_[1] + complex_2_[1]);
  std::cout << "Suma: ";
};

void ComplexClass::Sub(std::vector<int>, std::vector<int>){
  result_.emplace_back (complex_1_[0] - complex_2_[0]);
  result_.emplace_back (complex_1_[1] - complex_2_[1]);
  std::cout << "Resta: ";
};

void ComplexClass::Print(std::vector<int>){
  std::cout << result_[0] << " " << result_[1] << "i" << std::endl;
  result_.clear();
};


#endif