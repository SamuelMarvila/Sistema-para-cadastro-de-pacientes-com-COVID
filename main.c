#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "clearscr.h"
#include "pausecmd.h"
#include <conio.h>//para utilizar o getch()
#include <ctype.h>//para utilizar o isdigit()

//ATRIBUTOS DOS PACIENTES
typedef struct pessoa{
char nome[50];
char cpf[50];
char telefone[50];
int diaNasc,mesNasc,anoNasc;
int idade;
// ENDEREÇO
char rua[50];
int numeroCasa;
char bairro[50];
char cidade[50];
char estado[50];
int cep;
char email[50];


//DIAGNOSTICO
int diaDiag,mesDiag,anoDiag;
int comorbidade;

}PESSOA;

struct data{
int dia,mes,ano;

    };


//FUNÇÕES

void digitando(char *digitado);
void letras(char *Ldigitada);
void tela_de_login();
void menu();
void cadastro_de_pacientes();
int numeros( char *Ldigitada,int quantDigitos);
int numerosINT(int quantDigito, char limite);
void letrasEmail(char *Ldigitada);
void salvar(PESSOA paciente);
int idade(int dia,int mes,int ano);
void salvarGRisco(PESSOA paciente);

int main()
{

 tela_de_login();
 return 0;
}



void tela_de_login(){



    char entUsuario[50];
    int entSenha;
    int j=0;


    printf("\t\t================================================\n");
    printf("\t\t*            SISTEMA DE CADASTRO               *\n");
    printf("\t\t*           DE PESSOAS COM CONVID-19           *\n");


    do{

    printf("\t\t================================================\n");
    printf("\t\t              -----  LOGIN -----                \n");
    printf("\n \n");




    printf("DIGITE O USUARIO: \n");
    scanf("%s",entUsuario,5);
    printf("\n \n");
    printf("DIGITE A SENHA: \n");
    scanf("%d",&entSenha);
    printf("\n \n");

    // FUNÇÃO PARA CONVERTER EM MINUSCULO A ENTRADA DO USUARIO
    strlwr(entUsuario);


    //VALIDAÇÃO DO USUARIO E SENHA DIGITADOS
    if((strcmp(entUsuario,"admin") == 0) &&(entSenha== 1234))
       {
           j = 1;
           clearscr();

            menu();
       }else{


    clearscr();

        printf("[TENTE NOVAMENTE]\n\n");
        printf("[O Usuario ou Senha esta Incorreto]\n\n\n\n");

       }
    }while(j == 0);


}

