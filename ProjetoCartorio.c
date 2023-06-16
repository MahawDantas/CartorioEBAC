#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //início das funções
{	
	char arquivo[40]; //início das opções de registro
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //fim das opções de registro
	
	printf("Digite o CPF do usuário a ser cadastrado: \n");
	scanf("%s", cpf); //armazenando a informação do usuário(%s refere-se a string)
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //abre o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); //salva a informação da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ","); //separação das informações de registro com vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o Nome do usuário a ser cadastrado: \n");
	scanf("%s", nome); //armazenando a informação do usuário(%s refere-se a string)
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, nome); //salva a informação da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, " "); //separação das informações de registro com espaço
	fclose(file); //fecha o arquivo
	
	printf("Digite o Sobrenome do usuário a ser cadastrado: \n");
	scanf("%s", sobrenome); //armazenando a informação do usuário(%s refere-se a string)
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, sobrenome); //salva a informação da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ","); //separação das informações de registro com vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o Cargo do usuário a ser cadastrado: \n");
	scanf("%s", cargo); //armazenando a informação do usuário(%s refere-se a string)
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, cargo); //salva a informação da variável
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa até que o usuário ordene o contrário
	
}

int consulta()
{
	char cpf[40]; //início das opções de consulta
	char conteudo[200]; //fim das opções de consulta
	
	printf("Digite o CPF do usuário a ser consultado: \n");
	scanf("%s", cpf); //armazenando a informação do usuário(%s refere-se a string)
	
	FILE *file; //abre o arquivo
	file = fopen(cpf, "r"); //lê o arquivo
	
	if(file == NULL) //caso não fale o cpf registrado
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto houver conteúdo no arquivo 
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); //armazenando a informação do usuário(%s refere-se a string)
		printf("\n\n"); //pulando linhas
	}
	
	system("pause"); //pausa até que o usuário ordene o contrário
	
	fclose(file);	
}

int deletar()
{
	char cpf[40]; //opção de deletar
	
	printf("Digite o CPF do usuário a ser deletado: \n");
	scanf("%s", cpf); //armazenando a informação do usuário(%s refere-se a string)
	
	remove(cpf); //deletando o cpf
	
	FILE *file; //abre o arquivo
	file = fopen(cpf, "r"); //lê o arquivo
	
	if(file == NULL) //caso não fale o cpf registrado
	{
		printf("O usuário não se encontra no sistema. \n");
		system("pause"); //pausa até que o usuário ordene o contrário
	}	
} //fim das funções
 
 
 
int main()
{	
	int opcao = 0; //definindo as variáveis
	int laco = 1; //definindo as variáveis
	
	for(laco = 1; laco = 1;) //mantém o menu rodando até que o usuário ordene o contrário
	{
		
		system("cls"); //limpa a tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar Informações\n");
		printf("\t2 - Consultar Informações\n");
		printf("\t3 - Deletar Informações\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opção: ");	//fim do menu

		scanf("%d", &opcao); //armazenando a escolha do usuário(%d refere-se a inteiro)

		system("cls"); //limpa a tela
		
		switch(opcao) //início da seleção
		{
			case 1: //case = caso seja
			registro(); //função chamada
			break; //encerra o case
			
			case 2: //case = caso seja
			consulta(); //função chamada
			break; //encerra o case
			
			case 3: //case = caso seja
			deletar(); //função chamada
			break; //encerra o case
			
			case 4: //case = caso seja
			printf("Obrigado por utilizar o sistema!\n");
			return 0; //quebra tudo e sai do sistema
			break; //encerra o case
			
			default: //caso seja qualquer número fora dos cases
			printf("Esta opção não está disponível!\n");
			system("pause"); //pausa até que o usuário ordene o contrário
			break; //encerra o case
		} //fim da seleção
		
	}	
}
