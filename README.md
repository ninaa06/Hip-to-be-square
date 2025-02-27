# It's Hip To Be Square

In 1987, Huey Lewis and the News released "Fore!", their most accomplished album. I think their undisputed masterpiece is "Hip To Be Square", a song so catchy most people probably don't listen to the lyrics. But they should. Because it's not just about the pleasures of conformity and the importance of trends. It's also a personal statement about the band itself.

In honor of the hit song, your assignment is to find valid squares in a letter grid. A "letter grid" is a rectangular grid with one letter at each position. For example:

    ╭───────────────╮
    │ A   B   B   A │
    │               │
    │ U   B   B   U │
    │               │
    │ A   L   A   N │
    │               │
    │ A   L   D   A │
    ╰───────────────╯

A "valid square" is four points in the letter grid in the shape of a square with the same letter at each corner and sides parallel to the grid's edges. For example, the letter grid above has two valid squares:

    ╭───────────────╮    ╭───────────────╮
    │ A╶─╴·╶─╴·╶─╴A │    │ ·   B╶─╴B   · │
    │ │           │ │    │     │   │     │
    │ ·   ·   ·   · │    │ ·   B╶─╴B   · │
    │ │           │ │    │               │
    │ ·   ·   ·   · │    │ ·   ·   ·   · │
    │ │           │ │    │               │
    │ A╶─╴·╶─╴·╶─╴A │    │ ·   ·   ·   · │
    ╰───────────────╯    ╰───────────────╯

1. Square "A" with side length of 3
2. Square "B" with side length of 1

## Part 1: Creating a Letter Grid

Using the `LetterGrid` class as a starting point, create a data structure for a letter grid that can be instantiated from a string. For instance, the string "PA TR IC KB AT EM AN" becomes the following grid:

    ╭───────╮
    │ P   A │
    │       │
    │ T   R │
    │       │
    │ I   C │
    │       │
    │ K   B │
    │       │
    │ A   T │
    │       │
    │ E   M │
    │       │
    │ A   N │
    ╰───────╯

You should be able to instantiate the above letter grid and query it as follows:

    LetterGrid grid("PA TR IC KB AT EM AN");
    cout << grid.getRowCount() << endl;        // 7
    cout << grid.getColumnCount() << endl;     // 2
    cout << grid.getLetterAt(1, 1) << endl;    // R

As a best practice, you would check that the input string is valid, but that is not necessary for this assignment. You can assume all strings are well-formed: exactly one space between rows, all rows the same length, no empty strings, etc.

Some unit tests have been provided for you in `square_test.cpp`. Make sure the first two unit tests pass before moving on to the next part. (Note: The provided test cases do not cover all aspects of the code. Consider adding your own tests, and be sure to check edge cases!)

## Part 2: Locating Valid Squares

Next, implement the `getValidSquares` function so that it locates and returns all valid squares in the given letter grid.

A unit test for `getValidSquares` has been provided for you, but you should add more tests to confirm your code works as expected. Make sure all unit tests pass before moving on to the next part.

## Part 3: Algorithm Analysis

In the file `ANALYSIS.md`, answer the following questions:

1. What is the big O space complexity of your data structure in terms of _n_, where _n_ is the number of letters in the input string?
2. What is the big O time complexity of your `getValidSquares` implementation in terms of _n_, where _n_ is the number of letters in the input string?

For each question, briefly justify your answer in 1-2 sentences.

### Hint: Use Tight Bounds

Asymptotic notation should be stated as tightly as possible. Consider this code:

    for (int i = 0; i < n; i++) { ... }

It is completely correct to say that the above code is `O(n³)` because a linear algorithm grows no faster asymptotically than a cubic one. However, `O(n³)` is not a tight bound and should be expressed more accurately for this code as `O(n)`.

You will know when your asymptotic notation is "tight enough" when it cannot be expressed as a slower-growing function of the seven functions used in the textbook (Table 4.1). For example, if you claim an algorithm's time complexity is `O(n log n)`, but it can be shown that the algorithm actually runs in linear time, this is not a tight-enough bound because `O(n)` is one of the seven functions and it is "less than" `O(n log n)`.

### Hint: Consider Loop Limits Carefully

When analyzing the time complexity of a function, it is tempting to look at the code structure alone and ignore loop limits. Consider this code:

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ...
            }
        }
    }

This triply-nested loop has a time complexity of `O(n³)`. Now consider this code:

    const int MAX_X = 1000000;
    const int MAX_Y = 1000000;
    const int MAX_Z = 1000000;
    for (int i = 0; i < MAX_X; i++) {
        for (int j = 0; j < MAX_Y; j++) {
            for (int k = 0; k < MAX_Z; k++) {
                ...
            }
        }
    }

This is also a triply-nested loop, but its time complexity is _not_ `O(n³)`. It is actually constant-time (`O(1)`) because the number of operations performed does not vary as a function of `n`. In this case, the constant is likely impractically large but it is constant nonetheless.

When analyzing the time complexity of `getValidSquares`, be sure to consider the loop bounds in your code. Depending on how you chose to implement the function, its code structure may mislead you to an incorrect bound (or at least, one that is not tight enough).

## Part 4: Algorithm Benchmarking

To support your time complexity analysis in Part 3, conduct an experiment to observe the performance of `getValidSquares`. You can use the `Benchmark` unit test in `square_test.cpp` to assist with this effort. By default, it defines 10 benchmarks with increasing grid sizes: 10x10, 20x20, etc. (Feel free to adjust the grid sizes if needed to account for the speed of your computer.)

To collect the data, do not run the unit tests the usual way because the benchmark output is hidden by default. Instead, use the `CMake: Set Debug Target` command to select the `assignment2_tests` target, then run the `Benchmark` unit test using `CMake: Run Without Debugging` (or press Shift+F5 or click the little triangle in the status bar). The salient output is the "mean" field, which is in the second row, first column of each benchmark.

Next, graph the benchmark data using the [Desmos Graphing Calculator](https://www.desmos.com/calculator), pen and paper, or a tool of your choice. In `ANALYSIS.md`, note which tool you used, and briefly explain (1-2 sentences) in `ANALYSIS.md` how the empirical results support your theoretical analysis in Part 3. Also, take a screenshot of the graph (or a photograph if done on pen and paper) and include it with your submission in a PNG file called `graph.png` in the root of the repository.

## Appendix

The opening paragraph is a quote from the movie _American Psycho_. I don't actually have an obsession with Huey Lewis and the News.
