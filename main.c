#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ARV.h"

int main()
{
    Arv *a = CriaArvore();
    int n;

    int registro, idade;
    char nome[40], cargo[25];
    float salario;

    printf("\n Quantos dados deseja inserir: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("\n Registro: ");
        scanf("%d", &registro);

        printf("\n Nome: ");
        scanf("%s", nome);

        printf("\n Cargo: ");
        scanf("%s", cargo);

        printf("\n Idade: ");
        scanf("%d", &idade);

        printf("\n Salario: ");
        scanf("%f", &salario);

        InsereArv(a, registro, nome, cargo, idade, salario);
    }

    Imprime_PreOrder(a->raiz);
}