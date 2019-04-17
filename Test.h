#ifndef TEST_H
#define TEST_H
#include "LinkedListOfInts.h"
class Test
{
private:
  LinkedListOfInts* m_listPtr;

public:
  Test();
  ~Test();
  void execute();
};
#endif