void menu(){







    printf("\t\t================================================\n");
    printf("\t\t*                     MENU                     *\n");
    printf("\t\t================================================\n");
    printf(" \n 1 - CADASTRAR PACIENTE\n");
    printf(" \n 2 - SAIR \n");
    printf("\n SELECIONE A OPCAO DESEJADA: \n");


    int opcao;
    scanf("%d",&opcao);
    if(opcao== 1){
               clearscr();

        cadastro_de_pacientes();

    }else if(opcao == 2){
    printf("SISTEMA FINALIZADO...");
    }

}
void cadastro_de_pacientes(){




    printf("\t\t================================================\n");
    printf("\t\t*            CADASTRO DE PACIENTES             *\n");
    printf("\t\t================================================\n");

//CRIANDO A STRUCT PACIENTE
PESSOA paciente;



printf("\nDIGITE O NOME: \n");
letras(paciente.nome);

printf("\n\nDIGITE O CPF: \n");
numeros(paciente.cpf,11);

printf("\n\nDIGITE o TELEFONE: DD + NUMERO \n");
numeros(paciente.telefone,11);

printf("\n\t\t================  ENDERECO =====================\n");


printf("\n\nDIGITE A RUA: \n");
letras(paciente.rua);


printf("\n\nDIGITE O NUMERO DA CASA: \n");
paciente.numeroCasa = numerosINT(0,'s');


printf("\n\nDIGITE O BAIRRO: \n");
letras(paciente.bairro);

printf("\n\nDIGITE A CIDADE : \n");
letras(paciente.cidade);

printf("\n\nDIGITE O ESTADO: \n");
letras(paciente.estado);

printf("\n\nDIGITE O CEP: \n");
paciente.cep = numerosINT(8,'t');


printf("\n\t\t================================================\n");

printf("\n\nDIGITE O DIA DO SEU NASCIMENTO(DOIS DIGITOS): \n");
paciente.diaNasc = numerosINT(2,'t');


printf("\n\nDIGITE O MES DO SEU NASCIMENTO(DOIS DIGITOS):  \n");
paciente.mesNasc = numerosINT(2,'t');


printf("\n\nDIGITE O ANO DO SEU NASCIMENTO(QUATRO DIGITOS):  \n");
paciente.anoNasc = numerosINT(4,'t');


printf("\n\nDIGITE O SEU E-MAIL: \n");
letrasEmail(paciente.email);

printf("\n\nDIGITE O DIA DO DIAGNOSTICO: \n");
paciente.diaDiag = numerosINT(2,'s');


printf("\n\nDIGITE O MES DO DIAGNOSTICO: \n");
paciente.mesDiag = numerosINT(2,'s');


printf("\n\nDIGITE O ANO DO DIAGNOSTICO: \n");
paciente.anoDiag = numerosINT(4,'t');



printf("\n\n  TEM ALGUMA COMORBIDADE COMO: \n");
printf("\n [DIABETES, OBESIDADE, HIPERTENSAO, TURBECULOSE OU OUTROS]\n");
printf("\n 1 - SIM");
printf("\n 2 - NAO");
printf("\n OPACAO: ");


paciente.comorbidade = numerosINT(1,'t');;



paciente.idade = idade(paciente.diaNasc, paciente.mesNasc, paciente.anoNasc);


salvar(paciente);

if(paciente.comorbidade == 1 || paciente.idade >=65){
salvarGRisco(paciente);
}else{
menu();
}

}

void letras(char *Ldigitada)
{
    char digitado[50];//armazena o que foi digitado pelo usu�rio
    char c;//armazena cada caractere digitado pelo usu�rio
    int i=0;//vari�vel para controlar o �ndice do vetor de caracteres

  //  printf ("Informe seu nome: ");

    do
    {
       c=getch();//captura o caractere digitado pelo usu�rio
       if (isalpha(c)!=0 || c==32)//se for uma letra
       {
          digitado[i] = c;//armazena no vetor de caracteres
          i++;//incrementa o �ndice do vetor de caracteres
          printf ("%c", c);//exibe o caractere digitado
       }
       else if(c==8&&i)//se for pressionada a tecla BACKSPACE e houver caracteres j� digitados
       {
          digitado[i]='\0';//o �ndice atual do vetor de caracteres recebe a termina��o da string
          i--;//o �ndice do vetor de caracteres � decrementado
          printf("\b \b");//o caractere digitado � apagado da tela
       }
    }while(c!=13);//o loop vai ser executado at� que a tecla pressionada seja o ENTER (c�digo 13 na tabela ASCII)
     digitado[i]='\0';//o �ndice atual do vetor de caracteres recebe a termina��o da string


            char *testando = &digitado[0];


char *palavra = &digitado[0];

       while(*palavra != '\0'){
            *Ldigitada = *palavra;
            ++palavra;
            ++Ldigitada;


        }
    *Ldigitada ='\0';



}

int numeros( char *numero,int quantDigitos)
{

    char digitado[50];//armazena o que foi digitado pelo usu�rio
    char c;//armazena cada caractere digitado pelo usu�rio
    int i=0;//vari�vel para controlar o �ndice do vetor de caracteres
    int controle=0;

 while(controle==0){

    do
    {
       c=getch();//captura o caractere digitado pelo usu�rio
       if (isdigit(c)!=0)//se for um n�mero
       {
          digitado[i] = c;//armazena no vetor de caracteres
          i++;//incrementa o �ndice do vetor de caracteres
          printf ("%c", c);//exibe o caractere digitado
       }
       else if(c==8&&i)//se for pressionada a tecla BACKSPACE e houver caracteres j� digitados
       {
          digitado[i]='\0';//o �ndice atual do vetor de caracteres recebe a termina��o da string
          i--;//o �ndice do vetor de caracteres � decrementado
          printf("\b \b");//o caractere digitado � apagado da tela
       }
    }while(c!=13);//o loop vai ser executado at� que a tecla pressionada seja o ENTER (c�digo 13 na tabela ASCII)

    digitado[i]='\0';//o �ndice atual do vetor de caracteres recebe a termina��o da string


        //VALIDAÇÃO DE QUANTIDADE DE DIGITADO
        if(i>quantDigitos){
        printf("\n --- NUMEROS A MAIS DIGITADOS ---");
        printf("\n DIGITE NOVAMENTE \n");
        controle = 0;
        i =0;
        }else if(i<quantDigitos){
        printf("\n --- NUMEROS A MENOS DIGITADOS ---");
        printf("\n DIGITE NOVAMENTE: \n");
         controle = 0;
         i =0;
        }else{
         controle = 1;
        }
}

   char *nDigitado = &digitado[0];

        while(*nDigitado != '\0'){
            *numero = *nDigitado;
            ++nDigitado;
            ++numero;
        }

        *numero = *nDigitado;


return 0;
    }

