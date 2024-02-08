#include <iostream>
#include <string>

using namespace std;
class SpreadsheetCell
{
public:
    SpreadsheetCell();
    SpreadsheetCell(const SpreadsheetCell& src); // 복제 생성자 
    SpreadsheetCell(double initialValue); 
    SpreadsheetCell(const string& initialValue);

    SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
    void setValue(double inValue);
    double getValue() const;
    void setString(const string& inString);
    string getString() const;
protected:
    string doubleToString(double inValue) const;
    double stringToDouble(const string& inString) const;
    double mValue;
    string mString;
};