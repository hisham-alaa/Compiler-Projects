#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    ifstream i("in.txt");
    ofstream o("out.txt");
    
    int ldig=0;
    bool digit = false, plus = false, mult = false, incre = false, decre = false;
    string s,lastsymbol = "";
    char ch;

    i >> ch;
    while (!i.eof())
    {
        up:
        if (isdigit(ch)&& !digit) {
            s = "";
            while (isdigit(ch) && !i.eof()) {
                s += ch;
                i >> ch;
            }
            ldig = stoi(s);
            digit = true;
            decre = incre = mult = plus = incre = decre = false;
            goto up;
        }

        else if (ch == '+') {
            s = "";
            while (ch == '+' && !i.eof() && !isspace(ch)) {
                s += ch;
                i >> ch;
            }
            digit = false;
            (s.length() % 2 == 0) ? (incre = true) : (plus = true);
            goto up;
        }

        else if (ch == '-' && (plus || mult)) {
            s = "";
            while (ch == '-' && !i.eof()) {
                s += ch;
                i >> ch;
            }
            digit = false;
            if (s.length() % 2 == 0)
                decre = true;
            else
                goto er;
            goto up;
        }

        else if (ch == '*' && !plus && !mult)
        {
            mult = true;
            digit = false;
        }

        else {
            er:
            cout << endl << "non-valid input in char \'" << ch << "\'" << endl;
            return 0;
        }

        i >> ch;
    }
 
    cout <<endl<<"accepted" << endl;
    i.close();
    o.close();

	return 0;
}