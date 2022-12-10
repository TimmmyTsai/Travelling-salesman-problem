//Ting-Yu Tsai
//301456611
//tta80
#include "tspsolver.hpp"

TSPSolver::TSPSolver(ListOfPoints &list) {
m_list = list;
}

void TSPSolver::solve() {
  
  for (int i=0; i<3 ;i++){
    //for loop to add 3 points to solution
    m_solution.addPoint(m_list.getPointAt(i));
  }
  //create variables
  int end = 3;
  float t_dis; 
  float L_dis;
  string name;
  float min;
  float Dis1;
  float Dis2;
  float Dis3;

  //If the size of the m_list is greater than 3
  if (m_list.getSize()>end){

  for (int j = 3; j < m_list.getSize(); j++){
    //set a min value and reset it everytime when the j increases
    min = 1000000;
    //second to last
    for (int i=0; i<end-1; i++){
      Dis1 = (m_solution.getPointAt(i)).getDistance((m_list.getPointAt(j)));
      Dis2 = (m_list.getPointAt(j)).getDistance((m_solution.getPointAt(i+1)));
      Dis3 = (m_solution.getPointAt(i)).getDistance((m_solution.getPointAt(i+1)));  
      t_dis = Dis1 + Dis2 - Dis3; 

        //if tmp < min
        if (t_dis <= min){
        min = t_dis;        
        name = (m_solution.getPointAt(i)).getName();
        } 
    } //outside of Inner For Loop

      // the last case 
      Dis1 = (m_solution.getPointAt(j-1)).getDistance((m_list.getPointAt(j)));
      Dis2 = (m_solution.getPointAt(0)).getDistance((m_list.getPointAt(j)));
      Dis3 = (m_solution.getPointAt(j-1)).getDistance((m_solution.getPointAt(0)));
      L_dis = Dis1 + Dis2 - Dis3; 
        if (L_dis <= min){
          min = L_dis; 
          name = (m_solution.getPointAt(j-1)).getName(); 
          }
    //Add j to solution list 
    m_solution.addAfter(m_list.getPointAt(j),name);
    //stop increases as j increases
    end++; 
  }
 }
}

TSPCycle& TSPSolver::getSolution() {

  return m_solution;
}