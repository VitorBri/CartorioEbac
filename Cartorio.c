#include <stdio.h> // bliblioteca de comunicação
#include <stdlib.h> // bliblioteca de alocção de memória
#include <locale.h> // bliblioteca de texto por região 
#include <string.h> // bliblioteca responsável pela string




int registro() //Função de cadastro
	{
		
		//inicio criação de varíaveis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo [40];
		//final criação de varíaveis/string
		
		printf("Digite o CPF a ser cadastrado: "); // coletando informação do cliente
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
		
		
		printf("Digite o nome a ser cadastrado: "); // coletando informação do cliente
		scanf("%s" , nome);//refere-se a string
		
		file = fopen(arquivo, "a"); //abre o aquivo para a adiocionar valor
		fprintf(file, nome);// salva o valor da varaivel
		fclose(file);// fecha o arquivo
		
		file =  fopen(arquivo, "a");//abre o aquivo para a adiocionar valor
		fprintf(file,", SOBRENOME:");
		fclose(file);// fecha o arquivo
		
		printf("Digite o sobrenome a ser cadastrado: "); // coletando informação do cliente
		scanf("%s" ,sobrenome);//refere-se a string
		
		file = fopen(arquivo, "a");//abre o aquivo para a adiocionar valor
		fprintf(file, sobrenome);// salva o valor da varaivel
		fclose(file);// fecha o arquivo
		
		file =  fopen(arquivo, "a");//abre o aquivo para a adiocionar valor
		fprintf(file,", CARGO:");
		fclose(file);// fecha o arquivo
			
		printf("Digite o cargo a ser cadastrado: "); // coletando informação do cliente
		scanf("%s" , cargo);//refere-se a string
		
		file = fopen(arquivo, "a");//abre o aquivo para a adiocionar valor
		fprintf(file, cargo);// salva o valor da varaivel
		fclose(file);// fecha o arquivo
		
		system("pause");
			
	}
int consulta()//Função de consulta
	{
		setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
		
		//inicio criação de varíaveis/string
		char cpf[40];
		char conteudo[200];
		//final criação de varíaveis/string
		
		printf("Digite o CPF a ser consultado: ");// coletando informação do cliente
		scanf("%s", cpf);//refere-se a string
		
		FILE *file;//busca o arquivo
		file = fopen(cpf,"r");// ler o arquivo
		
		if(file == NULL)// Se não achar a informação
			{
				printf("Não foi possivel abrir o arquivo, não localizado!.\n");
				
			}
		
		while(fgets(conteudo, 200, file) != NULL)// Se achar a informação
			{
				printf("\nEssas são as informações do usuário:");
				printf("%s\n", conteudo);
				printf("\n\n");
			}
		
		system("pause");
	}
int deletar()//Função de deletar
	{
		char cpf[40];//criação de varíaveis/string
		
		printf("Digite o CPF do usuário ser deletado: ");// coletando informação do cliente
		scanf("%s",cpf);//refere-se a string
		
		remove(cpf);//remover informações
		
		FILE *file;//busca o arquivo
		file =fopen(cpf,"r");// ler o arquivo
		
		if(file == NULL)// Se não achar a informação
			{
				printf("\nO usuário não se encontra no sistema!.\n");
				printf("\n\n");
				system("pause");
			} 
	}
	 
	
int main()
{	
	int opcao=0; //Defininfo Variáveis 
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{	
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
		
		printf("### Cartório Da Ebac ###\n\n"); //Inicio do menu
		
		printf("Escolha a opção desejada do menu:\n\n"); //Opções do menu
		
			printf("\t1 -Registrar Nomes \n");
			printf("\t2 -Consultar Nomes \n");
			printf("\t3 -Deletar Nomes \n\n");
			printf("\t4 -Sair do sistema\n\n");
			printf("Opção: "); //Fim do menu
			
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		
		system("cls");//responsavel por limpar a tela
		
		//inicio da seleção do menu
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
				
				
				default://Opções inexistentes
				printf("Essa opção não esta disponivel!\n");
				system("pause");
				break;
				
			}
		//fim da seleção	
	}

}
 
