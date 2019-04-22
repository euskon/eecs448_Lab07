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
  printTestResults(test4());
  printTestResults(test5());
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
  // if(m_listPtr->isEmpty() == false)
  //working here see if isEmpty failed
  //or addFront failed to add
  return(false);
}
bool Test::test4()
{
  if(m_listPtr != nullptr)
  {
    delete m_listPtr;
    m_listPtr = new LinkedListOfInts();
  }
  printTestHeader();
  cout << "\t\ttesting: size() on empty list\n";
  vector<int> listInVector(m_listPtr->toVector());
  if(m_listPtr->size() == 0 && listInVector.size() == 0)
  {
    cout << "\t\tlist.size() == vector.size() == 0, True, size works on empty list\n";
    cout << "\t\tExpected: size() == 0, True\n";
    return(true);
  }
  cout << "\t\tlist.size() != 0, size fails on empty list\n";
  cout << "\t\tExpected: size() == 0\n";
  return(false);
}
bool Test::test5()
{
  bool testResult = true;
  printTestHeader();
  cout << "\t\ttesting: size() on non-empty list\n";
  if(m_listPtr != nullptr)
  {
    delete m_listPtr;
    m_listPtr = new LinkedListOfInts();
  }
  for(int i=0;i<3;i++)
  {
    cout << "\t\tcase: list of length " << i+1 << "\n";
    m_listPtr->addFront(i+10);
    vector<int> listInVector(m_listPtr->toVector());
    if((m_listPtr->size() == i+1) && (listInVector.size() == i+1))
    {
      cout << "\t\tlist.size() == vector.size() == " << i+1 << "\n";
      cout << "\t\tExpected: size() == " << i+1 << "\n";
      cout << "\t\tcase: Passed\n\n";
      testResult = testResult && true;
    }
    else
    {
      cout << "\t\tlist.size() != " << i+1 << "\n";
      cout << "\t\tExpected: size() == " << i+1 << "\n";
      cout << "\t\tcase: FAILED\n\n";
      testResult = false;
    }
  }
  return(testResult);
}
