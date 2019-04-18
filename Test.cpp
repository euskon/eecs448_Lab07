#include "Test.h"
Test::Test():NUM_OF_TESTS(20)
{
  m_listPtr = nullptr;
  testCount = 0;
}
Test::~Test()
{
  delete m_listPtr;
}
void Test::execute()
{
  printTestResults(test1());
  printTestResults(test2());
}
void Test::printTestHeader()
{
  testCount++;
  cout << "\tTEST#" << testCount << '\n';
}
void Test::printTestResults(bool result)
{
  if(result)
  {
    cout << "\tPASSED\n";
  }
  else
  {
    cout << "FAILED: check test specific results above.\n";
  }
}
bool Test::test1()
{
  printTestHeader();
  m_listPtr = new LinkedListOfInts();
  if((m_listPtr != nullptr) && m_listPtr->isEmpty() && (m_listPtr->size() == 0))
  {
    cout << "isEmpty() => True, List is correctly set to nullptr\n";
    cout << "size() => True, List has size of 0\n";
    return(true);
  }
  else
  {
    cout << "isEmpty()||size() => False, List constuctor failed.\n";
    return(false);
  }
}
bool Test::test2()
{
  printTestHeader();
  if(m_listPtr.isEmpty())
  {
    return(true);
  }
  return(false);
}
