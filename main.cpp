#include <iostream>
#include <string>

using namespace std;
void Is_literal(string);
bool Check_error(string);


int main()
{
    string test = "3";
    cout << "Hello, World!" << endl;
    for (int i = 0; i < test.length();i++){
        cout << isdigit(test[i]) << endl;
    }

    cout<< Check_error(test);
    return 0;
}

void Is_literal(string number)
{
    if (!Check_error(number))
    {
        cout << number << " is NOT a valid numeric literal" << endl;
    }

    else
    {
        cout << number << " is a valid numeric literal" << endl;
    }
}

bool Check_error(string number)
{
    bool literal;
    const int max = 50;
    int decimal_count = 0;
    int length = number.length();
//Check terminating cases that do not require iterating through the string//

//Checks if string length is over 50 characters long//
    if (length > max)
    {
        cout << "false";
        return !literal;
    }
//checks if program ends with an exponent symbol, starts with an exponent symbol, or ends with a unary symbol +/- //
    if (number[length - 1] == 'e' || number[length -1] == 'E'|| number[length -1] == '+' || number[length- 1] == '-' || number[0] == 'e' || number[0] == 'E')
    {
        cout << "false 1";
        return !literal;
    }

    for (int i = 0; i < length; i++)
    {
        cout << i << length<< endl;
//check if program can detect an input that is not a number, an exponent, a decimal, or unary symbol +/- //
        if (!isdigit(number[i]) && number[i] != 'e' && number[i] != 'E' && number[i] != '.' && number[i] != '+' && number[i] != '-')
        {
            cout << "false 2";
            return !literal;
        }
//checks for decimals in the program//
        else if (number[i] == '.')
        {
            if (decimal_count > 0)
            {
                cout << "false 3";
                return !literal;
            }
            else
            {
                decimal_count += 1;
            }
        }
//Checks for exponents//
        else if (number[i] == 'e' || number[i] == 'E')
        {
//Check that an exponent symbol is not followed by another exponent symbol//
            if (number[i + 1] == 'e' || number[i + 1] == 'E')
            {
                cout<< "false 4";
                return !literal;
            }
            else if (number[i + 1] == '+' || number[i + 1] == '-')
            {
                if (!isdigit(number[i +2]))
                {
                    cout << "false 5";
                    return !literal;
                }
            }
        }
//Check for +/- symbols//
        else if (number[i] == '+' || number[i] == '-')
        {
            if (number[i +1] == '+' || number[i +1] == '-')
            {
                cout << "false 6";
                return !literal;
            }
        }

    }

    cout <<" valid" << endl;
    return literal;
}
