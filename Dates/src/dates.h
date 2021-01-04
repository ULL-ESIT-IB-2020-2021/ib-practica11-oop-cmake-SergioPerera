#pragma once
#include <iostream>
#include <dates.h>
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

    if (day_== 31){
      month_++;
      day_ = 1;              //Volvemos al primer día del mes

      if(month_ == 13){
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
