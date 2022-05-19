/*#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;
int main() {

    ifstream i("in.txt");
    ofstream o("out.txt");

    bool opened = false, coma = false, ftaken = false, staken = false;
    int nums[20] = { 0 }, nds = 0, clr = 0;
    string colors[20], s;
    char ch;

    i >> ch;
    while (!i.eof())
    {
        if (ch == '(' && !opened && !coma) {
            o << "< open parenthesis >" << endl;
            opened = true;
            coma = true;
            ftaken = false;
            staken = false;
        }

        else if (isdigit(ch) && opened && (!ftaken || !staken)) {
            s = "";
            while (isdigit(ch)) {
                s += ch;
                cout << ch;
                i >> ch;
            }
            nums[nds++] = stoi(s);
            o << "< node num , " << s << " >" << endl;
            (!ftaken) ? (ftaken = true) : (staken = true);
            continue;
        }

        else if (ch == ',' && coma && ftaken) {
            o << "< coma >" << endl;
            coma = false;
        }

        else if (isalpha(ch) && opened && ftaken && !staken) {
            s = "";
            while (isalpha(ch)) {
                s += ch;
                cout << ch;
                i >> ch;
            }
            colors[clr++] = s;
            o << "< color , " << s << " >" << endl;
            staken = true;
            continue;
        }

        else if (ch == ')' && opened && staken) {
            o << "< close parenthesis >" << endl;
            opened = false;
            coma = true;
        }

        else {
            cout << endl << "non-valid input in char \'" << ch << "\'" << endl;
            return 0;
        }

        cout << ch;
        i >> ch;
    }

    sort(nums, nums + nds);
    cout << endl << endl << "Nodes are : " << nums[0] << "  ";
    for (int i = 1; i < nds; i++)
        if (nums[i - 1] != nums[i])
            cout << nums[i] << "  ";

    sort(colors, colors + clr);
    cout << endl << endl << "Colors are : " << colors[0] << "  ";
    for (int i = 1; i < clr; i++)
        if (colors[i - 1] != colors[i])
            cout << colors[i] << "  ";

    cout << endl;
    i.close();
    o.close();
    return 0;
}
*/



// scannar 

/*
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;
int main() {

    ifstream i("in.txt");
    ofstream o("out.txt");
    int nums[20] = { 0 }, nds = 0, clr = 0;
    string colors[20], s;
    char ch;

    i >> ch;
    while (!i.eof())
    {
        if (ch == '(')
            o << "< open parenthesis >" << endl;

        else if (isdigit(ch)) {
            s = "";
            while (isdigit(ch) && !i.eof()) {
                s += ch;
                cout << ch;
                i >> ch;
            }
            nums[nds++] = stoi(s);
            o << "< node num , " << s << " >" << endl;
            continue;
        }

        else if (ch == ',')
            o << "< coma >" << endl;

        else if (isalpha(ch)) {
            s = "";
            while (isalpha(ch) && !i.eof()) {
                s += ch;
                cout << ch;
                i >> ch;
            }
            colors[clr++] = s;
            o << "< color , " << s << " >" << endl;
            continue;
        }

        else if (ch == ')')
            o << "< close parenthesis >" << endl;

        else {
            cout << endl << "non-valid input in char \'" << ch << "\'" << endl;
            return 0;
        }

        cout << ch;
        i >> ch;
    }

    sort(nums, nums + nds);
    cout << endl << endl << "Nodes are : " << nums[0] << "  ";
    for (int i = 1; i < nds; i++)
        if (nums[i - 1] != nums[i])
            cout << nums[i] << "  ";

    sort(colors, colors + clr);
    cout << endl << endl << "Colors are : " << colors[0] << "  ";
    for (int i = 1; i < clr; i++)
        if (colors[i - 1] != colors[i])
            cout << colors[i] << "  ";

    cout << endl;
    i.close();
    o.close();
    return 0;
}
*/



//a Scannar for generating the stream of tokens for coloring graph 
//using 2d Array to implement table driven

/*
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
string s = "";
ifstream i("in.txt");
ofstream o("out.txt");

int val=0,curstate = 0,
    trans_table[3][5] = {   {1,2,3,4,5},
                            {6,6,6,4,6},
                            {7,7,7,7,5} };

void whichstate(char ch)
{
        if (ch == '(')
            curstate = trans_table[val][0];
        else if(ch==')')
            curstate = trans_table[val][1];
        else if(ch==',')
            curstate = trans_table[val][2];
        else if (isdigit(ch))
        {
            s += ch;
            val = 1;
            curstate = trans_table[val][3];
        }
        else if (isalpha(ch))
        {
            s += ch;
            val = 2;
            curstate = trans_table[val][4];
            if (i.eof())
                curstate = 7;
        }
        else
            curstate = -1;
}

int main() {
    char ch;

    i >> ch;
    while (!i.eof())
    {
 up:
        whichstate(ch);
        switch (curstate)
        {
        case 1:
            o << "Open parenthesis, '(' \n";
            val = 0;
            break;
        case 2:
            o << "Close parenthesis, ')' \n";
            val = 0;
            break;
        case 3:
            o << "Coma, ',' \n";
            val = 0;
            break;
        case 6:
            o << "Vertex, "+s+"\n";
            s = "";
            val = 0;
            goto up;
            break;
        case 7:
            o << "Color, " + s + " \n";
            s = "";
            val = 0;
            goto up;
            break;
        case -1:
            o << "Error \n";
            break;
        }

        i >> ch;
    }
    if (isdigit(ch))
        o << "vertex, "<<s<< " " << endl;
    else if (isalpha(ch))
        o << "color, " << s << " " << endl;


    cout << endl;
    i.close();
    o.close();
    return 0;
}
*/