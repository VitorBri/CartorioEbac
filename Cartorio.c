#include <stdio.h> // bliblioteca de comunica��o
#include <stdlib.h> // bliblioteca de aloc��o de mem�ria
#include <locale.h> // bliblioteca de texto por regi�o 
#include <string.h> // bliblioteca respons�vel pela string




int registro() //Fun��o de cadastro
	{
		
		//inicio cria��o de var�aveis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo [40];
		//final cria��o de var�aveis/string
		
		printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do cliente
		scanf("%s", cpf);//refere-se a string
		
		strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings 
		
		FILE *file; // cria o arquivo
		file = fopen(arquivo,"w" ); // cria o arquivo
		fprintf(file," CPF:");
		fprintf (file ,cpf); // salva o valor da varaivel 
		fclose(file);  // fecha o arquivo 
		
		file =  fopen(arquivo, "a");//abre o aquivo para a adiocionar valor
		fprintf(file,", NOME:");
		fclose(file);
		
		
		printf("Digite o nome a ser cadastrado: "); // coletando informa��o do cliente
		scanf("%s" , nome);//refere-se a string
		
		file = fopen(arquivo, "a"); //abre o aquivo para a adiocionar valor
		fprintf(file, nome);// salva o valor da varaivel
		fclose(file);// fecha o arquivo
		
		file =  fopen(arquivo, "a");//abre o aquivo para a adiocionar valor
		fprintf(file,", SOBRENOME:");
		fclose(file);// fecha o arquivo
		
		printf("Digite o sobrenome a ser cadastrado: "); // coletando informa��o do cliente
		scanf("%s" ,sobrenome);//refere-se a string
		
		file = fopen(arquivo, "a");//abre o aquivo para a adiocionar valor
		fprintf(file, sobrenome);// salva o valor da varaivel
		fclose(file);// fecha o arquivo
		
		file =  fopen(arquivo, "a");//abre o aquivo para a adiocionar valor
		fprintf(file,", CARGO:");
		fclose(file);// fecha o arquivo
			
		printf("Digite o cargo a ser cadastrado: "); // coletando informa��o do cliente
		scanf("%s" , cargo);//refere-se a string
		
		file = fopen(arquivo, "a");//abre o aquivo para a adiocionar valor
		fprintf(file, cargo);// salva o valor da varaivel
		fclose(file);// fecha o arquivo
		
		system("pause");
			
	}
int consulta()//Fun��o de consulta
	{
		setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
		
		//inicio cria��o de var�aveis/string
		char cpf[40];
		char conteudo[200];
		//final cria��o de var�aveis/string
		
		printf("Digite o CPF a ser consultado: ");// coletando informa��o do cliente
		scanf("%s", cpf);//refere-se a string
		
		FILE *file;//busca o arquivo
		file = fopen(cpf,"r");// ler o arquivo
		
		if(file == NULL)// Se n�o achar a informa��o
			{
				printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
				
			}
		
		while(fgets(conteudo, 200, file) != NULL)// Se achar a informa��o
			{
				printf("\nEssas s�o as informa��es do usu�rio:");
				printf("%s\n", conteudo);
				printf("\n\n");
			}
		
		system("pause");
	}
int deletar()//Fun��o de deletar
	{
		char cpf[40];//cria��o de var�aveis/string
		
		printf("Digite o CPF do usu�rio ser deletado: ");// coletando informa��o do cliente
		scanf("%s",cpf);//refere-se a string
		
		remove(cpf);//remover informa��es
		
		FILE *file;//busca o arquivo
		file =fopen(cpf,"r");// ler o arquivo
		
		if(file == NULL)// Se n�o achar a informa��o
			{
				printf("\nO usu�rio n�o se encontra no sistema!.\n");
				printf("\n\n");
				system("pause");
			} 
	}
	 
	
int main()
{	
	int opcao=0; //Defininfo Vari�veis 
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{	
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
		
		printf("### Cart�rio Da Ebac ###\n\n"); //Inicio do menu
		
		printf("Escolha a op��o desejada do menu:\n\n"); //Op��es do menu
		
			printf("\t1 -Registrar Nomes \n");
			printf("\t2 -Consultar Nomes \n");
			printf("\t3 -Deletar Nomes \n\n");
			printf("\t4 -Sair do sistema\n\n");
			printf("Op��o: "); //Fim do menu
			
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls");//responsavel por limpar a tela
		
		//inicio da sele��o do menu
		switch(opcao)
			{	
				case 1:// Registrar Nomes
				registro();
				break;
				
				case 2://Consultar Nomes
				consulta();
				break;
				
				
				case 3://Deletar Nomes
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistama!\n");
				return 0;
				break;
				
				
				default://Op��es inexistentes
				printf("Essa op��o n�o esta disponivel!\n");
				system("pause");
				break;
				
			}
		//fim da sele��o	
	}

}
 
