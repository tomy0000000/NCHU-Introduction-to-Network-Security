//
//  main.cpp
//  Caesar Cipher
//
//  Created by Tomy Hsieh on 2020/9/24.
//  Copyright © 2020 Tomy Hsieh. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

const int VALID_FROM = 32;  // (Space)
const int VALID_TO = 126;   // (~)
const int RANGE = VALID_TO - VALID_FROM + 1;

int main(int argc, const char * argv[]) {
  
  // Init
  string message;
  int key = 0;
  bool encrypt; // true/false for encrypt/decrypt
  
  // Prompt Action
  cout << "Decrypt(0) or Encrypt (1): ";
  cin >> encrypt;
  while (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input!!!" << endl;
    cout << "Decrypt(0) or Encrypt (1): ";
    cin >> encrypt;
  }
  cin.ignore();
  
  // Prompt Message
  cout << (encrypt ? "Message: " : "Encrypted Message: ");
  getline(cin, message, '\n');
  
  
  // Prompt Key
  // Modified from https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
  cout << "Key: ";
  cin >> key;
  while (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid Key!!!";
    cout << "Key: ";
    cin >> key;
  }
  
  // Conversion
  cout << (encrypt ? "Encrypted Message: " : "Decrypted Message: ") << endl;
  for (string::iterator it=message.begin(); it != message.end(); ++it) {
    int ascii = *it;
    if (encrypt) {
      ascii += key;               // shift
      if (ascii > VALID_TO) {     // handle overflow
        ascii -= VALID_FROM;      // normalize to 0 ~ range
        ascii %= RANGE;           // deduction
        ascii += VALID_FROM;      // denormalize
      }
    } else {
      ascii -= key;               // shift
      if (ascii <  VALID_FROM) {  // handle underflow
        ascii -= VALID_FROM - 1;  // normalize to 0 ~ range
        ascii %= RANGE;           // deduction
        ascii += VALID_TO;        // denormalize
      }
    }
    cout << char(ascii);
  }
  cout << endl;
  
}
