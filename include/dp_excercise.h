#ifndef DP_EXCERSISE_H
#define DP_EXCERSISE_H
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;
int uniquePaths(int m, int n);

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid);

int minPathSum(vector<vector<int>> &grid);

int minimumTotal(vector<vector<int>> &triangle);

/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/
int minFallingPathSum(vector<vector<int>>& matrix);

int minFallingPathSum2(vector<vector<int>>& grid);


int countRoutes(vector<int>& locations, int start, int finish, int fuel);

int maximalSquare(vector<vector<char>> &matrix);
#endif // DP_EXCERSISE_H

