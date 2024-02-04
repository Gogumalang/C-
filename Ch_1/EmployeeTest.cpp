#include <iostream>
#include "Employee.hpp"
using namespace std;
using namespace Records;

int main() {
    cout << "Testing the Employee class." << endl;
    Employee emp;
    emp.setFirstName("Marni");
    emp.setLastName("Kleper");
    emp.setEmployeeNumber(71);
    emp.setSalary(50000);
    emp.promote(100);
    emp.demote(50);
    emp.hire();
    emp.display();
    return 0;
}