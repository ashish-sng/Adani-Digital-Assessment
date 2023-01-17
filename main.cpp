#include <bits/stdc++.h>
using namespace std;

int colIndex;

vector<vector<int>> make2DList(int r, int c) { // function to create a 2-D List/Array with random integers between 0 to 100

    vector<vector<int>> res;

    for(int i = 0 ; i < r; ++i) {
        vector<int> temp;        
        for(int j = 0 ; j < c; ++j) {
            temp.push_back(1 + (rand() % 100));
        }
        res.push_back(temp);
    }

    return res;
}


// function to sort the 2-D list based on column index keeping the rows intact

bool comp(vector<int> &vec1, vector<int> &vec2) {
    if(vec1[colIndex-1] < vec2[colIndex-1])
        return true;

    return false;
}

void sort2DList(vector<vector<int>> &sol) {
    sort(sol.begin(), sol.end(), comp);
}

int main() {

    int row, col;
    cin >> row >> col; // 2-D matrix dimensions

    vector<vector<int>> sol = make2DList(row, col);

    for(int i = 0 ; i < row; ++i) {
        for(int j = 0 ; j < col; ++j)
            cout << sol[i][j] << " ";
        cout << endl;
    }

    cin >> colIndex; //column index according to which it has to sort 1-indexing
    cout << endl;

    sort2DList(sol);

    for(int i = 0 ; i < row; ++i) {
        for(int j = 0 ; j < col; ++j)
            cout << sol[i][j] << " ";
        cout << endl;
    }

    return 0;
}