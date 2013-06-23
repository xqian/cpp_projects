class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        if ( m == 0) return;
        int n = matrix[0].size();
        if ( n == 0) return;
        bool row0zero = rowHasZero(matrix, 0);
        bool col0zero = colHasZero(matrix, 0);
                
        for(int i=1; i < m; ++i) {
            for (int j=1; j < n; ++j) { //BUG: i=0, j=0;
                if ( matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
                        
        for(int i=1; i < m; ++i) { //BUG: i=0!!!
            if ( matrix[i][0] == 0) {
                   setRowZero(matrix, i);
            }
        }
        
        for(int i=1; i < n; ++i) {
            if ( matrix[0][i] == 0) {
                setColZero(matrix, i);
            }
        }
        
        if (row0zero) {
            setRowZero(matrix, 0);    
        }
        
        if (col0zero) {
            setColZero(matrix, 0);
        }
    }

    void setRowZero(vector<vector<int> > &matrix, int row) {
        for(int i=0; i < matrix[0].size(); ++i) {
            matrix[row][i] = 0;
        }
    }    

    void setColZero(vector<vector<int> > &matrix, int col) {
        for(int i = 0; i < matrix.size(); ++i) {
            matrix[i][col] = 0;
        }
    }    

    bool rowHasZero(vector<vector<int> > &matrix, int row) {
        for(int i=0; i < matrix[0].size(); ++i) {
            if ( matrix[row][i] == 0) {
                return true;
            }
        }
        return false;
    }
    
    bool colHasZero(vector<vector<int> > &matrix, int col) {
        for(int i=0; i < matrix.size(); ++i) {
            if ( matrix[i][col] == 0) {
                return true;
            }
        }
        return false;
    }
};
