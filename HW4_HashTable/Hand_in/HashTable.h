#include <iostream>
#include <string>

#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Data{
  string key = "";
  string gender = "";
  int height = 0;
  int weight = 0;
  Data *next = NULL;
  Data();
  Data(string, string, int, int);

  /*function*/
  string getGender(){return gender;}
  int getHeight(){return height;}
  int getWeight(){return weight;}
};

class HashTable{
public:
  // Construct and Destruct
  HashTable();
  ~HashTable();

public:
  // function
  bool addItem(string, string, int, int);

  // operator
  Data &operator[](string);
  Data operator[](const string) const;


private:
  static const int MaxSize = 9997;
  int hash(const string) const;
  Data *table[MaxSize];
};

#endif
