#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>


using namespace std;

ifstream i("in.txt");
string s;
char ch;

string readedtoken()
{
    i >> ch;

    if (ch == '(')
        return "(";

    else if (isdigit(ch)) {
        s = "";
        while (isdigit(ch) && !i.eof()) {
            s += ch;
            i >> ch;
        }
        return s;
    }

    else if (ch == ',')
        return ",";

    else if (isalpha(ch)) {
        s = "";
        while (isalpha(ch) && !i.eof()) {
            s += ch;
            i >> ch;
        }
        if (s == "red" || s == "blue" || s == "green") return s;

        return "error "+s;
    }

    else if (ch == ')')
        return ")";

    return "error "+ch;
}

string currenttoken() {}
bool match(string readed,string currunt) {}

int main() 
{
    


    

    i.close();
    return 0;
}