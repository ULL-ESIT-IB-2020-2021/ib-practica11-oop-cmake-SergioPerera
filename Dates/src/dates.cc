#pragma once
#include <iostream>
#include <dates.h>
#include <tools.h>
#include <string>
#include <fstream>
#include <cstdlib>

int main (int argc,char *argv[]){

  Usage (argc, argv);

  int day_ {std::stoi(argv[1])};
  int month_ {std::stoi(argv[2])};
  int year_ {std::stoi(argv[3])};
  int later_dates_number_ {std::stoi(argv[4])};
  std::string archive_name {argv[5]};

  DateClass in_date(day_, month_, year_, later_dates_number_);

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
