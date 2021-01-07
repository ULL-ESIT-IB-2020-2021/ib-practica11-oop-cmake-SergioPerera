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
  int special_months{32};
  int i{0};
  
  
  for(int a{i}; a <= later_dates_number_; a++){
    
    day_++;
    if (day_== special_months){
      month_++;
      day_ = 1;    
      switch(month_){
        case 1:
        i = 0;
        special_months = 31;
        special_months = special_months +3;
        break;
        case 2:
        i = -1;
        special_months = 30;
        special_months = special_months -1;
        break;
        case 3:
        special_months = 30;
        i = 0;
        special_months = special_months +2;
        break;
        case 4:
        special_months = 30;
        i = 0;
        special_months = special_months + 1;
        break;
        case 5:
        special_months = 30;
        i = 0;
        special_months = special_months +2;
        break;
        case 6:
        special_months = 30;
        i = 0;
        special_months = special_months + 1;
        case 7:
        special_months = 30;
        i = 0;
        special_months = special_months +2 ;
        break;
        case 8:
        special_months = 30;
        i = 0;
        special_months = special_months +2 ;
        break;
        case 9:
        special_months = 30;
        i = 0;
        special_months = special_months + 1;
        case 10:
        special_months = 30;
        i = 0;
        special_months = special_months +2;
        break;
        case 11:
        special_months = 30;
        i = 0;
        special_months = special_months + 1;
        case 12:
        special_months = 30;
        i = 0; 
        special_months = special_months +2;
        break;
      }           
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
