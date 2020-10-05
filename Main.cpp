#include<iostream>
#include <vector>
using namespace std;


void Display(vector<vector<int>>& matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    int temp = 0;
    if (row == col)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = i; j < col; j++)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        //Display(matrix);
        // iter2
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col / 2; j++)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][col - j - 1];
                matrix[i][col - j - 1] = temp;
            }
        }
    }
    else
    {
        throw invalid_argument("rotation not feasible");
    }
}

int main(int argc, char** argv)
{
    vector<vector<int>> matrix{ {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16} };
    rotate(matrix);
    Display(matrix);
    return 0;
}