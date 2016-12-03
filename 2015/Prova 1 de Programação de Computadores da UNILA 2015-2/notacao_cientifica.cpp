#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

void process(string str, int s, int pi, int zpv, int f);

int main()
{
    string str;
    int f, s, neg, i, control, vaium, zeroposvirgula;

    while (cin >> str)
    {
        control = 0;
        neg = 0;
        if (str[0] == '-') {
            neg = 1;
            str.erase(str.begin());
        }

        while (str[0]=='0') {
            str.erase(str.begin());
            if (str.empty()) break;
        }

        if (str.empty()) {
            if (neg==1) printf("-0.0000E+00\n");
            else printf("+0.0000E+00\n");
            continue;
        }

        zeroposvirgula = 0;
        if (str[0] == '.') {
            if (str.size()>1) {
                while (str[1]=='0') {
                    zeroposvirgula++;
                    str.erase(str.begin()+1);
                    if (str.size()==1) break; //sobrou so a virgula
                }
            }
            if (str.size()==1) {
                printf("+0.0000E+00\n");
                continue;
            }
        }

        s = str.size();

        (neg)?printf("-"):printf("+");

        if ((f=str.find("."))!=string::npos) {
            if (f>5) {
                process(str, f, 0, -2, -2);
            } else if (f==5) {
                if (s>=6) process(str, f, 1, -2, -2);
                else process(str, f, 0, -2, -2);
            } else {
                if (f==0) {
                    str = str.substr(1, str.size()-1);
                    s = str.size();
                    control = 1;
                    goto mylabel;
                } else {
                    str.erase(f, 1);
                    s = str.size();
                    //cout << str << " " << s << endl;
                    control = 2;
                    goto mylabel;
                }
            }
        } else {
            mylabel:
            if (s==5) {
                if (control == 1)
                    printf("%c.%c%c%c%cE-%02d\n", str[0], str[1], str[2], str[3], str[4], zeroposvirgula+1);
                else if (control == 2)
                    printf("%c.%c%c%c%cE+%02d\n", str[0], str[1], str[2], str[3], str[4], f-1);
                else
                    printf("%c.%c%c%c%cE+04\n", str[0], str[1], str[2], str[3], str[4]);
            } else if (s>5) {
                if (control == 1)
                    process(str, s, 0, zeroposvirgula, -2);
                else if (control == 2)
                    process(str, s, 0, -2, f);
                else
                    process(str, s, 0, -2, -2);
            } else {
                printf("%c.", str[0]);
                for (i=1; i<s; i++) printf("%c", str[i]);
                for (; i<5; i++) printf("0");
                if (control == 1)
                    printf("E-%02d\n", zeroposvirgula+1);
                else if (control == 2)
                    printf("E+%02d\n", f-1);
                else
                    printf("E+%02d\n", s-1);
            }
        }
    }

    return 0;
}

void process(string str, int s, int pi, int zpv, int f)
{
    //cout << " opa" << endl;
    int vaium, i;

    str[pi+5]>='5'?vaium = 1: vaium = 0;
    for (i=4; i>=0; i--)
    {
        if (vaium) {
            if (str[i]=='9') {
                str[i]='0', vaium = 1;
                continue;
            } else {
                 str[i]++, vaium = 0;
            }
        }
    }

    if (vaium) {
        str.insert(0, "1");
        s++;
        zpv++;
        f++;
    }

    if (zpv < 0) {
        if (f >= 0)
            printf("%c.%c%c%c%cE+%02d\n", str[0], str[1], str[2], str[3], str[4], f-1);
        else
            printf("%c.%c%c%c%cE+%02d\n", str[0], str[1], str[2], str[3], str[4], s-1);
    }
    else {
        if (zpv-1==0)
            printf("%c.%c%c%c%cE+%02d\n", str[0], str[1], str[2], str[3], str[4], zpv-1);
        else
            printf("%c.%c%c%c%cE-%02d\n", str[0], str[1], str[2], str[3], str[4], zpv-1);
    }


}