import java.util.*;
import java.util.Calendar;

/**
 * Gerador simples de números aleatórios.
 * @author Maria Eduarda Kawakami Moreira
 */
public class Random{
        private long p = 28924333L;
        private long m = 1284875;
        private long a = 3118464;
        private long xi = 1023;
		
		/**
		 * Construtor que usa uma semente aleatória, adquerida usando o método Calendar.getTimeInMillis().
		 */
		public Random(){
			xi = Calendar.getInstance().getTimeInMillis()%p;
		}
		
		/**
		 * Construtor que permite criar o gerador, especificando o valor inicial da semente.
		 * @param k - O valor inicial da semente.
		 */
		public Random(int k){
			xi = k;
		}

		/**
		 * Retorna um número aleatório no intervalo (0,1[
		 * @return O número gerado.
		 */
		public double getRand(){
                xi = (a + m * xi) % p;
                double d  = xi;
                return d/p;
        }
		
		/**
		 * Retorna um valor inteiro no intervalo (0,max[
		 * @param max - O valor limite para a geração do número inteiro.
		 * @return O número gerado.
		 */
        public int getIntRand(int max){
                double d = getRand()*max;
                return (int)d;
        }
		
		/**
		 * Permite alterar a semente de geração de números aleatórios.
		 * Supostamente deve ser chamada antes de iniciar a geração, mas se for chamado a qualquer instante, reseta o valor da semante.
		 * @param semente - o valor da nova semente de geração.
		 */
			
		 public void set_semente(long x){
			xi = x;
		}

		@Override
		public String toString(){
			return xi + "";
		}
}


