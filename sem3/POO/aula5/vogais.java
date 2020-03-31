import java.io.IOException;
import exercises.EntradaTeclado;

public class vogais{
	public static void main(String[] args){
		String str, upper, str2;
		int cont = 0;
		while(true)
		try{
			System.out.print("Digite uma palavra: ");
			str = EntradaTeclado.leString();
			break;
		}catch(Exception e){
			System.out.println("Não é uma string, tente novamente.");
		}
		upper = str.toUpperCase();
		for(int i = 0; i<upper.length(); i++){
			if(upper.charAt(i) == 'A' || upper.charAt(i) == 'E' || upper.charAt(i) == 'I' || upper.charAt(i) == 'O' || upper.charAt(i) == 'U')
			cont++;
		}
		System.out.println(upper);
		System.out.println("Numero de vogais: " + cont);
		while(true)
			try{
			System.out.print("Digite outra palavra: ");
			str2 = EntradaTeclado.leString();
			break;
			}catch(Exception e){
				System.out.println("Não é uma string, tente novamente.");
			}
		if(str.startsWith(str2))
			System.out.println("Aparece no inicio.");
		else
			System.out.println("Aparece no final.");

	}
}
