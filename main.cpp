
#include <iostream>
#include "utility.h"
#include "calc.h"


using namespace std;

void introduction() {
   cout << "Welcome to the PostFix-calculator" << endl;
}

void instructions() {
   cout << "Start with adding minimum of two numbers to the stack by " << endl;
   cout << "selecting '?'-command followed by the number you choose. " << endl;
   cout << "After entering the numbers, choose the operand '+' '-' '*' '/' 'x' 's' or 'a' " << endl;
   cout << "You can see the latest result by pressing '='" << endl;
}



int main()


{
   Stack stored_numbers;
   introduction();
   instructions();
   while (do_command(get_command(), stored_numbers));
}


