/**
 * Start of a driver file to test orgtree.cpp
 * CS 210 Fall 2022
 * @author Mitchell Shapiro <mshapiro6805@sdsu.edu>
 * @date Oct 2022
 */

#include "orgtree.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * THIS DRIVER FILE IS ONLY A START!
 * IT IS CRITICAL THAT YOU ADD YOUR
 * OWN TEST CASES. MOST CASES ARE
 * HIDDEN ON GRADESCOPE.
 */

/**
 * Print whether the given test case passed or failed
 * @param didPass - The test condition (true to pass, false to fail)
 * @param message - Description of what is being tested
 */
void assert(bool didPass, string message) {
    if (didPass) {
        cout << "Passed: " << message << endl;
    } else {
        cout << "FAILED: " << message << endl;
        // Halts execution, comment out to
        // continue testing other parts
		// If you do comment this out, ignore the
		// "All test cases passed!" printout
        exit(EXIT_FAILURE);
    }
}

//TODO
int main(int argc, char **argv) {
    /*
     * Construct the following organization chart for testing
     *                1
     *           /    \    \
     *           2    3    4
     *          / \  / \   \
     *          5 6  7 8   9
     *         /   \       \
     *         10  11      12
     */

    Employee *head = new Employee(1, vector<int>{2, 3, 4});
    Employee *e2 = head->getDirectReports().at(0);
    Employee *e3 = head->getDirectReports().at(1);
    Employee *e4 = head->getDirectReports().at(2);

    e2->addDirectReports(vector<int>{5, 6});
    e3->addDirectReports(vector<int>{7, 8});
    e4->addDirectReport(9);

    Employee *e5 = e2->getDirectReports().at(0);
    Employee *e6 = e2->getDirectReports().at(1);
    Employee *e9 = e4->getDirectReports().at(0);

    e5->addDirectReport(10);
    e6->addDirectReport(11);
    e9->addDirectReport(12);

    // Begin Testing
    // A few sample testing code are provided below
    
    // TODO Test all Orgtree functions
    //      according to the specifications in the comment section ABOVE each function signature. 
    
    // IMPORTANT: You should also construct at least one different chart 
    // Also make sure to check edge cases, such as empty chart, or one employee chart.

    // Test isEmployeePresentInOrg function
    bool employeePresent = Orgtree::isEmployeePresentInOrg(head, 6);
    assert(employeePresent, "ID 6 Present in tree");
    employeePresent = Orgtree::isEmployeePresentInOrg(head, -2);
    assert(employeePresent == false, "ID -2 Not present in tree");

    //TODO...

    // Test findEmployeeLevel function
    int employeeLevel = Orgtree::findEmployeeLevel(head, 4, 0);
    assert(employeeLevel == 1, "Level of ID 4 returns " + to_string(employeeLevel) + ", expected 1");

    //TODO...

    // Test findClosestSharedManager function
    // Call the function with certain combination of the arguments
    // Assert / verify the returned Employee* has the expected Employee ID

    //TODO...

    // Test findNumOfManagersBetween function
    int numManagers = Orgtree::findNumOfManagersBetween(head, 10, 11);
    assert(numManagers == 3, "Managers between 10 and 11 returns " + to_string(numManagers) + ", expected 3");

    // TODO numManagers = ...

    // Test deleteOrgtree function
    // VERY IMPORTANT: Related to valgrind memory leaking detection testing,
    // You MUST call your deleteOrgtree function at the end of this driver testing code
    // to delete all the allocated memory for the tree. 

    Orgtree::deleteOrgtree(head);

    // Use the printed employee ID along the sequence of deletion to verify your implementation
    // This part will be autograded as well as manually inspected for grading

    cout << endl << "All test cases passed!" << endl;

    // Return EXIT_SUCCESS exit code
    exit(EXIT_SUCCESS);
}