#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<windows.h> //substituir do <unistd.h> para que a funcao loading nao de problema, e tambem na funcao loading o usleep pelo sleep
#include <unistd.h>
#include <locale.h>
//===========STRUCTS=====================
struct Livro
{
    int ISBN;//numeracao unica do livro
    int ano_lancamento;//ano de lancamento do livro
    char nome_livro[31];//nome do livro
    char autor [30];//autor do livro
    int num_paginas;//numero de paginas
    char edicao [20];//edicao do livro
    float nota;//nota de 0 a 10 do livro
    int estante[11];
};
struct usuario
{
    char nome [31];
    int senha;
    struct Livro Livro [11];
    int atividade;
    int serial;
    
    int livros_cadastrados;
    int livros_sobra;
    float melhor_nota;
    char melhorLivro_nota [31];
    int mais_pag;
    char melhorLivro_pag [31];
    float pior_nota;
    char piorLivro_nota [31];
    int menos_pag;
    char piorLivro_pag [31];
    
    
};

//SISTEMA DE LOADING========================
void loading(){

	int i, j, k;
	char simboloum = '|';
	char simbolodois = '/';

	for(i = 0; i <= 2; i++){
        printf("\r");//A BARRA DE LOADING APARECE 3 VEZES COM ESSE FOR
		printf("Carregando");


	for(j = 0; j <=8; j++){
		printf("%c", simboloum);//A BARRA "I" APARECE 1 VEZ, DESDE PRO FOR K
		fflush(stdout);
		//Sleep (200);
		usleep(200000);//Aqui tem 0.2 segundos de intervalo
		for(k = 0; k <= 0; k++){
			printf("%c", simbolodois);//APARECE A BARRA "/" EM REVEZAMENTO COM A DE CIMA
			fflush(stdout);


		}
	}
	}
	printf("%c", simboloum);
}


//0.Aqui comeca o login da conta=======================
void login(struct usuario *u){
    int lixo, erros = 0;

    char escolha_usuario [11];
    char Usuario_A [10] ="Usuario A";
    char Usuario_B [10] ="Usuario B";
    char Usuario_C [10] ="Usuario C";


    printf("||Usuario A ==== Usuario B ==== Usuario C||\n\n");

    do
    {
		u->atividade = 0;

        printf("Escolha qual Usuario deseja Utilizar:");
        scanf("%[a-z A-Z]", escolha_usuario);
        printf("%s\n", escolha_usuario);
        while ((lixo = getchar()) != '\n' && lixo != EOF);//Limpa todos os Lixos da memoria criados pelos /n
        //Compara as strings para identificar qual dos Usuarios acima foi escolhido
        if (strcmp(escolha_usuario,Usuario_A) == 0) {
            u->serial = 1;
            printf("Escolha Seu Nome:");
            scanf("%[a-z A-Z]", u->nome);
            printf("\nDigite Sua Senha em numeros:");
            scanf("%d", &u->senha);
            u->atividade = 1;


            erros = 6;
        }
        else if (strcmp(escolha_usuario,Usuario_B) == 0) {
            u->serial = 2;
            printf("Escolha Seu Nome:");
            scanf("%[a-z A-Z]", u->nome);
            printf("\nDigite Sua Senha:");
            scanf("%d", &u->senha);
            u->atividade = 1;

            erros = 6;
        }
        else if (strcmp(escolha_usuario,Usuario_C) == 0) {
            u->serial = 3;
            printf("Escolha Seu Nome:");
            scanf("%[a-z A-Z]", u->nome);
            printf("\nDigite(apenas em numeros) Sua Senha:");
            scanf("%d", &u->senha);
            u->atividade = 1;

            erros = 6;
        }
        else//Existe um limite para os erros de ate 5 vezes de digitacao
            printf ("Digite Novamente\n\n");
        erros++;

        if (erros == 5) {
            printf("Suas Tentativas Acabaram");
            erros = 6;
        }
    } while (erros < 6);
}


