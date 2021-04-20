#include <iostream>
#include <vector>
using namespace std;

class sudoku {
private:
    int board[9][9];
    bool rowcheck[9][10];//emtpy is false;
    bool colcheck[9][10];
    bool boxcheck[3][3][10];
    vector<pair<int, int>> empty_index;
    int size;
    void show();
public:
    sudoku();
    void init();
    bool search(int index);
};

sudoku::sudoku() {
    for (int i = 0; i < 9; i++) {
        for (int j = 1; j <= 9; j++) {
            rowcheck[i][j] = false;
            colcheck[i][j] = false;
            boxcheck[i / 3][i % 3][j] = false;
        }
    }
}
void sudoku::show() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
void sudoku::init() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                pair<int, int> put;
                put.first = i;
                put.second = j;
                empty_index.push_back(put);
            }
            else {
                rowcheck[i][board[i][j]] = true;
                colcheck[j][board[i][j]] = true;
                boxcheck[i / 3][j / 3][board[i][j]] = true;
            }
        }
    }
    size = empty_index.size();
}

bool sudoku::search(int index) {
    if (index == size) {
        show();
        return true;
    }
    int row = empty_index[index].first, col = empty_index[index].second;
    for (int i = 1; i <= 9; i++) {
        if (rowcheck[row][i] || colcheck[col][i] || boxcheck[row / 3][col / 3][i]) {
            continue;
        }
        board[row][col] = i;
        rowcheck[row][i] = true;
        colcheck[col][i] = true;
        boxcheck[row / 3][col / 3][i] = true;
        if (search(index + 1)) {
            return true;
        }
        board[row][col] = 0;
        rowcheck[row][i] = false;
        colcheck[col][i] = false;
        boxcheck[row / 3][col / 3][i] = false;
    }
    return false;
}

int main() {
    sudoku test;
    test.init();
    test.search(0);
    return 0;
}
