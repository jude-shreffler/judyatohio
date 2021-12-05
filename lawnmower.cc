#include <iostream>

using namespace std;

/// constants
const int MAX_TESTS = 100;
const int MAX_LENGTH = 10;
const int MAX_WIDTH = 10;
const int MAX_HEIGHT = 2;

/**
 * @brief 
 * 
 * @param tests 
 * @param test 
 * @param length 
 * @param width 
 * @return true 
 * @return false 
 */
bool checkYAxis(int tests[MAX_TESTS][MAX_LENGTH][MAX_WIDTH], int test, int length, int width);

/**
 * @brief 
 * 
 * @param tests 
 * @param test 
 * @param length 
 * @param width 
 * @return true 
 * @return false 
 */
bool checkXAxis(int tests[MAX_TESTS][MAX_LENGTH][MAX_WIDTH], int test, int length, int width);

/**
 * @brief 
 * 
 * @param tests 
 * @param test 
 * @param length 
 * @param width 
 * @return true 
 * @return false 
 */
bool checkCell(int tests[MAX_TESTS][MAX_LENGTH][MAX_WIDTH], int test, int length, int width);

/**
 * @brief 
 * 
 * @param tests 
 * @param test 
 * @return true 
 * @return false 
 */
bool checkTest(int tests[MAX_TESTS][MAX_LENGTH][MAX_WIDTH], int test);


int main() {
    /// just variable init
    int numTests = 0;
    int testHeight = 0;
    int testWidth = 0;
    int tests[MAX_TESTS][MAX_LENGTH][MAX_WIDTH];
    
    /// input the number of tests
    /// cout << "Input number of test cases: ";
    cin >> numTests;

    /// input all the tests into tests[][][]
    for (int i = 0; i < numTests; i++) {
        /// cout << "Input size of test #" << i + 1 << ": ";
        cin >> testHeight;
        cin >> testWidth;
        for (int j = 0; j < testHeight; j++) {
            /// cout << "Input line #" << j + 1 << ": ";
            for (int k = 0; k < testWidth; k++) {
                cin >> tests[i][j][k];
            }
        }
    }

    /// check each test for truth or false
    for (int i = 0; i < numTests; i++) {
        cout << "Case #" << i + 1 << ": ";
        if (checkTest(tests, i) == true) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

bool checkYAxis(int tests[MAX_TESTS][MAX_LENGTH][MAX_WIDTH], int test, int length, int width) {
    /// check each value above the given coordinate to see if its larger. if it is, return false
    for (int i = 0; i < length; i++) {
        if (tests[test][length][width] < tests[test][i][width]) {
            return false;
        }
    }

    /// check each value below the given coordinate to see if its larger. if it is, return false
    for (int i = length + 1; i < MAX_LENGTH; i++) {
        if (tests[test][length][width] < tests[test][i][width]) {
            return false;
        }
    }

    return true;
}

bool checkXAxis(int tests[MAX_TESTS][MAX_LENGTH][MAX_WIDTH], int test, int length, int width) {
    /// check each value left of the given coordinate to see if its larger. if it is, return false
    for (int i = 0; i < width; i++) {
        if (tests[test][length][width] < tests[test][length][i]) {
            return false;
        }
    }

    /// check each value right of the given coordinate to see if its larger. if it is, return false
    for (int i = length + 1; i < MAX_WIDTH; i++) {
        if (tests[test][length][width] < tests[test][length][i]) {
            return false;
        }
    }

    return true;
}

bool checkCell(int tests[MAX_TESTS][MAX_LENGTH][MAX_WIDTH], int test, int length, int width) {
    /// if the cell is 0, return true
    if (tests[test][length][width] == 0) {
        return true;
    }

    /// next do the yaxis and xaxis check
    if (checkYAxis(tests, test, length, width) || checkXAxis(tests, test, length, width)) {
        return true;
    }

    return false;
}

bool checkTest(int tests[MAX_TESTS][MAX_LENGTH][MAX_WIDTH], int test) {
    /// loop through each element of the test and call checkCell
    for (int i = 0; i < MAX_LENGTH; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            if (checkCell(tests, test, i, j) == false) {
                return false;
            }
        }
    }
    return true;
}