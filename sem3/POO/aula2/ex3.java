import java.io.IOException;
import exercises.EntradaTeclado;

public class ex3{

        public static void main(String[] args) throws IOException {
		int n;
		while(true)
                        try{
                                System.out.print("Quantas linhas?");
                                n = EntradaTeclado.leInt();
                                break;
                        }catch(Exception e){
                                System.out.println("Valor não é um inteiro. Tente novamente.);
                        }
                for(int i = n; i >=1 ; i--){
			for(int k = n-i; k>0; k--{
				System.out.print(" ");	
			}  
                        for(int j = 1; j <= i; j++)
                               System.out.print("*");
                        System.out.println();
                }

        }

}


