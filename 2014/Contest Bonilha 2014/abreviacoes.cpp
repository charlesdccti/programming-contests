#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>

using namespace std;

#define MAX 10010

typedef pair<string, int> psi;//name size

int main()
{
    char phrase[MAX], phrase_cpy[MAX], *aux;
    string str;
    map<string, int>word_ocur;
    map<string, int>::iterator si_it;
    map<char, psi>abrv;
    map<char, psi>::iterator csi_it;
    set<string> abreviations;
    set<string>::iterator sit;

    while(cin.getline(phrase, MAX))
    {
        if(phrase[0]=='.') break;

        strcpy(phrase_cpy, phrase);

        word_ocur.clear();
        abrv.clear();
        abreviations.clear();

        aux = strtok(phrase, " ");
        while(aux!=NULL){
            word_ocur[(string)aux]++;
            aux = strtok(NULL, " ");
        }

        char key = word_ocur.begin()->first[0];

        for(si_it=word_ocur.begin(); si_it!=word_ocur.end(); si_it++)
        {
            if(si_it->first[0] != key)
                key = si_it->first[0];

            int size = (si_it->second)*((si_it->first).size()-2);
            if(size>0){
                if(abrv.find(key) == abrv.end()){
                    abrv[key].first = si_it->first;
                    abrv[key].second = size;
                } else{
                    if(abrv[key].second < size){
                        abrv[key].first = si_it->first;
                        abrv[key].second = size;
                    }
                }
            }
        }

        for(csi_it=abrv.begin(); csi_it!=abrv.end(); csi_it++)
            abreviations.insert(csi_it->second.first);

        /*
        for(sit=abreviations.begin(); sit!=abreviations.end(); sit++)
            cout << *sit << endl;
        */

        aux = strtok(phrase_cpy, " ");
        bool first_space = false;
        while(aux!=NULL)
        {
            if(first_space) printf(" ");

            if((sit = abreviations.find((string)aux)) != abreviations.end()){
                printf("%c.", (*sit)[0]);
            }
            else{
                printf("%s", aux);
            }

            aux = strtok(NULL, " ");
            first_space = true;
        }
        printf("\n");

        cout << abrv.size() << endl;

        
        for(csi_it=abrv.begin(); csi_it!=abrv.end(); csi_it++)
            cout << csi_it->first << ". = " << csi_it->second.first << endl;
        
    }


    return 0;
}