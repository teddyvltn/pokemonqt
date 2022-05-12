#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QTime>
#include <QApplication>

using namespace std;

class Player;

#ifndef UTILS_H
#define UTILS_H

// ** parseLine ** <- *file
// Parse current string with "," parser, and return a vector
vector<string> parseLine(string file);

// ** extract_fileData ** <- string
// Extract all the date from a file named fileName
// Store it in a vector[]
//
// txt files must respect a certain format as so:
//  - first line must be the keys
//  - and the rest is data
//
// Example:
// id,name,hp,attack,defense,speed
// 1,Bulbasaur,60,60,60,60
// ...
const vector<map<string, string>> extract_fileData(string fileName);

void save_data(Player* aPlayer);

// ** print_data **
void print_data(vector<map<string, string>> aData);

void delay(int ms);

#endif // UTILS_H

