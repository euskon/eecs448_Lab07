#ifndef TEST_H
#define TEST_H
#include "LinkedListOfInts.h"
class Test
{
private:
  LinkedListOfInts* m_listPtr;

public:
  /** @pre None.
  *   @post Test object created and readied for execution.
  *   [note] constructor which should create a list to be used
  *   during the testing process.
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
  /** TESTS
  * Testing suite for a linked list of integers
  * Legit
  */
  /**
    [note] Attempt to validate that m_front is pointing to nullptr
    using the isEmpty() func. Expect isEmpty() return TRUE.
    [note] Attempt to validate that size of list is set to 0 by constructor.
  */
  bool test1();//validate constructor created a LL that is empty & length == 0.
  bool test2();//validate
};
#endif
