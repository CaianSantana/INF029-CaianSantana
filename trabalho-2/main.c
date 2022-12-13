#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

int menu();


int menu()
{
    int op;
    printf("Digite as opção desejada\n");
    printf("0 - Sair\n");
    printf("1 - Criar estrutura\n");
    printf("2 - Inserir\n");
    printf("3 - Excluir\n");
    printf("4 - Listar uma estrutura\n");
    printf("5 - Modificar estrutura\n");
    scanf("%d", &op);
    return op;
}

/*int main()
{
    inicializar();
    int op;
    int sair = 0;
    int ret;
    int tam, pos, valor;
    while (!sair)
    {
        op = menu();
        switch (op)
        {
        case 0:
        {
            sair = 1;
            finalizar();
            break;
        }
        case 1:
        {
            printf("Digite o tamanho e a posicao da estrutura: ");
            scanf("%d%d",&tam, &pos);
            ret = criarEstruturaAuxiliar(pos, tam);
            if(ret == SUCESSO){
                printf("estrutura criada com sucesso.");
            }else if(ret == SEM_ESPACO_DE_MEMORIA){
                printf("A criação falhou por falta de memória.");
            }else if(ret == TAMANHO_INVALIDO){
                printf("Tamanho inválido.");
            }else if(ret == JA_TEM_ESTRUTURA_AUXILIAR){
                printf("Já há uma estrutura nesta posicao.");
            }
            printf("\n\n");
            break;
        }
        case 2:
        { //inserir
            printf("Digite valor e a posicao: ");
            scanf("%d%d",&valor,&pos);
            ret = inserirNumeroEmEstrutura(pos, valor);
            if (ret == SUCESSO)
            {
                printf("Inserido com sucesso");
            }
            else if (ret == SEM_ESPACO)
            {
                printf("Sem Espaço");
            }
            else if (ret == SEM_ESTRUTURA_AUXILIAR)
            {
                printf("Sem estrutura Auxiliar");
            }
            printf("\n\n");
            break;
        }

        case 3:
        { //excluir
            printf("Digite a posicao: ");
            scanf("%d",&valor);
            ret = excluirNumeroDoFinaldaEstrutura(pos);
            if (ret == SUCESSO)
            {
                printf("Excluido com sucesso");
            }
            else if (ret == SEM_ESPACO)
            {
                printf("Sem Espaço");
            }
            else if (ret == SEM_ESTRUTURA_AUXILIAR)
            {
                printf("Sem estrutura Auxiliar");
            }
            else if (ret == ESTRUTURA_AUXILIAR_VAZIA)
            {
                printf("estrutura vazia.");
            }
            printf("\n\n");
            break;
        }

        case 4:
        { //recuperar dados estrutura auxiliar
            printf("Qual a estrutura a ser listada (1..10)?");
            scanf("%d", &pos);

            int qtd = getQuantidadeElementosEstruturaAuxiliar(pos);

            if (qtd == POSICAO_INVALIDA)
            {
                printf("Posição inválida");
            } else if(qtd == ESTRUTURA_AUXILIAR_VAZIA){
                printf("estrutura vazia.");
            }
            else
            { // existe elemento
                int vetorAux[qtd];

                ret = getDadosEstruturaAuxiliar(pos, vetorAux);

                if (ret == SUCESSO)
                {
                    //imprimir para os dados para o usuário
                    int i = 0;
                    for (; i < qtd; i++)
                    {
                        printf("%d", vetorAux[i]);
                    }
                }
                else if(ret == ESTRUTURA_AUXILIAR_VAZIA)
                {
                printf("estrutura vazia.");
                }
                else if (ret == SEM_ESTRUTURA_AUXILIAR)
                {
                printf("Sem estrutura Auxiliar");
                }   
            }
            printf("\n\n");
            break;
        }
        default:
        {
            printf("opcao inválida\n");
        }
        }
    }

    return 0;
}*/