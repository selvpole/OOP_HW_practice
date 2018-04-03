#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <math.h>
#include "vector3.h"

vector3::vector3(){}

// create a new vector(x,y,z)
vector3::vector3(float inX, float inY, float inZ){
  set(inX, inY, inZ);
}

// create a new vector clone by vec
vector3::vector3(const vector3 &v){
  set(v.x, v.y, v.z);
}

// for matrix
float &vector3::operator[](unsigned int index){
  if(index > 2 || index < 0){
    std::cerr << "\nError: Index " << index
     << " out of range" << std::endl;
    exit(1);
  }
  if(index == 0)
    return this->x;
  else if(index == 1)
    return this->y;
  else if(index == 2)
    return this->z;
}

// for matrix
const float &vector3::operator[](unsigned int index)const{
  if(index >= 3 || index < 0) {
    std::cerr << "\nError: Index " << index
     << " out of range" << std::endl;
    exit(1);
  }
  if(index == 0)
    return this->x;
  else if(index == 1)
    return this->y;
  else if(index == 2)
    return this->z;
}

// operator=
vector3 &vector3::operator=(const vector3 &v){
  x = v.x;
  y = v.y;
  z = v.z;

  return *this;
}

// operator+=
vector3 &vector3::operator+=(const vector3 &v){
  x += v.x;
  y += v.y;
  z += v.z;
  return *this;
}

// operator-=
vector3 &vector3::operator-=(const vector3 &v){
  x -= v.x;
  y -= v.y;
  z -= v.z;
  return *this;
}

// operator*=
vector3 &vector3::operator*=(float f){
  this->x *= f;
  this->y *= f;
  this->z *= f;
  return *this;
}

// operator/=
vector3 &vector3::operator/=(float f){
  this->x /= f;
  this->y /= f;
  this->z /= f;
  return *this;
}

bool operator==(const vector3 &a, const vector3 &b)
{
  if(a.x != b.x) return false;
  if(a.y != b.y) return false;
  if(a.z != b.z) return false;
  else  return true;
}

bool operator!=(const vector3 &a, const vector3 &b)
{
  return !(a==b);
}

vector3 operator-(const vector3 &a){
  return vector3(a.x * -1, a.y * -1, a.z * -1);
}

vector3 operator+(const vector3 &a, const vector3 &b){
  return vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

vector3 operator-(const vector3 &a, const vector3 &b){
  return vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

vector3 operator*(const vector3 &a, float f){
  return vector3(a.x * f, a.y * f, a.z * f);
}

vector3 operator*(float f, const vector3 &v){
  return vector3(f * v.x, f * v.y, f * v.z);
}

vector3 operator/(const vector3 &v, float f){
  return vector3(v.x / f, v.y / f, v.z / f);
}

void vector3::set(float xIn, float yIn, float zIn){
  x = xIn;
  y = yIn;
  z = zIn;
}

float vector3::length() const{
  float len = sqrt(pow(this->x,2)+pow(this->y,2)+pow(this->z,2));
  return len;
}

void vector3::printVector3() const{
  std::cout << "(" << this->x << ", " << this->y << ", " << this->z
   << ")" << std::endl;
}
