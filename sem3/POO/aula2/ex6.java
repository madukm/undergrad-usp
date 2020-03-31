import java.io.IOException;
import exercises.EntradaTeclado;

public class ex6 {

	public static void main(String[] args) throws IOException {
		double n, min, max;
		System.out.println("Valores: ");
		n = EntradaTeclado.leDouble();
		max = min = n;
		while(true){
			while(true){
				try{
					n = EntradaTeclado.leDouble();
					break;
				}catch(Exception e){
					System.out.println("O valor não é um double.");
				}
			}
			if(n == 0) break;
			if(n < min)
				min = n;
			else if(n > max)
				max = n;
		}
		System.out.println("O menor valor é" + min);
		System.out.println("O maior valor é" + max);
	}

}
