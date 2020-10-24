#include <iostream>
#include <string>
using namespace std;
#include<string.h>
#include<stack>
int countBracketReversals(char input[]){
int len=strlen(input);
    stack<char> s;
    if(len%2!=0)
        return -1;
    else
    {
        for(int i=0;i<len;i++)
        {
            if(input[i]=='{')
            {
                s.push(input[i]);
            }
            else if(input[i]=='}')
            {
                if(s.empty())
                    s.push(input[i]);
                else if(s.top()=='}')
                    s.push(input[i]);
                else
                    s.pop();
            }
        }
        if(s.empty())
            return 0;
        else
        {
            int count=0;
            int c=s.size();
            for(int i=0;i<c/2;i++)
            {
            char c1=s.top();
            s.pop();
            char c2=s.top();
            s.pop();
                if(c1==c2)
                {
                   count++;  
                }
                else
                    count=count+2;
            }   
          return count;                
        }       
    }
}


int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}
