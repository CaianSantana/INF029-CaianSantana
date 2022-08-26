#include <stdio.h>
//7) Crie um programa que tenha uma função ler3Palavras. Essa função deve ler três palavras do usuário e retornar as três palavras. A função main deve imprimir essas três palavras.
typedef struct{
  char palavra[20];
}Palavra;
Palavra lerPalavra();
int main(void){
  Palavra palavras[3];
  for(int i = 0; i<3; i++)
    palavras[i]= lerPalavra();
  for(int i = 0; i<3; i++)
    printf("%s", palavras[i].palavra);
  
}

Palavra lerPalavra(){
  Palavra palavra;
  fflush(stdin);
  printf("Digite três palavras: ");
  fgets(palavra.palavra, 21, stdin);
  return palavra;
}