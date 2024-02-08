#include "SpreadsheetCell.hpp"
class SpreadsheetApplication; // forward declartion
class Spreadsheet
{
public:
    Spreadsheet(int inWidth, int inHeight, 
                    SpreadsheetApplication& theApp);
    ~Spreadsheet();
    Spreadsheet(const Spreadsheet& src);
    Spreadsheet& operator=(const Spreadsheet& rhs);
    void setCellAt(int x, int y, const SpreadsheetCell& cell);
    SpreadsheetCell getCell(int x, int y);
    int getId() const;
    static const int kMaxHeight = 100;
    static const int kMaxWidth = 100; 
protected:
    SpreadsheetApplication& mTheApp;
    void copyFrom(const Spreadsheet& src);
    bool inRange(int val, int upper);
    static int sCounter ;//= 0;  초기 선언 가능 
    int mId;
    int mWidth, mHeight;
    SpreadsheetCell** mCells;
private:
    // 클래스에서 동적 메모리 할당을 사용할 때 복제와 대입 때문에 발생하는 문제를 피하는 방법 중 하나. -> 메서드 사용을 막는것. 
    // Spreadsheet(const Spreadsheet& src); 
    // Spreadsheet& operator=(const Spreadsheet& rhs);

};