#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

int *vetorPrincipal[TAM];


/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho){

    int retorno = 0;
    int index = posicao -1;
    int i;
    // a posicao pode já existir estrutura auxiliar
    if(vetorPrincipal[index] != NULL){
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    // se posição é um valor válido {entre 1 e 10}
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA) return retorno = POSICAO_INVALIDA;
    // o tamanho nao pode ser menor que 1
    if(tamanho<1){
        retorno = TAMANHO_INVALIDO;
        return retorno;
    }
    // o tamanho ser muito grande
    vetorPrincipal[index] = malloc(tamanho*sizeof(int));
    for(i = 0; i<tamanho; i++) vetorPrincipal[index][i] = 32767;
    if(vetorPrincipal[index] == NULL){
        retorno = SEM_ESPACO_DE_MEMORIA;
        return retorno;
    }
    // deu tudo certo, crie
    return retorno = SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor){
    
    int index = posicao -1;
    int livre = 0;
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;
     
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA) return retorno = POSICAO_INVALIDA;
    
    else
    {
        if(vetorPrincipal[index] != NULL) existeEstruturaAuxiliar = 1;
        // testar se existe a estrutura auxiliar
        if (existeEstruturaAuxiliar)
        {
            for(int i = 0;; i++) 
                if(vetorPrincipal[index][i] == 32767){
                    temEspaco = 1;
                    livre = i;
                    break;
                } else if(vetorPrincipal[index][i] == '\0'){
                    temEspaco = 0;
                    break;
                }
            if (temEspaco)
            {
                vetorPrincipal[index][livre] = valor;
                //printf("%d\t%d\t",vetorPrincipal[index][livre], livre);
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao){
    int index = posicao-1;
    int retorno = 0;
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA) return retorno = POSICAO_INVALIDA; 
    if(vetorPrincipal[index] == NULL){
            retorno = SEM_ESTRUTURA_AUXILIAR;
            return retorno;
        }
    if(vetorPrincipal[index][0] == 32767 || vetorPrincipal[index][0] == '\0'){
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
            return retorno;
        }
    for(int i = 0;; i++)
        if(vetorPrincipal[index][i] == 32767 || vetorPrincipal[index][i] == '\0'){
            vetorPrincipal[index][i-1] = 32767;
            retorno = SUCESSO;
            return retorno;
        }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor){
    int index = posicao-1;
    int j;
    int retorno = 0;
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA) return retorno = POSICAO_INVALIDA; 
    if(vetorPrincipal[index] == NULL) return retorno = SEM_ESTRUTURA_AUXILIAR;
    if(vetorPrincipal[index][0] == 32767) return retorno = ESTRUTURA_AUXILIAR_VAZIA;
    for(int i = 0;; i++)
        if(vetorPrincipal[index][i] == valor){
            for(j = i;vetorPrincipal[index][j]!='\0'; j++ ) vetorPrincipal[index][j] = vetorPrincipal[index][j+1];
            vetorPrincipal[index][j-1] = 32767;
            return retorno = SUCESSO;
        } else  if(vetorPrincipal[index][i] == '\0') return retorno = NUMERO_INEXISTENTE;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao){
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    int retorno = 0;
    int index = posicao -1;
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA) return retorno = POSICAO_INVALIDA; 
    if(vetorPrincipal[index] == NULL) return retorno = SEM_ESTRUTURA_AUXILIAR;
    for(int i = 0;vetorPrincipal[index][i]!= 32767; i++ ) vetorAux[i] = vetorPrincipal[index][i];
    return retorno = SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    int retorno = 0;
    int index = posicao -1;
    int temp, cont = 0;
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA) return retorno = POSICAO_INVALIDA;
    if(vetorPrincipal[index] == NULL) return retorno = SEM_ESTRUTURA_AUXILIAR;
    for(int i = 0;vetorPrincipal[index][i]!= 32767; i++ ){
        vetorAux[i] = vetorPrincipal[index][i];
        cont++;
    } 
    for(int i = 0;i<cont-1; i++)
        for(int j = 0; j<cont-1; j++){
            if(vetorAux[j]>vetorAux[j+1] && (vetorAux[j] != 32767 || vetorAux[j+1] != 32767)){
                temp = vetorAux[j];
                vetorAux[j] = vetorAux[j+1];
                vetorAux[j+1] = temp;
            }
        }
    return retorno = SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorno = 0;
    
    int i = 0, j, cont = 0, k = 0;
    for(i = 0;i<10; i++ ){
        if(vetorPrincipal[i] != NULL){
            size_t n = sizeof(vetorPrincipal)/sizeof(vetorPrincipal[0]);
            for(j=0; j<n; j++){
                if(vetorPrincipal[i][j] == 32767) break;
                vetorAux[k] = vetorPrincipal[i][j];
                k++;
                if(vetorPrincipal[i][j] == '\0') break;
            } 
        } else cont++;
    }
    if(cont == 10) return retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    return retorno = SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorno = 0;
    int i = 0, j, cont = 0, k = 0, temp;
    for(i = 0;i<10; i++ ){
        if(vetorPrincipal[i] != NULL){
            size_t n = sizeof(vetorPrincipal)/sizeof(vetorPrincipal[0]);
            for(j=0; j<n; j++){
                if(vetorPrincipal[i][j] == 32767) break;
                vetorAux[k] = vetorPrincipal[i][j];
                k++;
                if(vetorPrincipal[i][j] == '\0') break;
            } 
        } else cont++;
    }

    for(i = 0;i<k-1; i++)
        for(j = 0; j<k-1; j++){
            if(vetorAux[j+1]<vetorAux[j]){
                temp = vetorAux[j];
                vetorAux[j] = vetorAux[j+1];
                vetorAux[j+1] = temp;
            
            }
        }
    if(cont == 10) return retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    return retorno = SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0, j=0, i=0, cont=0, index = posicao -1, *temp;
    if(novoTamanho==0) return retorno = NOVO_TAMANHO_INVALIDO;
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA) return retorno = POSICAO_INVALIDA;
    if(vetorPrincipal[index] == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    while(cont>=0){
        if(vetorPrincipal[index][cont]!='\0') cont++;
        else break;
    }

    novoTamanho += cont;

    if(novoTamanho<1) return retorno = NOVO_TAMANHO_INVALIDO;
    temp = malloc(cont*sizeof(int));
    for(i = 0; i<cont; i++) temp[i] = vetorPrincipal[index][i];
    free(vetorPrincipal[index]);
    vetorPrincipal[index] = malloc(novoTamanho*sizeof(int));
    for(i = cont; i<novoTamanho; i++) vetorPrincipal[index][i]= 32767;
    for(i = 0; i<cont; i++) vetorPrincipal[index][i]= temp[i];
    vetorPrincipal[index][novoTamanho]= '\0';

        
    if(vetorPrincipal[index] == NULL){
        retorno = SEM_ESPACO_DE_MEMORIA;
        return retorno;
    }
    return retorno = SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0, j=0, i=0, cont=0, index = posicao -1;
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA) return retorno = POSICAO_INVALIDA;
    if(vetorPrincipal[index] == NULL){
        retorno = SEM_ESTRUTURA_AUXILIAR;
        return retorno;
    }
    if(vetorPrincipal[index][0] == 32767 || vetorPrincipal[index][0] == '\0'){
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
            return retorno;
    }
    i=0;
    while(0==0){
        if(vetorPrincipal[index][i] == '\0') break;
        if(vetorPrincipal[index][i] == 32767) break;
        cont++;
        i++;
    }
    return cont;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    for(int i =0; i<10; i++) vetorPrincipal[i] = NULL;
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    for(int i =0; i<10; i++) free(vetorPrincipal[i]);
}