import java.io.IOException;
import random.Random;

public class constructor{
	public static void main(String[] args){
		Random r = new Random(3223);
		Random s = new Random(3205);
		int x, y, c = 0; 
		do{
			x = r.getIntRand(500) + 1;
			y = s.getIntRand(500) + 1;
			c++;
		}while(x!=y);
		System.out.println("Numero: " + x);
		System.out.println("Iteraçoes: " + c);
	}

}
