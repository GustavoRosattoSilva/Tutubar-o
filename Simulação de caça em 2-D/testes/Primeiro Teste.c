/***************************************************************************
 *     @file: tutubarão_primeiro_teste.c                                   *
 *   @author: Gustavo Rosatto Silva                                        *
 * @objective: criar uma simulação simples para um projeto envolvendo      *
 * eletrorrecepsção de tubarões / create a simulation for a project        *
 * involving shark electroreception                                        *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// setando as variaveis / set the initial variables
const int altura = 23, largura = 80, contador = 4;

int posicao_tubarao_x = 1, posicao_tubarao_y = 1, posicao_peixe_x, posicao_peixe_y, x, y, i, j, k, l;

//declaração de funções / funtion declaration
//função que transforma um inteiro em string / fution turn int in str
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

void cria_campo_eletrico_peixe_losangulo(char mapa_oceano[altura][largura], int contador){

    //limpa o mapa dos campos anteriores
    for (y = 0; y < altura; ++y){

       for (x = 0; x < largura; ++x){

           if (mapa_oceano[y][x] != '@' && mapa_oceano[y][x] != 'A' && mapa_oceano[y][x] != 'P' && mapa_oceano[y][x] != 'H'){
               
               mapa_oceano[y][x] = ' ';

           }

       }

    }

    for (i = 1; i <= contador; ++i){
        
        for (l = 0; l <= i; ++l){
            
            if (posicao_peixe_y + l > 0 && posicao_peixe_y + l < altura && posicao_peixe_x + i - l > 0 && posicao_peixe_x + i - l < largura && mapa_oceano[posicao_peixe_y + l][posicao_peixe_x + i - l] == ' '){
                
                mapa_oceano[posicao_peixe_y + l][posicao_peixe_x + i - l] = str_1(i);

            }

            if (posicao_peixe_y - l > 0 && posicao_peixe_y - l < altura && posicao_peixe_x - i + l > 0 && posicao_peixe_x - i + l < largura && mapa_oceano[posicao_peixe_y - l][posicao_peixe_x - i + l] == ' '){
                
                mapa_oceano[posicao_peixe_y - l][posicao_peixe_x - i + l] = str_1(i);
                
            }

            if (posicao_peixe_y + l > 0 && posicao_peixe_y + l < altura && posicao_peixe_x - i + l > 0 && posicao_peixe_x - i + l < largura && mapa_oceano[posicao_peixe_y + l][posicao_peixe_x - i + l] == ' '){
                
                mapa_oceano[posicao_peixe_y + l][posicao_peixe_x - i + l] = str_1(i);

            }

            if (posicao_peixe_y - l > 0 && posicao_peixe_y - l < altura && posicao_peixe_x + i - l > 0 && posicao_peixe_x + i - l < largura && mapa_oceano[posicao_peixe_y - l][posicao_peixe_x + i - l] == ' '){

                
                mapa_oceano[posicao_peixe_y - l][posicao_peixe_x + i - l] = str_1(i);
                
            }

        }

    }
    
}

void cria_campo_eletrico_peixe_quadrado(char mapa_oceano[altura][largura], int contador){

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

char gerador_de_cordenada(char chave_de_movimento_peixe){
    
    int numero_aleatorio;


    numero_aleatorio = rand()%4;

    if (numero_aleatorio == 0){

        chave_de_movimento_peixe = 's';

    }

    if (numero_aleatorio == 1){

        chave_de_movimento_peixe = 'd';

    }

    if (numero_aleatorio == 2){

        chave_de_movimento_peixe = 'a';

    }

    if (numero_aleatorio == 3){

         chave_de_movimento_peixe = 'w';
                
    }

    return chave_de_movimento_peixe;

}

//imprime o mapa completo
void imprime_mapa(char mapa_oceano[altura][largura]){
    
    //cria_campo_eletrico_peixe_losangulo(mapa_oceano, contador);
    cria_campo_eletrico_peixe_quadrado(mapa_oceano, contador);


    for (y = 0; y < altura; ++y){

       for (x = 0; x < largura; ++x){

           printf("%c",mapa_oceano[y][x]);

       }

       printf("\n");

    }

}

//imprime só o campo de visão do tubarão
void imprime_mapa_2(char mapa_oceano[altura][largura]){

    cria_campo_eletrico_peixe_losangulo(mapa_oceano, contador);
    cria_campo_eletrico_peixe_quadrado(mapa_oceano, contador);

    int x_1, y_1, y_2, x_2;

    
    y_1 = posicao_tubarao_y - 3;

    x_1 = posicao_tubarao_x - 3;

    y_2 = posicao_tubarao_y + 3;

    x_2 = posicao_tubarao_x + 3;

    if (x_1 < 0){
      
        x_1 = 0;
    
    }

    if (y_1 < 0){
      
        y_1 = 0;
    
    }

    if (y_2 > altura){
      
        y_2 = altura;
    
    }

    if (x_2 > largura){
      
        x_2 = largura;
    
    }


    for (y = y_1; y < y_2; ++y){

       for (x = x_1; x < x_2; ++x){

           printf("%c",mapa_oceano[y][x]);

       }

       printf("\n");

    }

}

char redefine_mapa_tubarao(char mapa_oceano[altura][largura], char auxiliar){
        if ((auxiliar == 'A' || auxiliar == 'a') && posicao_tubarao_x - 1 >= 1 && mapa_oceano[posicao_tubarao_y][posicao_tubarao_x -1] != 'A'){
            
            mapa_oceano[posicao_tubarao_y][posicao_tubarao_x] = ' ';
            
            posicao_tubarao_x--;
            
            if (posicao_peixe_y == posicao_tubarao_y && posicao_peixe_x == posicao_tubarao_x){
                
                auxiliar = 'k';
            
            }

            mapa_oceano[posicao_tubarao_y][posicao_tubarao_x] = '@';
        }
    
        if ((auxiliar == 'W' || auxiliar == 'w') && posicao_tubarao_y - 1 >= 1 && mapa_oceano[posicao_tubarao_y - 1][posicao_tubarao_x] != 'A'){
            
            mapa_oceano[posicao_tubarao_y][posicao_tubarao_x] = ' ';
            
            posicao_tubarao_y--;
            
            if (posicao_peixe_y == posicao_tubarao_y && posicao_peixe_x == posicao_tubarao_x){
                
                auxiliar = 'k';
            
            }

            mapa_oceano[posicao_tubarao_y][posicao_tubarao_x] = '@';
        }

        if ((auxiliar == 'S' || auxiliar == 's') && posicao_tubarao_y + 1 <= (altura -2) && mapa_oceano[posicao_tubarao_y + 1][posicao_tubarao_x] != 'A'){
            
            mapa_oceano[posicao_tubarao_y][posicao_tubarao_x] = ' ';
            
            posicao_tubarao_y++;
            
            if (posicao_peixe_y == posicao_tubarao_y && posicao_peixe_x == posicao_tubarao_x){
                
                auxiliar = 'k';
            
            }

            mapa_oceano[posicao_tubarao_y][posicao_tubarao_x] = '@';
        }
    
        if ((auxiliar == 'D' || auxiliar == 'd') && posicao_tubarao_x + 1 <= (largura - 2) && mapa_oceano[posicao_tubarao_y][posicao_tubarao_x + 1] != 'A'){
            
            mapa_oceano[posicao_tubarao_y][posicao_tubarao_x] = ' ';
            
            posicao_tubarao_x++;
            
            if (posicao_peixe_y == posicao_tubarao_y && posicao_peixe_x == posicao_tubarao_x){
                
                auxiliar = 'k';
            
            }
            
            mapa_oceano[posicao_tubarao_y][posicao_tubarao_x] = '@';
        }


        return auxiliar;

}

char redefine_mapa_peixe(char mapa_oceano[altura][largura]){

        char chave_de_movimento_peixe, auxiliar;

        while(1 == 1){

            chave_de_movimento_peixe = gerador_de_cordenada(chave_de_movimento_peixe);
        
            if ((chave_de_movimento_peixe == 'A' || chave_de_movimento_peixe == 'a') && posicao_peixe_x - 1 >= 1 && mapa_oceano[posicao_peixe_y][posicao_peixe_x -1] != 'A'){
            
                mapa_oceano[posicao_peixe_y][posicao_peixe_x] = ' ';
            
                posicao_peixe_x--;
            
                if (posicao_peixe_y == posicao_tubarao_y && posicao_peixe_x == posicao_tubarao_x){
                
                    auxiliar = 'k';
            
                }

                mapa_oceano[posicao_peixe_y][posicao_peixe_x] = 'P';

                break;
        
            }
    
            if ((chave_de_movimento_peixe == 'W' || chave_de_movimento_peixe == 'w') && posicao_peixe_y - 1 >= 1 && mapa_oceano[posicao_peixe_y - 1][posicao_peixe_x] != 'A'){
            
                mapa_oceano[posicao_peixe_y][posicao_peixe_x] = ' ';
            
                posicao_peixe_y--;
            
                if (posicao_peixe_y == posicao_tubarao_y && posicao_peixe_x == posicao_tubarao_x){
                
                    auxiliar = 'k';
            
                }

                mapa_oceano[posicao_peixe_y][posicao_peixe_x] = 'P';

                break;
        
            }

            if ((chave_de_movimento_peixe == 'S' || chave_de_movimento_peixe == 's') && posicao_peixe_y + 1 <= (altura -2) && mapa_oceano[posicao_peixe_y + 1][posicao_peixe_x] != 'A'){
            
                mapa_oceano[posicao_peixe_y][posicao_peixe_x] = ' ';
            
                posicao_peixe_y++;
            
                if (posicao_peixe_y == posicao_tubarao_y && posicao_peixe_x == posicao_tubarao_x){
                
                    auxiliar = 'k';
            
                }

                mapa_oceano[posicao_peixe_y][posicao_peixe_x] = 'P';

                break;
        
            }
    
            if ((chave_de_movimento_peixe == 'D' || chave_de_movimento_peixe == 'd') && posicao_peixe_x + 1 <= (largura - 2) && mapa_oceano[posicao_peixe_y][posicao_peixe_x + 1] != 'A'){
            
                mapa_oceano[posicao_peixe_y][posicao_peixe_x] = ' ';
            
                posicao_peixe_x++;
            
                if (posicao_peixe_y == posicao_tubarao_y && posicao_peixe_x == posicao_tubarao_x){
                
                    auxiliar = 'k';
            
                }
            
                mapa_oceano[posicao_peixe_y][posicao_peixe_x] = 'P';

                break;
        
            }

        }

        system("clear");

        imprime_mapa(mapa_oceano);


        return auxiliar;

}

int main(){

    // setando as variaveis / set the initial variables
    char mapa_oceano[altura][largura], auxiliar;

    // preencheendo o mapa / contruct the map
    cria_mapa(mapa_oceano);

    //imprimindo o mapa / print the map
    imprime_mapa(mapa_oceano);

    //movimentando meu tubarão
    
    while(1==1){
        scanf("%c", &auxiliar);
        
        if (auxiliar == 'k'){
        
            break;
        
        }

        else{


            redefine_mapa_tubarao(mapa_oceano, auxiliar);

            auxiliar = redefine_mapa_peixe(mapa_oceano);
            
            

        }
        
        if (auxiliar == 'k'){
        
            printf("win\n");
        
            break;
        
        }

    }

    return 0;

}

         // próximos passos//

// melhorar a IA de movimentar o peixe
// documentar melhor o código
// criar uma IA para movimentar o tubarão
