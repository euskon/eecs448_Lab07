#ifndef TEST_H
#define TEST_H
#include "LinkedListOfInts.h"
#include <vector>
#include <iostream>
using namespace std;
class Test
{
private:
  LinkedListOfInts* m_listPtr;
  int testCount;
  const int NUM_OF_TESTS;

public:
  /** @pre None.
  *   @post Test object created and m_listPtr = nullptr.
  *   [note] constructor which should init list to nullptr
  */
  Test();
  /** @pre Test object in scope.
  *   @post Test object deleted and dependents destroyed.
  *   [note] delete list and clean up anything else.
  */
  ~Test();
  /** @pre valid list must exist m_listPtr
  *   @post returns the result of testing
  *   [note] feedback from tests and outputting them in
  *   some degree of detail.
  */
  void execute();
  void printTestHeader();
  void printTestResults(bool result);
  void resetTestList();
  void printVect(vector<int> const& vect);

  /** TESTS --------------------------------------
  * Testing suite for a linked list of integers
  * Legit
  * ----------------------------------------------
  */

  /**
    [note] Attempt to validate that m_front is pointing to nullptr
    using the isEmpty() func. Expect isEmpty() return TRUE.
    [note] Attempt to validate that size of list is set to 0 by constructor.

    validate: constructor created a LL that is empty & length == 0.
    given: empty list
    expect: True */
  bool test1();

  /*
    validate: isEmpty()
    trusting: toVector(int v)
    given: empty list
    expect: True */
  bool test2();

  /*
    validate: isEmpty()
    trusting: addFront(int value)
    given: non-empty list
    expect: False */
  bool test3();

  /*
    validate: size()
    trusting: toVector();
    given: empty list
    expect: list.size() == 0 */
  bool test4();

  /*
    validate: size()
    trusting: toVector(), addFront();
    given: list of length 1, 2, and 3.
    expect: list.size() == 1, 2, 3, respectively */
  bool test5();

  /*
    validate: addFront(int value);
    trusting: toVector(), vect.at();
    given: empty list
    expect: [ list.size() == 1 && vect.at(0) == 5 ] == true */
  bool test6();

  /*
    validate: addFront(int value);
    trusting: toVector(), vect.at();
    given: non-empty list
    expect: [ list.size() == 2 && vect.at(0) == 23 ] == true */
  bool test7();

  /*
    validate: addBack(int value);
    trusting: toVector(), vect.size(), vect.at();
    given: empty list
    expect: [ list.size() == 1 && vect.at(vect.size() - 1) == 15 ] == true */
  bool test8();

  /*
    validate: addBack(int value);
    trusting: toVector(), vect.size(), vect.at();
    given: non-empty list
    expect: [ list.size() == 2 && vect.at(vect.size() - 1) == 33 ] == true */
  bool test9();

  /*
    validate: addBack(int value);
    trusting: toVector(), vect.size(), vect.at();
    given: list of size 3 use addBack(28) 
            and check the front with vect.at(0)
    expect: size = 4 && v[3] == 28 */
  bool test10();
  /*
    validate: removeFront();
    trusting: toVector(), vect.size(), vect.at();
    given: list of size 4
    expect: [ vect.size() == 3 && vect.at(0) == 33 ] == true */
    //temp = front;
    //front = front.next();
    //delete temp;
  bool test11();
  /*
    validate: removeBack();
    trusting: toVector(), vect.size(), vect.at();
    given: list of size 4
    expect: [ vect.size() == 3 && vect.at(2) == 14 ] == true */
  bool test12();

};
#endif
