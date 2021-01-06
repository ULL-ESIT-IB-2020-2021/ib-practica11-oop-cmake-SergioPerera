#include <iostream>
#include <fstream>
#include <string>

int main (){
    

  std::ifstream file("lala.txt");
  std::string pollo;
  while (std::getline(file, pollo)) {
    std::cout << pollo << "\n";
  } 
}