#include "matrix33.h"
#include <iostream>
#include <iomanip>

using std::cerr;
using std::cout;
using std::endl;
using std::fixed;
using std::setw;

matrix33::matrix33(){
  vector3 init(0, 0, 0);
  set(init, init, init);
}

matrix33::matrix33(const matrix33 &ma){
  set(ma.vec[0], ma.vec[1], ma.vec[2]);
 }

matrix33::matrix33(const vector3 &v1, const vector3 &v2, const vector3 &v3){
  set(v1, v2, v3);
}

matrix33::~matrix33(){}

/*------------------------------FUNCTION------------------------------*/

// transpose the matrix
matrix33 matrix33::transpose(){
  matrix33 tmp;
  for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
      tmp[i][j] = (*this)[j][i];

  return tmp;
}

// make adjugate matrix
matrix33 matrix33::adjugate(){
  matrix33 ma2;
  for(int i=0; i<3; i++)
    for(int j=0; j<3; j++){
      ma2[i][j] = ((*this)[(i+1)%3][(j+1)%3] * (*this)[(i+2)%3][(j+2)%3] -
                  (*this)[(i+1)%3][(j+2)%3] * (*this)[(i+2)%3][(j+1)%3]);
    }
  return ma2.transpose();
}

matrix33 matrix33::invert(){
  matrix33 tmp = (*this).adjugate();
  if((*this).determinant() == 0){
    cerr << "The matrix cannot invert" << endl;
    exit(1);
  }
  else{
    tmp /= (*this).determinant();
    return tmp;
  }
}

void matrix33::identity(){
  vector3 v1(1,0,0);
  vector3 v2(0,1,0);
  vector3 v3(0,0,1);
  set(v1, v2, v3);
}

void matrix33::set(vector3 v1, vector3 v2, vector3 v3){
  vec[0] = v1;
  vec[1] = v2;
  vec[2] = v3;
}

void matrix33::printMatrix(){
  cout << setw(3) << vec[0].x << " " << setw(3) << vec[1].x
                              << " " << setw(3) << vec[2].x << endl
       << setw(3) << vec[0].y << " " << setw(3) << vec[1].y
                              << " " << setw(3) << vec[2].y << endl
       << setw(3) << vec[0].z << " " << setw(3) << vec[1].z
                              << " " << setw(3) << vec[2].z << endl;
}


/*------------------------------OPERATORS------------------------------*/


vector3 &matrix33::operator[](unsigned int index){
  if(index >= 3 || index < 0){
    cerr << "\nError: index " << index
    << " out of range" << endl;
    exit(1); // terminate program; index out of range
  }
  if(index == 0)  return vec[0];
  if(index == 1)  return vec[1];
  if(index == 2)  return vec[2];
}

const vector3 &matrix33::operator[](unsigned int index) const{
  if(index >= 3 || index < 0){
    cerr << "\nError: index " << index
    << " out of range" << endl;
    exit(1); // terminate program; index out of range
  }
  if(index == 0)  return vec[0];
  if(index == 1)  return vec[1];
  if(index == 2)  return vec[2];
}

matrix33 &matrix33::operator=(const matrix33 &ma){
  if(*this == ma)
    return *this;
  else{
    *this = ma;
    return *this;
  }
}

matrix33 &matrix33::operator*=(float f){
  for(int i=0; i<3; i++)
    vec[i] *= f;
  return *this;
}

matrix33 &matrix33::operator/=(float f){
  for(int i=0; i<3; i++)
    vec[i] /= f;
  return *this;
}

matrix33 operator+(const matrix33 &ma1, const matrix33 &ma2){
  matrix33 tmp;
  for(int i=0; i<3; i++)
      tmp[i] = ma1[i] + ma2[i];
  return tmp;
}

matrix33 operator*(const matrix33 &ma, float f){
  matrix33 tmp;
  for(int i=0; i<3; i++)
    tmp[i] = ma[i] * f;
  return tmp;
}

matrix33 operator*(const matrix33 &ma1, const matrix33 &ma2){
  matrix33 tmp;
  for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    tmp[j][i] = ma1[0][i]*ma2[j][0] +
                ma1[1][i]*ma2[j][1] +
                ma1[2][i]*ma2[j][2];
  return tmp;
}

matrix33 operator/(const matrix33 &ma, float f){
  matrix33 tmp;
  for(int i=0; i<3; i++)
    tmp[i] = ma[i] / f;
  return tmp;
}

bool operator==(const matrix33 &ma1, const matrix33 &ma2){
  if(ma1[0] != ma2[0])  return false;
  if(ma1[1] != ma2[1])  return false;
  if(ma1[2] != ma2[2])  return false;

  return true;
}

bool operator!=(const matrix33 &ma1, const matrix33 &ma2){
  return !(ma1==ma2);
}

/*------------------------------VARIABLE------------------------------*/

float matrix33::determinant(){
  float det=0;
  for(int i=0; i<3; i++){
    det += (*this)[0][i] * (*this)[1][(i+1)%3] * (*this)[2][(i+2)%3];
    det -= (*this)[0][i] * (*this)[1][(i+2)%3] * (*this)[2][(i+1)%3];
  }
  return det;
}
