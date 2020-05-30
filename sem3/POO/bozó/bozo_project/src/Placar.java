//import java.util.*;

/**
 * Esta classe representa o placar de um jogo de Bozó.
 * Permite que combinações de dados sejam alocadas às posições e mantém o escore de um jogador.
 * @author Maria Eduarda Kawakami Moreira.
 */
public class Placar{
	private int placar[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	
	/**
	 * Adiciona uma sequencia de dados em uma determinada posição do placar.
	 * Após a chamada, aquela posição torna-se ocupada e não pode ser usada uma segunda vez.
	 * @param posicao - Posição a ser preenchida.
	 * As posições 1 a 6 correspondem às quantidas de uns até seis, ou seja, as laterais do placar.
	 * As outas posições são: 7 - full hand; 8 - sequencia; 9 - quadra; e 10 - quina
	 * @param dados - um array de inteiros, de tamanho 5.
	 * Cada posição corresponde a um valor de um dado.
	 * Supões-se que cada dado pode ter valor entre 1 e 6.
	 * @throws java.lang.IllegalArgumentException Se a posição estiver ocupada ou se for passado um valor de posição inválido, essa exceção é lançada.
	 * Não é feita nenhuma verificação quanto ao tamanho do array nem quanto ao seu conteúdo.
	 */

	public void add(int posicao, int[] dados) throws java.lang.IllegalArgumentException{
		if(posicao <= 0 || posicao > 10 || placar[posicao-1] != -1)
			throw new IllegalArgumentException("Posição ocupada.");
		else{
			if(posicao <= 6){
				int score = 0;
				for(int i=0; i<dados.length; i++){
					if(dados[i] == posicao)
						score += posicao;
				}
				placar[posicao-1] = score;
			}
			else{
				switch(posicao){
					case 7:
						//FULL HAND: 2 dados de um número e 3 de outro, ou 5 dados de um número.
						int flag2 = 0, flag3 = 0, flag5 = 0; //As flags serão usadas para verificarmos.
						int fullHand[] = new int[6];
						for(int i=0; i<5; i++)
							//try{
								fullHand[dados[i]-1]++;
							//}catch(ArrayIndexOutOfBoundsException e){
							//	continue;
							//}
						for(int i=0; i<6; i++){
							if(fullHand[i] == 2)
								flag2 = 1;
							if(fullHand[i] == 3)
								flag3 = 1;
							if(fullHand[i] == 5)
								flag5 = 1;
						}
						if(flag2 == 1 && flag3 == 1) 
							placar[6] = 15;
						else if(flag5 == 1)
							placar[6] = 15;
						else
							placar[6] = 0;
						break;
					case 8:
						//SEQUÊNCIA: Dados de 1 a 5 ou de 2 a 6.
						int sequencia[] = new int[6];
						int flagSeq = 1;
						for(int i=0; i<5; i++){
							//try{
								sequencia[dados[i]-1]++;
							//}catch(ArrayIndexOutOfBoundsException e){
							//	continue;
							//}
						}
						//Para verificarmos a sequência, basta ver se nos 4 dados, os lados 2 a 5 aparecem apenas 1 vez, pois o dado restante terá que ter lado 1 ou lado 6.
						for(int i=1;i<5;i++){
							if(sequencia[i] != 1)
								flagSeq = 0;
						}
						if(flagSeq == 1)
							placar[7] = 20;
						else
							placar[7] = 0;
						break;

					case 9:
						//QUADRA: 4 dados de um mesmo número.
						int flag4 = 0;
						int quadra[] = new int[6];
						for(int i=0; i<5; i++){
							//try{
								quadra[dados[i]-1]++;
							//}catch(ArrayIndexOutOfBoundsException e){
							//	continue;
							//}
						}
						for(int i=0; i<6; i++){
							if(quadra[i] >= 4)
								flag4 = 1;
						}
						if(flag4 == 1)
							placar[8] = 30;
						else
							placar[8] = 0;
						break;

					case 10:
						//QUINA: 5 dados de um mesmo número.
						int flagQuina = 0;
						int quina[] = new int[6];
						for(int i=0; i<5; i++){
							//try{
								quina[dados[i]-1]++;
							//}catch(ArrayIndexOutOfBoundsException e){
							//	continue;
							//}
						}
						for(int i=0; i<6; i++){
							if(quina[i] == 5)
								flagQuina = 1;
						}
						if(flagQuina == 1)
							placar[9] = 40;
						else
							placar[9] = 0;
						break;
						
					default:
						break;
				}
			}
		}
	}
	/**
	 * Computa a soma dos valores obtidos, considerando apenas as posições que já estão ocupadas.
	 * @return O valor da soma.
	 */
	public int getScore(){
		int score = 0;
		for(int i = 0; i<10; i++)
			if(placar[i] != -1)
				score += placar[i];
		return score;
	}
	
	/**
	 * A representação na forma de string, mostra o placar completo, indicando quais são as posições livres (com seus respectivos números)		 e o valor obtido nas posições já ocupadas. Por exemplo: 
 		(1)    |   (7)    |   (4) 
 		--------------------------
 		(2)    |   20     |   (5) 
 		--------------------------
 		(3)    |   30     |   (6) 
		--------------------------
        	   |   (10)   |
        	   +----------+ 

		mostra as posições 8 (sequencia) e 9 (quadra) ocupadas.
	 */
	@Override
	public String toString(){
		return
				" "+(placar[0] == -1 ? "(1)" : placar[0]+"  ")+"    " +
                "|   "+(placar[6] == -1 ? "(7)" : " "+placar[6])+"    " +
                "|   "+(placar[3] == -1 ? "(4)" : placar[3])+"    \n" +
                " --------------------------\n" +
                " "+(placar[1] == -1 ? "(2)" : placar[1]+"  ")+"    " +
                "|   "+(placar[7] == -1 ? "(8)" : " "+placar[7])+"    " +
                "|   "+(placar[4] == -1 ? "(5)" : placar[4])+"    \n" +
                " --------------------------\n" +
                " "+(placar[2] == -1 ? "(3)" : placar[2]+"  ")+"    " +
                "|   "+(placar[8] == -1 ? "(9)" : " "+placar[8])+"    " +
                "|   "+(placar[5] == -1 ? "(6)" : placar[5])+"    \n" +
                " --------------------------\n" +
                "        |   "+(placar[9] == -1 ? "(10)" : " "+placar[9]+" ")+"   |\n" +
                "        +----------+ ";
    }
}
