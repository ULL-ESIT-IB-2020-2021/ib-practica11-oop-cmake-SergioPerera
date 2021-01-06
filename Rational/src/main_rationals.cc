#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "tools.h"



int main(int argc, char *argv[]){
  Usage (argc,argv);

  std::string name_archive_to_read{argv[1]};
  std::ifstream archive_to_read;
  archive_to_read.open(name_archive_to_read, std::ios::in);
  if(archive_to_read.fail()){
    std::cout << "No se pudo abrir el archivo " << name_archive_to_read << " o no está creado" << std::endl;
    exit(EXIT_SUCCESS);
  }

  std::string name_archive_to_write {argv[2]};
  std::ofstream archive_to_write;
  archive_to_write.open(name_archive_to_write, std::ios::out);
  if(archive_to_write.fail()){
    std::cout << "Error al crear el archivo" << std::endl;
    exit(EXIT_SUCCESS);
  }

  int numerator_1{};
  int numerator_2{};
  int denominator_1{};
  int denominator_2{};

  std::string negative{"-"};
  std::string in_numbers;
  std::string current_number;

  while (std::getline(archive_to_read, in_numbers)){     // aquí hacemos que el in_numbers contenga la información de una línea distinta en cada iteración

    current_number = in_numbers[0];
    numerator_1 = std::stoi(current_number);
    current_number = in_numbers[2];
    denominator_1 = std::stoi(current_number);

    current_number = in_numbers[4];
    numerator_2 = std::stoi(current_number);                   
    current_number = in_numbers[6];
    denominator_2 = std::stoi(current_number);

    Rationals result(numerator_1, numerator_2, denominator_1, denominator_2);

    result.Add(archive_to_write);
    result.Sub(archive_to_write);
    result.Mult(archive_to_write);
    result.Div(archive_to_write);
    result.Compare(archive_to_write);
  }
  archive_to_write.close();
}
