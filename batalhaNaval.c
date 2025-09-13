#include <stdio.h>
#include <stdbool.h>

// Constantes para o tamanho do tabuleiro e navios
#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for(int i = 0; i < TAM_TABULEIRO; i++) {
        for(int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se a posição do navio é válida
bool posicaoValida(int linha, int coluna, int tamanho, bool vertical, int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Verifica se está dentro dos limites do tabuleiro
    if(linha < 0 || coluna < 0) return false;
    
    if(vertical) {
        if(linha + tamanho - 1 >= TAM_TABULEIRO) return false;
    } else {
        if(coluna + tamanho - 1 >= TAM_TABULEIRO) return false;
    }
    
    // Verifica se não há sobreposição com outros navios
    for(int i = 0; i < tamanho; i++) {
        if(vertical) {
            if(tabuleiro[linha + i][coluna] != 0) return false;
        } else {
            if(tabuleiro[linha][coluna + i] != 0) return false;
        }
    }
    
    return true;
}

// Função para posicionar um navio no tabuleiro
bool posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, bool vertical) {
    if(!posicaoValida(linha, coluna, TAM_NAVIO, vertical, tabuleiro)) {
        printf("Posicao invalida para o navio!\n");
        return false;
    }
    
    // Posiciona o navio
    for(int i = 0; i < TAM_NAVIO; i++) {
        if(vertical) {
            tabuleiro[linha + i][coluna] = 3;
        } else {
            tabuleiro[linha][coluna + i] = 3;
        }
    }
    
    return true;
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\n  ");
    for(int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d", i);
    }
    printf("\n");
    
    for(int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d", i);
        for(int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%2d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Batalha Naval - Posicionamento de Navios\n");
    
    // Declaração e inicialização do tabuleiro
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializarTabuleiro(tabuleiro);
    
    // Posicionamento dos navios (coordenadas definidas no código)
    // Navio 1 - Horizontal (linha 2, coluna 3)
    bool navio1Posicionado = posicionarNavio(tabuleiro, 2, 3, false);
    
    // Navio 2 - Vertical (linha 5, coluna 7)
    bool navio2Posicionado = posicionarNavio(tabuleiro, 5, 7, true);
    
    // Verifica se ambos os navios foram posicionados com sucesso
    if(!navio1Posicionado || !navio2Posicionado) {
        printf("Erro ao posicionar os navios. Verifique as coordenadas.\n");
        return 1;
    }
    
    // Imprime o tabuleiro com os navios posicionados
    imprimirTabuleiro(tabuleiro);
    
    // Legenda
    printf("\nLegenda:\n");
    printf("0 - Agua\n");
    printf("3 - Navio\n");
    
    return 0;
}