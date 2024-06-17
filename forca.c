// ICC-1 João Gabriel Pieroli da Silva BCC-024 USP-ICMC

#include <stdio.h>
#include <stdlib.h>

/*  A função "pedirasinfos" basicamente é responsável por obter a palavra da forca e a dica que o usuário dá ao jogador que irá tentar descobri-la.
*/
void pedirasinfos(char *palavra, char *dica)
{
 	//Ler palavra da forca
	printf("Qual a palavra a ser descoberta?\n");
	scanf("%29s", palavra);

	 //Pedir a dica para dar a quem vai descobrir
	printf("Qual dica deverá ser dada?\n");
	scanf("%29s", dica);
}
/*  A função "uppereocultarsecreta" padroniza a palavra recebida em caso de ter sido digitada com letras minúsculas e/ou só com algumas maíusculas, de modo a torná-la garantidamente toda maíuscula. Além disso, ela cria o vetor secreta para mostrar ao usuário o avanço de suas descobertas sobre a palavra. Ainda, aqui é onde eu descubro o tamanho do vocábulo que estou lidando e, por derreferência, passo ele para main (evitando, assim, o uso da biblioteca string.h)
*/
void uppereocultarsecreta(char *palavra, char *secreta, int *tam){
	int a=0;
	while (palavra[a]!='\0')
	{
	    //  Lê a palavra posição por posição, mudando, se for o caso, de uma letra minúscula para a sua respectiva maiúscula. Isso foi feito para padronizar a verificação futura.
		if(palavra[a]>96 && palavra[a]<123)
		{
			palavra[a]-=32; 
		}
		
		//  Cria uma sequência de hífens de mesmo tamanho da palavra original para mostrar ao usuário a palavra enquanto ainda faltam descobrir letras. Esse vetor vai se atualizando conforme o usuário descobre partes do vocábulo secreto.
		secreta[a]='-'; 
		
		// Variável que verifica o tamanho da palavra (Poderia ser feito com a função strlen da string.h)
		(*tam)++; 
		
		a++;
	}
}
/* A função forca é aquela que detém a base lógica do programa, que é justamente um jogo de forca convencional */
void forca(char *dica, char *secreta, char *palavra, char *letra, int tam) {
    
    //  Estabelece uma quantidade fixa de tentativas (Cabeça, troco, braço esquerdo, braço direito, perna esquerda e perna direito, ou seja, o padrão, sem roubos)
    int tentativas = 6; 
    
    //  Inicializa com um caracter especial o vetor de letras que já foram tentadas
    char letrastentadas[6] = {'+', '+', '+', '+', '+', '+'}; 
    
    // Aqui começa de fato o loop da forca, considerando que a cada erro, diminuímos uma tentativa, e a cada acerto, em nada influencia na quantia de tentativas.
    while (tentativas > 0) {

        //  Primeiramente, mostramos a dica dada pelo usuário ao jogador da função "pedirasinfos".
        printf("Dica: %s\n", dica);
        
        //  Segundamente, exibimos a cada loop a quantia de tentativas que ainda restam.
        printf("\n%d tentativas restantes\n", tentativas);
        
        //  Terceiramente, mostramos como está a palavra secreta até então. (Com hífens para as letras que, até então, não tenham sido descobertas)
        printf("\n%s\n", secreta);

        //  A partir do momento que tivermos errado, ao menos, uma letra, esta aparecerá nesse momento, em que se imprime as letras tentadas, que serão diferentes do caracter especial selecionado '+'.
        if (tentativas < 6) {
            printf("Letras que você já tentou e não estão na palavra: ");
            for (int i = 0; i < 6; i++) {
                if (letrastentadas[i] != '+') {
                    printf("%c ", letrastentadas[i]);
                }
            }
            printf("\n");
        }

        // Então, perguntamos ao jogador qual letra gostaria de tentar.
        printf("\nQual a letra que gostaria de tentar?\n");
        scanf(" %c", letra);

        // Fazemos uma conversão da letra para maiúscula caso seja necessário
        if (*letra >= 'a' && *letra <= 'z') {
            *letra -= 32;
        }
        
        //  Declaramos uma variável acerto (que poderia ser do tipo booleana, mas teríamos que importar a biblioteca stdbool.h). Como não fiz isso, para a situação, bastou utilizar 0 para falso, 1 para verdadeiro.
        int acerto = 0;

        //  Verificamos se a letra digitada existe na palavra e, se sim, o vetor de hífens secreto é alterado naquela exata posição para a letra correta. Ainda, se entramos nesse if, significa que acertamos a letra, então, acerto recebe 1(verdadeiro) e não descontaremos a quantidade de tentativas
        for (int i = 0; i < tam; i++) {
            if (palavra[i] == *letra) {
                secreta[i] = *letra;
                acerto = 1;
            }
        }
        
        //  Agora, verificamos se no vetor secreto, ainda existem hífens, significando que restam letras a serem descobertas. Se ele entrar no if, a variavel palavra_completa recebe 0, de forma a indicar que é falsa a ideia de que a palavra foi descoberta por completo.
        int palavra_completa = 1;
        for (int i = 0; i < tam; i++) {
            if (secreta[i] == '-') {
                palavra_completa = 0;
                break;
            }
        }

        //  Em princípio, vemos se a palavra foi ou não completamente descoberta. Se sim, limpamos o visor e declaramos a vitória ao jogador, saindo, por fim, do loop while. Caso contrário, a palavra ainda não foi descoberta. Então, precisamos analisar se o jogador acertou ou não uma letra. Se acerto for falso, isto é, erramos a letra, acerto é 0 e ele entra no if, guarda a letra falhamente tentada e decrementa tentativas. Se acerto, vier como verdadeiro, ou seja, acerto=1, ele não vai entrar no if e o programa apenas continua, sem fazer decrementos ou armazenar letras erradas. Por fim, o sistema limpa e volta ao inínio do while até que: 1) A palavra seja acertada(break sai do loop); 2) Esgotem as tentativas;
        if (palavra_completa) {
            system("clear");
            printf("Parabéns! Você conseguiu acertar a palavra: %s\n", secreta);
            break;
        } else {
            if (acerto==0) {
                letrastentadas[6 - tentativas] = *letra; 
                tentativas--;
            }
            system("clear");
        }
    }
    
    // Se esgotadas as tentativas, a mensagem de derrota é imprimida na tela e, dessa maneira, acaba o programa.
    if (tentativas == 0) {
        printf("Não foi dessa vez que você descobriu a palavra: %s\n", palavra);
    }
}
int
main () {
	char palavra[30]={}, dica[30]={}, secreta[30]={}, letra[1]={};

	pedirasinfos(palavra, dica);

	//Limpar visor;
	system("clear");

	int tam=0;
	uppereocultarsecreta(palavra, secreta, &tam);

	forca(dica, secreta, palavra, letra, tam);

	return EXIT_SUCCESS;
}