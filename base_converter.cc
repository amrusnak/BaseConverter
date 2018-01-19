/****************************************************************
 * Author/copyright:  Alex Rusnak
 * Date: 24 May 2017
 * This program 
 **/
#include "base_converter.h"


string DecimalToHex(int decimal) { // converts decimals to hexadecimals
  string hex ="";
  int value = 0; 
  bool negativetest = false; 
  if (decimal < 0){ // changes negative number to positive for passing
    value = (decimal * -1);
    negativetest = true;
  }else {
    value = decimal; 
  }
  int digit = 0;
  char hexdig = '1';
  while (value > 0){
    digit = value % 16; // determining remainder, then changing hexdig to match the hexadecimal value of that remainder
    if (digit == 1){
      hexdig = '1';
    }if (digit == 2){
      hexdig = '2';
    }if (digit == 3){
      hexdig = '3';
    }if (digit == 4){
      hexdig = '4';
    }if (digit == 5){
      hexdig = '5';
    }if (digit == 6){
      hexdig = '6';
    }if (digit == 7){
      hexdig = '7';
    }if (digit == 8){
      hexdig = '8';
    }if (digit == 9){
      hexdig = '9';
    }if (digit == 10){
      hexdig = 'A';
    }if (digit == 11){
      hexdig = 'B';
    }if (digit == 12){
      hexdig = 'C';
    }if (digit == 13){
      hexdig = 'D';
    }if (digit == 14){
      hexdig = 'E';
    }if (digit == 15){
      hexdig = 'F';
    }
    hex.insert(hex.begin(), hexdig); // inserting hexdig into the string
    value /= 16; 
  }
  if (negativetest){ 
    hex.insert(hex.begin(), '-');
  }
  return hex;
}

int HexToDecimal(string hex) { // converting hexadeciaml to decimal
  int output = 0;
  int x = 0;
  for(int i = (hex.length()-1); i > -1; --i){ // for loop runs through the string, then matches hexadecimal value. 
    if(hex.at(i)=='1'){ 
      output += (1*(pow(16, x))); // multiplying corresponding decimal with 16 to the power of the bit place
    }else if(hex.at(i)=='2'){
      output += (2 * (pow(16, x)));
    }else if(hex.at(i)=='3'){
      output += (3 * (pow(16, x)));
    }else if(hex.at(i)=='4'){
      output += (4 * (pow(16, x)));
    }else if(hex.at(i)=='5'){
      output += (5 * (pow(16, x)));
    }else if(hex.at(i)=='6'){
      output += (6 * (pow(16, x)));
    }else if(hex.at(i)=='7'){
      output += (7 * (pow(16, x)));
    }else if(hex.at(i)=='8'){
      output += (8 * (pow(16, x)));
    }else if(hex.at(i)=='9'){
      output += (9 * (pow(16, x)));
    }else if(hex.at(i)==('A')){
      output += (10 * (pow(16, x)));
    }else if(hex.at(i)==('B')){
      output += (11 * (pow(16, x)));
    }else if(hex.at(i)==('C')){
      output += (12 * (pow(16, x)));
    }else if(hex.at(i)==('D')){
      output += (13 * (pow(16, x)));
    }else if(hex.at(i)==('E')){
      output += (14 * (pow(16, x)));
    }else if(hex.at(i)==('F')){
      output += (15 * (pow(16, x)));
    } else if(hex.at(i)==('a')){
      output += (10 * (pow(16, x)));
    }else if(hex.at(i)==('b')){
      output += (11 * (pow(16, x)));
    }else if(hex.at(i)==('c')){
      output += (12 * (pow(16, x)));
    }else if(hex.at(i)==('d')){
      output += (13 * (pow(16, x)));
    }else if(hex.at(i)==('e')){
      output += (14 * (pow(16, x)));
    }else if(hex.at(i)==('f')){
      output += (15 * (pow(16, x)));
    } 
    ++x; // increasing bit place marker
  }
  return output; 
}

string DecimalToBinary(int dec, int bits) { // converting decimal to binary
  int total_digits = bits;
  string binary = "";
  int number = dec;
  int digit = 0;
  string shortbinary = "";
  while (number > 0) { // binary converter
    digit = number % 2; // find digit
    std::ostringstream oss;
    oss << digit;
    binary.insert(0, oss.str()); //add digit
    number /= 2; // half input number
  }
  if (binary.length() > total_digits){ // checking if the binary is longer than requested digits
    for(int i = 0; i< total_digits; i++){
      shortbinary.insert(shortbinary.begin(), binary.at(i));
    } 
    return shortbinary;
  } else if (binary.length() < total_digits){ // is binary shorter than requested digits?
    int extradigitsnumber = total_digits-binary.length();
    for (int g = 0; g< extradigitsnumber; g++){
      binary.insert(0, "0");
    } 
    return binary; 
    
  } else if(binary.length() == total_digits){ // is it just right?
    return binary;
  }
  return 0;
}

