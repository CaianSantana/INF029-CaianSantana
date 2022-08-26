#include <stdio.h>
// 1) Crie um programa que tenha uma função soma e a função main. A função main deve ler dois valores, enviar para a função soma. A função soma deve realizar a soma e retornar o valor. A Função main deve imprimir o resultado da soma.

int soma(int numero1, int numero2);

int main(void) {
  int numero1, numero2;
  printf("Digite um número: ");
  scanf("%d", &numero1);
  printf("Digite outro número: ");
  scanf("%d", &numero2);
  printf("%d",soma(numero1, numero2));
  
}


int soma(int numero1, int numero2){
  int resultado;
  resultado = numero1 + numero2;
  return resultado;
}