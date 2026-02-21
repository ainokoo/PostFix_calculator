#include <iostream>
#include "utility.h"
#include "calc.h"


using namespace std;

char get_command()
{
   char command;
   bool waiting = true;
   cout << "Select command and press <Enter>:";

   while (waiting) {
      cin >> command;
      command = tolower(command);
      if (command == '?' || command == '=' || command == '+' ||
          command == '-' || command == '*' || command == '/' ||
          command == 'q' || command == 'x' || command == 's' ) waiting = false;


      else {
         cout << "Please enter a valid command:"   << endl
              << "[?]push to stack   [=]print top" << endl
              << "[+] [-] [*] [/]   are arithmetic operations" << endl
              << "If you want to change the order of the calculated numbers, " << endl
              << "enter [x] before arithmetic operator. " << endl
              << "You can also get the total value of the stack calculated to a single number by entering [s]" << endl
              << "[Q]uit." << endl;
      }
   }
   return command;
}


bool do_command(char command, Stack &numbers)
/*
Pre:  The first parameter specifies a valid calculator command.
Post: The command specified by the first parameter
      has been applied to the Stack of numbers given by the second parameter.
      A result of true is returned unless command == 'q'.
Uses: The class Stack.
*/

{
double p, q;
double total = 0;

switch (command) {

    case 's': // kaikki stackin luvut yhteen

 

    while (!numbers.empty()) {
        numbers.top(p);
        total += p;
        numbers.pop();
    }
    numbers.push(total);

    break;

    case 'x': //ota pois, laita uudestaan
        if (numbers.top(p) == underflow) {
        cout << "Stack empty" << endl;
        } else {
          numbers.pop();
          if (numbers.top(q) == underflow) {
            cout << "Stack has only one entry" << endl;
            numbers.push(p); 
          } else {
            numbers.pop();
            if (numbers.push(p) == overflow) 
                cout << "Stack is full, lost number" << endl;
            if (numbers.push(q) == overflow)
                cout << "Stack is full, lost number" << endl;
          }
        }

    break;

    case '?':
      cout << "Enter a real number: " << flush;
      cin >> p;
        if (numbers.push(p) == overflow)
            cout << "Warning: Stack full, lost number" << endl;
    break;

    case '=':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else
            cout << p << endl;
    break;

    case '+':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
         }

        else {
            numbers.pop();
            if (numbers.push(q + p) == overflow)
               cout << "Warning: Stack full, lost result" << endl;
         }
      }
      break;

    case '-':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has only one entry" << endl;
                numbers.push(p);
        }

        else {
            numbers.pop();
            if (numbers.push(q - p) == overflow) 
                cout << "Warning: Stack full, lost result" << endl;
            
        }
      }
    break;

    case '*':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
         else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has only one entry" << endl;
                numbers.push(p);
        }

        else {
            numbers.pop();
            if (numbers.push(q * p) == overflow) 
                cout << "Warning: Stack full, lost result" << endl;
            
        }
      }
    break;

    case '/':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has only one entry" << endl;
                numbers.push(p);
        }

        else {
            numbers.pop();
            if (numbers.push(q / p) == overflow) 
                cout << "Warning: Stack full, lost result" << endl;
            
        }
      }
    break;

    case 'q':
      cout << "Calculation finished.\n";
      return false;
   }
   return true;
}


Stack::Stack() {
    count = 0;
}

bool Stack::empty() const {
    return count == 0;
}

Error_code Stack::push(const Stack_entry &item) {
    if (count >= maxstack)
        return Error_code::overflow;
    entry[count++] = item;
    return Error_code::success;
}

Error_code Stack::pop() {
    if (count == 0)
        return Error_code::underflow;
    --count;
    return Error_code::success;
}

Error_code Stack::top(Stack_entry &item) const {
    if (count == 0)
        return Error_code::underflow;
    item = entry[count - 1];
    return Error_code::success;
}

