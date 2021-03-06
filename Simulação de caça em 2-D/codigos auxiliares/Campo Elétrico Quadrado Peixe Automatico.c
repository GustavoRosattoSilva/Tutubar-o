/***************************************************************************
 *     @file: tutubarão.c                                                  *
 *   @author: Gustavo Rosatto Silva                                        *
 * @objective: teste preliminares para um projeto envolvendo               *
 * eletrorrecepsção de tubarões / preliminary tests for a project          *
 * involving shark electroreception                                        *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// setando as variaveis / set the initial variables
const int altura = 23, largura = 80, contador = 4;

int posicao_tubarao_x = 1, posicao_tubarao_y = 1, posicao_peixe_x, posicao_peixe_y, x, y, i, j, k;

//declaração de funções / funtion declaration

//fuções para converter inteiro em real e real em inteiro
char str_1(int numero){

    if (numero == 1){
        
        return '1';
    
    }

    if (numero == 2){
        
        return '2';
    
    }

    if (numero == 3){
        
        return '3';
    
    }

    if (numero == 4){
        
        return '4';
    
    }

    if (numero == 5){
        
        return '5';
    
    }

    if (numero == 6){
        
        return '6';
    
    }

    if (numero == 7){
        
        return '7';
    
    }

    if (numero == 8){
        
        return '8';
    
    }

    if (numero == 9){
        
        return '9';
    
    }

    if (numero == 10){
        
        return '0';
    
    }

    return ' ';

}

int int_1(char carctere){

    if (carctere == '1'){
        
        return 1;
    
    }

    if (carctere == '2'){
        
        return 2;
    
    }

    if (carctere == '3'){
        
        return 3;
    
    }

    if (carctere == '4'){
        
        return 4;
    
    }

    if (carctere == '5'){
        
        return '5';
    
    }

    if (carctere == '6'){
        
        return 6;
    
    }

    if (carctere == '7'){
        
        return 7;
    
    }

    if (carctere == '8'){
        
        return 8;
    
    }

    if (carctere == '9'){
        
        return 9;
    
    }

    if (carctere == '0'){
        
        return 10;
    
    }

    return 0;

}



void cria_campo_eletrico_peixe(char mapa_oceano[altura][largura], int contador){

    //limpa o mapa dos campos anteriores
    for (y = 0; y < altura; ++y){

       for (x = 0; x < largura; ++x){

           if (mapa_oceano[y][x] != '@' && mapa_oceano[y][x] != 'A' && mapa_oceano[y][x] != 'P' && mapa_oceano[y][x] != 'H'){
               
               mapa_oceano[y][x] = ' ';

           }

       }

    }

    for (i = 0; i <= contador; ++i){
        
        for (j = posicao_peixe_y - i; j <= posicao_peixe_y + i; ++j){
            
            for (k = posicao_peixe_x - i; k <= posicao_peixe_x + i; ++k){
                
                if (k > 0 && k < largura && j > 0 && j < altura && mapa_oceano[j][k] == ' '){
                    
                    mapa_oceano[j][k] = str_1(i);    
                
                }

            }

        }

    }
    

}

void cria_mapa(char mapa_oceano[altura][largura]){

    int count, i;

    //cria as bordas do mapa / start the boards of map
    for (y = 0; y < altura; ++y){

       for (x = 0; x < largura; ++x){

            if (x == 0 || x == largura - 1 || y == 0 || y == altura - 1){

               mapa_oceano[y][x] = 'H';

            }

            else{

                mapa_oceano[y][x] = ' ';

            }

       }

    }
    
    //cria obstaculos aleatório / create random obstacle
    srand(time(NULL));
    count = rand()%150;
    for (i = 0; i < count; ++i){
        mapa_oceano[(rand()%(altura-3)) + 1][(rand()%(largura-3)) + 1] = 'A';
    }

    //seta a posição inicial do tubarão / set the initial shark position
    mapa_oceano[posicao_tubarao_y][posicao_tubarao_x] = '@';

    //seta a posição inicial do peixe / set the initial fish position
    posicao_peixe_x = (rand()%(largura-3)) + 1;
    
    posicao_peixe_y = (rand()%(altura-3)) + 1;
    
    mapa_oceano[posicao_peixe_y][posicao_peixe_x] = 'P';

}


//imprime o mapa completo
void imprime_mapa(char mapa_oceano[altura][largura]){
    
    cria_campo_eletrico_peixe(mapa_oceano, contador);

    for (y = 0; y < altura; ++y){

       for (x = 0; x < largura; ++x){

           printf("%c",mapa_oceano[y][x]);

       }

       printf("\n");

    }

}




int main(){

    // setando as variaveis / set the initial variables
    char mapa_oceano[altura][largura];

    // preencheendo o mapa / contruct the map
    cria_mapa(mapa_oceano);

    //imprimindo o mapa / print the map
    imprime_mapa(mapa_oceano);
    //cria_campo_eletrico_peixe(mapa_oceano,contador);

    //movimentando meu tubarão

    return 0;

}

         // próximos passos//

// melhorar a IA de movimentar o peixe
// documentar melhor o código
// criar uma IA para movimentar o tubarão
