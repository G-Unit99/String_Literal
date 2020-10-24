#include <iostream>
#include <string>
#include <cmath>

using namespace std;
void Is_literal(string);
bool Check_exponent(string);
bool Check_decimal(string);
bool Check_symbol(string);
bool Check_error(string);


int main()
{
    bool a;
    string test = "12a3";
    cout << a << endl;
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
        cout << " is NOT a valid numeric literal" << endl;
    }

    else
    {
        cout << "is a valid numeric literal" << endl;
    }
}

bool Check_exponent(string number)
{
    for (int i = 0; i < number.length();i++)
    {

    }
}

bool Check_decimal(string number)
{

}

bool Check_symbol(string number)
{

}

bool Check_error(string number)
{
    bool literal;
    const int max = 50;
    int length = number.length();

    if (length > max)
    {
        cout << "false";
        return !literal;
    }



    for (int i = 0; i < length; i++)
    {
//check beginning inputs for errors, such as starting with an exponent or a symbol other than + or -//
        if (i == 0)
        {
            if (!isdigit(number[0]) && number[0] != '+' && !isdigit(number[0]) && number[0] != '-')
            {
                cout << "false 1";
                return !literal;
            }
        }
//check if program can detect an input that is not a number or an exponent
        else if (!isdigit(number[i]) && number[i] != 'e' && number[i] != 'E')
        {
            cout<< "false 2";
            return !literal;
        }

        else if ( i == 1)
        {

        }
    }

    cout <<" valid" <<endl;
    return literal;
}
