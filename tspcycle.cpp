//Ting-Yu Tsai
//301456611
//tta80
#include <iostream>

#include "tspcycle.hpp"

TSPCycle::TSPCycle() {
  //ignore for now 
 cout << "default TSPCycle constructor" << endl;
}

// returns the distance of the cycle
float TSPCycle::getLength() const {
  float dis = 0;
  int j= 0;
  int len = m_points.size();
  for (int i=0;i<(len-1);i++){
    dis += m_points[i].getDistance(m_points[i+1]);
  }
  dis += m_points[j].getDistance(m_points[len-1]);
  
  return dis;
}
