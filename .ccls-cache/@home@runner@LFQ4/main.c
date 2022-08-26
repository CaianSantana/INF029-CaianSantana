#include <stdio.h>
//4) Crie um programa que tenha uma função ler 3 Numeros. Essa função deve ler três números do usuário e retornar os três números. A função main deve imprimir esses três números. Utilize vetor para fazer o retorno.
typedef struct{
  int numeros[3];
}Numero;

Numero lernumero();

int main(void) {
  Numero numero = lernumero();
  for(int i = 0; i<3; i++)
    printf("%d\n",numero.numeros[i]);
}

Numero lernumero(){
  Numero numero;
  for(int i = 0; i<3; i++){
  printf("Digite um número: ");
    scanf("%d", &numero.numeros[i]);
  }
  return numero;
}