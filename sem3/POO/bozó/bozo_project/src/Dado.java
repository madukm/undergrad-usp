import java.util.*;

/**
 * Simula um dado de número de lados variados.
 * Ao criar o objeto é possível estabelecer o número de lados.
 * A rolagem do dado é feita por meio de um gerador de números aleatórios (Random).
 * @author Maria Eduarda Kawakami Moreira
 */
public class Dado{
	//Objects:
	private int lados;
	private int lancamentoAnterior; 	
	
	/**
	 * Cria um dado com 6 lados (um cubo).
	 */
	public Dado(){
		this.lados = 6;
	}

	/**
	 * Cria objeto com um número qualquer de lados
	 * @param n - - número de lados do dado.
	 */
	public Dado(int n){
		this.lados = n;
	}
	/**
	 * Não tem função real dentro da classe. Foi usada apenas para testar os métodos implementados.
	 * @param args - -- Sem uso.
	 */
	public static void main(java.lang.String[] args){}
	
	/**
	 * Recupera o último número selecionado.
	 * @return o número do último lado selecionado.
	 */
	public int getLado(){
		return lancamentoAnterior;
	}
	
	/**
	 * Simula a rolagem do dado por meio de um gerador aleatório.
	 * O número selecionado pode posteriormente ser recuperado com a chamada a getLado().
	 * @return O número que foi sorteado.
	 */
	public int rolar(){
		Random r = new Random();
		int x = r.getIntRand(lados-1) + 1;//queremos um numero no dado, que vai de 1 até n
		lancamentoAnterior = x;
		return x;
	}

	/**
	 * Transforma representação do dado em String.
	 * É mostrada uma representação do dado que está para cima. Note que só funciona corretamente para dados de 6 lados. Exemplo:
		+-----+
		|*   *|
		|  *  |
		|*   *|
		+-----+
 	 */
	@Override
	public String toString(){
		switch(lancamentoAnterior){
			case 1:
				return
					"+-----+\n"+
					"|     |\n"+
					"|  *  |\n"+
					"|     |\n"+
					"+-----+\n";
			case 2:
           		return
               		"+-----+\n"+
                	"|*    |\n"+
                	"|     |\n"+
                	"|    *|\n"+
	            	"+-----+\n";
			case 3:
           		return
               		"+-----+\n"+
               		"|*    |\n"+
               		"|  *  |\n"+
               		"|    *|\n"+
                	"+-----+\n";
			case 4:
           		return
           			"+-----+\n"+
                	"|*   *|\n"+
                	"|     |\n"+
                	"|*   *|\n"+
          			"+-----+\n";
			case 5:
				return 
					"+-----+\n"+
					"|*   *|\n"+
                	"|  *  |\n"+
                	"|*   *|\n"+
                	"+-----+\n";
			case 6:
				return
					"+-----+\n"+
                	"|* * *|\n"+
                	"|     |\n"+
                	"|* * *|\n"+
                	"+-----+\n";
			default:
				return null;
		}
	}
}
