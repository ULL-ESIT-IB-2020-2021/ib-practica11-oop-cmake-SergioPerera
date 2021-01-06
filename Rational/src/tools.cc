#include <iostream>
#include <cstdlib>

void Usage (int argc, char *argv[]){
  
  if ( argc < 3 ){

    std::cout << argv[0] << ": Falta un parámetro" << std::endl;
    std::cout << "Modo de uso: " << argv[0] << " fichero_entrada.txt fichero_salida.txt" << std::endl;

    exit(EXIT_SUCCESS);
  }

  std::string kHelpText = "Este programa necesita que se le introduzca una fecha tal que dd/mm/aaaa N fichero_salida.txt";

  std::string parameter{argv[1]};

  if ( parameter == "--help" ) {

    std::cout << kHelpText << std::endl;

    exit(EXIT_SUCCESS);
  }
}