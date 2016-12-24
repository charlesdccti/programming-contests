#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main()
{
    unsigned int N, M;
    register int i, j, k;
    unsigned long long matrix[20][20];
    int maior[20];
    int sw, qt_Num;
    unsigned long long aux;
    
    cin >> N;
    
    for (i=0; i<N; i++)
    {
        cin >> M;
        
        for (j=0; j<M; j++)
            for (k=0; k<M; k++){
                cin >> matrix[j][k];
                matrix[j][k]*=matrix[j][k];
            }
        
        for (k=0; k<M; k++){
            sw = 1;
            for (j=0; j<M; j++){
                qt_Num = 0;
                aux = matrix[j][k];
                while (aux!=0){
                    aux = aux/10;
                    qt_Num++;
                }
                if (qt_Num > sw)
                    sw = qt_Num;
            }
            maior[k] = sw;
        }
    
        cout << "Quadrado da matriz #" << i+4 << ":" << endl;
        
        for (j=0; j<M; j++){
            for (k=0; k<M; k++){
                if (k != M-1)    
                    cout << setw(maior[k]) << matrix[j][k] << " ";
                else
                    cout << setw(maior[k]) << matrix[j][k];         
            }
            //if(!(i==N-1 && j==M-1))
                cout << endl;
        }
        if (i!=N-1)
            printf("\n");
    }   
    
    return 0;
}