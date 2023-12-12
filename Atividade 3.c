#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

struct dados_produto
{
    char nome[200];
    float preco;
    int estoque;
};

int atualizarEstoque(int pE, int quantidadeProduto)
{
    return pE - quantidadeProduto;
}
float precoNovo(float pP, float produtoValor)
{
    return  pP * produtoValor;
}

int main()
{
    int opcao, escolha, quantidadeProduto, estoqueAtualizado, pE;
    float produtoValor, precoAtualizado, pP;
    char produtoNome[200];

    struct dados_produto produto;

    printf("Deseja registrar seu novo produto?\n");
    printf("1 - Sim.\n");
    printf("2 - Não.\n");
    scanf("%i", &escolha);

    system("cls||clear");

    switch (escolha)
    {
    case 1:

        setbuf(stdin, 0);
        printf("Registre o seu produto.\n");
        printf("Nome: ");
        gets(produto.nome);

        printf("\n");

        printf("Preço: ");
        scanf("%f", &produto.preco);

        setbuf(stdin, 0);
        printf("\n");

        printf("Quantidade em estoque: ");
        scanf("%i", &produto.estoque);

        printf("\n");

        printf("Registro finalizado!");

        system("cls||clear");

        break;

    default:
        break;
    }

    do
    {
        printf("Lojinha da Xuxa\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa.\n");
        printf("Resposta: ");
        scanf("%i", &opcao);

        system("cls||clear");

        fflush(stdin);

        switch (opcao)
        {
        case 1:
            fflush(stdin);

            printf("Nome do produto: \n");
            gets(produtoNome);

            printf("Digite o valor do produto: ");
            scanf("%f", &produtoValor);

            pP = produtoValor - produto.preco;

            printf("Quantidade desejada do produto: ");
            scanf("%i", &quantidadeProduto);

            if (quantidadeProduto <= produto.estoque)
            {
                pE = quantidadeProduto - produto.estoque;
                printf("Compra realizada com sucesso!\n");
            }
            else
            {
                printf("Sem estoque suficiente.\n");
            }

            precoAtualizado = precoNovo(pP, produtoValor);
            estoqueAtualizado = atualizarEstoque(pE, quantidadeProduto);

            break;

        case 2:

            printf("Produto em estoque.");
            printf("\n");
            printf("Nome: %s \n", produto.nome);
            printf("Preço total do estoque: %.2f \n", precoAtualizado);
            printf("Estoque: %i \n", estoqueAtualizado);

            break;

        default:
            break;
        }

    } while (opcao != 3);

    return 0;
}
