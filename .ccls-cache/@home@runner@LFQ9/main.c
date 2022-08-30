#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//8) Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do cliente. A função main deve imprimir os dados do cliente.
//9) Evolua o programa que tem a função cadastrarCliente, para fazer as validações dos dados. Cada validação deve ser feita em uma função diferente, conforme lista abaixo. A função cadastrarCliente deve chamar cada uma dessas funções. A função main deve imprimir se o cadastro foi realizado com sucesso ou se houve erro, informando onde foi o erro:

//     • função validarSexo: recebe o sexo digitado, e valida é um sexo válido (opções: m e M para masculino; f e F para feminino, o e O para outro).
//     • função validarCPF: recebe o cpf digitado, e valida é um cpf válido;
//     • função validarNacimento: recebe o data digitada, e valida é uma data válida

typedef struct{
  char Nome[20];
  long int DataNascimento;
  char CPF[12];
  char Sexo[2];
}Cliente;
Cliente SetCliente(char Nome[51], long int DataNascimento, char CPF[12], char Sexo[2]){
  Cliente c;
  strcpy(c.Nome, Nome);
  c.DataNascimento = DataNascimento;
  strcpy(c.CPF, CPF);
  strcpy(c.Sexo, Sexo);
  return c;
}
int validarNome(char nome[]);
int validarSexo(char Sexo[]);
int validarCPF( char CPF[]);
int validarNascimento(long int data);
Cliente CadastrarCliente();


int main(void) {
  Cliente cliente = CadastrarCliente();
  printf("Cadastro realizado com sucesso!");
}  

Cliente CadastrarCliente(){
  char nome[51], sexo[2], cpf[12];
  long int data ;
  Cliente cliente;
  printf("Digite o nome: ");
  fgets(nome, 51, stdin);
  if(validarNome(nome)==1){
    printf("Nome inválido.");
    exit(0);
  }
  printf("Digite a data de nascimento(somente números): ");
  scanf("%li", &data);
  if(validarNascimento(data)==1){
    printf("Data inválida.");
    exit(0);
  }
  printf("Digite o CPF(somente números): ");
  fflush(stdin);
  getchar();
  fgets(cpf, 12, stdin);
  if(validarCPF(cpf)==1){
    printf("cpf inválido.");
    exit(0);
  }
  fflush(stdin);
  getchar();
  printf("Digite o sexo: ");
  fflush(stdin);
  fgets(sexo, 2, stdin);
  if(validarSexo(sexo)==1){
    printf("Sexo inválido.");
    exit(0);
  }
  cliente = SetCliente(nome, data, cpf, sexo);
  return cliente;
}

int validarNome(char nome[]){// • função validarNome: recebe o nome digitado, e valida se nome tem até 20 caracteres;
  if(strlen(nome)<= 20 & strlen(nome) >1)
    return 0;
  else
    return 1;
}
int validarNascimento(long int data){//     • função validarNacimento: recebe o data digitada, e valida é uma data válida
  int dia, mes, ano;
  dia = data/1000000;
  mes = ((data/10000)*10000 - (dia)*1000000)/10000;
  ano = data - (data/10000)*10000;
  if((dia>=1 && dia <=31) &&(mes >=1 && mes<=12) && (ano>=1900 && ano<=2022))
    return 0;
  else
    return 1;
}
int validarCPF(char CPF[]){//     • função validarCPF: recebe o cpf digitado, e valida é um cpf válido;
  int cont=0;
  if(strlen(CPF)==11){
    for(int i = 0; i<11; i++)
      if(CPF[i]>=48 && CPF[i]<=57)
        continue;
      else
        cont++;
      if(cont==0)
        return 0;
      else
        return 1;
  }else
    return 1;
} 
int validarSexo(char Sexo[]){//     • função validarSexo: recebe o sexo digitado, e valida é um sexo válido (opções: m e M para masculino; f e F para feminino, o e O para outro).
  if(Sexo[0] == 70 || Sexo[0] == 77 || Sexo[0] == 102 || Sexo[0] == 108 || Sexo[0] == 79 || Sexo[0] == 111)
    return 0;
  else
    return 1;
}
