#include <stdio.h>

//6) Crie um programa que tenha uma função ler3Letras. Essa função deve ler três letras do usuário e retornar as três letras. A função main deve imprimir essas três letras.

typedef struct{
  char letra[4];
}Letra;
Letra lerletra();
int main(void){
printf("%s", lerletra().letra);
}

Letra lerletra(){
  Letra letra;
  printf("Digite três letras: ");
  fgets(letra.letra, 4, stdin);
  return letra;
}