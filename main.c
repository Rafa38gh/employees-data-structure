#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "ARV.h"

void LeituraARQ(Arv *a)
{
    FILE *ARQ;
    int n, registro, idade;
    char nome[40], cargo[25];
    float salario;

    ARQ = fopen("Dados.txt","r");
    if(ARQ == NULL)
    {
        printf("\n\n\n\t\t\t\t=> ERRO NA ABERTURA DO ARQUIVO <=\n\n");
        system("pause");
        exit(0);
    }

    fscanf(ARQ,"%d", &n);
    for(int i = 0; i < n; i++)
    {
        fscanf(ARQ, "%d", &registro);
        fgets(nome, 40, ARQ);
        fscanf(ARQ, "%d", &idade);
        fgets(cargo, 25, ARQ);
        fscanf(ARQ, "%f", &salario);

        InsereArv(a, registro, nome, cargo, idade, salario);
    }

    fclose(ARQ);
}

//=================================================================================================
// Main
int main()
{   //=============================================================================================
    // Variáveis principais
    Arv *a = CriaArvore();

    LeituraARQ(a);
    Imprime_PreOrder(a->raiz);
    
    return 0;
}