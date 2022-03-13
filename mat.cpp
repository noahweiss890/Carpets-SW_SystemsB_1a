#include <iostream>
// #include <string>
using namespace std;

#include "mat.hpp"

namespace ariel {
	string mat(int col, int row, char symb1, char symb2) {
		if(col < 0 || col%2 != 1 || row < 0 || row%2 != 1) {
            throw invalid_argument("Mat size is always odd!");
        }

		char arr[row][col];
		
		for(int i = 0; i < row; i++) {
		    for(int j = 0; j < col; j++) {
		        arr[i][j] = symb1;
		    }
		}
		
		// paint every other ring with symb2
        for(int k = 1; k <= col/2 && k <= row/2; k += 2) {
            // top and bottom line
            for(int i = k; i < col - k; i++) {
                arr[k][i] = symb2;
                arr[row-k-1][i] = symb2;
            }
            // left and right side
            for(int i = k; i < row - k; i++) {
                arr[i][k] = symb2;
                arr[i][col-k-1] = symb2;
            }
        }
        
        string ans = "";
        
        // print array
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                ans += arr[i][j];
            }
            ans += "\n";
        }
        
        return ans;
	}
}