import java.io.IOException;
import random.Random;
/* pra calcular numero aleatorio, fazemos x(i+1) = (a+m x(i))m  getRand()
 getIntRand(int m) numero aleatorio entre 0 e m-1
*/


public class learning{
	public static void main(String[] args){
		Random r = new Random();
		for(int i=0; i<6; i++){
			int x = r.getIntRand(60) + 1;
			System.out.println(i+1 + "numero:" +  x);
		}
	
	}




}