int numerosINT(int quantDigito, char limite)
{
    char digitado[50];//armazena o que foi digitado pelo usu�rio
    char c;//armazena cada caractere digitado pelo usu�rio
    int i=0;//vari�vel para controlar o �ndice do vetor de caracteres
    int numero=0;//vari�vel para armazenar a convers�o do que foi digitado pelo usu�rio
    int controle=0;

 while(controle==0){

    do
    {
       c=getch();//captura o caractere digitado pelo usu�rio
       if (isdigit(c)!=0)//se for um n�mero
       {
          digitado[i] = c;//armazena no vetor de caracteres
          i++;//incrementa o �ndice do vetor de caracteres
          printf ("%c", c);//exibe o caractere digitado
       }
       else if(c==8&&i)//se for pressionada a tecla BACKSPACE e houver caracteres j� digitados
       {
          digitado[i]='\0';//o �ndice atual do vetor de caracteres recebe a termina��o da string
          i--;//o �ndice do vetor de caracteres � decrementado
          printf("\b \b");//o caractere digitado � apagado da tela
       }
    }while(c!=13);//o loop vai ser executado at� que a tecla pressionada seja o ENTER (c�digo 13 na tabela ASCII)

    digitado[i]='\0';//o �ndice atual do vetor de caracteres recebe a termina��o da string
    numero = atoi(digitado);//a vari�vel numero recebe o valor do vetor de caracteres convertido para inteiro
if(limite =='t'){
   if(i > quantDigito){
        printf("\n --- NUMEROS A MAIS DIGITADOS ---");
        printf("\n DIGITE NOVAMENTE \n");
        controle = 0;
        i =0;
        }else if(i<quantDigito){
        printf("\n --- NUMEROS A MENOS DIGITADOS ---");
        printf("\n DIGITE NOVAMENTE: \n");
         controle = 0;
         i =0;
        }else{
         controle = 1;
        }
 }else{
  controle = 1;
 }

 }
    return numero;



}


void letrasEmail(char *Ldigitada)
{

    int controle;

   char email[50];



    do{

    controle = 0;


  scanf("%s",email,50);

  int tam=strlen(email);

  int arroba = 0, ponto = 0, antesPonto = 0, depoisPonto = 0, i;

  for (i = 0; i < tam; i++) {
    char c = email[i];
    if(c == '@') {
      if (arroba)
        break; // não pode ter uma segunda @
      arroba = 1;
      if (i < 3)
        break; // se @ vier antes de 3 caracteres, erro
    }
    else if (arroba) { // se já encontrou @
      if (ponto) { // se já encontrou . depois de @
        depoisPonto++;
      }
      else if(c == '.') {
        ponto = 1;
        if (antesPonto < 3) {
          break; // se . depois de @ vier antes de 3 caracteres, erro
        }
      }
      else {
        antesPonto++;
      }
    }
   }// for

  if (i == tam && depoisPonto > 1)
  {
    controle =2;
    email[i]='\0';
  }
  else {
    printf(" \n [E-MAIL INVALIDO]" );
        printf(" \n DIGITE NOVAMENTE SEU E-MAIL: \n" );

     controle =1;
  }


    }while(controle !=2);





       char *palavra = &email[0];

       while(*palavra != '\0'){
            *Ldigitada = *palavra;
            ++palavra;
            ++Ldigitada;


        }
    *Ldigitada ='\0';



}



