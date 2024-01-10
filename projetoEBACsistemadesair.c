#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //definindo função de cadastrar o usuário no sistema
{
	//início da criação das variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação das variáveis/strings
	
	printf("Digite o seu CPF para cadastrar:\n"); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se à string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	

	FILE *file; //acessa e cria arquivo
	file = fopen(arquivo, "w"); //cria arquivo
	fprintf(file, "CPF:");
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre arquivo e adiciona itens
	fprintf(file, "\nNome:");
	fclose(file);
	
	printf("Digite seu nome para cadastrar:\n");
	scanf("%s", nome);
	
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSobrenome:");
	fclose(file);
	
	printf("Digite seu sobrenome para cadastrar:\n");
	scanf("%s", sobrenome);
	
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nCargo:");
	fclose(file);
	
	printf("Digite o cargo na empresa para cadastrar:\n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf(file, "\n");
	fclose(file);
	
	system("pause");
	

	
	
}

int consulta ()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf que deseja consultar:\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //ler arquivo
	
	if(file == NULL)
	{
		printf("Arquivo não localizado\n");
	}
	
	    printf("\nEssas são as informações do usuário:\n\n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
		printf("\n");
	}
	
	    fclose(file);
	    system("pause");
		
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf que deseja deletar:\n");
	scanf("%s", cpf);
	
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	
	if(file == NULL) //se o arquivo for igual à nulo
	{
		printf("Usuário não encontrado\n");
		system("pause");
	}
	
	else //senão, deleta o arquivo
	{
		remove(cpf); //função de deletar
		printf("Usuário deletado\n");
	}
	
	system("pause");
	
    
	
}

int main ()
{
	int opcao=0; //definindo variáveis
	int laco=1; //definindo repetições
	
	for (laco=1;laco=1;)
	{
		
		system ("cls"); //sistema de limpar a tela
		
	
	    setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	    printf("### Cartório da EBAC ### \n\n"); //início do menu
	    printf("Escolha a opção desejada no menu: \n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
	    printf ("Opção: "); //fim do menu
	
	    scanf ("%d", &opcao); //armazenando a escolha do usuário
	
	    system ("cls");
	    
	    switch(opcao)
	    {
	    	case 1:
	    	registro(); //chamada de funções
		    break;
		    
		    case 2:
		    consulta();
		    break;
		    
		    case 3:
		    deletar();
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar nosso sistema!\n");
		    return 0; //quebra de laço/repetição/função
		    break;
		    
		    default: 
		    printf ("Esta opção não está disponível\n");
		    system ("pause");
		    	
} //fim da seleção
	

	
}
}
