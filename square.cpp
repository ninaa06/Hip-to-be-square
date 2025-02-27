#include "square.h"
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

Square::Square(int row, int column, int length)
{
    this->row = row;
    this->column = column;
    this->length = length;
}

bool Square::operator==(const Square &other) const
{
    return (row == other.row) && (column == other.column) && (length == other.length);
}

LetterGrid::LetterGrid(string input)
{
    istringstream stream(input);
    string line;
    while (getline(stream, line, ' '))
    {
        vector<char> row;
        for (char c : line)
        {
            row.push_back(c);
        }
        grid.push_back(row);
    }
    rows = grid.size();
    cols = (rows > 0) ? grid[0].size() : 0;
}

int LetterGrid::getRowCount() const
{
    return rows;
}

int LetterGrid::getColumnCount() const
{
    return cols;
}

char LetterGrid::getLetterAt(int row, int column) const
{
    return grid[row][column];
}

vector<Square> LetterGrid::getValidSquares() const
{
    vector<Square> squares;
    for (int r1 = 0; r1 < rows; ++r1)
    {
        for (int c1 = 0; c1 < cols; ++c1)
        {
            char letter = grid[r1][c1];
            for (int size = 1; r1 + size < rows && c1 + size < cols; ++size)
            {
                int r2 = r1 + size, c2 = c1 + size;
                if (grid[r1][c2] == letter && grid[r2][c1] == letter && grid[r2][c2] == letter)
                {
                    squares.emplace_back(r1, c1, size);
                }
            }
        }
    }
    return squares;
}
