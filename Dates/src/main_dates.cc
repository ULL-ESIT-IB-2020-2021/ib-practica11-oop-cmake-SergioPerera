#pragma once
#include <iostream>
//#include <functions.h>
#include <string>
#include <fstream>
#include <cstdlib>

class DateClass {
 private:  
  int year_;
  int month_;
  int day_;
  int later_dates_number_;
  int archive_;
 
 public:
  DateClass(int, int, int, int);
  void Print(std::ofstream& archive);
  void NextDates(std::ofstream& archive);
  void LeapYear(std::ofstream& archive);
};
DateClass::DateClass(int day, int month, int year, int later_dates_number){
  day_ = day; 
  month_ = month;
  year_ = year;
  later_dates_number_ = later_dates_number;
};
void DateClass::Print(std::ofstream& archive){
  archive << day_ << "/" << month_ << "/" << year_ << std::endl;
};
void DateClass::NextDates(std::ofstream& archive){
  for(int i{1}; i <= later_dates_number_; i++){
    day_++;

    if (day_== 30){
      month_++;
      day_ = 1;              //Volvemos al primer día del mes

      if(month_ == 12){
        year_++;
        month_ = 1;          //Volvemos al primer mes del año
      }
    }
    archive << day_ << "/" << month_ << "/" << year_ << std::endl;
  }
}
void DateClass::LeapYear(std::ofstream& archive){
  if(year_ % 4 == 0){
    archive << "El año " << year_ << " es bisiesto" << std::endl;
  }
}



void Usage (int argc, char *argv[]){
  
  if ( argc < 5 ){

    std::cout << argv[0] << ": Falta un parámetro" << std::endl;
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

  int day_ {std::stoi(argv[1])};
  int month_ {std::stoi(argv[2])};
  int year_ {std::stoi(argv[3])};
  int later_dates_number_ {std::stoi(argv[4])};
  std::string archive_name {argv[5]};

  DateClass in_date(day_, month_, year_, later_dates_number_);

  //in_date.Print();
  
  std::ofstream archive;
  archive.open(archive_name,std::ios::out);
  if(archive.fail()){
    std::cout << "Error al crear el archivo" << std::endl;
    exit(EXIT_SUCCESS);
  }
  
  in_date.Print(archive);
  in_date.NextDates(archive);
  in_date.LeapYear(archive);
  archive.close();

}
