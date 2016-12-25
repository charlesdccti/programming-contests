#include <bits/stdc++.h>

#define AT t%2
#define DF (t+1)%2

using namespace std;

struct Hab {
    int tipo; //1(fis) 2(mag) 3(sup)
    int poder;
    int custo_hp;
    int custo_mp;
    int efeito; //1(atk fis +25%) atacante (ate usar atk fis)
                //2(def +25%) atacante (ate sofrer atk qualquer)
                //3(atk fis -25%) defensor (ate ele usar atk fis)
                //4(def -25%) defensor (ate ele sofrer atk qualquer) 

    Hab(int _t = 0, int _p = 0, int _h = 0, int _m = 0, int _e = 0) :
        tipo(_t), poder(_p), custo_hp(_h), custo_mp(_m), efeito(_e) {}
};


struct Pl {
    string nome;
    double nivel;
    double hp;
    double mp;
    double atk;
    double mag;
    double def;
    int efect_atk[2]; //0 + 1 -
    int efect_def[2]; //0 + 1 -
    Pl(string _n = "blank", double _i = 0, double _h = 0, 
        double _m = 0, double _a = 0, double _g = 0, double _d = 0) :
        nome(_n), nivel(_i), hp(_h), mp(_m), atk(_a), mag(_g), def(_d) 
        {
            efect_atk[0] = efect_atk[1] = 0;
            efect_def[0] = efect_def[1] = 0;
        }
};

Pl j[2];

unordered_map <string, Hab> hability;
void initialize_habilities();

double value_atack(double at, double df, double p, double diff)
{
    return 5.0 * sqrt((at/df)*p) * (1.0 + diff * 0.1);
}

void atkturn(int t, string h) 
{
    Hab hab = hability[h];
    
    if (hab.custo_mp > j[AT].mp) return;
    j[AT].mp -= (double)hab.custo_mp;
    j[AT].hp -= j[AT].hp * 0.01 * (double)hab.custo_hp;

    if (hab.tipo == 3) {
        if (hab.efeito == 1) {
            if (j[AT].efect_atk[0] == 0)
                j[AT].efect_atk[0] = j[AT].efect_atk[1] + 1;
        } else if (hab.efeito == 3) {
            if (j[DF].efect_atk[1] == 0)
                j[DF].efect_atk[1] = j[DF].efect_atk[0] + 1;
        } else if (hab.efeito == 2) {
            if (j[AT].efect_def[0] == 0)
                j[AT].efect_def[0] = j[AT].efect_def[1] + 1;
        } else if (hab.efeito == 4) {
            if (j[DF].efect_def[1] == 0)
                j[DF].efect_def[1] = j[DF].efect_def[0] + 1;
        }
    } else if (hab.tipo == 2) {
        double diff = j[AT].nivel - j[DF].nivel;
        double p = hab.poder;
        double at = j[AT].mag;
        double df = j[DF].def;
        
        if (j[DF].efect_def[0] == 1) {
            df += df * 0.25;
            j[DF].efect_def[0] = 0;
            if (j[DF].efect_def[1] == 2) {
                df -= df * 0.25;
                j[DF].efect_def[1] = 0;
            }
        } else if (j[DF].efect_def[0] == 2) {
            df -= df * 0.25;
            j[DF].efect_def[0] = 0;
            if (j[DF].efect_def[1] == 1) {
                df += df * 0.25;
                j[DF].efect_def[1] = 0;
            }
        }

        j[DF].hp -= value_atack(at, df, p, diff);  
    } else {
        double diff = j[AT].nivel - j[DF].nivel;
        double p = hab.poder;
        double at = j[AT].atk;
        double df = j[DF].def;
        
        if (j[DF].efect_def[0] == 1) {
            df += df * 0.25;
            j[DF].efect_def[0] = 0;
            if (j[DF].efect_def[1] == 2) {
                df -= df * 0.25;
                j[DF].efect_def[1] = 0;
            }
        } else if (j[DF].efect_def[0] == 2) {
            df -= df * 0.25;
            j[DF].efect_def[0] = 0;
            if (j[DF].efect_def[1] == 1) {
                df += df * 0.25;
                j[DF].efect_def[1] = 0;
            }
        }

        if (j[AT].efect_atk[0] == 1) {
            at += at * 0.25;
            j[AT].efect_atk[0] = 0;
            if (j[AT].efect_atk[1] == 2) {
                at -= at * 0.25;
                j[AT].efect_atk[1] = 0;
            }
        } else if (j[AT].efect_atk[0] == 2) {
            at -= at * 0.25;
            j[AT].efect_atk[0] = 0;
            if (j[AT].efect_atk[1] == 1) {
                at += at * 0.25;
                j[AT].efect_atk[1] = 0;
            }
        }

        j[DF].hp -= value_atack(at, df, p, diff);

    }
}


