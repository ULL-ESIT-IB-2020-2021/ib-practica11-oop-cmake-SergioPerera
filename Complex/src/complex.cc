#pragma once
#include <iostream>
#include <vector>

class ComplexClass {
 private:
  std::vector<int> result_;
  std::vector<int> complex_1_;
  std::vector<int> complex_2_;

 public:
  ComplexClass( std::vector<int>, std::vector<int> );
  void Add(std::vector<int>, std::vector<int>);
  void Sub(std::vector<int>, std::vector<int>);
  void Print(std::vector<int>);
};

void ComplexClass::Add(std::vector<int>, std::vector<int>){
  result_.emplace_back (complex_1_ [0] + complex_2_[0]);
  result_.emplace_back (complex_1_ [1] + complex_2_[1]);
};

void ComplexClass::Sub(std::vector<int>, std::vector<int>){
  result_.emplace_back (complex_1_ [0] - complex_2_[0]);
  result_.emplace_back (complex_1_ [1] - complex_2_[1]);
};

void ComplexClass::Print(std::vector<int>){
  std::cout << result_[0] << " " << result_[1] << "i" << std::endl;
};



int main (){
  std::vector<int> complex_1_ {4, 5};
  std::vector<int> complex_2_ {7, -8};
  std::vector<int> result_;

  ComplexClass complex(complex_1_, complex_2_);

  complex.Add(complex_1_, complex_2_);
  complex.Print(result_);
  complex.Sub(complex_1_, complex_2_);
  complex.Print(result_);
  

}
