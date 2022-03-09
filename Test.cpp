/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	// simple situation
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													"@-------@\n"
													"@-@@@@@-@\n"
													"@-@---@-@\n"
													"@-@@@@@-@\n"
													"@-------@\n"
													"@@@@@@@@@"));
	
	// simple situation
	CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
													 "@-----------@\n"
													 "@-@@@@@@@@@-@\n"
													 "@-----------@\n"
													 "@@@@@@@@@@@@@"));
    
	// simple situation
	CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n"
													"$+$\n"
													"$+$\n"
													"$+$\n"
													"$$$"));
    
	// 1 by 1
	CHECK(nospaces(mat(1, 1, '+', ')')) == nospaces("+"));
	
	// horizontal line
	CHECK(nospaces(mat(11, 1, '#', '(')) == nospaces("###########"));

	// thick horizontal line
	CHECK(nospaces(mat(15, 3, '%', '-')) == nospaces("%%%%%%%%%%%%%%%\n"
													 "%-------------%\n"
													 "%%%%%%%%%%%%%%%"));
	
	// vertical line
	CHECK(nospaces(mat(1, 11, '=', '4')) == nospaces("=\n"
													 "=\n"
													 "=\n"
													 "=\n"
													 "=\n"
													 "=\n"
													 "=\n"
													 "=\n"
													 "=\n"
													 "=\n"
													 "="));
	
	// thick vertical line
	CHECK(nospaces(mat(3, 15, '^', '?')) == nospaces("^^^\n"
													 "^?^\n"
													 "^?^\n"
													 "^?^\n"
													 "^?^\n"
													 "^?^\n"
													 "^?^\n"
													 "^?^\n"
													 "^?^\n"
													 "^?^\n"
													 "^?^\n"
													 "^?^\n"
													 "^?^\n"
													 "^?^\n"
													 "^^^"));
	
	// second char is space
	CHECK(nospaces(mat(9, 5, 'N', ' ')) == nospaces("NNNNNNNNN\n"
													"N       N\n"
													"N NNNNN N\n"
													"N       N\n"
													"NNNNNNNNN"));
	
	// first char is space
	CHECK(nospaces(mat(9, 5, ' ', 'T')) == nospaces("         \n"
													" TTTTTTT \n"
													" T     T \n"
													" TTTTTTT \n"
													"         "));
	
	// both chars are spaces
	CHECK(nospaces(mat(7, 3, ' ', ' ')) == nospaces("       \n"
													"       \n"
													"       "));

	// same symbol
	CHECK(nospaces(mat(31, 19, 'x', 'x')) == nospaces(  "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
														"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
														"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
														"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
														"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
														"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
														"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
														"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
														"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
														"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
														"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
														"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
														"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
														"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
														"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
														"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
														"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
														"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n"
														"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"));

}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%')); // column even number
    CHECK_THROWS(mat(2, 1, '^', '(')); // column even number
	CHECK_THROWS(mat(3, 6, 'q', 'p')); // row even number
	CHECK_THROWS(mat(1, 22, '0', 'o')); // row even number
	CHECK_THROWS(mat(44, 68, 'j', 'k')); // column and row even number
    CHECK_THROWS(mat(5, -11, '4', 'X')); // row negative number
	CHECK_THROWS(mat(-3, 17, 'f', 'i')); // column negative number
	CHECK_THROWS(mat(-23, -43, 'X', 'Y')); // column and row negative number
}


