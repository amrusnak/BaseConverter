/****************************************************************
 * Author/copyright:  Alex Rusnak
 * Date: 24 May 2017
 **/
#ifndef CSCE240_BASE_CONVERTER_H_
#define CSCE240_BASE_CONVERTER_H_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <assert.h>
#include <cctype>
#include <cmath>

using std::pow;
using std::to_string;
using std::cin;
using std::cout;
using std::endl;
using std::string;

class BaseConverter {

public:
  BaseConverter(int base10);

  /**
   *  These methods return the member variable in the base indicated.
   */
  string GetUnsignedBase2(int bits);
  string GetBase16();
  string GetSignedBase2(int bits);
  int GetBase10();

  /**
   * These methods set the member variable from the base indicated.
   */
  void SetUnsignedBase2(string base_2);
  void SetBase16(string base_16);
  void SetBase10(int base_10);
  void SetSignedBase2(string base_2);

private:
  int base10_;

};

#endif
