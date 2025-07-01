/*
 */

#include "main.hpp"
#include "unit_test_Task4.hpp"
string TEST_CASE = "Task4";
int main(int argc, char *argv[])
{
  cout << "-------------------------------------------------------------"
       << endl;
  cout << GREEN << BOLD << TEST_CASE << " - KTLT2 - HK242 " << endl;
  cout << CYAN << BOLD << "" << endl
       << endl;
  if (argc < 1)
  {
    printTestCase();
    return 1;
  }

  handleTestUnit(argc, argv);
  cout << "-------------------------------------------------------------"
       << endl;
}

void handleTestUnit(int argc, char *argv[])
{
  UNIT_TEST_Task4 unitTest;

  if (argc == 1 || (argc == 2 && std::string(argv[1]) == "all"))
  {
    std::cout << GREEN << BOLD << "Running unit_test/unit_test_" << TEST_CASE << RESET << "\n";
    unitTest.runAllTests();
  }
  else if (argc == 2)
  {
    std::cout << GREEN << BOLD << "Running unit_test/unit_test_" << TEST_CASE << RESET << "\n";
    unitTest.runTest(argv[1]);
  }
  else
  {
    printTestCase();
  }
}
