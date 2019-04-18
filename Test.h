#ifndef TEST_H
#define TEST_H
#include "LinkedListOfInts.h"
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

  /** TESTS --------------------------------------
  * Testing suite for a linked list of integers
  * Legit
  * ----------------------------------------------
  */

  /**
    [note] Attempt to validate that m_front is pointing to nullptr
    using the isEmpty() func. Expect isEmpty() return TRUE.
    [note] Attempt to validate that size of list is set to 0 by constructor.

    validate constructor created a LL that is empty & length == 0.
    given: empty list
    expect: True */
  bool test1();

  /*validate isEmpty()
    given: empty list
    expect: True */
  bool test2();

  /*validate isEmpty()
    given: non-empty list
    expect: False */
  bool test3();
};
#endif
