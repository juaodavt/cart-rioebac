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
   fprintf(file,cpf); // salva o valor da variável
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
   	  printf("Não foi possivel abrir o arquivo, não localizado");
   }
   
   while(fgets(conteudo,200, file) != NULL)
   {
   	printf("\nEssas são as informações do usuário: ");
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
     	printf("O usuário não se encontra no sistema!.\n ");
     	system("pause");
     	
     	printf("O usuário foi deletado com sucesso\n");
     	system("pause");
     	
     
	 }
     
}


int main()
{
	int opcao=0; // definido variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); // responsavel por limpar a tela 
		
		setlocale(LC_ALL, "portuguese");
		
		printf("### cartório da EBAC ###\n\n"); // inicio do menu
		printf("escolha a opção desejada do menu\n\n ");
		printf("\t1 - registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - deletar nomes\n\n");
		printf("\t4 - sair do sistema\n\n");
		printf("opção: "); // fim do menu
		
		
		scanf("%d", &opcao); // armazenando a escolha do usuário 
		
		system("cls");
		
		switch(opcao) // inicio da seleção do menu
		{
			case 1:
			registro(); // chamada de funções 
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
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;	
		} // fim da seleção
   }

}
