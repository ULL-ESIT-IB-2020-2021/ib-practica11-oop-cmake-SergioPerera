#include <iostream>
#include <functions.h>


void Usage (int argc, char *argv[]){
  
  if ( argc == 1 ){

    std::cout << argv[0] << ": Falta una fecha como parámetro" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;

    exit(EXIT_SUCCESS);
  }

  std::string kHelpText = "Este programa necesita que se le introduzca una fecha tal que dd/mm/aaaa N fichero_salida.txt";
  std::string parameter{argv[1]};

  if ( parameter == "--help" ) {

    std::cout << kHelpText << std::endl;

    exit(EXIT_SUCCESS);
  }
}