/*#### Versão v01 ####
- Estrutura básica para representar aluno
- Estrutura inicial de menu e switch
- Lista de alunos
- Inserir aluno
- Listar alunos */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
  char Matricula [21];
  char Nome [51];
  char Sexo;
  char DataNascimento[11];
  char CPF[15];
}Aluno; //Cadastro de Alunos (Matrícula, Nome, Sexo, Data Nascimento, CPF) 
typedef struct
{
  char Matricula [21];
  char Nome [51];
  char Sexo;
  char DataNascimento[11];
  char CPF[15];
}Professor; //Cadastro de Professores (Matrícula, Nome, Sexo, Data Nascimento, CPF).
typedef struct
{
  char Nome[31];
  char Código[11];
  int Semestre;
  char Professor[51];
}Disciplina; //Cadastro de Disciplinas (Nome, Código, Semestre, Professor)

void ListarAlunos(int alternativa)
{
  int i,  numeroAlunos = 41;
  char sexo;
  Aluno alunos[41];
  switch(alternativa)
    {
      case 1:
        for(i=0;i<numeroAlunos;i++)
          printf("Listando todos:\n\nMatrícula: %s\nNome: %s\nSexo: %s\nData de Nascimento: %s\nCPF:               %s\n\n",alunos[i].Matricula,alunos[i].Nome,alunos[i].Sexo,alunos[i].DataNascimento,alunos[i].CPF);
      break;
      case 2:
      break;
      case 3:
        getchar();
        printf("Escolha o sexo?(M/F)\n");
        scanf("%c",&sexo);
        printf("\e[1;1H\e[2J");
        if(sexo == 77)
        {
          printf("Masculino.");
          /*for(i=0;i<numeroAlunos;i++)
            if(alunos[i].Sexo == 77)
              printf("Listando somente alunos do sexo masculino:\n\nMatrícula: %s\nNome: %s\nData de Nascimento: %s\nCPF:               %s\n\n",alunos[i].Matricula,alunos[i].Nome,alunos[i].DataNascimento,alunos[i].CPF);*/
            
        }else if(sexo == 70)
         {
          printf("Feminino.");
           /*for(i=0;i<numeroAlunos;i++)
            if(alunos[i].Sexo == 70)
              printf("Listando somente alunos do sexo feminino:\n\nMatrícula: %s\nNome: %s\nData de Nascimento: %s\nCPF:               %s\n\n",alunos[i].Matricula,alunos[i].Nome,alunos[i].DataNascimento,alunos[i].CPF);*/
         }else
          printf("Dígito inválido.");
    }
}
int main(void) {
  int escolha;
  Aluno alunos[40];
  printf("|----------- Sistema Escola -----------|\n| O que deseja acessar?                |\n| 1 - alunos                           |\n| 2 - Professores                      |\n| 3 - Disciplinas                      |\n|--------------------------------------|\n\n");
  scanf("%d",&escolha);
  printf("\e[1;1H\e[2J");
  switch (escolha)
  {
    case 1:
      printf("\n\n|----------- Sistema Escola -----------|\n| Você escolheu alunos.                |\n| O que deseja fazer?                  |\n| 1 - Cadastrar Aluno                  |\n| 2 - Matricular Aluno em um Disciplina|\n| 3 - Listar Alunos                    |\n|--------------------------------------|\n\n" );
    scanf("%d", &escolha);
      printf("\e[1;1H\e[2J");
      switch(escolha)
        {
          case 1:
          break;
          case 2:
          break;
          case 3:
            printf("\n\n|----------- Sistema Escola -----------|\n| Você escolheu listar alunos.         |\n| Como deseja fazer isso?              |\n| 1 - Listar todos                     |\n| 2 - ordenando por nome               |\n| 3 - Listar por sexo                  |\n| 3 - ordenando por data de nascimento |\n|--------------------------------------|\n\n");
            scanf("%d", &escolha);
            printf("\e[1;1H\e[2J");
            ListarAlunos(escolha);
          break;
        }

    break;
    case 2: 
      printf("\n\n|----------- Sistema Escola -----------|\n| Você escolheu Professores.           |\n| O que deseja fazer?                  |\n| 1 - Cadastrar Professor              |\n| 2 - Listar Professores               |\n|--------------------------------------|\n\n");
      scanf("%d", &escolha);
  }
}