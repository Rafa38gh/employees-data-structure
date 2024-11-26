#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
    fgetc(ARQ);
    for(int i = 0; i < n; i++)
    {
        fscanf(ARQ, "%d", &registro);
        fgetc(ARQ);
        fgets(nome, 40, ARQ);
        fscanf(ARQ, "%d", &idade);
        fgetc(ARQ);
        fgets(cargo, 25, ARQ);
        fscanf(ARQ, "%f", &salario);
        fgetc(ARQ);

        InsereArv(a, registro, nome, cargo, idade, salario);
    }

    fclose(ARQ);
}

void NovoCadastro(Arv *a)
{
    int registro, idade;
    int cargoOps;
    char nome[40], cargo[25];
    float salario;

    system("cls");
    printf("\n ========| NOVO CADASTRO |========");

    // Registro
    do
    {
        printf("\n\t Registro: ");
        scanf("%d", &registro);

        if(registro < 1000 || registro > 9999)
        {
            printf("\n\n ERRO: Registro invalido...");
        }

    } while (registro < 1000 || registro > 9999);

    // Nome
    printf("\n\t Nome: ");
    scanf(" %39[^\n]", nome);

    // Cargo
    do
    {
        printf("\n\t Cargo:");
        printf("\n\t\t 1. ANALISTA DE SISTEMAS\n\t\t 2. ANALISTA DE SUPORTE\n\t\t 3. PROGRAMADOR\n\t\t 4. CONTADOR\n\t\t 5. ADMINISTRATIVO\n\t\t 6. GERENTE");
        printf("\n\t Escolha uma opcao: ");
        scanf("%d", &cargoOps);

        switch(cargoOps)
        {
            case 1:
                strcpy(cargo, "ANALISTA DE SISTEMAS");
                break;
            
            case 2:
                strcpy(cargo, "ANALISTA DE SUPORTE");
                break;
            
            case 3:
                strcpy(cargo, "PROGRAMADOR");
                break;
            
            case 4:
                strcpy(cargo, "CONTADOR");
                break;
            
            case 5:
                strcpy(cargo, "ADMINISTRATIVO");
                break;
            
            case 6:
                strcpy(cargo, "GERENTE");
                break;
            
            default:
                printf("\n\n ERRO: Valor invalido inserido...");
        }
    } while (cargoOps <= 0 || cargoOps > 6);
    
    // Idade
    do
    {
        printf("\n\t Idade: ");
        scanf("%d", &idade);

        if(idade < 18 || idade > 100)
        {
            printf("\n\n ERRO: Idade fora do padrao permitido...");
        }

    } while (idade < 18 || idade > 100);

    // Salário
    printf("\n\t Salario: ");
    scanf("%f", &salario);

    InsereArv(a, registro, nome, cargo, idade, salario);
}

void EditarFuncionario(NoArv *cadastro)
{
    int idade;
    int cargoOps;
    char nome[40], cargo[25];
    float salario;

    system("cls");
    printf("\n ========| EDITAR CADASTRO |========");

    // Nome
    printf("\n\t Nome: ");
    scanf(" %39[^\n]", nome);

    // Cargo
    do
    {
        printf("\n\t Cargo:");
        printf("\n\t\t 1. ANALISTA DE SISTEMAS\n\t\t 2. ANALISTA DE SUPORTE\n\t\t 3. PROGRAMADOR\n\t\t 4. CONTADOR\n\t\t 5. ADMINISTRATIVO\n\t\t 6. GERENTE");
        printf("\n\t Escolha uma opcao: ");
        scanf("%d", &cargoOps);

        switch(cargoOps)
        {
            case 1:
                strcpy(cargo, "ANALISTA DE SISTEMAS");
                break;
            
            case 2:
                strcpy(cargo, "ANALISTA DE SUPORTE");
                break;
            
            case 3:
                strcpy(cargo, "PROGRAMADOR");
                break;
            
            case 4:
                strcpy(cargo, "CONTADOR");
                break;
            
            case 5:
                strcpy(cargo, "ADMINISTRATIVO");
                break;
            
            case 6:
                strcpy(cargo, "GERENTE");
                break;
            
            default:
                printf("\n\n ERRO: Valor invalido inserido...");
        }
    } while (cargoOps <= 0 || cargoOps > 6);
    
    // Idade
    do
    {
        printf("\n\t Idade: ");
        scanf("%d", &idade);

        if(idade < 18 || idade > 100)
        {
            printf("\n\n ERRO: Idade fora do padrao permitido...");
        }

    } while (idade < 18 || idade > 100);

    // Salário
    printf("\n\t Salario: ");
    scanf("%f", &salario);

    strcpy(cadastro->nome, nome);
    strcpy(cadastro->cargo, cargo);
    cadastro->idade = idade;
    cadastro->salario = salario;

    FormataNo(cadastro);
}

