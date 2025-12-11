#include <bits/stdc++.h>
using namespace std;

int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    unordered_map<int, int> minCol, maxCol;
    unordered_map<int, int> minRow, maxRow;

    for (auto &b : buildings) {
        int r = b[0], c = b[1];

        if (!minCol.count(r) || c < minCol[r]) minCol[r] = c;
        if (!maxCol.count(r) || c > maxCol[r]) maxCol[r] = c;

        if (!minRow.count(c) || r < minRow[c]) minRow[c] = r;
        if (!maxRow.count(c) || r > maxRow[c]) maxRow[c] = r;
    }

    int covered = 0;
    for (auto &b : buildings) {
        int r = b[0], c = b[1];

        if (minCol[r] < c && c < maxCol[r] &&
            minRow[c] < r && r < maxRow[c])
            covered++;
    }

    return covered;
}