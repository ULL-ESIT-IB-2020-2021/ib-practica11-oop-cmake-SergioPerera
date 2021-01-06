#pragma once
#include <iostream>
#include <vector>

void Usage (int argc, char *argv[]){

  std::string kHelpText = "Este programa necesita que se le introduzcan las coordenadas de los números complejos tal que X Y X Y";
  std::string parameter{argv[1]};

  if ( parameter == "--help" ) {

    std::cout << kHelpText << std::endl;

    exit(EXIT_SUCCESS);
  } 

  if ( argc < 5 ){

    std::cout << argv[0] << ": Falta un parámetro" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;

    exit(EXIT_SUCCESS);
  }

 
}