//1.Aqui comeca a funcao de adicionar um livro=====================
void escolha_liv(struct usuario *u)
{
    int escolha_livro, lixo, contagem;



	contagem = 1;
        printf("Escolha Qual da Lista Deseja Criar\n");
        printf("1.Livro||2.Livro||3.Livro||4.Livro||5.Livro||\n||6.Livro||7.Livro||8.Livro||9.Livro||10.Livro\n\n");
    do
    {
        printf("Escolha:");
        scanf ("%d", &escolha_livro);
        if (u->Livro[escolha_livro].estante[escolha_livro] != 1)
        {
            while ((lixo = getchar()) != '\n' && lixo != EOF);
            printf("Qualquer informacao pode ser alterada no futuro\n");
            printf("================================\n");

            printf("Digite o nome do Livro:");
            scanf("%[a-z A-Z]", u->Livro[escolha_livro].nome_livro);

            printf("Digite o nome do Autor:");
            while ((lixo = getchar()) != '\n' && lixo != EOF);
            scanf("%[a-z A-Z]", u->Livro[escolha_livro].autor);

            printf("Digite o numero do livro/ISBN:");
            scanf("%d", &u->Livro[escolha_livro].ISBN);

            while ((lixo = getchar()) != '\n' && lixo != EOF);

            printf("Digite a edicao do livro por extenso:");
            scanf("%[a-z A-Z]", u->Livro[escolha_livro].edicao);

            printf("Digite o Ano de lancamento do livro:");
            scanf("%d", &u->Livro[escolha_livro].ano_lancamento);

            printf("Digite o numero de paginas do livro:");
            scanf ("%d", &u->Livro[escolha_livro].num_paginas);

            printf("De sua nota de 0 a 10 para %s:", u->Livro[escolha_livro].nome_livro);
            scanf ("%f", &u->Livro[escolha_livro].nota);

            while ((lixo = getchar()) != '\n' && lixo != EOF){}


//=====DADOS DAS ESTATISTICAS ENTRAM POR AQUI ==================



             u->Livro[escolha_livro].estante[escolha_livro] = 1;
            
             u->livros_cadastrados = u->livros_cadastrados + 1;
        
             u->livros_sobra = u->livros_sobra - 1;
             
             if (u->Livro[escolha_livro].nota > u->melhor_nota)
             {
             	u->melhor_nota = u->Livro[escolha_livro].nota;
             	strcpy(u->melhorLivro_nota, u->Livro[escolha_livro].nome_livro);
             }
            
            if (u->Livro[escolha_livro].num_paginas > u->mais_pag)
            {
             	u->mais_pag = u->Livro[escolha_livro].num_paginas;
             	strcpy(u->melhorLivro_pag, u->Livro[escolha_livro].nome_livro);
            }
        
            if (u->Livro[escolha_livro].nota < u->pior_nota)
            {
             	u->pior_nota = u->Livro[escolha_livro].nota;
             	strcpy(u->piorLivro_nota, u->Livro[escolha_livro].nome_livro);
            }
            
            if (u->Livro[escolha_livro].num_paginas < u->menos_pag)
            {
             	u->menos_pag = u->Livro[escolha_livro].num_paginas;
             	strcpy(u->piorLivro_pag, u->Livro[escolha_livro].nome_livro);
            }
            
             
             
             
             
 //==========CONTINUACAO DE ADICIONAR LIVRO====================

             if (escolha_livro <= 1 && escolha_livro > 10)
             {
                 contagem = escolha_livro;
             }
             printf("===LIVRO SALVADO COM SUCESSO!===");
             printf("\n===============================\n");
         }
         else if (u->Livro[escolha_livro].estante[escolha_livro] != 0)
        {
            printf("ESTANTE CHEIA, TENTE OUTRO LIVRO\n\n");
            contagem = escolha_livro;
        }

    } while (contagem == escolha_livro);
}
//=============================================================

