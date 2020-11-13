//
//  main.cpp
//  Vigenere Cipher
//
//  Created by Tomy Hsieh on 2020/10/5.
//  Copyright © 2020 Tomy Hsieh. All rights reserved.
//

#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

//const int VALID_FROM = 65;  // (A)
//const int VALID_TO = 90;   // (Z)
const int VALID_FROM = 32;  // (Space)
const int VALID_TO = 126;   // (~)
const int RANGE = VALID_TO - VALID_FROM + 1;

bool is_valid_input(string str) {
  return !any_of(str.begin(), str.end(), [](char c){ return int(c) < VALID_FROM || VALID_TO < int(c); });
}

int main(int argc, const char * argv[]) {
  
  // Init
  bool encrypt; // true/false for encrypt/decrypt
  string message, key;
  
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
  while (!is_valid_input(message)) {
    cout << "Invalid input!!!" << endl;
    cout << (encrypt ? "Message: " : "Encrypted Message: ");
    getline(cin, message, '\n');
  }
  
  // Prompt Key
  cout << "Key: ";
  getline(cin, key, '\n');
  while (!is_valid_input(key)) {
    cout << "Invalid input!!!" << endl;
    cout << "Key: ";
    getline(cin, key, '\n');
  }
  
  // Conversion
  cout << (encrypt ? "Encrypted Message: " : "Decrypted Message: ") << endl;
  string::iterator it_msg = message.begin();
  string::iterator it_key = key.begin();
  while (it_msg != message.end()) {
    
    // Convert to ASCII
    int ascii = *it_msg;
    int shift = int(*it_key) - VALID_FROM;
    
    // Shifting
    if (encrypt) {
      ascii += shift;
      if (VALID_TO < ascii) {
        ascii -= RANGE;
      }
    } else {
      ascii -= shift;
      if (ascii < VALID_FROM) {
        ascii += RANGE;
      }
    }
    cout << char(ascii);
    
    // Move Iterator
    ++it_msg;
    if (++it_key == key.end()) {
      it_key = key.begin();
    }
  }
  cout << endl;
  
}
