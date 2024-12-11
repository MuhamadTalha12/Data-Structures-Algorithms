#include<iostream>
#include<vector>
using namespace std;

void displayMatrix(vector<vector<int>> mat)
{
    for(int z = 0; z < mat.size(); z++)
    {
        for(int y = 0; y < mat[z].size(); y++)
        {
            cout << mat[z][y] << " ";
        }
        cout << "\n";
    }
}

void addRow(vector<vector<int>>& mat, vector<int> row)
{
    mat.push_back(row);
}

void addColumn(vector<vector<int>>& mat, vector<int> col)
{
    if(mat.size() == col.size())
    {
        for(int z = 0; z < mat.size(); z++)
        {
            mat[z].push_back(col[z]);
        }
        cout << "\nMatrix After adding Column\n";
    }
    else
    {
        cout << "Column Size is greater. Column can't be added.\n";
    }
}

vector<vector<int>> matrixTranspose(vector<vector<int>> mat)
{
    vector<vector<int>> transposedMat(mat[0].size(), vector<int>(mat.size()));
    for(int z = 0; z < mat.size(); z++)
    {
        for(int y = 0; y < mat[z].size(); y++)
        {
            transposedMat[y][z] = mat[z][y];
        }
    }
    return transposedMat;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}};
    cout << "Default Matrix\n";
    displayMatrix(mat);
    
    addRow(mat, {7, 8, 9});
    addRow(mat, {3, 2, 1});
    cout << "Matrix After Adding 2 Rows\n";
    displayMatrix(mat);
    
    addColumn(mat, {1, 3, 9, 3});
    displayMatrix(mat);
    
    cout << "Transposed Matrix\n";
    displayMatrix(matrixTranspose(mat));
}