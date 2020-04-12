package bozo;

import java.util.*;
import java.io.IOException;

/**
 *	Esta classe possui apenas a main, que executa o jogo.
 *	@author Maria Eduarda Kawakami Moreira
 */
public class Bozo{
	/**
	 * Método inicial do programa.
	 * Ele cuida da execução do jogo e possui um laço, no qual cada iteração representa uma rodada do jogo.
	 * Em cada rodada, o jogador joga os dados até 3 vezes e depois escolhe a posição do placar que deseja preencher.
	 * No final das rodadas a pontuação total é exibida.
	 * @param args -
	 * @throws IOException
	 * @author Maria Eduarda Kawakami Moreira
	 */
	public static void main(java.lang.String[] args) throws java.io.IOException{
		Placar placar = new Placar();
		RolaDados rolaDados = new RolaDados(5);
		int dados[];
		System.out.println(placar);
		for(int i=0; i<10; i++){ //10 rodadas.
			System.out.println("-------Rodada " + (i+1) + "-------");
			System.out.println("Pressione enter para rolar os dados: ");
			String enter = EntradaTeclado.leString(); 
			dados = rolaDados.rolar(); //Rola os dados pela primeira vez.
			System.out.print(rolaDados); //Imprime os dados.
			for(int j=0; j<2; j++){ //Esse laço representa as duas vezes em que o jogador pode mudar os dados que queira.
				System.out.println("\nDigite o número dos dados que deseja trocar separados por espaço.");
				String dadosMudar = EntradaTeclado.leString();
				dados = rolaDados.rolar(dadosMudar);
				System.out.println(rolaDados); //Imprime os dados.
			}
			int posicao; 
			System.out.println(placar);
			while(true){
				System.out.println("Escolha a posição que deseja ocupar: ");
				try{
					posicao = EntradaTeclado.leInt();
					break;
				}catch(IllegalArgumentException e){
					System.out.println("Posição inválida. Escolha a posição que deseja ocupar: ");
				}
			}
			placar.add(posicao, dados); //Atualiza o placar com a posição escolhida pelo jogador.
			System.out.println(placar); //Imprime novamente o placar.
		}
		System.out.println("-------FIM DE JOGO-------");
		System.out.println("Total de pontos: " + placar.getScore()); //Imprime o total de pontos que o jogador fez no jogo.
	}
}
