#include <iostream>
#include <map>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    string str;
    bool ASCII[26];
    int i, n, j, q;

    cin >> n;
    getchar();
    for (j=0; j<n; j++)
    {
        getline(cin, str);
        for (i=0; i<26; i++)
            ASCII[i] = 0;

        for (i=0; i<str.size(); i++){
            if (str[i]-'a'>=0 && str[i]-'a' <=25)
            ASCII[str[i]-'a'] = 1;
        }

        q = 0;
        for (i=0; i<26; i++){
            if (ASCII[i])
                q++;
        }

        if (q==26)
            cout << "frase completa" << endl;
        else if (q>=13)
            cout << "frase quase completa" << endl;
        else
            cout << "frase mal elaborada" << endl;
    }


    return 0;
}