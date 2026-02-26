#include <iostream>
#include "utility.h"
#include "calc.h"

using namespace std;

char get_command()
{
    char command;
    bool waiting = true;
    cout << "Select command and press <Enter>:";

    while (waiting)
    {
        cin >> command;
        command = tolower(command);
        if (command == '?' || command == '=' || command == '+' ||
            command == '-' || command == '*' || command == '/' ||
            command == 'q' || command == 'x' || command == 's' ||
            command == 'a')
            waiting = false;

        else
        {
            cout << "Please enter a valid command:" << endl
                 << "[?]push to stack   [=]print top" << endl
                 << "[+] [-] [*] [/]   are arithmetic operations" << endl
                 << "If you want to change the order of the calculated numbers, " << endl
                 << "enter [x] before arithmetic operator. " << endl
                 << "You can also get the total value of the stack calculated to a single number by entering [s]" << endl
                 << "If you want to calculate the mean, enter [a]" << endl
                 << "[Q]uit." << endl;
        }
    }
    return command;
}

bool do_command(char command, Stack &numbers)

{
    double p, q;

    switch (command)
    {

    case 'a': // keskiarvo
    {
        if (numbers.empty())
        {
            cout << "Stack is empty" << endl;
            break;
        }

        double total = 0;
        int number_count = 0;

        while (!numbers.empty())
        {
            numbers.top(p);
            total += p;
            numbers.pop();
            number_count++;
        }

        double mean = total / number_count;
        numbers.push(mean);
    }
    break;

    case 's': // kaikki stackin luvut yhteen
    {
        if (numbers.empty())
        {
            cout << "Stack is empty" << endl;
            break;
        }

        double total = 0;

        while (!numbers.empty())
        {
            numbers.top(p);
            total += p;
            numbers.pop();
        }
        numbers.push(total);
    }
    break;

    case 'x': // vaihtaa laskettavat arvot päikseen
        if (numbers.top(p) == underflow)
        {
            cout << "Stack empty" << endl;
        }
        else
        {
            numbers.pop();
            if (numbers.top(q) == underflow)
            {
                cout << "Stack has only one entry" << endl;
                numbers.push(p);
            }
            else
            {
                numbers.pop();
                if (numbers.push(p) == overflow)
                    cout << "Stack is full, lost number" << endl;
                if (numbers.push(q) == overflow)
                    cout << "Stack is full, lost number" << endl;
            }
        }

        break;

    case '?':
        cin >> p;
        cout << "Entered number: " << p << endl;
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
        else
        {
            numbers.pop();
            if (numbers.top(q) == underflow)
            {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else
            {
                numbers.pop();
                if (numbers.push(q + p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;

    case '-':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else
        {
            numbers.pop();
            if (numbers.top(q) == underflow)
            {
                cout << "Stack has only one entry" << endl;
                numbers.push(p);
            }

            else
            {
                numbers.pop();
                if (numbers.push(q - p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;

    case '*':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else
        {
            numbers.pop();
            if (numbers.top(q) == underflow)
            {
                cout << "Stack has only one entry" << endl;
                numbers.push(p);
            }

            else
            {
                numbers.pop();
                if (numbers.push(q * p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;

    case '/':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else
        {
            numbers.pop();
            if (numbers.top(q) == underflow)
            {
                cout << "Stack has only one entry" << endl;
                numbers.push(p);
            }

            else
            {
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

Stack::Stack()
{
    count = 0;
}

bool Stack::empty() const
{
    return count == 0;
}

Error_code Stack::push(const Stack_entry &item)
{
    if (count >= maxstack)
        return Error_code::overflow;
    entry[count++] = item;
    return Error_code::success;
}

Error_code Stack::pop()
{
    if (count == 0)
        return Error_code::underflow;
    --count;
    return Error_code::success;
}

Error_code Stack::top(Stack_entry &item) const
{
    if (count == 0)
        return Error_code::underflow;
    item = entry[count - 1];
    return Error_code::success;
}
