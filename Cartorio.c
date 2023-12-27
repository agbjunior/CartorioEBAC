#include <stdio.h> // biblioteca de comunicação com o usuario
#include <stdlib.h>  // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() // Função responsável por cadastrar os usuários no sistema
{
	// início criação de variáveis/string 
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	// final criação de variáveis/string
	
	printf("Digite o cpf a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", cpf); // %s refere-se as string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w");  // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo
	fprintf(file, ","); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // coletando informações do usuário
	scanf("%s", nome); // %s refere-se as string
	
	file = fopen(arquivo, "a");  //cria o arquivo
	fprintf(file,nome); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, ","); // salvo o valor da variável
	fclose(file);  // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando informações do usuário
	scanf("%s", sobrenome); // %s refere-se as string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,sobrenome); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, ","); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // coletando informações do usuário
	scanf("%s", cargo); // %s refere-se as string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,cargo); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	system("pause");
	
}

int Consulta()
{
	setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
	// início criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	// final criação de variáveis/string
	
	printf("Digite o cpf a ser consultado: "); // coletando informações do usuário
	scanf("%s",cpf); // %s refere-se as string
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); // cria o arquivo
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int Deletar()
{
    char cpf[40];
    
    printf ("Digite o cpf do usuário a ser deletado: "); // coletando informações do usuário
    scanf("%s",cpf); // %s refere-se as string
    
    remove(cpf);
    
    FILE *file; // cria o arquivo
    file = fopen(cpf, "r"); // cria o arquivo
    
    if(file == NULL)
    {
    	printf("O usuário nao se encontra no sistema!.\n");
    	system("pause");	
	}
    
    
}

int main ()
    {
	int opcao=0; //Definindo Variáveis 
	int x=1;
		
	for(x=1;x=1;)	
{
		system("cls"); // responsável por limpar a tela

		setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
		
 		printf("Cartório da EBAC\n\n"); //Início do menu	
 		printf("Escolha a opção desejada do menu:\n\n");
 		printf("\t1 - Inclusão de usuários\n");
 		printf("\t2 - Consulta de usuários\n");
 		printf("\t3 - Deletar usuários\n\n"); 
 		printf("\t4 - Sair do sistema\n\n");
 		printf("Opção:");// Fim do menu
 
 		scanf("%d", &opcao); // armazenando a escolha do usuário
 
 		system ("cls");
 		
 		switch(opcao) // início da seleção do menu
			
		{
			case 1:
			registro(); // chamada de funções
			break;
			
			case 2:
			Consulta(); // chamada de funções
			break;
			
			case 3:
			Deletar(); // chamada de funções	
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf ("Não existe essa função, tente novamente!\n");
			system("pause");
			break;
		
		}  	
	}	

}



