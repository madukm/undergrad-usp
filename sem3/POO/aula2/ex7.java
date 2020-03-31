import java.io.IOException;
import exercises.EntradaTeclado;

public class ex7 {

	public static double function(double x){
		return x*x*x - x*x - 13*x + 8;
	}

	public static void main(String[] args) throws IOException {
		double a, b, media;
		int i = 0; //interacoes
		while(true)
			try{
				System.out.print("Forneça o limite inferior do intervalo: ");
				a = EntradaTeclado.leDouble();
				System.out.print("Forneça o limite superior do intervalo: ");
				b = EntradaTeclado.leDouble();
				if(a>=b){
					System.out.println("Intervalo invalido. Tente novamente.");
				}
				break;
			}catch(Exception e){
				System.out.println("Valores nao sao double. Tente novamente.");
			}	
		do{
			media = (a + b)/2; //novo chute
			if((function(a) * function(media)) > 0){
				a = media;
			}
			else{
				b = media;
			}//novo intervalo
			i++;
		}while(Math.abs(function(media)) >= 0.00000001);
		System.out.println("Raiz: " + media);
		System.out.println("Interacoes: " + i);
	}
	
}
