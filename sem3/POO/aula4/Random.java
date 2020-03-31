package random;

import java.io.IOException;

public class Random{
        private long p = 28924333L;
        private long m = 1284875;
        private long a = 3118464;
        private long xi;
        //usando private pq n queremos saber como o metodo foi implementado, queremos apenas o resultado do random
        //ocultamento de informacao
        public Random(long semente){
		xi = semente;
	}

	public double getRand(){
                xi = (a + m * xi) % p;
                double d  = xi;
                return d/p;
        }

        public int getIntRand(int max){
                double d = getRand()*max;
                return (int)d;
        }

	//getters e setters
	public long get_semente(){
		return xi;
	}

	public void set_semente(long x){
		xi = x;
	}
}


