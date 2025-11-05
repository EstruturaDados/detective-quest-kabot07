
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char nome[50];
    struct No* esquerda;
    struct No* direita;
} No;

// ---- ARVORE DE PISTAS BST ----
typedef struct NoPista{
    char pista[50];
    struct NoPista* esquerda;
    struct NoPista* direita;
}NoPista;

// Criar novo NoPista
NoPista* criarPista(const char* texto){
    NoPista* nova = (NoPista*)malloc(sizeof(NoPista));
    if (!nova){
        printf("Erro");
        exit(1);
    }
    strcpy(nova->pista, texto);
    nova->esquerda = nova-> direita = NULL;
    return nova;
}

//Inserir pista (em ordem alfabética)
NoPista* inserirPista(NoPista* raiz, const char* texto){
    if (raiz == NULL) return criarPista(texto);
    if (strcmp(texto, raiz->pista) < 0)
        raiz->esquerda = inserirPista(raiz->esquerda, texto);
    else if (strcmp(texto, raiz->pista)> 0)
        raiz->direita = inserirPista(raiz->direita, texto);

    return raiz;
}

// Buscar pista

int buscarPista(NoPista* raiz, const char* texto){
    if (raiz == NULL) return 0;
    if (strcmp(texto, raiz->pista) == 0) return 1;
    if (strcmp(texto, raiz->pista) < 0)
        return buscarPista(raiz->esquerda, texto);
    else    
        return buscarPista(raiz->direita, texto);
    
}

// Organizar em ordem alfabetica
void emOrdem(NoPista* raiz){
    if (raiz != NULL){
        emOrdem(raiz->esquerda);
        printf("%s\n", raiz->pista);
        emOrdem(raiz->direita);

    }
}

// Liberar memoria BST
void liberarPistas(NoPista* raiz){
    if (raiz != NULL){
        liberarPistas(raiz->esquerda);
        liberarPistas(raiz->direita);
        free(raiz);
    }
}


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

void explorarSalas(No* salaAtual, NoPista** pistas) {
    char escolha;
    while(salaAtual != NULL){
        printf("\n Você está: %s \n", salaAtual->nome);
    

    //Destribuição de Pistas
    if (strcmp(salaAtual->nome, "Biblioteca") == 0 )
        *pistas = inserirPista(*pistas, "Livro com anotações suspeitas");
    else if (strcmp(salaAtual->nome, "Cozinha") == 0 )
        *pistas = inserirPista(*pistas, "Faca ensanguentada ");
    else if (strcmp(salaAtual->nome, "Escritório") == 0 )
        *pistas = inserirPista(*pistas, "Carta de chantagem ");
    else if (strcmp(salaAtual->nome, "Garagem") == 0 )
         *pistas = inserirPista(*pistas, "Pegada de Lama");
    else if (strcmp(salaAtual->nome, "Suíte Master") == 0 )
        *pistas = inserirPista(*pistas, "Diário Rasgado");
    
    
    
    
         if (salaAtual->esquerda == NULL && salaAtual->direita == NULL){
        printf("Você chegou ao fim do caminho\n");
        break;
    }
    
// ---- MENU DIREÇÃO ----
    printf("========== D E T E T I V E =========\n\n");    
    printf(" Qual porta direção deseja ir? \n");
    if (salaAtual->esquerda != NULL) printf("(1).Porta a esquerda:%s\n", salaAtual->esquerda->nome);
    if (salaAtual->direita != NULL) printf("(2).Porta a direta:%s\n", salaAtual->direita->nome);
    printf("(3) Ver pistas encontradas\n");
    printf("(0). Sair do jogo\n");
    scanf(" %c", &escolha);
    printf("\n");   
    getchar();
    
    if(escolha =='1' && salaAtual->esquerda != NULL) {
        salaAtual = salaAtual->esquerda;
} else if (escolha == '2' && salaAtual->direita != NULL){
        salaAtual = salaAtual->direita;
} else if (escolha == '3'){
    printf("\n Pistas encontradas até agora: \n");
    emOrdem(*pistas);

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
    NoPista* pistas = NULL;
    
  do {  printf("========== D E T E T I V E =========\n\n"); //MENU PRINCIPAL
     printf("                MENU           \n");
    printf("1. Entrar na casa\n");
    printf("0. Sair do jogo\n");
    printf("Escolha: ");scanf("%d", &opcaomenu);
    printf("\n"); 

    switch (opcaomenu){
    
    case 1: 
        No* mansao = montarMansao();
        pistas = NULL;
        explorarSalas(mansao, &pistas);
        liberar(mansao);
        liberarPistas(pistas);
        pistas = NULL;

    break;

    case 0: 
    printf("Saindo do jogo\n");
    exit(1);
    liberarPistas(pistas);
    
    break;
    
    default: 
    printf("Opção Inválida\n");
    }} while (opcaomenu != 0);

    return 0;
}