int main() 
{
    ios::sync_with_stdio(0);
    initialize_habilities();

    for (int i = 0; i < 2; i++)
        cin >> j[i].nome >> j[i].nivel >> j[i].hp >> j[i].mp
            >> j[i].atk >> j[i].mag >> j[i].def;

    string magia;
    int t = 0, over = 0;
    
    while(cin >> magia)
    {
        if (over) continue;
        atkturn(t, magia);
        if (j[DF].hp <= 0) {
            cout << j[DF].nome << " is dead." << endl;
            cout << j[AT].nome << setprecision(2) << fixed << " HP: " 
                 << j[AT].hp << ", MP: " << j[AT].mp << ", ATK: ";

            if (j[AT].efect_atk[0] == 1) {
                j[AT].atk *=  1.25;
                if (j[AT].efect_atk[1] == 2) 
                    j[AT].atk *=  0.75;
            }
                
            if (j[AT].efect_atk[0] == 2) {
                j[AT].atk *=  0.75;
                if (j[AT].efect_atk[1] == 1) 
                    j[AT].atk *=  1.25;   
            }    

            
            cout << setprecision(1) << fixed << j[AT].atk << ", MAG: " 
                 << j[AT].mag << ", DEF: ";

            if (j[AT].efect_def[0] == 1) {
                j[AT].def *=  1.25;
                if (j[AT].efect_def[1] == 2) 
                    j[AT].def *=  0.75;
            }
                
            if (j[AT].efect_def[0] == 2) {
                j[AT].def *=  0.75;
                if (j[AT].efect_def[1] == 1) 
                    j[AT].def *=  1.25;   
            }    

            cout << j[AT].def << endl;

            over = 1;
        }
        t++;
    }
 
    return 0;
}

void initialize_habilities()
{
    hability["MightySwing"] =  Hab(1, 270, 14,  0, 0);
    hability["GiganticFist"] = Hab(1, 560, 16,  0, 0);
    hability["RainyDeath"] =   Hab(1, 350, 20,  0, 0);
    hability["Agilao"] =       Hab(2, 200,  0,  8, 0);
    hability["Agidyne"] =      Hab(2, 320,  0, 12, 0);
    hability["Bufula"] =       Hab(2, 200,  0,  8, 0);
    hability["Bufudyne"] =     Hab(2, 320,  0, 12, 0);
    hability["Megidola"] =     Hab(2, 360,  0, 32, 0);
    hability["Megidolaon"] =   Hab(2, 420,  0, 60, 0);
    hability["BlackViper"] =   Hab(2, 440,  0, 64, 0);
    hability["Tarukaja"] =     Hab(3, 320,  0, 12, 1);
    hability["Rakukaja"] =     Hab(3, 320,  0, 12, 2);
    hability["Tarunda"] =      Hab(3, 320,  0, 12, 3);
    hability["Rakunda"] =      Hab(3, 320,  0, 12, 4);
}