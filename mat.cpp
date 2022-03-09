#include <iostream>
// #include <string>
using namespace std;

#include "mat.hpp"

namespace ariel {
	string mat(int col, int row, char symb1, char symb2) {
		if(col < 0 || col%2 != 1 || row < 0 || row%2 != 1) {
			// string ans = "Illegal parameters"; (col:" + col;// + ", row: " + row + ")";
            return "Illegal parameters!";// (col:" << col << ", row: " << row << ")";
        }
        
	}
}