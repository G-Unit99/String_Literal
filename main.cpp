#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
string Is_literal(string, int);
bool Check_error(string);


int main()
{
    int input = 0;
    int file_end =0;
    string file ="";
    string test = "t";

//Get file from user input//
    cout << "Enter a .txt file -> ";
    getline(cin,file);
    cout << endl;
    input = file.length();
//Check that the user inputted a .txt file//
    while (file[input-1] != 't' && file[input -2] != 'x' && file[input-3] != 't'&& file[input - 4] != '.')
    {
        input = 0;
        file = "";

        cout << "Input Error: please enter a .txt file -> ";
        getline(cin,file);
        cout << endl;
        input = file.length();
    }
//Read file//
    ifstream file_(file);
    if (file_.is_open())
    {
       cout << "open" << endl;
       int greatest_length = 0;
       int file_length = 0;
       string line = "";
        while (getline(file_, line))
        {
            file_length += 1;
            if (line.length() > greatest_length)
            {
                greatest_length = line.length();
            }
            file_end = file_length;
        }
//reset line reader//
       file_.clear();
       file_.seekg(0,file_.beg);
       while (getline(file_, line))
        {
            cout << left << setw(greatest_length) << line << Is_literal(line,greatest_length) << "\n";
        }
       cout << "closed" << endl;
       file_.close();
    }
    else
    {
        cout << "file is not open" << endl;
    }

    fstream write(file);
    if (write.is_open())
    {
        cout << "open" << endl;
        int greatest_length = 0;
        string line;

        streambuf *oldbuf = cout.rdbuf();
        cout.rdbuf(file_.rdbuf());
        while (file_end!=0)
        {
            string holder = line;
            write << setw(greatest_length) << holder << Is_literal(holder,greatest_length) << "\n";
            file_end--;
        }
        cout.rdbuf(oldbuf);
        cout << "closed" << endl;
        file_.close();
    }

}

string Is_literal(string number, int length)
{
    int greatest_length = length;
    string result = "";
    if (!Check_error(number))
    {
        result = " is a valid numeric literal";
    }

    else
    {
        result = " is Not a valid numeric literal";
    }
    return result;
}

bool Check_error(string number)
{
    bool literal = 0;
    const int max = 50;
    int decimal_count = 0;
    int length = number.length();
//Check terminating cases that do not require iterating through the string//

//Checks if string length is over 50 characters long//
    if (length > max)
    {
        return !literal;
    }
//checks if program ends with an exponent symbol, starts with an exponent symbol, or ends with a unary symbol +/- //
    if (number[length - 1] == 'e' || number[length -1] == 'E'|| number[length -1] == '+' || number[length- 1] == '-' || number[0] == 'e' || number[0] == 'E')
    {
        return !literal;
    }

    for (int i = 0; i < length; i++)
    {
//check if program can detect an input that is not a number, an exponent, a decimal, or unary symbol +/- //
        if (!isdigit(number[i]) && number[i] != 'e' && number[i] != 'E' && number[i] != '.' && number[i] != '+' && number[i] != '-')
        {
            return !literal;
        }
//checks for decimals in the program//
        else if (number[i] == '.')
        {
            if (decimal_count > 0)
            {
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
                return !literal;
            }
            else if (number[i + 1] == '+' || number[i + 1] == '-')
            {
                if (!isdigit(number[i +2]))
                {
                    return !literal;
                }
            }
        }
//Check for +/- symbols//
        else if (number[i] == '+' || number[i] == '-')
        {
            if (number[i +1] == '+' || number[i +1] == '-')
            {
                return !literal;
            }
        }

    }


    return literal;
}
