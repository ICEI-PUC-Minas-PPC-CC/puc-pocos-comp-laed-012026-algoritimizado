#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Livro
{
    int ISBN;//numeracao unica do livro
    int ano_lancamento;//ano de lancamento do livro
    char nome_livro[30];//nome do livro
    char autor [30];//autor do livro
    int num_paginas;//numero de paginas
    char edicao [20];//edicao do livro
    float nota;//nota de 0 a 10 do livro
};
struct usuario
{
    char nome [30];
    int senha;
    struct Livro Livro [10];
    char atividade [9];
};
int main()
{
    int lixo, erros = 0, serial = 0, escolha_menu = 0, escolha_livro, contagem = 0, contagem2, estante[10];
    struct usuario u[3];
    char y [2] ="x", n [2] ="l";
    char escolha_usuario [11];
    char Usuario_A [10] ="Usuario A";
    char Usuario_B [10] ="Usuario B";
    char Usuario_C [10] ="Usuario C";
    printf("================================\n");
    printf("BEM VINDO A BIBLIOTECA VIRTUAL\n");
    printf("================================\n\n\n\n");

    printf("||Usuario A ==== Usuario B ==== Usuario C||\n\n");

    do
    {

        printf("Escolha qual Usuario deseja Utilizar:");
        scanf("%[a-z A-Z]", &escolha_usuario);
        printf("%s\n", escolha_usuario);
        while ((lixo = getchar()) != '\n' && lixo != EOF);//Limpa todos os Lixos da memoria criados pelos /n
        //Compara as strings para identificar qual dos Usuarios acima foi escolhido
        if (strcmp(escolha_usuario,Usuario_A) == 0) {
            serial = 1;
            printf("Escolha Seu Nome:");
            scanf("%[a-z A-Z]", &u[0].nome);
            printf("\nDigite Sua Senha:");
            scanf("%d", &u[0].senha);
            strcpy(u[0].atividade,"ativo");
            printf("O USUARIO A ESTA ATIVO\n");
            printf("O USUARIO B ESTA EXCLUIDO\n");
            printf("O USUARIO C ESTA EXCLUIDO\n");

            erros = 6;
        }
        else if (strcmp(escolha_usuario,Usuario_B) == 0) {
            serial = 2;
            printf("Escolha Seu Nome:");
            scanf("%[a-z A-Z]", &u[1].nome);
            printf("\nDigite Sua Senha:");
            scanf("%d", &u[1].senha);
            strcpy(u[1].atividade,"ativo");
            printf("O USUARIO A ESTA EXCLUIDO\n");
            printf("O USUARIO B ESTA ATIVO\n");
            printf("O USUARIO C ESTA EXCLUIDO\n");

            erros = 6;
        }
        else if (strcmp(escolha_usuario,Usuario_C) == 0) {
            serial = 3;
            printf("Escolha Seu Nome:");
            scanf("%[a-z A-Z]", &u[2].nome);
            printf("\nDigite Sua Senha:");
            scanf("%d", &u[2].senha);
            strcpy(u[2].atividade,"ativo");
            printf("O USUARIO A ESTA EXCLUIDO\n");
            printf("O USUARIO B ESTA EXCLUIDO\n");
            printf("O USUARIO C ESTA ATIVO\n");

            erros = 6;
        }
        else//Existe um limite para os erros de ate 5 vezes de digitacao
            printf ("Digite Novamente\n\n");
        erros++;

        if (erros == 5) {
            printf("Suas Tentativas Acabaram");
            return 0;
        }
    } while (erros <= 6);


    do
    {
        printf("\n==========MENU PRINCIPAL==========\n\n\n");
        printf("1. Criar Novo Livro\n2. Editar Livro\n3. Excluir Livro\n4. Pesquisar\n5. Listar\n6. Estatisticas\n7. Sair\n");

        printf("Escolha:");
        scanf ("%d", &escolha_menu);

        switch (escolha_menu)
        {
        case 1:
            printf("Escolha Qual da Lista Deseja Criar\n");
            contagem--;
            break;
        case 2:
            printf("caso 2");
            contagem--;
            break;

        case 3:
            printf("caso 3");
            contagem--;
            break;

        case 4:
            printf("caso 4");
            contagem--;
            break;
        case 5:
            printf("caso 5");
            contagem--;
            break;
        case 6:
            printf("caso 6");
            contagem--;
            break;
        case 7:
            return 0;

            break;

        default:
            printf("Digite Novamente\n");
            contagem++;
        }


    } while (contagem <= 7);



}
