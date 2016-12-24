#include <stdio.h>
#include <string.h>

int main()
{
    int N, i, K, j;

    scanf("%d", &N);

    for (i=0; i<N; i++)
    {
        scanf("%d", &K);
        char idioma[K][25];
        for (j=0; j<K; j++)
            scanf("%s%*c", idioma[j]);

        for (j=0; j<K-1; j++){
            if (strcmp(idioma[j], idioma[j+1])){
                printf("ingles\n");
                break;
            }
        }

        if (j==K-1)
            printf("%s\n", idioma[0]);
    }

    return 0;
}