int BinaryToDecimal (string bits){ // converts from binary to decimal
  int output = 0;
  int x = 0; // place counter
  for(int i = bits.length()-1; i >=0; --i){ // going place by place in the string
    if(bits.at(i)=='1'){ // if bit space is positive (i.e. if it's 1)
      output += (pow(2, x)); // add 2 raised to the place of the digit to output
    }
    x++; // move digit counter up
  }
  return output;
}

string Complement(string bits){
  string flip(bits); 
  for (unsigned int i = 0; i < flip.size(); ++i) // going through place by place
    if (flip.at(i) == '0') // is it 0 at this place?
      flip.replace(i, 1, "1"); // change to 1
    else // if not (then its 1)
      flip.replace(i, 1, "0"); // flip to 0
    return flip;
}

string AddBase2(string bits){
  string output = "";
  char rem = '1';
  for(int i = (bits.length()-1); i> -1; --i){ //going through place by place
    if(bits.at(i) == '1'&& rem== '1'){ //is the remainder 1 and the binary 1?
      output.insert(output.begin(), '1'); //prehend 1
      rem = '1'; // make the remainder 1
    }else if(bits.at(i) == '0' && rem == '1'){ // is the reaminder 1 and the binary 0?
      output.insert(output.begin(), '1'); // prehend 1
      rem = '0'; // remainder = 0
    }else if(bits.at(i) == '1' && rem== '0'){ // is the binary 1 and the remainder 0?
      output.insert(output.begin(), '1'); // prehend 1
      rem = '0'; // remainder 0
    }else if(bits.at(i) == '0' && rem == '0'){ // are the binary and the remainder both 0?
      output.insert(output.begin(), '0'); // prehend 0
      rem = '0';// remiander =0
    }
  }
  return output;
}

string To2sComplement(string bits, bool neg) {
  if (!neg&&(bits.at(0)=='1')){ // is it positive and does it start with 1?
    bits.insert(bits.begin(), '0'); // add a 0 to give it a sign
    return bits; 
  } else if (!neg&&(bits.at(0)=='0')){ // is it positive and already starts with 0?
    return bits; // just return
  } else{ // is it negative?
    string input = Complement(bits); // flip bits
    string output = AddBase2(input); // add base 2
    return output;
  }
}

string From2sComplement(string bits) {
  if (bits.at(0)=='0'){ // is it positive?
    while(bits.at(0)=='0') { // erase extra zeros
      bits.erase(0,1);
    }
    return bits; 
  } else if(bits.at(0)=='1') { // is it negative? 
    string input = Complement(bits); //covert it to the complement
    string output = AddBase2(input); // add 1
    return output;
  }
  return bits;
}

BaseConverter::BaseConverter(int base10) { // constructor
  base10_=base10;
}

int BaseConverter::GetBase10() { //returns the base10_ value
  int output = base10_;
	return output;
}

string BaseConverter::GetUnsignedBase2(int bits) {
  int negativecheck = base10_;
  int positivestore;
  string output = "";
  if (negativecheck < 0) { // checking if its negative
    positivestore = ((base10_) * (-1));
    output = (DecimalToBinary(positivestore, bits));
  } else {
    output = (DecimalToBinary(base10_, bits)); //calling the decimal to binary converter
  }
  return output;
  }


string BaseConverter::GetSignedBase2(int bits) { // getting the signed binary
  string output = "";
  bool negative= false; // is the input negative? 
  int signswitch = base10_;
	if (base10_ < 0){ // is base10_ negative
	  signswitch = (base10_ * -1); //make it positive 
	  negative = true; // make boolean positive
	} 
	output = To2sComplement(DecimalToBinary(signswitch, bits), negative); // calls the To2sComplement with an unsigned binary string created by my method
  return output;
	
}

string BaseConverter::GetBase16() { // gets the base 16 versionof the stored variable
  string output = (DecimalToHex(base10_)); // calls the decimal to hex converter and places output in string
  return output;
	return 0;
}

void BaseConverter::SetBase10(int base_10) {
  base10_ = base_10; // sets the value of the variable using input
}

void BaseConverter::SetUnsignedBase2(string base_2) { // sets the unsigned binary value of the stored variable
   int output = 0;
  output = (BinaryToDecimal(base_2)); // calls binary to decimal converter
  base10_ = output;
}

void BaseConverter::SetSignedBase2(string base_2) { // sets the stored varaible using a 2s complement input
  string input = From2sComplement(base_2); // converting to unsigned base 2
  int output = BinaryToDecimal(input); // converting to an integer
  if(base_2.at(0)=='1') { // if the input string was negative, make the integer output negative
    output *= -1;
  }
  base10_ = output;
}


void BaseConverter::SetBase16(string base_16) { // sets the stored variable from a base 16 input
  int output = HexToDecimal(base_16); // changes the hex to decimal
  if (base_16.at(0) == '-') { // if the input string hase a negative sign at the beginning
    output = (output * -1); // multiply the decimal output by -1 to make it negative
  }
  base10_ = output; 
}