void BuscaFuncionario(Arv *a)
{
    int registro;
    char input;
    NoArv *cadastro;

    system("cls");
    printf("\n ========| BUSCA DE FUNCIONARIO |========");
    printf("\n\t Insira o registro do funcionario: ");
    scanf("%d", &registro);

    cadastro = BuscaArv(a->raiz, registro);

    if(cadastro != NULL)
    {
        printf("\n\nFuncionario encontrado:");
        printf("\n\t Registro: %d", cadastro->registro);
        printf("\n\t Nome: %s", cadastro->nome);
        printf("\n\t Cargo: %s", cadastro->cargo);
        printf("\n\t Idade: %d", cadastro->idade);
        printf("\n\t Salario: %.2f", cadastro->salario);

        printf("\n\n Deseja alterar as informacoes do funcionario? [S|N]: ");
        scanf(" %c", &input);
        input = toupper(input);

        if(input == 'S')
        {
            EditarFuncionario(cadastro);
        }

    } else
    {
        printf("\n\n ERRO: Registro nao encontrado no sistema...");
    }
}

void BuscaCargoAux(NoArv *pai, char cargo[])
{
    if(pai != NULL)
    {
        if(strcmp(pai->cargo, cargo) == 0)
        {
            printf("\n %d", pai->registro);
            printf("\t%s", pai->nome);
            printf("\t%s", pai->cargo);
            printf("\t%d", pai->idade);
            printf("\t%.2f", pai->salario);
        }

        BuscaCargoAux(pai->esq, cargo);
        BuscaCargoAux(pai->dir, cargo);
    }
}

void BuscaCargo(NoArv *pai)
{
    int input, cargoLen;
    char cargo[25];

    do
    {
        system("cls");
        printf("\n ========| BUSCA POR CARGO |========");
        printf("\n\t Cargo:");
        printf("\n\t\t 1. ANALISTA DE SISTEMAS\n\t\t 2. ANALISTA DE SUPORTE\n\t\t 3. PROGRAMADOR\n\t\t 4. CONTADOR\n\t\t 5. ADMINISTRATIVO\n\t\t 6. GERENTE");
        printf("\n\t Escolha uma opcao: ");
        scanf("%d", &input);

        switch(input)
        {
            case 1:
                strcpy(cargo, "ANALISTA DE SISTEMAS");
                break;
            
            case 2:
                strcpy(cargo, "ANALISTA DE SUPORTE");
                break;
            
            case 3:
                strcpy(cargo, "PROGRAMADOR");
                break;
            
            case 4:
                strcpy(cargo, "CONTADOR");
                break;
            
            case 5:
                strcpy(cargo, "ADMINISTRATIVO");
                break;
            
            case 6:
                strcpy(cargo, "GERENTE");
                break;
            
            default:
                printf("\n\n ERRO: Valor invalido inserido...");
        }
    } while (input <= 0 || input > 6);

     // Formatação do vetor cargo
    cargoLen = strlen(cargo);
    for(int i = cargoLen; i < 25; i++)
    {
        cargo[i] = ' ';
    }
    cargo[24] = '\0';

    BuscaCargoAux(pai, cargo);
}

void Menu(Arv *a)
{
    int input;

    do
    {
        printf("\n\n\n ========| MENU PRINCIPAL |========");
        printf("\n\t 1. Imprimir pre-ordem");
        printf("\n\t 2. Imprimir in-ordem");
        printf("\n\t 3. Imprimir pos-ordem");
        printf("\n\t 4. Cadastrar novo funcionario");
        printf("\n\t 5. Buscar funcionario");
        printf("\n\t 6. Busca por cargo");
        printf("\n\t 0. Sair");
        printf("\n\n\t Escolha uma opcao: ");
        scanf("%d", &input);

        switch(input)
        {
            case 1:
                printf("\n\n Arvore em pre-ordem:\n\n");
                Imprime_PreOrder(a->raiz);
                break;

            case 2:
                printf("\n\n Arvore in-ordem:\n\n");
                Imprime_InOrder(a->raiz);
                break;
            
            case 3:
                printf("\n\n Arvore em pos-ordem:\n\n");
                Imprime_PosOrder(a->raiz);
                break;
            
            case 4:
                NovoCadastro(a);
                break;
            
            case 5:
                BuscaFuncionario(a);
                break;

            case 6:
                BuscaCargo(a->raiz);
                break;

            case 0:
                printf("\n\n Encerrando o programa...");
                break;
            
            default:
                printf("\n\n Opcao invalida, tente novamente");
                break;
        }
    } while (input != 0);
}

//=================================================================================================
// Main
int main()
{
    Arv *a = CriaArvore();

    LeituraARQ(a);
    Menu(a);
    
    return 0;
}