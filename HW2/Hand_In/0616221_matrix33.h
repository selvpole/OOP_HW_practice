#ifndef _MATRIX33_H_
#define _MATRIX33_H_
#include "vector3.h"

class matrix33:public vector3
{
public: // contructor
  matrix33(); // default constructor
  matrix33(const matrix33 &ma); // contruct with matrix
  matrix33(const vector3 &, const vector3 &, const vector3 &); // contruct with vector
  ~matrix33(); // destructor
public: // function
  matrix33 transpose();
  matrix33 adjugate();
  matrix33 invert();
  float determinant();
  void identity();
  void set(vector3, vector3, vector3);  // set column vector
  void printMatrix();
public: // operator for matrix and vector
  vector3 &operator[](unsigned int index);
  const vector3 &operator[](unsigned int index) const;

  matrix33 &operator=(const matrix33 &);
  matrix33 &operator*=(float);
  matrix33 &operator/=(float);
  friend matrix33 operator+(const matrix33 &, const matrix33 &);
  friend matrix33 operator*(const matrix33 &, float);
  friend matrix33 operator*(const matrix33 &, const matrix33 &);
  friend matrix33 operator/(const matrix33 &, float);
  friend bool operator==(const matrix33 &, const matrix33 &);
  friend bool operator!=(const matrix33 &, const matrix33 &);
  // print the matrix

private:  // private variable
  vector3 vec[3];
};

#endif
