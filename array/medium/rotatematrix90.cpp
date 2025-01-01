#include <iostream>
using namespace std;
// bruite force:
// Approach: Take another dummy matrix of n*n, and then take the first row of the matrix and put it in the last column of the dummy matrix, take the second row of the matrix, and put it in the second last column of the matrix and so.
vector < vector < int >> bruite(vector < vector < int >> & matrix) {
    int n = matrix.size();
    vector < vector < int >> rotated(n, vector < int > (n, 0));
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        rotated[j][n - i - 1] = matrix[i][j];
    }
    }
    return rotated;
}
// optimal sol:
// Intuition: By observation, we see that the first column of the original matrix is the reverse of the first row of the rotated matrix, so that’s why we transpose the matrix and then reverse each row, and since we are making changes in the matrix itself space complexity gets reduced to O(1).

// Approach:

// Step 1: Transpose the matrix. (transposing means changing columns to rows and rows to columns)

// Step 2: Reverse each row of the matrix.
void optimal(vector <vector <int>> &matrix){
    int n = matrix.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}