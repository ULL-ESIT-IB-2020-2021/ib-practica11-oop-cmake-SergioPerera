#pragma once
#include <iostream>
//#include <functions.h>
#include <string>


class DateClass {
 public:
   int year{};
   int month{};
   int day{};

   void Print(){

    std::cout << day << "/ " << month << "/" << year << std::endl;

  }

};

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

int main (int argc,char *argv[]){

  Usage (argc, argv);

  DateClass day {std::stoi(argv[1])};
  DateClass month {std::stoi(argv[2])};
  DateClass year {std::stoi(argv[3])};
  DateClass later_dates_number {std::stoi(argv[4])};

  day.Print();
 

  







}