int idade(int dia,int mes,int ano)
{

    int idade;

    struct tm tempo;
    time_t tempoSeg;

    time(&tempoSeg);
    tempo= *localtime(&tempoSeg);

    struct data atual;

    atual.ano = tempo.tm_mday;
    atual.mes = tempo.tm_mon + 1;
    atual.ano = tempo.tm_year + 1900;

    idade = atual.ano - ano;
    if(mes > atual.mes){
    idade = idade-1;
    }else if((mes == atual.mes)&(dia > atual.mes)){
    idade= idade -1;
    }

    return idade;
}

void salvar(PESSOA paciente){


    FILE *salvarPaciente;
    salvarPaciente = fopen("pacientes.txt","a");
    if(salvarPaciente == NULL){
        printf("ERRO");
        getchar();
        exit(0);
    }
    else{
    fprintf(salvarPaciente,"\n----------------------- \n");

    fprintf(salvarPaciente,strcat(paciente.nome,"\n"));

    fprintf(salvarPaciente,strcat(paciente.cpf,"\n"));

    fprintf(salvarPaciente,strcat(paciente.telefone,"\n"));

    fprintf(salvarPaciente,"\n ENDERECO: \n");

    fprintf(salvarPaciente,strcat(paciente.rua,"\n"));

    char numcasa[10];
    sprintf(numcasa, "%i", paciente.numeroCasa);
    fprintf(salvarPaciente,strcat(numcasa,"\n"));

    fprintf(salvarPaciente,strcat(paciente.bairro,"\n"));

    fprintf(salvarPaciente,strcat(paciente.cidade,"\n"));

    fprintf(salvarPaciente,strcat(paciente.estado,"\n"));

    char numCep[10];
    sprintf(numCep, "%i", paciente.cep);
    fprintf(salvarPaciente,strcat(numCep,"\n"));

    char numDia[10];
    sprintf(numDia, "%i", paciente.diaNasc);
    fprintf(salvarPaciente,strcat(numDia," /"));

    char numMes[10];
    sprintf(numMes, "%i", paciente.mesNasc);
    fprintf(salvarPaciente,strcat(numMes," /"));

     char numAno[10];
    sprintf(numAno, "%i", paciente.anoNasc);
    fprintf(salvarPaciente,strcat(numAno,"\n"));

      char numIdade[10];
    sprintf(numIdade, "%i", paciente.idade);
    fprintf(salvarPaciente,strcat(numIdade,"\n"));

    fprintf(salvarPaciente,strcat(paciente.email,"\n"));

     char diaDiag[10];
    sprintf(diaDiag, "%i", paciente.diaDiag);
    fprintf(salvarPaciente,strcat(diaDiag," /"));

    char mesDiag[10];
    sprintf(mesDiag, "%i", paciente.mesDiag);
    fprintf(salvarPaciente,strcat(mesDiag," /"));

     char anoDiag[10];
    sprintf(anoDiag, "%i", paciente.anoDiag);
    fprintf(salvarPaciente,strcat(anoDiag,"\n"));



    fclose(salvarPaciente);
printf("\n \n SALVO COM SUCESSO NO BANCO DE PACIENTES \n");

}

}


void salvarGRisco(PESSOA paciente){


    FILE *salvarGRisco;
    salvarGRisco = fopen("GrupodeRisco.txt","a");
    if(salvarGRisco == NULL){
        printf("ERRO");
        getchar();
        exit(0);
    }
    else{
    fprintf(salvarGRisco,"\n----------------------- \n");

     char numIdade[10];
    sprintf(numIdade, "%i", paciente.idade);
    fprintf(salvarGRisco,strcat(numIdade,"\n"));

    char numCep[10];
    sprintf(numCep, "%i", paciente.cep);
    fprintf(salvarGRisco,numCep);

    fprintf(salvarGRisco,"\n----------------------- \n");

    fclose(salvarGRisco);

printf("\n \n SALVO COM SUCESSO NO BANCO DE PACIENTES DO GRUPO DE RISCO \n");

menu();

}

}


