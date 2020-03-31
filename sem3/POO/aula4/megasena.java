import java.io.IOException;
import random.Random;
import exercises.EntradaTeclado;

public class megasena{
	public static void main(String[] args) throws IOException{
		Random r = new Random(748);
		int semente;
		while(true)
		try{
			System.out.print("Semente: ");
			semente = EntradaTeclado.leInt();
			break;
		}catch(Exception e){
			System.out.println("Try again.");
		}

		r.set_semente(semente);
		for(int i=0; i<6; i++){
			int x = r.getIntRand(60)+1;
			System.out.println(i+1 + "numero: " + x);
		}
	}

}
