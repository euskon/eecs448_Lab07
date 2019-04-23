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
  printTestResults(test6());
  printTestResults(test7());
  printTestResults(test8());
  printTestResults(test9());
  printTestResults(test10());
  printTestResults(test11());
  printTestResults(test12());
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
void Test::resetTestList()
{
  if(m_listPtr != nullptr)
  {
    delete m_listPtr;
    m_listPtr = new LinkedListOfInts();
  }
}
void Test::printVect(vector<int> const& vect)
{
  for(int i = 0; i < vect.size(); i++)
  {
    cout << "index " << i << ":" << vect.at(i) << "\n";
  }
}
bool Test::test1()
{
  printTestHeader();
  cout << "\t\ttesting: LinkedListOfInts() constructor\n";
  //execute function to be tested
  m_listPtr = new LinkedListOfInts();
  //check result and output
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
  //execute function to be tested &&
  //check result and output
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
  //execute function to be tested &&
  //check result and output
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
  printTestHeader();
  resetTestList();
  cout << "\t\ttesting: size() on empty list\n";
  vector<int> listInVector(m_listPtr->toVector());
  //execute function to be tested &&
  //check result and output
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
  resetTestList();
  cout << "\t\ttesting: size() on non-empty list\n";  
  for(int i=0;i<3;i++)
  {
    cout << "\t\tcase: list of length " << i+1 << "\n";
    m_listPtr->addFront(i+10);
    vector<int> listInVector(m_listPtr->toVector());
    //execute function to be tested &&
    //check result and output
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
bool Test::test6()
{
  printTestHeader();
  resetTestList();
  cout << "\t\ttesting: addFront(5) on empty list\n";
  //execute function to be tested
  m_listPtr->addFront(5);
  vector<int> listInVector(m_listPtr->toVector());
  //check result and output
  if(listInVector.size() == 1 && listInVector.at(0) == 5)
  {
    cout << "\t\t[ list.size() == 1 && vect.at(0) == 5 ] == true\n";
    cout << "\t\tExpected: true\n";
    return(true);
  }
  cout << "\t\t[ list.size() == 1 && vect.at(0) == 5 ] == false\n";
  cout << "\t\tExpected: true\n";
  return(false);
}
bool Test::test7()
{
  printTestHeader();
  resetTestList();
  cout << "\t\ttesting: addFront(23) on non-empty list\n";
  //execute function to be tested
  m_listPtr->addFront(5);
  m_listPtr->addFront(23);
  vector<int> listInVector(m_listPtr->toVector());
  //check result and output
  if(listInVector.size() == 2 && listInVector.at(0) == 23)
  {
    cout << "\t\t[ list.size() == 2 && vect.at(0) == 23 ] == true\n";
    cout << "\t\tExpected: true\n";
    return(true);
  }
  else
  {
    //extra specific feedback
    if(listInVector.size() < 2)
    {
      cout << "\t\t value(s) not added to list\n";
    }
    if(listInVector.at(0) != 23)
    {
      cout << "\t\tIncorrect value at list position zero\n";
      cout << "\t\tGiven: " << listInVector.at(0) << "\n";
      cout << "\t\tExpected: 23\n";
    }
    return(false);
  }
}
bool Test::test8()
{
  printTestHeader();
  resetTestList();
  cout << "\t\ttesting: addBack(15) on empty list\n";
  //execute function to be tested
  m_listPtr->addBack(15);
  vector<int> listInVector(m_listPtr->toVector());
  //check result and output
  if(listInVector.size() == 1 && listInVector.at(0) == 15)
  {
    cout << "\t\t[ list.size() == 1 && vect.at(0) == 15 ] == true\n";
    cout << "\t\tExpected: true\n";
    return(true);
  }
  cout << "\t\t[ list.size() == 1 && vect.at(0) == 15 ] == false\n";
  cout << "\t\tExpected: true\n";
  return(false);
}
bool Test::test9()
{
  printTestHeader();
  resetTestList();
  cout << "\t\ttesting: addBack(33) on non-empty list\n";
  //execute function to be tested
  m_listPtr->addBack(15);
  m_listPtr->addBack(33);
  vector<int> listInVector(m_listPtr->toVector());
  //check result and output
  if(listInVector.size() == 2 && listInVector.at(listInVector.size() - 1) == 33)
  {
    cout << "\t\t[ list.size() == 2 && vect.at(listInVector.size() - 1) == 33 ] == true\n";
    cout << "\t\tExpected: true\n";
    return(true);
  }
  else
  {
    //extra specific feedback
    if(listInVector.size() < 2)
    {
      cout << "\t\t value(s) not added to list\n";
    }
    if(listInVector.at(listInVector.size() - 1) != 33)
    {
      cout << "\t\tSpecial: bug detected Incorrect value at list position (size - 1)\n";
      cout << "\t\tGiven: " << listInVector.at(listInVector.size() - 1) << "\n";
      cout << "\t\tExpected: 33\n";
    }
    return(false);
  }
}
bool Test::test10()
{
  printTestHeader();
  resetTestList();
  cout << "\t\ttesting: addBack() on list of size 3\n";
  m_listPtr->addBack(7);
  m_listPtr->addBack(14);
  m_listPtr->addBack(21);
  m_listPtr->addBack(28);
  vector<int> listInVector(m_listPtr->toVector());
  if((listInVector.size() == 4) && (listInVector.at(listInVector.size() - 1) == 28))
  {
    cout << "\t\t[ list.size() == 4 && vect.at(vect.size() - 1) == 28 ] == true\n";
    cout << "\t\tExpected: true\n";
    return(true);
  }
  else
  {
    cout << "\t\t vect.at(vect.size() - 1) != 28\n";
    cout << "\t\tExpected: last element to equal 28\n";
    //extra specific feedback
    if(listInVector.at(0) == 28)
    {
      cout << "\t\tSpecial: bug detected vect.at(0) == 28\n";
      cout << "\t\taddBack() caught addFront()-ing\n";
    }
    return(false);
  }
}
bool Test::test11()
{
  bool funcBoolResult = false;
  printTestHeader();
  resetTestList();
  cout << "\t\ttesting: removeFront() on list of size 4\n";
  m_listPtr->addFront(7);
  m_listPtr->addFront(14);
  m_listPtr->addFront(21);
  m_listPtr->addFront(28);
  vector<int> listInVector(m_listPtr->toVector());
  cout << "\t\tbefore:\n";
  printVect(listInVector);
  //execute function to be tested
  funcBoolResult = m_listPtr->removeFront();
  listInVector = m_listPtr->toVector();
  cout << "\t\tafter:\n";
  printVect(listInVector);
  //check result and output
  //extra specific feedback
  if(funcBoolResult && (listInVector.size() == 3) && (listInVector.at(0) == 21)) 
  {
    cout << "\t\tremoveFront() returned true\n";
    cout << "\t\tvect.size() == 3 && vect.at(0) == 21\n";
    cout << "\t\tExpected: size == 3 and front == 21\n";
    return(true);
  }
  //extra specific feedback
  else if(funcBoolResult && (listInVector.size() == 4) && (listInVector.at(0) == 21))
  {
    cout << "\t\tremoveFront() returned true\n";
    cout << "\t\tvect.size() == 4\n";
    cout << "\t\tExpected: size == 3 and front == 21\n";
    cout << "\t\tsize failed to decrement but remove worked\n";
  }
  //extra specific feedback
  else if((funcBoolResult == false) && (listInVector.size() != 3 ) && (listInVector.at(0) != 21))
  {
    cout << "\t\tremoveFront() returned false\n";
    cout << "\t\tvect.size() != 3 && vect.at(0) != 21\n";
    cout << "\t\tExpected: size == 3 and front == 21\n";
  }
  else
  {
    cout << "\t\tfurther testing required\n";
  }
  return(false);
}
bool Test::test12()
{
  bool funcBoolResult = false;
  printTestHeader();
  resetTestList();
  cout << "\t\ttesting: removeBack() on list of size 4\n";
  m_listPtr->addFront(7);
  m_listPtr->addFront(14);
  m_listPtr->addFront(21);
  m_listPtr->addFront(28);
  vector<int> listInVector(m_listPtr->toVector());
  cout << "\t\tbefore:\n";
  printVect(listInVector);
  //execute function to be tested
  funcBoolResult = m_listPtr->removeBack();
  listInVector = m_listPtr->toVector();
  cout << "\t\tafter:\n";
  printVect(listInVector);
  //check result and output
  //extra specific feedback
  if(funcBoolResult && (listInVector.size() == 3) && (listInVector.at(2) == 14)) 
  {
    cout << "\t\tremoveBack() returned true\n";
    cout << "\t\tvect.size() == 3 && vect.at(2) == 14\n";
    cout << "\t\tExpected: size == 3 and front == 14\n";
    return(true);
  }
  //extra specific feedback
  else if(funcBoolResult && (listInVector.size() == 4) && (listInVector.at(2) == 14))
  {
    cout << "\t\tremoveBack() returned true\n";
    cout << "\t\tvect.size() == 4\n";
    cout << "\t\tExpected: size == 3 and front == 21\n";
    cout << "\t\tsize failed to decrement but remove worked\n";
  }
  //extra specific feedback
  else if((funcBoolResult == false) && (listInVector.size() != 3 ) && (listInVector.at(2) != 14))
  {
    cout << "\t\tremoveBack() returned false\n";
    cout << "\t\tvect.size() != 3 && vect.at(0) != 21\n";
    cout << "\t\tExpected: size == 3 and front == 21\n";
    cout << "\t\tsize failed to decrement and remove failed\n";
  }
  else
  {
    cout << "\t\tfurther testing required\n";
  }
  return(false);
}
