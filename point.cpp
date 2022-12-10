//Ting-Yu Tsai
//301456611
//tta80
#include "point.hpp"
#include <cmath>

float Point::getDistance(const Point &other) const { 
  float value_x;
  float value_y;
  float ans;
  //Get the x and y values 
  value_x = abs((m_x) - (other.m_x));
  value_y = abs((m_y) - (other.m_y));
  //calculate
  ans = sqrt((value_x)*(value_x) + (value_y)*(value_y));
  
  return ans;
}

string Point::toString() const {
  // examples how to create string from small parts
  string str(m_name);
  str += " = (";
  str += std::to_string(m_x);
  str.append(",").append(std::to_string(m_y)).append(")");
  return str;
}


void Point::printPoint() const {
  cout << toString() << endl;
}

// used for printing Point using << operator.
// For example, the following code will work
// Point origin(0,0,'O');
// cout << origin;
ostream& operator<<(ostream &os, const Point &p) {
  return os << p.toString();
}
