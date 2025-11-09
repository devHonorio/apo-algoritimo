#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

struct Dados
{
    int codigo;
    char nome[50];
    int idade;
    char sexo;
    float salario;
};

struct Dados cliente[5];

void imprimir_dados(struct Dados cli[]);
int calcular_somatoria_idade(struct Dados cli[]);

void limpar_enter()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    printf("\n\nO programa iniciou...\n");

    for (int i = 0; i < 5; i++)
    {

        printf("\n--- Cadastro do Cliente Nº %d ---\n", i + 1);

        cliente[i].codigo = i + 1;
        printf("Seu código é: %d\n", cliente[i].codigo);

        printf("Digite o nome: ");

        fgets(cliente[i].nome, 50, stdin);

        if (cliente[i].nome[strlen(cliente[i].nome) - 1] == '\n')
        {
            cliente[i].nome[strlen(cliente[i].nome) - 1] = '\0';
        }

        printf("Qual é a sua idade: ");
        scanf("%d", &cliente[i].idade);

        limpar_enter();

        printf("Qual é o seu sexo [m/f]: ");

        scanf(" %c", &cliente[i].sexo);

        limpar_enter();

        printf("Qual é o seu salário: ");

        scanf("%f", &cliente[i].salario);

        limpar_enter();
    }

    printf("\n\n-------- IMPRESSÃO DOS DADOS CADASTRADOS --------\n");

    imprimir_dados(cliente);

    int soma_idade = calcular_somatoria_idade(cliente);

    float media_idade = (float)soma_idade / 5;

    printf("\n\n-------- CÁLCULO DA MÉDIA DE IDADE --------\n");
    printf("Somatória total das idades: %d\n", soma_idade);
    printf("Média de idade dos clientes: %.2f\n", media_idade);

    printf("\n\nFim do programa...");

    printf(" Pressione qualquer tecla para sair...");
    getch();

    return 0;
}

void imprimir_dados(struct Dados cli[])
{

    printf("\n%-5s | %-50s | %-5s | %-5s | %-5s\n", "CÓD.", "NOME", "IDADE", "SEXO", "SALÁRIO");
    printf("-------------------------------------------------------------------\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%-5d | %-50s | %-5d | %-5c | R$ %-8.2f\n",
               cli[i].codigo,
               cli[i].nome,
               cli[i].idade,
               cli[i].sexo,
               cli[i].salario);
    }
}

int calcular_somatoria_idade(struct Dados cli[])
{
    int soma = 0;
    for (int i = 0; i < 5; i++)
    {
        soma += cli[i].idade;
    }
    return soma;
}