import java.io.IOException;
import exercises.EntradaTeclado;

public class ex8 {
	
	public static double function(double x){
		return x*x*x - x*x - 13*x + 8;
	}//funcao f

	public static double fLinha(double x){
		return 3*x*x - 2*x - 13;
	}//derivada da f

	public static void main(String[] args) throws IOException{
		double x, x1;
		int i = 0;
		while(true)
			try{	
				System.out.print("Chute: ");
                		x = EntradaTeclado.leDouble();
				break;
			}catch(Exception e){
				System.out.println("Valor nao é double. Tente novamente.");
			}
		do{
			x1 = x - function(x)/fLinha(x); //novo chute
			x = x1;
			i++;
		}while(Math.abs(function(x1)) >= 0.00000001);
		System.out.println("Raiz: " + x1);
		System.out.println("Interacoes: " + i);

	}

}
