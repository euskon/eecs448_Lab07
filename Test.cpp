#include "Test.h"
Test::Test()
{
  m_listPtr = new LinkedListOfInts();
}
Test::~Test()
{
  delete m_listPtr;
}
void Test::execute()
{

}
