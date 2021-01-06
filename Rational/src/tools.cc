#include <iostream>
#include <cstdlib>

void Usage (int argc, char *argv[]){
  
  std::string kHelpText = "Este programa necesita que se le introduzca una fecha tal que dd/mm/aaaa N fichero_salida.txt";

  std::string parameter{argv[1]};

  if ( parameter == "--help" ) {

    std::cout << "fichero_entrada: fichero de texto conteniendo líneas con un par de número racionales: a/b c/d separados por un espacio" << std::endl;
    std::cout << "fichero_salida: fichero de texto que contendrá líneas con las operaciones realizadas" << std::endl;

    exit(EXIT_SUCCESS);
  }
  
  if ( argc < 3 ){

    std::cout << argv[0] << ": Faltan uno o varios parámetros" << std::endl;
    std::cout << "Modo de uso: " << argv[0] << " fichero_entrada.txt fichero_salida.txt " << std::endl;
    std::cout << "Pruebe: " << argv[0] << " --help para más información " << std::endl;

    exit(EXIT_SUCCESS);
  }

  
}