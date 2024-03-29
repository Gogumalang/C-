#include "Spreadsheet.hpp"

int Spreadsheet::sCounter = 0;
Spreadsheet::Spreadsheet(int inWidth, int inHeight, SpreadsheetApplication& theApp) : 
        mWidth(inWidth < kMaxWidth ? inWidth : kMaxWidth), 
        mHeight(inHeight < kMaxHeight ? inHeight : kMaxHeight),
        mTheApp(theApp)
{
    mId = sCounter++;
    mCells = new SpreadsheetCell* [inWidth];
    for(int i =0;i<inWidth;i++) {
        mCells[i] = new SpreadsheetCell[inHeight];
    }
}

Spreadsheet::~Spreadsheet() 
{
    for(int i =0 ; i< mWidth; i++) {
        delete[] mCells[i];
    }
    delete[] mCells;
    mCells = nullptr;
}

void Spreadsheet::copyFrom(const Spreadsheet& src) 
{
    mWidth = src.mWidth;
    mHeight = src.mHeight;
    mCells = new SpreadsheetCell* [mWidth];
    for(int i =0; i<mWidth; i++) {
        mCells[i] = new SpreadsheetCell[mHeight];
    }
    for(int i =0; i<mWidth; i++) {
        for(int j =0; j<mHeight; j++) {
            mCells[i][j] = src.mCells[i][j];
        }
    }
}

Spreadsheet::Spreadsheet(const Spreadsheet& src) : 
        mTheApp(src.mTheApp)
{
    mId = sCounter++;
    copyFrom(src);
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs) 
{
    if(this == &rhs) {
        return *this;
    }

    for(int i = 0; i < mWidth; i++) {
        delete[] mCells[i];
    }
    delete[] mCells;
    mCells = nullptr;
    copyFrom(rhs);

    return *this;

}

void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& cell)
{
    if(!inRange(x,mWidth) || !inRange(y,mHeight)) {
        throw std::out_of_range("");
    }
    mCells[x][y] = cell;
}

SpreadsheetCell Spreadsheet::getCell(int x, int y) 
{
    if(!inRange(x,mWidth) || !inRange(y,mHeight)) {
        throw std::out_of_range("");
    }
    return mCells[x][y];
}

int Spreadsheet::getId() const
{
    return mId;
}