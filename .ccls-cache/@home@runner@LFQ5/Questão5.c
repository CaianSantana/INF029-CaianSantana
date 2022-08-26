#include <stdio.h>
//5) Crie um programa que tenha uma função ler4Numeros. Essa função deve ler quatro números do usuário e retornar os quatro números. A função main deve imprimir esses quatro números. Utilize struct para fazer o retorno.
typedef struct{
  int numeros[4];
}Numero;

Numero lernumero();

int main(void) {
  Numero numero = lernumero();
  for(int i = 0; i<4; i++)
    printf("%d\n",numero.numeros[i]);
}

Numero lernumero(){
  Numero numero;
  for(int i = 0; i<4; i++){
  printf("Digite um número: ");
    scanf("%d", &numero.numeros[i]);
  }
  return numero;
}