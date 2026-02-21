
#include <iostream>
#include "utility.h"
#include "calc.h"


using namespace std;

void introduction() {
   cout << "Welcome to the PostFix-calculator" << endl;
}

void instructions() {
   cout << "Start with adding minimum of two numbers to the stack by " << endl;
   cout << "selecting '?'-command and enter. After that you can enter a real number." << endl;
   cout << "After entering the numbers, choose the operand '+' '-' '*' or '/' " << endl;
   cout << "You can see the latest result by pressing '='" << endl;
}



int main()
/*
Post: The program has executed simple arithmetic
      commands entered by the user.
Uses: The class Stack and the functions
      introduction, instructions, do_command, and get_command.
*/

{
   Stack stored_numbers;
   introduction();
   instructions();
   while (do_command(get_command(), stored_numbers));
}


