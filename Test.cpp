#include "Test.h"
Test::Test():NUM_OF_TESTS(20)
{
  m_listPtr = nullptr;
  testCount = 0;
}
Test::~Test()
{
  delete m_listPtr;
  m_listPtr = nullptr;
}
void Test::execute()
{
  printTestResults(test1());
  printTestResults(test2());
  printTestResults(test3());
}
void Test::printTestHeader()
{
  testCount++;
  cout << "\tTEST#" << testCount << "|*************************\n";
}
void Test::printTestResults(bool result)
{
  if(result)
  {
    cout << "\t     Passed\n";
  }
  else
  {
    cout << "\t     FAILED\n";
  }
}
bool Test::test1()
{
  printTestHeader();
  cout << "\t\ttesting: LinkedListOfInts() constructor\n";
  m_listPtr = new LinkedListOfInts();
  if((m_listPtr != nullptr) && m_listPtr->isEmpty() && (m_listPtr->size() == 0))
  {
    cout << "\t\tisEmpty() => true, List is correctly set to nullptr\n";
    cout <<"\t\tExpected: true\n";
    cout << "\t\tsize() => true, List has a size of 0\n";
    cout <<"\t\tExpected: true\n";
    return(true);
  }
  else
  {
    cout << "\t\tisEmpty() == false || size() != 0, List constuctor failed.\n";
    return(false);
  }
}
bool Test::test2()
{
  printTestHeader();
  cout << "\t\ttesting: isEmpty() on empty list\n";
  vector<int> listInVector(m_listPtr->toVector());
  if(m_listPtr->isEmpty() && listInVector.empty())
  {
    cout <<"\t\t[ list.isEmpty() && vector.empty() ] == true\n";
    cout <<"\t\tExpected: true\n";
    return(true);
  }
  return(false);
}
bool Test::test3()
{
  printTestHeader();
  cout << "\t\ttesting: isEmpty() on non-empty list\n";
  m_listPtr->addFront(17);
  vector<int> listInVector(m_listPtr->toVector());
  if(!(listInVector.empty()) && !(m_listPtr->isEmpty()))
  {
    cout << "\t\tGiven: list.size() > 1 \n";
    cout << "\t\tExpected: false\n";
    return(true);
  }
  cout <<"\t\t[ list.isEmpty() || vector.empty() ] == true\n";
  cout <<"\t\tExpected: false\n";
  return(false);
}
bool Test::test4()
{

}