//====================5.PESQUISA===============================

int pesquisa (struct usuario *u)

{

	char escolha_usuario [31];



	int i,contador = 1, contador2, lixo;



	for (contador = 1; contador <= 11; contador++){

		while ((lixo = getchar()) != '\n' && lixo != EOF);
		printf("\n===Pesquise===\n");
		printf("Digite o Livro:");

		scanf("%[a-z A-Z]", escolha_usuario);



		for (contador2 = 1; contador2 <= 10; contador2++){



			i = strcmp(escolha_usuario, u->Livro[contador2].nome_livro);
//AQUI ACONTECE UMA COMPARACAO DE STRING, SENDO IGUAL = 0


			if (i == 0 && u->Livro[contador2].estante[contador2] == 1){

				loading();
//PUXO A FUNCAO LOADING POR QUESTAO ESTETICO
				printf("\n\n%s Encontrado\n", u->Livro[contador2].nome_livro);

				return contador2;

				contador2 = 12;

			}

			else if (contador2 == 10 && i != 0){

				loading();

				printf("\nNao encontrado\n");

			}

		}

	}

}
//=============================================================

//==================2.EDITAR OS LIVROS==========================
void editar(struct usuario *u)
{
	   int escolha, n_livro, contagem = 1;
	   n_livro = pesquisa(u);
	   printf("\nO que deseja fazer?\n\n");

	   do
	   {

	   	printf("\n1.Nome do Livro Atual: %s\n", u->Livro[n_livro].nome_livro);
	   	printf("2.Nome do Autor: %s\n", u->Livro[n_livro].autor);
	   	printf("3.ISBN: %d\n", u->Livro[n_livro].ISBN);
	   	printf("4.edicao do livro: %s\n", u->Livro[n_livro].edicao);
	   	printf("5.Ano de lançamento: %d\n", u->Livro[n_livro].ano_lancamento);
	   	printf("6.Numero de paginas: %d\n", u->Livro[n_livro].num_paginas);
	   	printf("7.nota: %.2f\n", u->Livro[n_livro].nota);
	   	printf("8.Sair\n");
	   	printf("Digite o que deseja Editar:\n");
	   	scanf("%d", &escolha);


	   	switch (escolha)
	   	{
	   		case 1:
	   			printf("Digite:");
	   			scanf("%s", u->Livro[n_livro].nome_livro);
	   			contagem--;
	   			break;

	   		case 2:
	   			printf("Digite:");
	   			scanf("%s", u->Livro[n_livro].autor);
	   			contagem--;
	   			break;

	   		case 3:
	   			printf("Digite:");
	   			scanf("%d", &u->Livro[n_livro].ISBN);
	   			contagem--;
	   			break;

	   		case 4:
	   			printf("Digite:");
	   			scanf("%s", u->Livro[n_livro].edicao);
	   			contagem--;
	   			break;

	   		case 5:
	   			printf("Digite:");
	   			scanf("%d", &u->Livro[n_livro].ano_lancamento);
	   			contagem--;
	   			break;

	   		case 6:
	   			printf("Digite:");
	   			scanf("%d", &u->Livro[n_livro].num_paginas);
	   			contagem--;
	   			break;

	   		case 7:
	   			printf("Digite:");
	   			scanf("%f", &u->Livro[n_livro].nota);
	   			contagem--;
	   			break;

	   		case 8:
	   			printf("\nSaindo...\n===Salvo com sucesso===\n");
	   			contagem = 10;
	   			break;

	   		default:
	   			printf("Digite Novamente\n\n");
	   			contagem++;
	   	}

	   }while (contagem <9);
}
//============================================================

