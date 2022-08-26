#include <stdio.h>
#include <stdlib.h>
//3) Faça um programa que tenha uma função que recebe um número inteiro e retorna o fatorial deste número. Esta função deve ainda verificar se é possível calcular o fatorial, se não for, ela deve de alguma forma retornar para a main que deu algum erro. A função main deve solicitar o valor do usuário e imprimir o fatorial dele, ou se não é possível calcular o fatorial.

int Fatorial(int numero);

int main(void) {
  int numero;
  printf("Digite um número: ");
  scanf("%d", &numero);
  printf("%d",Fatorial(numero));
  
}


int Fatorial(int numero){
  if(numero <= 0){
    printf("Número inválido!");
    exit(0);
    }
  int resultado=1;
  for(int i = 1; i<=numero;i++)
    resultado *= i;
  return resultado;
}