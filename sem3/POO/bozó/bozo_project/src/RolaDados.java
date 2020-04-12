import java.util.*;

/**
 * Essa é uma classe auxiliar que permite gerenciar um conjunto de vários dados simultaneamente.
 * Operações como rolar alguns dos dados ou exibir o resultado de todos eles, são implementadas.
 * @author Maria Eduarda Kawakami Moreira
 */
public class RolaDados{
	//Objects:
	private int numeroDados;
	private Dado dados[];

	/**
	 * Construtor que cria e armazena vários objetos do tipo Dado.
	 * Usa para isso o construtor padrão daquela classe, ou seja, um dado de 6 lados e gerando sempre uma semente aleatória para o gerador de números aleatórios.
	 * Os dados criados podem ser referenciados por números, entre 1 a n.
	 * @param n - Número de dados a serem criados.
	 */
	public RolaDados(int n){
		dados = new Dado[n];
		for(int i=0; i<n; i++)
			dados[i] = new Dado();
		numeroDados = n;
	}

	/**
	 * Rola todos os dados.
	 * @return Retorna o valor de cada um dos dados, inclusive os que não foram rolados.
	 * Nesse caso,o valor retornado é o valor anterior que ele já possuia.
	 */
	public int[] rolar(){
		int lancamentos[] = new int[numeroDados]; 
		for(int i=0; i<numeroDados; i++){
			lancamentos[i] = dados[i].rolar();
			while(true)
				try{
 			   		Thread.sleep(100); //Usado para evitar que a mesma semente seja gerada na classe Random. 
					break;
				}catch(InterruptedException e){
    				Thread.currentThread().interrupt();
				}
		}
		return lancamentos;
	}

	/**
	 * Rola alguns dos dados.
	 * @param quais - É um array de booleanos que indica quais dados devem ser rolados.
	 * Cada posição representa um dos dados.
	 * Ou seja, a posição 0 do array indica se o dado 1 deve ser rolado ou não, e assim por diante.
	 * @return Retorna o valor de cada um dos dados, inclusive os que não foram rolados.
	 */
	public int[] rolar(boolean[] quais){
		int lancamentos[] = new int[numeroDados];
		for(int i=0; i<numeroDados; i++){
			if(quais[i] == true){
				lancamentos[i] = dados[i].rolar(); //Dados a serem rolados
				while(true)
					try{
						Thread.sleep(100);
						break;
					}catch(InterruptedException e){
						Thread.currentThread().interrupt();
					}
			}
			else
				lancamentos[i] = dados[i].getLado(); //Dados que não serão rolados apenas pegam o lado do lançamento anterior.
		}
		return lancamentos;
	}
	
	/**
	 * Rola alguns dos dados.
	 * @param s - É um string que possui o número de dados a serem rolados. Por exemplo "1 4 5" indica que os dados 1 4 e cinco devem ser rolados.
	 * Os números devem ser separados por espaços.
	 * Se o valor passado na string estiver fora do intervalo válido, ele é ignorado simplesmente.
	 * @return Retorna o valor de cada um dos dados, inclusive os que não foram rolados.
	 */	
	public int[] rolar(String s){
		String[] separado = s.split(" ");
		boolean quais[] = {false, false, false, false, false};
		for(int i=0; i<separado.length; i++){
			try{
				int num = Integer.parseInt(separado[i]); //Separando cada número.
				quais[num-1] = true; //Tranforma a string em um boolean.
			}catch(NumberFormatException e){
				continue;
			}
		}
		return rolar(quais); //Chama a função rolar(boolean quais[]);
	}

	/**
	 * Usa a representação em string dos dados, para mostrar o valor de todos os dados do conjunto. Exibe os dados horisontalmente, por exemplo:
	 *  1          2          3          4          5
	   +-----+    +-----+    +-----+    +-----+    +-----+    
	   |*   *|    |     |    |*    |    |*    |    |*   *|    
       |  *  |    |  *  |    |     |    |  *  |    |     |    
       |*   *|    |     |    |    *|    |    *|    |*   *|    
       +-----+    +-----+    +-----+    +-----+    +-----+   	
	 */
	@Override	
	public String toString(){
		String dadosMostrar = 
			" 1          2          3          4          5\n"+
			"+-----+    +-----+    +-----+    +-----+    +-----+    \n";
		//Primeira linha da representação dos dados.
		for(int i=0; i<numeroDados; i++){
			if(dados[i].getLado() == 5 || dados[i].getLado() == 4)
				dadosMostrar += "|*   *|";
			else if(dados[i].getLado() == 2 || dados[i].getLado() == 3)
				dadosMostrar += "|*    |";
			else if(dados[i].getLado() == 6)
				dadosMostrar += "|* * *|";
			else
				dadosMostrar += "|     |";
			dadosMostrar += "    ";
		}
		dadosMostrar += "\n";
		//Segunda linha da representação dos dados.
		for(int i=0; i<numeroDados; i++){
			if(dados[i].getLado() == 1 || dados[i].getLado() == 3 || dados[i].getLado() == 5)
				dadosMostrar += "|  *  |";
			else	
				dadosMostrar += "|     |";
			dadosMostrar += "    ";
		}
		dadosMostrar += "\n";
		//Terceira linha da representação dos dados.
		for(int i=0; i<numeroDados; i++){
			if(dados[i].getLado() == 4 || dados[i].getLado() == 5)
				dadosMostrar += "|*   *|";
			else if(dados[i].getLado() == 2 || dados[i].getLado() == 3)
				dadosMostrar += "|    *|";
			else if(dados[i].getLado() == 6)
				dadosMostrar += "|* * *|";
			else
				dadosMostrar += "|     |";
			dadosMostrar += "    ";
		}
		dadosMostrar += "\n";
		dadosMostrar += "+-----+    +-----+    +-----+    +-----+    +-----+   \n";
		return dadosMostrar;
	}
}
