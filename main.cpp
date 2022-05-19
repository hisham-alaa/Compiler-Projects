#include <iostream>
#include<string>
#include<fstream>
using namespace std;
ifstream infile("input.txt");
ofstream outfile("output.txt");
string dig(char c,string s)
{
    while(isdigit(c))
    {
        s+=c;
        c=infile.get();
    }
    return s;
}
int main()
{
    string s="";
    int x=0;
    char c;
    while(!infile.eof())
    {
        c=infile.get();
        a:if(c==';')
        {
            outfile<<"< semicolon >"<<endl;
        }
        if(c=='(')
        {
            outfile<<"< open_paranthesis >"<<endl;
        }
        if(c==')')
        {
            outfile<<"< closed_paranthesis >"<<endl;
        }
        if(c=='{')
        {
            outfile<<"< open_pracket >"<<endl;
        }
        if(c=='}')
        {
            outfile<<"< closed_pracket >"<<endl;
        }
        if(isdigit(c))
        {
            x=(c-'0');
            c=infile.get();
            while(isdigit(c))
            {
                cout<<"c = "<<c<<"\tx = "<<x<<endl;
                x*=10;
                x+=(c-'0');
                c=infile.get();
            }
            cout<<"c = "<<c<<endl;
            cout<<"x = "<<x<<endl;
            outfile<<"< number, "<<x<<" >"<<endl;
            x=0;
            goto a;
        }
        if(isalpha(c))
        {
           z: while(isalpha(c))
            {
                s+=c;
                c=infile.get();
            }
            if(s=="for")
            {
                outfile<<"< for_iteration >"<< "\n";
            }
            else if(s=="int"||s=="float"||s=="double"||s=="bool"||s=="char"||s=="string")
            {
                outfile<<"< data type >"<< "\n";
            }
            else 
            {
                if(c=='+'||c=='-'||c=='*'||c=='/')
                {
                    if(c=='+')
                    {
                        c=infile.get();
                        if(c=='+')
                        {
                            outfile<<"< increment "<<s<<", 1 >"<<endl;
                        }
                        if(c=='=')
                        {
                            c=infile.get();
                            if(isdigit(c))
                            {
                                while(isdigit(c))
                                {
                                    x*=10;
                                    x+=c-'0';
                                    c=infile.get();
                                }
                                outfile<<"< increment "<<s<<", "<<x<<" >"<<endl;
                                x=0;
                            }
                        }
                    }
                    else if(c=='-')
                    {
                        c=infile.get();
                        if(c=='-')
                        {
                            outfile<<"< decrement "<<s<<", 1 >"<<endl;
                        }
                        if(c=='=')
                        {
                            c=infile.get();
                            if(isdigit(c))
                            {
                                while(isdigit(c))
                                {
                                    x*=10;
                                    x+=c-'0';
                                    c=infile.get();
                                }
                                outfile<<"< decrement "<<s<<", "<<x<<" >"<<endl;
                                x=0;
                            }
                        }
                    }
                    else if(c=='*')
                    {
                        c=infile.get();
                        if(c=='=')
                        {
                            c=infile.get();
                            if(isdigit(c))
                            {
                                while(isdigit(c))
                                {
                                    x*=10;
                                    x+=c-'0';
                                    c=infile.get();
                                }
                                outfile<<"< duplicate "<<s<<", "<<x<<" >"<<endl;
                                x=0;
                            }
                        }
                    }
                    else if(c=='/')
                    {
                        c=infile.get();
                        if(c=='=')
                        {
                            c=infile.get();
                            if(isdigit(c))
                            {
                                while(isdigit(c))
                                {
                                    x*=10;
                                    x+=c-'0';
                                    c=infile.get();
                                }
                                outfile<<"< divide "<<s<<", "<<x<<" >"<<endl;
                                x=0;
                            }
                        }
                    }
                }
                else if(c=='<'||c=='>'||c=='!'||c=='=')
                {
                    outfile<<"< identifier, "<<s<<" >"<<endl;
                    if(c=='<')
                    {
                        c=infile.get();
                        if(c=='=')
                        {
                            outfile<<"< relop_LE >"<<endl;
                        }
                        else outfile<<"< relop_LT >"<<endl;
                    }
                    else if(c=='>')
                    {
                        c=infile.get();
                        if(c=='=')
                        {
                            outfile<<"< relop_GE >"<<endl;
                        }
                        else outfile<<"< relop_GT >"<<endl;
                    }
                    else if(c=='!')
                    {
                        c=infile.get();
                        if(c=='=')
                        {
                            outfile<<"< relop_NE >"<<endl;
                        }
                    }
                    else if(c=='=')
                    {
                        c=infile.get();
                        if(c=='=')
                        {
                            outfile<<"< relop_EQ >"<<endl;
                        }
                        else 
                        {
                            outfile<<"< assignment >"<<endl;
                            cout<<"\tc = "<<c<<endl;
                        }
                    }
                }
                else if(isdigit(c))
                {
                    s+=c;
                    c=infile.get();
//                    s+=dig(c,s);
                    goto z;
                }
                else outfile<<"< identifier, "<<s<<" >"<<endl;
            }
            s="";
            goto a;
        }
    }
    infile.close();
    outfile.close();
    return 0;
}