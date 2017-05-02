#include <bits/stdc++.h>

using namespace std;
    
int main()
{
    int t;
    stack<char> s;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> str;
        int ans = 1;

        for (int i = 0; i < str.size(); i++) 
        {
            //cout << s.size();
            if (str[i] == '(' || str[i] == '[' 
                || str[i] == '{') {
                s.push(str[i]);
            } else {
                if (s.empty()) {
                    ans = 0;
                    break;
                } else {
                    //cout << s.top() << str[i];
                    if (s.top() == '(') {
                        if (str[i] == ')') 
                            s.pop();
                        else {
                            ans = 0;
                            break;
                        }
                    } else if (s.top() == '{') {
                        if (str[i] == '}')
                            s.pop();
                        else {
                            ans = 0;
                            break;
                        }
                    } else {
                        if (str[i] == ']')
                            s.pop();
                        else {
                            ans = 0;
                            break;
                        }
                    }
                }
            }
        }

        //cout << s.size();
        if (!s.empty()) ans = 0;
        while (!s.empty()) s.pop();

        cout << (ans ? "S" : "N") <<endl;
    }


    return 0;
}