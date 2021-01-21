// Copyright 2021 ArinaMonicheva
#include <iostream>
#include <string>
#include "postfix.h"

int main() {
  std::string exmpl("(1 + 2) / (3 + 4 * 6.7) - 5.3 * 4.4");
  std::string exmpl1("2 + 2");
  std::string exmpl2("2 + 6 * 3 / (4 - 2)");
  std::string exmpl3("(2 + 8.3) * (6 - 3.2)");
  std::string exmpl4("(6 * (4 - 2) + 5) * (2.6 + 3 * 7) - 9");

  std::cout << exmpl << "     ->     " << infix2postfix(exmpl) << std::endl;
  std::cout << exmpl1 << "     ->     " << infix2postfix(exmpl1) << std::endl;
  std::cout << exmpl2 << "     ->     " << infix2postfix(exmpl2) << std::endl;
  std::cout << exmpl3 << "     ->     " << infix2postfix(exmpl3) << std::endl;
  std::cout << exmpl4 << "     ->     " << infix2postfix(exmpl4) << std::endl;

  return 0;
}
