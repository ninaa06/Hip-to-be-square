#include "square.h"
#include <iostream>

using namespace std;

void printGrid(const LetterGrid& grid) {
    for (int r = 0; r < grid.getRowCount(); r++) {
        for (int c = 0; c < grid.getColumnCount(); c++) {
            cout << grid.getLetterAt(r, c) << " ";
        }
        cout << endl;
    }
}

int main() {
    LetterGrid grid("ABBA UBBU ALAN ALDA");
    
    cout << "Letter Grid:\n";
    printGrid(grid);
    
    cout << "\nRows: " << grid.getRowCount() << endl;
    cout << "Columns: " << grid.getColumnCount() << endl;

    vector<Square> squares = grid.getValidSquares();
    cout << "Valid squares found: " << squares.size() << endl;

    for (const Square& s : squares) {
        cout << "Square at (" << s.getRow() << ", " << s.getColumn() << ") with size " << s.getLength() << endl;
    }

    return 0;
}
