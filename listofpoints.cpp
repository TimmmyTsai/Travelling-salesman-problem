//Ting-Yu Tsai
//301456611
//tta80
#include "listofpoints.hpp"


ListOfPoints::ListOfPoints() {
 vector<Point> m_points;
}

void ListOfPoints::addAfter(Point& newPt, string name) {
  for (long unsigned int i=0; i< m_points.size(); i++){  
    if (m_points[i].getName() == name){
      
      m_points.insert((m_points.begin()+i+1),newPt);
    }
  }
}

void ListOfPoints::addPoint(Point& newPt)  {
  m_points.push_back(newPt);
}

Point& ListOfPoints::getPointAt(unsigned int i) {
  return m_points[i];
}

int ListOfPoints::getSize() const {
  int len = m_points.size();
  return len;
}

void ListOfPoints::printList() const {
  for (long unsigned int i = 0; i < m_points.size(); i++){
    cout << "the point is " << m_points[i] << endl;
  }
}

void ListOfPoints::draw() const {
//initializing the map with 2D array
  string mappoints[21][21];
  
  for (long unsigned int i = 0; i < 21; i++){
    for (long unsigned int j = 0; j < 21; j++){
      mappoints[i][j] = '-';
    }
  }

  for (long unsigned int i = 0; i < m_points.size(); i++){
    // info of points
    int x = m_points[i].getX();
    int y = m_points[i].getY();
    mappoints[20-y][x] = m_points[i].getName();
  }
  
// printing the map out
  for (long unsigned int i = 0; i < 21; i++){
    for (long unsigned int j = 0; j < 21; j++){
      if (j == 20){
        cout << mappoints[i][j] << endl;
      }
      else{
        cout << mappoints[i][j];
      }
    }
  }  
}