#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em momória
#include <locale.h> // Biblioteca de alocação de texto por região 
#include <string.h> // Biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
    // criação de variáveis/string 
    char arquivo[40]; 
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // fim da criação de variáveis/string 
    
    printf("Digite o CPF a ser cadastrado :"); // coletando dados do usuário
	scanf("%s",cpf); // %s refere-se às string
	
	strcpy(arquivo, cpf); //Responsável por criar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); // salva o valor da variável
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualiza o arquivo
	fprintf(file,",");
	fclose(file);// fecha o arquivo
	
	printf("Digite o nome a ser cadastrado :"); // coletando dados do usuário
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("Digite o sobrenome a ser cadastrado :"); // coletando dados do usuário
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
		
	printf("Digite o cargo a ser cadastrado :"); // coletando dados do usuário
	scanf("%s",cargo);
	
	
	system("pause");
	 
}
int consulta()
{
    setlocale(LC_ALL, "portuguese"); // Definindo a linguagem


	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado :");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas são as informações do usuário :");
		printf("%s,",conteudo);
		printf("\n\n");
	}
	
	system("pause");



}
int deletar()
{
    char cpf[40];

	printf("Digite o CPF do usuário a ser deletado :");
	scanf("%s",cpf);
	
	remove(cpf); 
	
	FILE *file;
	file = fopen(cpf,"r");
	
		
	if(file == NULL)
	{
		printf("Usuário não encontrado no sistema!\n");
	    system("pause");
	}  

	if(file != NULL)
	{
	    fclose(file);
     	printf("O usuário foi deletado com sucesso!\n");
    	system("pause");
    	remove("cpf");
	}
	

}
  
int main()
    {
 
	int opcao=0; // Definindo as variáveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n"); 
	printf("Login de adminstrador!\n\nDigite a sua senha! ");
	scanf("%s",senhadigitada);

	comparacao = strcmp(senhadigitada, "admin");
    
    if(comparacao ==0)
    {
		system ("cls");
    	for(laco=1;laco=1;)
    	{
	
	    
	
	       setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
	
	       printf("### Cartório da EBAC ###\n\n"); // Início do menu
	       printf("Escolha a opção desejada do menu:\n\n");
	       printf("\t1 - Registrar nomes\n");
	       printf("\t2 - Consultar nomes\n");
	       printf("\t3 - Deletar nomes\n"); 
	       printf("\t4 - Sair do sistema\n");
	       printf("Opção:"); // Fim do menu

	       scanf("%d", &opcao); // Armazenando a escolha do usuário
	
	       system("cls");
	
	
   	       switch(opcao)
           {
	        	case 1:
	        	registro();
	        	break;
	    
	            case 2:
	        	consulta();
   	        	break;
    		
            	case 3:	
            	deletar();
            	break;
     	
            	case 4:
            	printf("Obrigado por utilizar o sistema!\n");
            	return 0;
            	break;
     		 	 	
            	default:
   	            printf("Opção inválida!\n"); 
   	         	system("pause");
   	         	break;
       	    }
	    }
	
	}
	
	else
		printf("Senha incorreta!");
	
}


	