//Exclusao logico de livros========================================
void excluir (struct usuario *u)
{
 	int lista, escolha_usuario, contagem = 1, n_livro;
 	int escolha_usuario1;
 	do
 	{
 		printf("\n1.Excluir\n2.Sair\n\nDigite:");
 		scanf("%d", &escolha_usuario);
 	
 		switch (escolha_usuario)
 		{
 			case 1:
 				printf("Digite Qual livro deseja apagar\n\n");
 				n_livro = pesquisa(u);
 				
 				u->Livro[n_livro].estante[n_livro] = 0;
 				u->livros_cadastrados = u->livros_cadastrados - 1;
 				u->livros_sobra = u->livros_sobra + 1;
 				printf("\nLIVRO APAGADO COM SUCESSO\n");
			     contagem--;
			     break;
		      case 2:
	      		printf("\nSaindo");
	      		contagem = 11;
	      		break;
	      	default:
	      		printf("\nDigite Novamente\n");
 		}
 	}while (contagem < 11);
}
//===================================================
	      
//====================4.LISTAGEM=====================
void lista (struct usuario *u)
{
	 int lista;
	 printf("==========Listando Livros==========\n\n");
     for (lista = 1;lista <= 10; lista++)
     {
  		if (u->Livro[lista].estante[lista] == 1){
  			printf(">>%s \n", u->Livro[lista].nome_livro);
      	}
      	else if (u->Livro[lista].estante[lista] != 1){
          	printf("Estante Vazia\n");
      	}
      }
}
//=====================================================

//6.funcao das estatisticas================================
void estatisticas (struct usuario *u)
{
	
	printf("======= ESTATISTICAS =========\n\n");
	printf("Total de Livros: %d\n", u->livros_cadastrados);
	printf("Espaços Restantes: %d\n", u->livros_sobra);
	printf("Melhor Livro: %s (%.1f)\n",u->melhorLivro_nota, u->melhor_nota);
	printf("Maior Livro: %s (%d)\n", u->melhorLivro_pag, u->mais_pag);
	printf("Pior Livro: %s (%.1f)\n", u->piorLivro_nota, u->pior_nota);
	printf("Menor Livro: %s (%d)\n", u->piorLivro_pag, u->menos_pag);
	
	printf("=============================\n\n");
	
}

//=======================================================


//===============SISTEMA PRINCIPAL======================
int main()
{
    int escolha_menu = 0, contagem;
    struct usuario u;
    setlocale(LC_ALL, "Portuguese");

    for(contagem = 0; contagem <=11; contagem++){

        u.Livro[contagem].estante[contagem] = '0';

    }
    contagem = 0;
    printf("================================\n");
    printf("BEM VINDO A BIBLIOTECA VIRTUAL\n");
    printf("================================\n\n\n\n");

    login(&u);
	u.livros_cadastrados = 0;
	u.livros_sobra = 10;
	u.mais_pag = 0;
	u.melhor_nota = 0;
	u.pior_nota = 10;
	u.menos_pag = 9999;
    do
    {
        printf("\n==========MENU PRINCIPAL==========\n\n\n");
        printf("×÷×1.Criar Novo Livro\n×÷×2.Editar Livro\n×÷×3.Excluir Livro\n×÷×4.Listar\n×÷×5.Pesquisar\n×÷×6.Estatisticas\n×÷×7.Sair\n");

        printf("Escolha:");
        scanf ("%d", &escolha_menu);

        switch (escolha_menu)
        {
        case 1:
            escolha_liv(&u);
            contagem--;
            break;
        case 2:
            editar(&u);
            contagem--;
            break;

        case 3:
            excluir (&u);
            contagem--;
            break;

        case 4:
            lista(&u);
            contagem--;
            break;
        case 5:
        	pesquisa(&u);
            contagem--;
            break;
        case 6:
        	estatisticas(&u);
            contagem--;
            break;
		case 7:
			printf("Saindo");
			return 0;
        default:
            printf("Digite Novamente\n");
            contagem++;
        }


    } while (contagem <= 7);



}

