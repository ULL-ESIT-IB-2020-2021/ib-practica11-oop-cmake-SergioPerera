#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "tools.h"
#include <stdexcept>


int main(int argc, char *argv[]){

  if(argv[1] == NULL){                                              //Esto se hace porque si a un string le asignamos un pointer vacío da error std::logic_error
    std::cout << "Modo de uso: " << argv[0] << " fichero_entrada.txt fichero_salida.txt " << std::endl;
    std::cout << "Pruebe: " << argv[0] << " --help para más información " << std::endl;
    exit(EXIT_SUCCESS);
  }
  
  Usage (argc, argv);
  
  std::string name_archive_to_read{argv[1]};
  std::ifstream archive_to_read;
  archive_to_read.open(name_archive_to_read, std::ios::in);
  if(archive_to_read.fail()){
    std::cout << "No se pudo abrir el archivo de entrada o no está creado" << std::endl;
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
  int counter{}, negative_counter{};
  std::string negative {"-"};
  std::string in_numbers;
  std::string current_number;

  while (std::getline(archive_to_read, in_numbers)){     // aquí hacemos que el in_numbers contenga la información de una línea distinta en cada iteración
    counter = 0;
    for(int i{0}; i < in_numbers.length(); i++){
      if(in_numbers[i] > 47 && in_numbers[i] < 58){
        counter++;
        negative_counter++;
        current_number = in_numbers[i];
        switch(counter){
          case 1:
          numerator_1 = std::stoi(current_number);
          case 2: 
          denominator_1 = std::stoi(current_number);
            if(denominator_1 == 0){
              std::cout << "No puede haber denominador 0" << std::endl; 
            }
          case 3:
          numerator_2 = std::stoi(current_number);
          case 4:
          denominator_2 = std::stoi(current_number);
            if(denominator_2 == 0){
              std::cout << "No puede haber denominador 0" << std::endl; 
            }
        }
      }
    }  
 
    Rationals result(numerator_1, numerator_2, denominator_1, denominator_2);

    result.Add(archive_to_write);
    result.Sub(archive_to_write);
    result.Mult(archive_to_write);
    result.Div(archive_to_write);
    result.Compare(archive_to_write);
    result.Median(archive_to_write);
  
  }
  archive_to_write.close();
}
