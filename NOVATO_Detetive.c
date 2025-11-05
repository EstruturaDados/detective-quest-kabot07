
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char nome[50];
    struct No* esquerda;
    struct No* direita;
} No;

// ---- Função responsável por criar novo Nó ----
No* criarSala(const char* nome){
       No* novaSala = (No*) malloc(sizeof(No));
    if (novaSala == NULL){
        printf("Erro ao alocar memória\n");
        exit(1); //Encerra o programa
    }

    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    return novaSala;
}

//----- ARVORE FIXA MANSAO ----

No* montarMansao(){ 
    No* hall = criarSala("Hall de Entrada"); //RAIZ
    No* SalaEstar = criarSala("Sala de Estar");
    No* SalaJantar = criarSala("Sala de Jantar");
    No* Biblioteca = criarSala("Biblioteca");
    No* Escritorio = criarSala("Escritório");
    No* Cozinha = criarSala("Cozinha");
    No* Lavabo = criarSala("Lavabo");
    No* Despensa = criarSala("Despensa");
    No* Lavanderia = criarSala("Lavanderia");
    No* ArmarioFerramentas = criarSala("Armario de Ferramentas");
    No* Garagem = criarSala("Garagem");
    No* Escadas = criarSala("Subir Escadas");
    No* Jardim = criarSala("Jardim");
    No* SuiteMaster = criarSala("Suite Master");
    No* BanheiroSuite = criarSala("Banheiro Suite");
    No* Quarto1 = criarSala("Quarto 1");
    No* Banheiro1 = criarSala("Banheiro 1");


    // --- BIFURCAÇÕES ----

    //Primeira
    hall->esquerda = SalaEstar;
    hall->direita = SalaJantar;

    //Caminho da esquerda (Sala de Estar)
     SalaEstar->esquerda = Biblioteca;
     SalaEstar->direita = Escritorio;

    //Caminho da esquerda (Escritório)
     Escritorio->esquerda = NULL;
     Escritorio->direita = NULL;

    //Caminho da direita (Sala de Jantar)
     SalaJantar->esquerda = Cozinha;
    SalaJantar->direita = Lavabo;

    //Porta Cozinha
    Cozinha->esquerda = Despensa;
    Cozinha->direita = Lavanderia;

    
    //Porta Despensa
    Despensa->esquerda = NULL;
    Despensa->direita = NULL;
    

    //Porta Lavanderia
     Lavanderia->esquerda = ArmarioFerramentas;
    Lavanderia->direita = Garagem;

    //Porta ArmarioFerramentas
    ArmarioFerramentas->esquerda = NULL;
    ArmarioFerramentas->direita = NULL;

    //Porta Biblioteca
     Biblioteca->esquerda = Escadas;
    Biblioteca->direita = Jardim;
    
    //Porta Subir Escada
     Escadas->esquerda = SuiteMaster;
    Escadas->direita = Quarto1;
    
    //Porta Suite Master
     SuiteMaster->esquerda = BanheiroSuite;
    SuiteMaster->direita = NULL;
    
    //Porta Quarto 1
     Quarto1->esquerda = Banheiro1;
    Quarto1->direita = NULL;

      //Porta Banheiro 1
     Quarto1->esquerda = NULL;
    Quarto1->direita = NULL;


    return hall;
}

//---- JOGABILIDADE ----

void explorarSalas(No* salaAtual){
    char escolha;
    while(salaAtual != NULL){
        printf("\n Você está: %s \n", salaAtual->nome);
    
    if (salaAtual->esquerda == NULL && salaAtual->direita == NULL){
        printf("Você chegou ao fim do caminho\n");
        break;
    }
    
// ---- MENU DIREÇÃO ----
    printf("========== D E T E T I V E =========\n\n");    
    printf(" Qual porta direção deseja ir? \n");
    if (salaAtual->esquerda != NULL) printf("(1).Porta a esquerda:%s\n", salaAtual->esquerda->nome);
    if (salaAtual->direita != NULL) printf("(2).Porta a direta:%s\n", salaAtual->direita->nome);
    printf("(0). Sair do jogo\n");
    scanf(" %c", &escolha);
    printf("\n");   
    getchar();
    
    if(escolha =='1' && salaAtual->esquerda != NULL) {
        salaAtual = salaAtual->esquerda;
} else if (escolha == '2' && salaAtual->direita != NULL){
        salaAtual = salaAtual->direita;
} else if (escolha == '0') {
    printf("Você está saindo da mansão.");
    break;
} else {
    printf("Opção inválida!\n");
} }}

// ---- LIBERAR MEMORIA ----

void liberar(No* raiz){
    if (raiz != NULL) {
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
}

//------

int main () {

    int opcaomenu, portaescolhida;
    printf("========== D E T E T I V E =========\n\n"); //MENU PRINCIPAL
do {  printf("                MENU           \n");
    printf("1. Entrar na casa\n");
    printf("0. Sair do jogo\n");
    printf("Escolha: ");scanf("%d", &opcaomenu);
    printf("\n"); 

    switch (opcaomenu){
    
    case 1: 
        No* mansao = montarMansao();
        explorarSalas(mansao);
        liberar(mansao);

    break;

    case 0: 
    printf("Saindo do jogo\n");
    exit(1);
    
    break;
    
    default: 
    printf("Opção Inválida\n");
    }} while (opcaomenu != 0);

    return 0;
}

