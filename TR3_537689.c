#include <stdio.h>
#include <stdlib.h>

//MODELO DE EXEMPLO

int main(){

   	//Variáveis que podem ser usadas
   	unsigned int x[200];
   	int y;
   	int z;
   	int k;
   	int w;
   	int j;
   	int i;

   	//#########################

    //Criando um laço for para que todos os indices do vetor x recebam o valor 0
    for(y = 0;y <= 199;y++){
        x[y] = 0;
    }
    
    //Lendo os números de entrada do usuário
    printf("Digite os numeros (-1 para sair)\n");
    //Enquanto y for diferente de -1 ele continuara repetindo o laço
    while (y != -1) {
        scanf("%d", &y);
        //Se y for diferente de -1 
        if (y != -1) {
            /*
                O vetor x no índice que tem o valor da divisão inteira entre y e 32 
                recebe o (OU BITWISE) de x no índice com o valor da divisão inteira entre y e 32 
                e (1 << y%32) então o binário de 1 será deslocado para a esquerda o valor do resto da divisão de y e 32

                Exemplificando:
                Entrada: 5
                x[5/32] = x[5/32] | (1 << y%32) 
                x[0] = x[0] | (1 << 2) 
            */
            x[y/32] = x[y/32] | (1 << y%32);

        }
    }

    printf("IMPRIMINDO \n");
    //Y percorre de 0 a até 200
    for(y = 0; y <= 199; y++) {
            //Z percorre de 0 até 32
            for(z = 0;z <= 31;z++){
                /*
                    Se o E BITWISE entra 1 e o valor que está em x no índice y (tendo seu bit deslocado z vezes para a esquerda) for verdadeiro
                    será impresso o valor de y vezes 32 + z
                    Exemplificando:
                    Dados: y = 20 e Z = 2
                    if(1 & (x[20] >> 2)){
                        printf("%d \n",((32*20) + 2));
                    }
                */
                if(1 &(x[y] >> z)){
                    printf("%d \n",((32*y) + z));
                }
            }
        }

   	//#########################

	return 0;
}
