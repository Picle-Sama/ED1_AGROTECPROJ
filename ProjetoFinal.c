#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct produto{
    int codigo;
    char nome_do_produto[30];
    int quantidade;
    float precos[3];
    struct produto *prox;
}Tproduto;

typedef struct historico{
    int codigo;
    int vendas[4];
    struct historico *prox;
}Thistorico;

typedef struct PedidoItem{
    int id_produto;
    int quantidade;
    struct PedidoItem *prox;
}TPedidoItem;

typedef struct pedido{
    int id_pedido;
    TPedidoItem *itens;
    struct pedido *prox;
}Tpedido;

typedef struct cliente{
    int id_cliente;
    char nome[30];
    Tpedido *pedidos;
    struct cliente *prox;
}Tcliente;

//estruturas cabeças
typedef struct{
    Tproduto *inicio;
    Tproduto *fim;
}TCabecaProduto;

typedef struct{
    Thistorico *inicio;
    Thistorico *fim;
}TCabecaHistorico;

typedef struct{
    Tcliente *inicio; // aponta pro inicio da lista cliente
    Tcliente *fim;
}TCabecaCliente;


TCabecaProduto *criar_lista_produtos();
TCabecaHistorico *criar_lista_historico();
TCabecaCliente *criar_lista_clientes();



void exibir_pedidos(TCabecaCliente *p);


int main()
{
    TCabecaProduto *Lista_produtos = NULL;
    TCabecaHistorico *Lista_hist = NULL;
    TCabecaCliente *Lista_clientes = NULL;

    Lista_produtos = criar_lista_produtos();
    Lista_hist = criar_lista_historico();
    Lista_clientes = criar_lista_clientes();

    int opcao;
    do {
        printf("\n=== AGROTEC ===\n");
        printf("1 - Carregar dados do estoque\n");
        printf("2 - Carregar preços\n");
        printf("3 - Carregar histórico de vendas\n");
        printf("4 - Carregar pedidos\n"); //ok
        printf("5 - Inserir novo produto\n");
        printf("6 - Inserir nova venda\n");
        printf("7 - Inserir novo cliente\n");
        printf("8 - Processar pedidos\n");
        printf("9 - Prever compras\n");
        printf("10 - Gerar relatório final\n");
        printf("0 - Sair\n");
        printf("Escolha uma das opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // carregar_estoque()
                break;
            case 2:
                // carregar_precos()
                break;
            case 3:
                // carregar_historico()
                break;
            case 4:
                /*
                if()
                    exibir_pedidos();
                else
                    printf("Lista vazia.\n");
                */
                break;
            case 5:
                // inserir_produto()
                break;
            case 6:
                // inserir_venda()
                break;
            case 7:
                // inserir_cliente()
                break;
            case 8:
                // processar_pedidos()
                break;
            case 9:
                // prever_compras()
                break;
            case 10:
                // relatorio_final()
                break;
            case 0:
                // liberar_memoria()
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    }while(opcao!=0);

    return 0;
}

TCabecaProduto *criar_lista_produtos(){
    TCabecaProduto *novo = NULL;
    novo = (TCabecaProduto *)malloc(sizeof(TCabecaProduto));
    if(novo){
        novo->inicio = NULL;
        novo->fim = NULL;
    }
    return novo;
}

TCabecaHistorico *criar_lista_historico(){
    TCabecaHistorico *novo = NULL;
    novo = (TCabecaHistorico *)malloc(sizeof(TCabecaHistorico));
    if(novo){
        novo->inicio = NULL;
        novo->fim = NULL;
    }
    return novo;
}

TCabecaCliente *criar_lista_clientes(){
    TCabecaCliente *novo = NULL;
    novo = (TCabecaCliente *)malloc(sizeof(TCabecaCliente));
    if(novo){
        novo->inicio = NULL;
        novo->fim = NULL;
        novo->inicio_pedido = NULL;
        novo->fim_pedido = NULL;
    }
    return novo;
}




void exibir_pedidos(TCabecaCliente *p){
    Tcliente *cliente = p->inicio;
    while(cliente){
        Tpedido *pedido = cliente->pedidos;

        while(pedido){
            printf("PEDIDO(%d)\n\tCliente(%d): %s", pedido->id_pedido, cliente->id_cliente, cliente->nome);
            printf("\n\tItens:");
            TPedidoItem *item = pedido->itens;

            while(item){
                printf("\n\t\tCodigo do produto: %d", item->id_produto);
                printf("\n\t\tQuantidade: %d", item->quantidade);
                item = item->prox;
            }
            printf("\n");
            pedido = pedido->prox;
        }
        cliente = cliente->prox;
    }
}
