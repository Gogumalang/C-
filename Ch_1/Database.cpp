#include <iostream>
#include <stdexcept>
#include "Database.hpp"
using namespace std;
namespace Records {
    Database::Database()
    {
        mNextEmployeeNumber = kFirstEmployeeNumber;
    }
    Database::~Database() {}
    Employee& Database::addEmployee(string inFirstName, string inLastName)
    {
        Employee theEmployee;
        theEmployee.setFirstName(inFirstName);
        theEmployee.setLastName(inLastName);
        theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
        theEmployee.hire();
        mEmployees.push_back(theEmployee);
        return mEmployees[mEmployees.size()-1];
    }
    Employee& Database::getEmployee(int inEmployeeNumber) 
    {
        for (vector<Employee>::iterator iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) {
            if(iter->getEmployeeNumber() == inEmployeeNumber) 
                return *iter;
        }
        cerr << "No employee with number " << inEmployeeNumber <<endl;
        throw exception();
    }
    Employee& Database::getEmployee(string inFirstName, string inLastName)
    {
        for (vector<Employee>::iterator iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) {
            if((iter->getFirstName() == inFirstName) && (iter->getLastName() == inLastName))
                return *iter;
        }
        cerr << "No employee with name " << inFirstName << ", " << inLastName <<endl;
        throw exception();
    }
    void Database::displayAll() const
    {
        for(vector<Employee>::const_iterator iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) {
            iter->display();
        }
    }
    void Database::displayCurrent() const 
    {
        for(vector<Employee>::const_iterator iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) {
            if(iter->getIsHired()) iter->display();
        }
    }
    void Database::displayFormer() const 
    {
        for(vector<Employee>::const_iterator iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) {
            if(!iter->getIsHired()) iter->display();
        }
    }
}