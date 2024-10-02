#include <stdio.h>
#include <string.h>  
    

void forca (int estado){
     if (estado == 0) {
        printf( "\n------------------------" );
        printf( "\n|                     |");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n_\n");
     
     } else if(estado == 1) {
        
        printf( "\n------------------------" );
        printf( "\n|                     |");
        printf( "\n|                     O");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n_\n");

     } else if(estado == 2) {
        
        printf( "\n------------------------" );
        printf( "\n|                     |");
        printf( "\n|                     O");
        printf( "\n|                     |");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n_\n");

     } else if(estado == 3) {
        
        printf( "\n------------------------" );
        printf( "\n|                     |");
        printf( "\n|                     O");
        printf( "\n|                    -|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n_\n");

     } else if(estado == 4) {
       
        printf( "\n------------------------" );
        printf( "\n|                     |");
        printf( "\n|                     O");
        printf( "\n|                    -|-");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n_\n");


     } else if(estado == 5) {
       
        printf( "\n------------------------" );
        printf( "\n|                     |");
        printf( "\n|                     O");
        printf( "\n|                    -|-");
        printf( "\n|                    /  ");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n_\n");

      } else if(estado == 6) { 
       
        printf( "\n------------------------" );
        printf( "\n|                     |");
        printf( "\n|                     O");
        printf( "\n|                    -|-");
        printf( "\n|                    / \\ ");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|");
        printf( "\n|       Perdeu o game!");
        printf( "\n|");
        printf( "\n_\n");

      }
  }

int main(void) {
 
    char p_sec[100]; //palavra secreta

                
    printf( "JOGADOR 1:\n" );
    printf( "Palavra secreta!\n" ); 
    fgets(p_sec, 100, stdin);
    printf( " A palavra secreta é: %s \n", p_sec );

    for ( int i =0; i < 30; i++ ){
            printf("\n");   
 
    }
    // retira o último caracter de p_sec que está a mais, devido a captura ser fgets() 
    p_sec[strlen(p_sec) -1] ='\0';  

    char p_tela[100];// tring para imprimit os traçinhos da  palavra a ser adivinhada
    strcpy(p_tela, p_sec); // copia os dados de p_sec para p_tela
   
  
    //substitui letras pot '_'
    for ( int i = 0; i < strlen(p_tela); i++){ 
         p_tela[i] = '_';

    }
    int erros = 0;   
    while (1){

        // imprimir a forca
        forca (erros);

        // imprimir os underdscores( underlines) para cadda letra da palacvra secreta
        printf("\nAdivinhe: ");
        for ( int i = 0; i < strlen(p_tela); i++) {
             printf( "%c ", p_tela[i]);
        }
               
        //recebe a letra
        printf( "\nLetra: ");
        char letra;
        scanf( " %c", &letra);// o espaço antres do " %c" é: para não ficar um looping.
        
        // se letra correta atualisa a palavra na tela

        // verifica se a letra está correta
        int sera_que_errou = 1; // 1 sim 0 não
        for (int i = 0; i < strlen(p_tela); i++) {
            if (letra == p_sec[i]){// certo
                p_tela[i] = letra;
         
                sera_que_errou = 0;
            } 
        }
        
        //senao, incrementa erros
        if(sera_que_errou == 1) {
            erros ++;
        }
        
        // verifica se o jogo acabou
        // verifica se ganhou 
        // verifica se p_sec é igual a p_tela
        if  (strcmp(p_tela, p_sec) == 0) {
            // então ganhou
             printf("\n Acertou: ");
             for (int i = 0; i < strlen(p_tela); i++){
             printf( "%c ", p_tela[i]);

             }
             printf("\n Parabéns! Você Venceu !!!");
             printf(" \nYou Win!\n");
             break;
        }
         
        // verifica se perdeu
        if(erros == 6){ //perdeu
            forca( erros );
            break;
        }

    }

    return 0;
}















