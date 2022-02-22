//Problem source https://github.com/KOLXOZHIK/algorithms
//Author: KOLHOZNIK

#include <iostream>
#include <stack>

using namespace std;

bool is_opening(const char& c) 
{
    if(c == '(' || c == '{' || c == '[')
	return true;
    return false;
}
bool is_closing(const char& c) 
{
    if(c == ')' || c == '}' || c == ']')
	return true;
    return false;
}
bool is_match(const char& c1, const char& c2) 
{
    if(c1=='(' && c2==')')
	return true;
    if(c1=='{' && c2=='}')
	return true;
    if(c1=='[' && c2==']')
	return true;
    return false;
}

bool check_parenthesis(const string& s)
{
    bool res = false;
    int n = s.size();
    stack<char> b;
    for(int i =0; i<n; i++)
    {
	if(is_opening(s[i]))
	{
		b.push(s[i]);
	}
	if(is_closing(s[i])) 
	{
		if(b.empty() || !is_match(b.top(), s[i]))
		{
			return false;
	        }
	        else b.pop();
	}	
    }
    return b.empty();
}

int main(int argc, char** argv) 
{
    if(argc != 2)
	cout << "Usage: check_brackets string\n";
    else
    {
         string s(argv[1]);    
	   if(check_parenthesis(s))
		cout << s << " is valid\n";
	   else
	        cout << s << " is not valid\n";
    }
}
