#ifndef ARV_H_INCLUDED
#define ARV_H_INCLUDED

#define TAM_NOME 40
#define TAM_CARGO 25

typedef struct NoArvore
{
    int registro;
    char nome[40];
    char cargo[25];
    int idade;
    float salario;

    struct NoArvore *esq;
    struct NoArvore *dir;
} NoArv;

typedef struct Arvore
{
    NoArv *raiz;
} Arv;

Arv *CriaArvore()
{
    Arv *a = (Arv*) malloc(sizeof(Arv));
    a->raiz = NULL;
    return a;
}

int VaziaArv(Arv *a)
{
    if(a->raiz == NULL)
    {
        return 1;
    }
    return 0;
}

NoArv *InsereAux(NoArv *no, int registro, char nome[], char cargo[], int idade, float salario)
{
    int flag;
    NoArv *pai;
    NoArv *novo = (NoArv*) malloc(sizeof(NoArv));

    novo->registro = registro;
    strcpy(novo->nome, nome);
    strcpy(novo->cargo, cargo);
    novo->idade = idade;
    novo->salario = salario;

    novo->esq = NULL;
    novo->dir = NULL;

    if(no == NULL)
    {
        return novo;

    } else
    {
        pai = no;
        flag = 0;

        while(flag == 0)
        {
            if(pai->registro == registro)
            {
                system("cls");
                printf("\n\t\t ERRO: Registros iguais detectados...");
                printf("\nRegistro: %d", pai->registro);
                printf("\nNome: %s", pai->nome);
                printf("\n\nRegistro: %d", registro);
                printf("\nNome: %s", nome);

                flag = 1;

            } else
            {
                if(pai->registro < registro)
                {
                    if(pai->dir == NULL)
                    {
                        pai->dir = novo;
                        flag = 1;

                    } else
                    {
                        pai = pai->dir;
                    }

                } else
                {
                    if(pai->registro > registro)
                    {
                        if(pai->esq == NULL)
                        {
                            pai->esq = novo;
                            flag = 1;

                        } else
                        {
                            pai = pai->esq;
                        }
                    }
                }
            }  
        }
    }

    return no;
}

void InsereArv(Arv *a, int registro, char nome[], char cargo[], int idade, float salario)
{
    int nomeLen, cargoLen;

    // Formatação do vetor nome
    nomeLen = strlen(nome);
    for(int i = nomeLen; i < TAM_NOME; i++)
    {
        nome[i] = ' ';
    }
    nome[39] = '\0';

    // Formatação do vetor cargo
    cargoLen = strlen(cargo);
    for(int i = cargoLen; i < TAM_CARGO; i++)
    {
        cargo[i] = ' ';
    }
    cargo[24] = '\0';

    a->raiz = InsereAux(a->raiz, registro, nome, cargo, idade, salario);
}

NoArv *BuscaArv(NoArv *no, int registro) 
{
    // Se o nó atual é NULL ou o registro é encontrado
    if (no == NULL || no->registro == registro) 
    {
        return no;
    }

    // Se o registro que estamos buscando é menor que o registro do nó atual,
    // buscamos na subárvore esquerda
    if (registro < no->registro) 
    {
        return BuscaArv(no->esq, registro);
    }

    // Se o registro que estamos buscando é maior que o registro do nó atual,
    // buscamos na subárvore direita
    return BuscaArv(no->dir, registro);
}

void Imprime_PreOrder(NoArv *pai)
{
    if(pai != NULL)
    {
        printf("\n %d", pai->registro);
        printf("\t%s", pai->nome);
        printf("\t%s", pai->cargo);
        printf("\t%d", pai->idade);
        printf("\t%.2f", pai->salario);

        Imprime_PreOrder(pai->esq);
        Imprime_PreOrder(pai->dir);
    }
}

void Imprime_InOrder(NoArv *pai)
{
    if(pai != NULL)
    {
        Imprime_InOrder(pai->esq);

        printf("\n %d", pai->registro);
        printf("\t%s", pai->nome);
        printf("\t%s", pai->cargo);
        printf("\t%d", pai->idade);
        printf("\t%.2f", pai->salario);

        Imprime_InOrder(pai->dir);
    }
}

void Imprime_PosOrder(NoArv *pai)
{
    if(pai != NULL)
    {
        Imprime_PosOrder(pai->esq);
        Imprime_PosOrder(pai->dir);

        printf("\n %d", pai->registro);
        printf("\t%s", pai->nome);
        printf("\t%s", pai->cargo);
        printf("\t%d", pai->idade);
        printf("\t%.2f", pai->salario);
    }
}

#endif  // ARV_H_INCLUDED