#pragma once

#include <string>
#include <vector>

// A single square in a letter grid.
class Square {
    int row;
    int column;
    int length;
public:
    // Initializes a new square where row and column indicate the upper left corner
    // and length is the length of the square's side.
    Square(int row, int column, int length);
    
    // Returns true if two squares have the same row, column, and length; false otherwise.
    bool operator==(const Square& other) const;

    // Added getter functions
    int getRow() const { return row; }
    int getColumn() const { return column; }
    int getLength() const { return length; }

};

// A rectangular grid with one letter at each position.
class LetterGrid {
private:
    std::vector<std::vector<char>> grid;
    int rows;
    int cols;

public:
    // Initializes a new letter grid with the given string. The string must be formatted
    // such that the first characters represent the first row of the grid (only upper case
    // letters, no spaces), followed by a single space, then the next row of the grid, and
    // so on.
    LetterGrid(std::string input);

    // Returns the number of rows in the grid.
    int getRowCount() const;

    // Returns the number of columns in the grid.
    int getColumnCount() const;

    // Returns the letter at the given coordinate (0-based, origin in top left of grid).
    char getLetterAt(int row, int column) const;

    // Returns all valid squares in the letter grid. A valid square is four elements in
    // the grid having the same letter and the same distance from each other.
    std::vector<Square> getValidSquares() const;
};
