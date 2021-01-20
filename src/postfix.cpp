// Copyright 2021 ArinaMonicheva
#include <string>
#include <vector>
#include <sstream>
#include "MyStack.h"
#include "postfix.h"

std::string infix2postfix(std::string infix) {
  MyStack<char> forOperators(305);  // just for safety (max 100 '(' + all 200 max operators) + safe space
  bool flag = false;
  std::string postfixRecord, temp;
  std::istringstream input(infix);

  while ( input >> temp ) {
    if ( temp[0] == '(' ) {
      forOperators.push(temp[0]);
      temp.erase(0, 1);
    } else if ( temp.find(')') < temp.length() ) {
        flag = true;
        temp.erase(temp.length() - 1, 1);
    }

    if ( temp[0] > 47 && temp[0] < 58 ) {
      postfixRecord += temp + ' ';
    } else if ( temp[0] == '+' || temp[0] == '-') {
      if ( forOperators.isEmpty() || forOperators.get() == '(' ) {
        forOperators.push(temp[0]);
      } else {
        while ( !(forOperators.isEmpty() || forOperators.get() == '(') ) {
          postfixRecord += forOperators.pop();
          postfixRecord += ' ';
        }
        forOperators.push(temp[0]);
      }
    } else if (temp[0] == '*' || temp[0] == '/') {
        if ( !(forOperators.get() == '*' || forOperators.get() == '/') ) {
          forOperators.push(temp[0]);
        } else {
          while ( !forOperators.isEmpty() && (forOperators.get() == '/' || forOperators.get() == '*') ) {
            postfixRecord += forOperators.pop();
            postfixRecord += ' ';
          }
          forOperators.push(temp[0]);
        }
    }

    if (flag) {
      while (forOperators.get() != '(') {
        postfixRecord += forOperators.pop();
        postfixRecord += ' ';
      }
      forOperators.pop();
	  flag = false;
    }
    
  }

  while ( !forOperators.isEmpty() ) {
    postfixRecord += forOperators.pop();
    postfixRecord += ' ';
  }

  return postfixRecord;
}
