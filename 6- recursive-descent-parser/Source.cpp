#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>


using namespace std;

ifstream in("in.txt");
ofstream out("out.txt");
string s = "";
enum TOKEN {
    OPEN_PARENTHESIS, CLOSE_PARENTHESIS, COMA, END_OF_FILE, COLOR, VERTEX, ERROR
};
TOKEN curtoken;
char ch;

string tokenname(TOKEN t)
{
    if (t == OPEN_PARENTHESIS)return "OPEN_PARENTHESIS";
    else if (t == CLOSE_PARENTHESIS)return "CLOSE_PARENTHESIS";
    else if (t == COMA)return "COMA";
    else if (t == END_OF_FILE)return "END_OF_FILE";
    else if (t == COLOR)return "COLOR";
    else if (t == VERTEX)return "VERTEX";
    return "ERROR";
}

TOKEN Readedtoken()
{
    s = "";
    in.get(ch);

    if (in.eof()) {
        s = "$";
        return END_OF_FILE;
    }

    else if (ch == '(')
    {
        s += ch;
        return OPEN_PARENTHESIS;
    }

    else if (ch == ')')
    {
        s += ch;
        return CLOSE_PARENTHESIS;
    }

    else if (ch == ',')
    {
        s += ch;
        return COMA;
    }

    else if (isdigit(ch)) {
        while (isdigit(ch) && !in.eof()) {
            s += ch;
            in.get(ch);
        }
        in.putback(ch);
        return VERTEX;
    }

    else if (isalpha(ch)) {
        while (isalpha(ch) && !in.eof()) {
            s += ch;
            in.get(ch);
        }
        in.putback(ch);
        if (s == "red" || s == "blue" || s == "green" || s == "white" || s == "yellow") return COLOR;
    }

    return ERROR;
}

void Match(TOKEN t)
{
    if (t == curtoken)
        out << tokenname(curtoken) << "-" << s << endl;
    else
    {
        out << "Error in \'" << tokenname(curtoken) << "-" << s << "\'" << endl;
        return;
    }
    curtoken = Readedtoken();
}


void Graph();
void Graph2();
void Id();
void Id2();
void Num();
void Color();
void Component();


void Begin() {
    curtoken = Readedtoken();
    Graph();
    Match(END_OF_FILE);
}

int main()
{
    Begin();


    system("pause");
    return 0;
}

void Graph() {
    Match(OPEN_PARENTHESIS);
    Id();
    Match(COMA);
    Component();
    Match(CLOSE_PARENTHESIS);
    Graph2();
}

void Graph2() {
    if (curtoken == COMA)
    {
        Match(COMA);
        Graph();
    }
}

void Id() {
    Num();
    Id2();
}

void Id2() {
    if (curtoken == VERTEX)
        Id();
}

void Num() {
    Match(VERTEX);
}

void Component() {
    if (curtoken == VERTEX)
        Id();
    else if (curtoken == COLOR)
        Color();
    else
        out << "Error in \'" << s << "\'" << endl;
}

void Color() {
    Match(COLOR);
}