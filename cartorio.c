#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
int registro()
{
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   
   printf("Digite o CPF a ser cadastrado: ");
   scanf("%s",cpf);
   
   strcpy(arquivo, cpf); // responsavel por copiar os valores das string
   
   FILE *file; // cria o arquivo
   file = fopen(arquivo, "w"); // cria o arquivo e "W" significa escrever 
   fprintf(file,cpf); // salva o valor da vari�vel
   fclose(file); // fecha o arquivo
   
   file = fopen(arquivo, "a");
   fprintf(file, ",");
   fclose(file);
   
   printf("Digite o nome a ser cadastrado: ");
   scanf("%s",nome);
   
      file = fopen(arquivo, "a");
   fprintf(file, nome);
   fclose(file);
   
      file = fopen(arquivo, "a");
   fprintf(file, ",");
   fclose(file);
   
   
   printf("Digite o sobrenome a ser cadastrado: ");
   scanf("%s",sobrenome);
   
     file = fopen(arquivo, "a");
   fprintf(file,sobrenome);
   fclose(file);
   
      file = fopen(arquivo, "a");
   fprintf(file, ",");
   fclose(file);
   
   printf("Digite o cargo a ser cadastrado: ");
   scanf("%s",cargo);
   
     file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);
   
   system("pause");
   
}

int consulta()
{
   setlocale(LC_ALL, "portuguese"); // definindo a liguagem
   char cpf[40];
   char conteudo[200];
   
   printf("Digite o CPF a ser consultado: ");
   scanf("%s",cpf);
   
   FILE *file;
   file = fopen(cpf, "r");
   
   if(file == NULL)
   {
   	  printf("N�o foi possivel abrir o arquivo, n�o localizado");
   }
   
   while(fgets(conteudo,200, file) != NULL)
   {
   	printf("\nEssas s�o as informa��es do usu�rio: ");
   	printf("%s",conteudo);
   	printf("\n\n");
   }
   
   system("pause");
}
int deletar()
{
     char cpf[40];
     
     printf("digite o cpf a ser deletado: ");
     scanf("%s",cpf);
     
     remove(cpf);
     
     FILE *file;
     file = fopen(cpf, "r");
      
     if(file == NULL)
     {
     	printf("O usu�rio n�o se encontra no sistema!.\n ");
     	system("pause");
     	
     	printf("O usu�rio foi deletado com sucesso\n");
     	system("pause");
     	
     
	 }
     
}


int main()
{
	int opcao=0; // definido vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); // responsavel por limpar a tela 
		
		setlocale(LC_ALL, "portuguese");
		
		printf("### cart�rio da EBAC ###\n\n"); // inicio do menu
		printf("escolha a op��o desejada do menu\n\n ");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n\n");
		printf("\t4 - sair do sistema\n\n");
		printf("op��o: "); // fim do menu
		
		
		scanf("%d", &opcao); // armazenando a escolha do usu�rio 
		
		system("cls");
		
		switch(opcao) // inicio da sele��o do menu
		{
			case 1:
			registro(); // chamada de fun��es 
			system("pause");
			break;
	
			case 2:
			consulta();
			system("pause");
			break;
			
			case 3:
			deletar();
			system("pause");
			break;
			
		    case 4:
		    printf("obrigado por utilizar o sistema!\n");
		    return 0;
		    break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;	
		} // fim da sele��o
   }

}
