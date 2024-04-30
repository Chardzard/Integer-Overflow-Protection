/*
  Parke
  10/23/2022
  We will take two digits as input from our user and not only perform input validation, 
  but also check for integer overflows. We will then add our 2 digits together
*/

#include <iostream>   // iostream
#include <iomanip>   // setfill, setw
#include <string>   // find_first_not_of, npos, getline, .length()
#include <climits> // ULONG_MAX - constant

int main() {                        // Main driver for program
  
                                   // Variable declarations, assign bigVal to ULONG_MAX for later use 
  std::string num1;
  std::string num2;
  int counter1 = 1;
  int counter2 = 1;
  int counter3 = 1;
  unsigned long long bigVal = ULONG_MAX;

  std::cout << "Enter num1: ";
  std::getline(std::cin, num1);    // Prompt user for input and assign to variable

  while (num1.find_first_not_of("0123456789.-") != std::string::npos || num1[0] == '-' || num1.size() == std::to_string(bigVal).size() && num1 > std::to_string(bigVal)){
    if (counter1 < 3){
      std::cout << std::endl << "INVALID RE-Enter num: ";
      std::getline(std::cin, num1); // While loop prompts user for another input if previous input is not positive, all digits or less than bigVal
      counter1 += 1;
    }
    else{                           // Program aborts if user inputs illegal input more than 3 times
      std::cout << std::endl << "PROGRAM ABORT" << "\n" << std::endl;
      return;
    }
    }

  std::cout << std::endl << "Enter num2: ";
  std::getline(std::cin, num2);    // Prompt user for input and assign to variable

  while (num2.find_first_not_of("0123456789.-") != std::string::npos || num2[0] == '-' || num2.size() == std::to_string(bigVal).size() && num2 > std::to_string(bigVal)){
    if (counter2 < 3){
      std::cout << std::endl << "INVALID RE-Enter num: ";
      std::getline(std::cin, num2); // While loop prompts user for another input if previous input is not positive, all digits or less than bigVal
      counter2 += 1;
    }
    else{                          // Program aborts if user inputs illegal input more than 3 times
      std::cout << std::endl << "PROGRAM ABORT" << "\n" << std::endl;
      return;
    }
    }
  try{                                           // try/except block to check that entry can actually be converted to unsigned long, if not we re-prompt user for input
  unsigned long verifiedNum1 = std::stoul(num1);
  unsigned long verifiedNum2 = std::stoul(num2); // Convert our strings into final number variables, then set finalVal to total from input for later use
  unsigned long finalVal = verifiedNum1 + verifiedNum2;
  while (finalVal > bigVal || finalVal == 0){   // While loop to check if adding our two digits causes an overflow, and if so re-prompt user for input 
    if (counter3 < 3){
      std::cout << std::endl << "INVALID RE-Enter lower num2: ";
      std::cin >> num2;
      counter3 += 1;
    }
    else{                         // Program aborts if user inputs illegal input more than 3 times
      std::cout << std::endl << "PROGRAM ABORT" << "\n" << std::endl;
      return -1;
    }
  }                               // Output final answer to console using proper formatting 
  int len = std::to_string(finalVal).length() + 2;  
  std::cout << std::endl << std::setfill(' ') << std::setw(len) << std::right << verifiedNum1 << std::endl;
  std::cout << "+" << std::setw(len - 1) << std::right << verifiedNum2 << std::endl;
  std::cout << std::setfill('-') << std::setw(len) << '-' << std::endl;
  std::cout << std::setfill(' ') << std::setw(len) << finalVal << std::endl;
  } catch(std::invalid_argument& ex){
    std::cout << "PROGRAM ABORT";
    return 255;
    }
return 0;                        // Successful program run
}