TEST_CASE("Big input") {
	// small square
	CHECK(nospaces(mat(3, 3, '+', '=')) == nospaces("+++\n"
													"+=+\n"
													"+++"));

	// medium square
	CHECK(nospaces(mat(51, 51, '0', '+')) == nospaces(  "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n"
														"O+++++++++++++++++++++++++++++++++++++++++++++++++O\n"
														"O+OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO+O\n"
														"O+O+++++++++++++++++++++++++++++++++++++++++++++O+O\n"
														"O+O+OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO+O+O\n"
														"O+O+O+++++++++++++++++++++++++++++++++++++++++O+O+O\n"
														"O+O+O+OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO+O+O+O\n"
														"O+O+O+O+++++++++++++++++++++++++++++++++++++O+O+O+O\n"
														"O+O+O+O+OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO+O+O+O+O\n"
														"O+O+O+O+O+++++++++++++++++++++++++++++++++O+O+O+O+O\n"
														"O+O+O+O+O+OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO+O+O+O+O+O\n"
														"O+O+O+O+O+O+++++++++++++++++++++++++++++O+O+O+O+O+O\n"
														"O+O+O+O+O+O+OOOOOOOOOOOOOOOOOOOOOOOOOOO+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+++++++++++++++++++++++++O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+OOOOOOOOOOOOOOOOOOOOOOO+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+++++++++++++++++++++O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+OOOOOOOOOOOOOOOOOOO+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+O+++++++++++++++++O+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+O+OOOOOOOOOOOOOOO+O+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+O+O+++++++++++++O+O+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+O+O+OOOOOOOOOOO+O+O+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+O+O+O+++++++++O+O+O+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+O+O+O+OOOOOOO+O+O+O+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+O+O+O+O+++++O+O+O+O+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+O+O+O+O+OOO+O+O+O+O+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+O+O+O+O+O+O+O+O+O+O+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+O+O+O+O+OOO+O+O+O+O+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+O+O+O+O+++++O+O+O+O+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+O+O+O+OOOOOOO+O+O+O+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+O+O+O+++++++++O+O+O+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+O+O+OOOOOOOOOOO+O+O+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+O+O+++++++++++++O+O+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+O+OOOOOOOOOOOOOOO+O+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+O+++++++++++++++++O+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+OOOOOOOOOOOOOOOOOOO+O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+O+++++++++++++++++++++O+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+OOOOOOOOOOOOOOOOOOOOOOO+O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+O+++++++++++++++++++++++++O+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+OOOOOOOOOOOOOOOOOOOOOOOOOOO+O+O+O+O+O+O\n"
														"O+O+O+O+O+O+++++++++++++++++++++++++++++O+O+O+O+O+O\n"
														"O+O+O+O+O+OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO+O+O+O+O+O\n"
														"O+O+O+O+O+++++++++++++++++++++++++++++++++O+O+O+O+O\n"
														"O+O+O+O+OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO+O+O+O+O\n"
														"O+O+O+O+++++++++++++++++++++++++++++++++++++O+O+O+O\n"
														"O+O+O+OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO+O+O+O\n"
														"O+O+O+++++++++++++++++++++++++++++++++++++++++O+O+O\n"
														"O+O+OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO+O+O\n"
														"O+O+++++++++++++++++++++++++++++++++++++++++++++O+O\n"
														"O+OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO+O\n"
														"O+++++++++++++++++++++++++++++++++++++++++++++++++O\n"
														"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"));

	// big square
	CHECK(nospaces(mat(101, 101, '>', '-')) == nospaces(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"
														">--------------------------------------------------------------------------------------------------->\n"
														">->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->\n"
														">->----------------------------------------------------------------------------------------------->->\n"
														">->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->\n"
														">->->------------------------------------------------------------------------------------------->->->\n"
														">->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->\n"
														">->->->--------------------------------------------------------------------------------------->->->->\n"
														">->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->\n"
														">->->->->----------------------------------------------------------------------------------->->->->->\n"
														">->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->\n"
														">->->->->->------------------------------------------------------------------------------->->->->->->\n"
														">->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->\n"
														">->->->->->->--------------------------------------------------------------------------->->->->->->->\n"
														">->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->\n"
														">->->->->->->->----------------------------------------------------------------------->->->->->->->->\n"
														">->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->\n"
														">->->->->->->->->------------------------------------------------------------------->->->->->->->->->\n"
														">->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->\n"
														">->->->->->->->->->--------------------------------------------------------------->->->->->->->->->->\n"
														">->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->\n"
														">->->->->->->->->->->----------------------------------------------------------->->->->->->->->->->->\n"
														">->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->\n"
														">->->->->->->->->->->->------------------------------------------------------->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->--------------------------------------------------->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->----------------------------------------------->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->------------------------------------------->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->--------------------------------------->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->----------------------------------->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->------------------------------->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->--------------------------->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->----------------------->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->------------------->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->->>>>>>>>>>>>>>>>>->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->->--------------->->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->->->>>>>>>>>>>>>->->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->->->----------->->->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->->->->>>>>>>>>->->->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->->->->------->->->->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->->->->->>>>>->->->->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->->->->->--->->->->->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->->->->->--->->->->->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->->->->->>>>>->->->->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->->->->------->->->->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->->->->>>>>>>>>->->->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->->->----------->->->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->->->>>>>>>>>>>>>->->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->->--------------->->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->->>>>>>>>>>>>>>>>>->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->------------------->->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->----------------------->->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->--------------------------->->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->------------------------------->->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->----------------------------------->->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->--------------------------------------->->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->------------------------------------------->->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->----------------------------------------------->->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->--------------------------------------------------->->->->->->->->->->->->->\n"
														">->->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->->\n"
														">->->->->->->->->->->->------------------------------------------------------->->->->->->->->->->->->\n"
														">->->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->->\n"
														">->->->->->->->->->->----------------------------------------------------------->->->->->->->->->->->\n"
														">->->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->->\n"
														">->->->->->->->->->--------------------------------------------------------------->->->->->->->->->->\n"
														">->->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->->\n"
														">->->->->->->->->------------------------------------------------------------------->->->->->->->->->\n"
														">->->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->->\n"
														">->->->->->->->----------------------------------------------------------------------->->->->->->->->\n"
														">->->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->->\n"
														">->->->->->->--------------------------------------------------------------------------->->->->->->->\n"
														">->->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->->\n"
														">->->->->->------------------------------------------------------------------------------->->->->->->\n"
														">->->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->->\n"
														">->->->->----------------------------------------------------------------------------------->->->->->\n"
														">->->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->->\n"
														">->->->--------------------------------------------------------------------------------------->->->->\n"
														">->->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->->\n"
														">->->------------------------------------------------------------------------------------------->->->\n"
														">->->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->->\n"
														">->----------------------------------------------------------------------------------------------->->\n"
														">->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>->\n"
														">--------------------------------------------------------------------------------------------------->\n"
														">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"));

	// wide big rectangle
	CHECK(nospaces(mat(101, 31, 'X', '~')) == nospaces( "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n"
														"X~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~X\n"
														"X~XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX~X\n"
														"X~X~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~X~X\n"
														"X~X~XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX~X~X\n"
														"X~X~X~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~X~X~X\n"
														"X~X~X~XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX~X~X~X\n"
														"X~X~X~X~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~X~X~X~X\n"
														"X~X~X~X~XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX~X~X~X~X\n"
														"X~X~X~X~X~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~X~X~X~X~X\n"
														"X~X~X~X~X~XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX~X~X~X~X~X\n"
														"X~X~X~X~X~X~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~X~X~X~X~X~X\n"
														"X~X~X~X~X~X~XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX~X~X~X~X~X~X\n"
														"X~X~X~X~X~X~X~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~X~X~X~X~X~X~X\n"
														"X~X~X~X~X~X~X~XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX~X~X~X~X~X~X~X\n"
														"X~X~X~X~X~X~X~X~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~X~X~X~X~X~X~X~X\n"
														"X~X~X~X~X~X~X~XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX~X~X~X~X~X~X~X\n"
														"X~X~X~X~X~X~X~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~X~X~X~X~X~X~X\n"
														"X~X~X~X~X~X~XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX~X~X~X~X~X~X\n"
														"X~X~X~X~X~X~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~X~X~X~X~X~X\n"
														"X~X~X~X~X~XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX~X~X~X~X~X\n"
														"X~X~X~X~X~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~X~X~X~X~X\n"
														"X~X~X~X~XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX~X~X~X~X\n"
														"X~X~X~X~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~X~X~X~X\n"
														"X~X~X~XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX~X~X~X\n"
														"X~X~X~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~X~X~X\n"
														"X~X~XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX~X~X\n"
														"X~X~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~X~X\n"
														"X~XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX~X\n"
														"X~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~X\n"
														"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"));

	// tall big rectangle
	CHECK(nospaces(mat(31, 101, '|', ':')) == nospaces( "|||||||||||||||||||||||||||||||\n"
														"|:::::::::::::::::::::::::::::|\n"
														"|:|||||||||||||||||||||||||||:|\n"
														"|:|:::::::::::::::::::::::::|:|\n"
														"|:|:|||||||||||||||||||||||:|:|\n"
														"|:|:|:::::::::::::::::::::|:|:|\n"
														"|:|:|:|||||||||||||||||||:|:|:|\n"
														"|:|:|:|:::::::::::::::::|:|:|:|\n"
														"|:|:|:|:|||||||||||||||:|:|:|:|\n"
														"|:|:|:|:|:::::::::::::|:|:|:|:|\n"
														"|:|:|:|:|:|||||||||||:|:|:|:|:|\n"
														"|:|:|:|:|:|:::::::::|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|||||||:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:::::|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|||:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|:|:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:|||:|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|:::::|:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:|||||||:|:|:|:|:|:|\n"
														"|:|:|:|:|:|:::::::::|:|:|:|:|:|\n"
														"|:|:|:|:|:|||||||||||:|:|:|:|:|\n"
														"|:|:|:|:|:::::::::::::|:|:|:|:|\n"
														"|:|:|:|:|||||||||||||||:|:|:|:|\n"
														"|:|:|:|:::::::::::::::::|:|:|:|\n"
														"|:|:|:|||||||||||||||||||:|:|:|\n"
														"|:|:|:::::::::::::::::::::|:|:|\n"
														"|:|:|||||||||||||||||||||||:|:|\n"
														"|:|:::::::::::::::::::::::::|:|\n"
														"|:|||||||||||||||||||||||||||:|\n"
														"|:::::::::::::::::::::::::::::|\n"
														"|||||||||||||||||||||||||||||||"));
}