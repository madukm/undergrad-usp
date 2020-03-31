import java.io.IOException;
import exercises.EntradaTeclado;

public class ex2{
	
	public static void main(String[] args) throws IOException{
		double x, x0, x1, temp;
		while(true){
			try{
			System.out.print("Valor de x: ");
			x = EntradaTeclado.leDouble();
			break;
			}catch(Exception e){
				System.out.println("Valor não é um double. Tente novamente");
			}
		}
		while(true){
			try{
				System.out.print("Chute inicial: ");
				x0 = EntradaTeclado.leDouble();
				break;
			}catch(Exception e){
				System.out.println("Valor não é um double. Tente novamente");
			}
		}
		do{
			x1 = (x0+x/x0)/2;
			temp = x0;
			x0 = x1;
			
		}while(Math.abs(temp-x1)>=0.00000001);
		System.out.println("A raiz e: " + x1); 
	}

}

