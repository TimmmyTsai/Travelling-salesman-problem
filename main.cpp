//Ting-Yu Tsai
//301456611
//tta80
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "point.hpp"
#include "listofpoints.hpp"
#include "tspsolver.hpp"
#include "tspcycle.hpp"

using namespace std;

//testSolver Function
void testSolver(ListOfPoints &input) {
  cout << "---run the solver---" << endl;

  TSPSolver solver(input);
  solver.solve();
  TSPCycle solution = solver.getSolution();
  cout << "Solution found is: " << endl;
  solution.printList();
  cout << "the length of the solution is: " << solution.getLength() << endl;
}

// All test cases BELOW
//1.test cases for cycle
void testCycle(){
  Point p_a(0, 0, "A");
  Point p_b(0, 3, "B");
  Point p_c(3, 3, "C");
  Point p_d(3, 0, "D");

  TSPCycle testcycle;
  testcycle.addPoint(p_a);
  testcycle.addPoint(p_c);
  testcycle.addAfter(p_b, "A");
  testcycle.addAfter(p_d, "C");

  testcycle.printList();
  cout <<"The length is "<< testcycle.getLength() << endl;
  testcycle.draw();
}
//2.test Point
void testPoint() {
  Point origin(0,0,"ORIGIN");
  cout << "--print using printPoint():" << endl;
  origin.printPoint();
  cout << "--print using toString():" << endl;
  cout << origin.toString() << endl;
  cout << "--print using << operator:" << endl;
  cout << origin << endl;
  
  Point q(3,4,"Q");
  //distance should be 5
  cout << "distance between ORIGIN and Q is " << q.getDistance(origin) << endl;

}
//3.test for printafter
void test1() {
//can try deleting the fourth point and change p[3] and for loop i<4
  Point p[4] = {Point(2,2,"A"),
                Point(2,6,"B"),
                Point(5,6,"C"),
                Point(5,9,"D")};
      cout << "Creating a list of points:" << endl;
      ListOfPoints inputTSP;
      for (int i=0;i<4;i++)
      inputTSP.addPoint(p[i]);        
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}
//4.test
void test2() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<10;i++) {
    string s;
    s = 'A'+i;
    p = Point(i,0,s);
    inputTSP.addPoint(p);
  }
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}
//5.test
void test3() {
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<50;i++) {
    p = Point(rand() % 1000, rand() % 1000,"P"+to_string(i));
    inputTSP.addPoint(p);
  }
  // some coordinates values more than 20, so we do not use draw here

  testSolver(inputTSP);
}
//6.test
void test6() {
  ListOfPoints inputTSP;
  Point p[11] = {
    Point(7, 1, "A"),
    Point(2, 1, "B"),
    Point(8, 5, "C"),
    Point(10, 3, "D"),
    Point(3, 1, "E"),
    Point(4, 3, "F"),
    Point(2, 4, "G"),
    Point(9, 4, "H"),
    Point(8, 8, "I"),
    Point(3, 2, "J"),
    Point(6, 9, "K")
  };
  for (int i = 0; i < 11; i++) inputTSP.addPoint(p[i]);
  cout << "Printing the list:" << endl;
  inputTSP.printList();
  inputTSP.draw();
  testSolver(inputTSP);
}
//7.test
void test9() {
  ListOfPoints inputTSP;
  Point p[7] = {
    Point(1, 1, "A"),
    Point(5, 1, "B"),
    Point(5, 5, "C"),
    Point(1, 5, "D"),
    Point(3, 3, "E"),    
    Point(7, 3, "F"),
    Point(3, 7, "G")
  };
  for (int i = 0; i < 7; i++) inputTSP.addPoint(p[i]);
  cout << "Printing the list:" << endl;
  inputTSP.printList();
  inputTSP.draw();
  testSolver(inputTSP);
}
//8.test
void test14() {
  ListOfPoints inputTSP;
  Point p[9] = {
    Point(3, 5, "L"),
    Point(4, 5, "U"),
    Point(5, 5, "V"),
    Point(7, 5, "Y"),
    Point(8, 5, "A"),
    Point(4, 4, "I"),
    Point(5, 4, "G"),
    Point(6, 4, "O"),
    Point(7, 4, "R")
  };
  for (int i = 0; i < 9; i++) inputTSP.addPoint(p[i]);
  cout << "Printing the list:" << endl;
  inputTSP.printList();
  inputTSP.draw();
  testSolver(inputTSP);
}


int main() {
  
  cout << "****Test point**" << endl;
  testPoint();
  cout << "****End of test point**" << endl << endl;
  
    cout << "****Test Cycle**" << endl;
  testCycle();
  cout << "****End of test Cycle**" << endl << endl;

  cout << "****test1**:" << endl; 
  test1(); 
  cout << "****end of test1**:" << endl << endl; 

  cout << "****test2**:" << endl;
  test2();
  cout << "****end of test2**:" << endl << endl;

  cout << "****test3**:" << endl;
  test3();
  cout << "****end of test3**:" << endl << endl;
  
  cout << "****test6**:" << endl;
  test6();
  cout << "****end of test6**:" << endl << endl;
  
  cout << "****test9**:" << endl;
  test9();
  cout << "****end of test9**:" << endl << endl;
  
  cout << "****test14**:" << endl;
  test14();
  cout << "****end of test14**:" << endl << endl;
  
  return 0;
}


 
