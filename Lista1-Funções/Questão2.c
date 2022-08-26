#include <stdio.h>
// 2) Crie um programa que tenha uma função subtrai e a função main. A função main deve ler três valores, enviar para a função subtrai. A função subtrai deve realizar a subtração dos três valores (primeiro menos o segundo menos o terceiro) e retornar o valor. A Função main deve imprimir o resultado da subtração.

int subtracao(int numero[3]);

int main(void) {
  int numero[3];
  for(int i = 0; i<3; i++){
    printf("Digite um número: ");
    scanf("%d", &numero[i]);
    }
  printf("%d",subtracao(numero));
}

int subtracao(int numero[3]){
  int resultado = numero[0];
  for(int i=1; i<3; i++)
    resultado-= numero[i];
  return resultado;
}