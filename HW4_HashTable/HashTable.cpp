#include <iostream>
#include <string>
#include "HashTable.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::cerr;

/*------------------- Data -------------------*/
Data::Data():key(""), gender(""), height(0), weight(0){;}

Data::Data(string k, string gd, int h, int w){
  key = k;
  gender = gd;
  height = h;
  weight = w;
}

/*---------- Construct and Destruct ----------*/

HashTable::HashTable(){
  for(int i=0; i<MaxSize; i++)
    table[i] = new Data;  // might have problem
}

HashTable::~HashTable(){
  // for(int i=0; i<MaxSize; i++)
  //   delete table[i];
}

/*----------------- function -----------------*/

bool HashTable::addItem(string k, string gd, int h, int w){
  try{
    int idx = hash(k);
    Data *curData = table[idx];
    Data *newData = new Data(k, gd, h, w);
    if(curData == NULL)
      curData = newData;
    else{
      while(curData->next != NULL){
        curData = curData->next;
      }
      curData->next = newData;
    }
  }
  catch(...){
    cerr << "error setting" << endl;
    return false;
  }
}

Data HashTable::operator[](const string k) const{
  try{
    int idx = hash(k);
    Data *curData = table[idx];
    while(curData->key != k){
      if(curData == NULL)
        throw;
      curData = curData->next;
    }
    return *curData;
  }
  catch(...){
    cerr << "error finding the data" << endl;
    exit(0);
  }
}

Data &HashTable::operator[](string k){
  try{
    int idx = hash(k);
    Data *curData = table[idx];
    while(curData->key != k){
      if(curData == NULL)
      throw;
      curData = curData->next;
    }
    return *curData;
  }
  catch(...){
    cerr << "error finding the data" << endl;
    exit(0);
  }

}

int HashTable::hash(const string s) const{
  int seed = 97;
  unsigned int idx = 0;

  for(int i=0; i<s.size(); i++){
    idx = (idx * seed) + s[i];
  }

  return idx%MaxSize;
}
