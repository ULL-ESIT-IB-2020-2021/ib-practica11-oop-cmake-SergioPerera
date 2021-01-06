#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class Rationals{
 private:
  int numerator_1_{};
  int numerator_2_{};
  int denominator_1_{};
  int denominator_2_{};

 public:
  Rationals(int, int, int, int);
  void Add(std::ofstream& archive_to_write);
  void Sub(std::ofstream& archive_to_write);
  void Mult(std::ofstream& archive_to_write);
  void Div(std::ofstream& archive_to_write);
  void Compare(std::ofstream& archive_to_write);
  void Print(std::ofstream& archive_to_write);

};
Rationals::Rationals(int numerator_1, int numerator_2,int denominator_1, int denominator_2){
  numerator_1_ = numerator_1;
  numerator_2_ = numerator_2;
  denominator_1_ = denominator_1;
  denominator_2_ = denominator_2;
};


int main(){

  std::ifstream file("archive_to_read.txt");

  int numerator_1{};
  int numerator_2{};
  int denominator_1{};
  int denominator_2{};

  std::string negative{"-"};
  std::string in_numbers;
  std::string current_number;

  while (std::getline(file, in_numbers)){     // aquí hacemos que el in_numbers contenga la información de una línea distinta en cada iteración
    std::cout << in_numbers << "\n";

    if (in_numbers[0] == negative[0]){               // miramos si el primer racional es negativo 
      current_number = in_numbers[1];
      numerator_1 = std::stoi(current_number);
      current_number = in_numbers[3];
      denominator_1 = std::stoi(current_number);
      
      /*current_number = in_numbers[4];
      numerator_2 = std::stoi(current_number); 
      current_number = in_numbers[6];                 // establecemos el segundo racional como positivo
      denominator_2 = std::stoi(current_number);*/
    }
    else if(in_numbers[5] == negative[0]){               // miramos si el segundo racional es negativo y lo cambiamos
      current_number = in_numbers[7];
      numerator_2 = std::stoi(current_number);
      current_number = in_numbers[9];
      denominator_2 = std::stoi(current_number);

      current_number = in_numbers[0];
      numerator_1 = std::stoi(current_number);  
      current_number = in_numbers[2];               
      denominator_1 = std::stoi(current_number);
    }
    else{
      current_number = in_numbers[0];
      numerator_1 = std::stoi(current_number);
      current_number = in_numbers[2];
      denominator_1 = std::stoi(current_number);

      current_number = in_numbers[4];
      numerator_2 = std::stoi(current_number);                   // establecemos el segundo racional como positivo
      current_number = in_numbers[6];
      denominator_2 = std::stoi(current_number);
    }


  }
}
