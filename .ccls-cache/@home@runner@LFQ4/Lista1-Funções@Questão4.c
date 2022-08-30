#include <stdio.h>
//4) Crie um programa que tenha uma função ler 3 Numeros. Essa função deve ler três números do usuário e retornar os três números. A função main deve imprimir esses três números. Utilize vetor para fazer o retorno.

int* lernumero();

int main(void) {
  int numero[3]; 
  lernumero(numero);
  for(int i = 0; i<3; i++)
    printf("%d\n",numero[i]);
}

int* lernumero(int vetor[]){
  for(int i = 0; i<3; i++){
  printf("Digite um número: ");
    scanf("%d", &vetor[i]);
  }
}