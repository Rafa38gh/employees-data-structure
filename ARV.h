#ifndef ARV_H_INCLUDED
#define ARV_H_INCLUDED

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

    return no;
}

void InsereArv(Arv *a, int registro, char nome[], char cargo[], int idade, float salario)
{
    a->raiz = InsereAux(a->raiz, registro, nome, cargo, idade, salario);
}

void Imprime_PreOrder(NoArv *pai)
{
    printf("\n %d", pai->registro);
    printf("\t\t %s", pai->nome);
    printf("\t\t %s", pai->cargo);
    printf("\t\t %d", pai->idade);
    printf("\t\t %.2f", pai->salario);

    if(pai->dir != NULL)
    {
        Imprime_PreOrder(pai->dir);
    }
    if(pai->esq != NULL)
    {
        Imprime_PreOrder(pai->esq);
    }
}


#endif  // ARV_H_INCLUDED