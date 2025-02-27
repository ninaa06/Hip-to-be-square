#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>
#include "square.h"

#include <algorithm>
#include <memory>

using namespace std;

TEST_CASE("A square letter grid can be constructed properly") {
    // A B B A
    // U B B U
    // A L A N
    // A L D A
    LetterGrid grid("ABBA UBBU ALAN ALDA");
    REQUIRE(grid.getRowCount() == 4);
    REQUIRE(grid.getColumnCount() == 4);
    REQUIRE(grid.getLetterAt(0, 0) == 'A');
    REQUIRE(grid.getLetterAt(0, 3) == 'A');
    REQUIRE(grid.getLetterAt(1, 0) == 'U');
    REQUIRE(grid.getLetterAt(2, 2) == 'A');
    REQUIRE(grid.getLetterAt(3, 0) == 'A');
    REQUIRE(grid.getLetterAt(3, 3) == 'A');
}

TEST_CASE("A rectangular letter grid can be constructed properly") {
    // P A
    // T R
    // I C
    // K B
    // A T
    // E M
    // A N
    LetterGrid grid("PA TR IC KB AT EM AN");
    REQUIRE(grid.getRowCount() == 7);
    REQUIRE(grid.getColumnCount() == 2);
    REQUIRE(grid.getLetterAt(0, 0) == 'P');
    REQUIRE(grid.getLetterAt(0, 1) == 'A');
    REQUIRE(grid.getLetterAt(3, 0) == 'K');
    REQUIRE(grid.getLetterAt(3, 1) == 'B');
    REQUIRE(grid.getLetterAt(6, 0) == 'A');
    REQUIRE(grid.getLetterAt(6, 1) == 'N');
}

bool containsSquare(const vector<Square> &squares, const Square& square) {
    for (auto i = squares.begin(); i != squares.end(); i++) {
        if (*i == square) {
            return true;
        }
    }

    return false;
}

TEST_CASE("ABBA UBBU ALAN ALDA has 2 squares") {
    // A B B A
    // U B B U
    // A L A N
    // A L D A
    LetterGrid grid("ABBA UBBU ALAN ALDA");
    auto squares = grid.getValidSquares();
    REQUIRE(squares.size() == 2);
    REQUIRE(containsSquare(squares, Square(0, 0, 3)));
    REQUIRE(containsSquare(squares, Square(0, 1, 1)));
}

unique_ptr<LetterGrid> createGrid(int length)
{
    int size = length * length + length - 1;
    string input(size, 'A');
    for (int i = length; i < size; i += length + 1) {
        input[i] = ' ';
    }
    return make_unique<LetterGrid>(input);
}

TEST_CASE("Benchmark") {
    vector< unique_ptr<LetterGrid> > grids(10);
    generate(grids.begin(), grids.end(), [n=0] () mutable {
        n += 10;
        return createGrid(n);
    });

    BENCHMARK("Benchmark 1") {
        return grids[0]->getValidSquares();
    };
    BENCHMARK("Benchmark 2") {
        return grids[1]->getValidSquares();
    };
    BENCHMARK("Benchmark 3") {
        return grids[2]->getValidSquares();
    };
    BENCHMARK("Benchmark 4") {
        return grids[3]->getValidSquares();
    };
    BENCHMARK("Benchmark 5") {
        return grids[4]->getValidSquares();
    };
    BENCHMARK("Benchmark 6") {
        return grids[5]->getValidSquares();
    };
    BENCHMARK("Benchmark 7") {
        return grids[6]->getValidSquares();
    };
    BENCHMARK("Benchmark 8") {
        return grids[7]->getValidSquares();
    };
    BENCHMARK("Benchmark 9") {
        return grids[8]->getValidSquares();
    };
    BENCHMARK("Benchmark 10") {
        return grids[9]->getValidSquares();
    };
}
