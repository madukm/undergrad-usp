import java.util.*;
import java.io.IOException;

/**
 * Classe para testar o perímetro e a área das figuras.
 * @author Maria Eduarda Kawakami Moreira
 */
public class CriaFiguras{
	/**
	 * Menu do programa.
	 * Informa a área e o perímetro da figura descrita pelo usuário.
	 */
	public static void main(String[] args) throws Exception{
		int op = 0;
		CriaFiguras cf = new CriaFiguras();
		while(op != 2){
			System.out.println("1: Área e Perímetro\n2: Sair\n");
			op = le_opcao(2);
			switch(op){
				case 1:
					System.out.println("-----ÁREA E PERÍMETRO-----");
					cf.areaPerimetro();
					break;
				case 2:
					System.out.println("Encerrando....");
					return;
			}
		}
	}

	/**
	 * Função que lê uma String.
	 * @throws IOException.
	 * @return String lida.
	 */
	public static String le_string(){
		String str;
		while(true)
			try{
				str = EntradaTeclado.leString();
				return str;
			}catch(IOException e){
				System.out.println("Formato inválido. Tente novamente: ");
			}
	}

	/**
	 * Função que lê um inteiro.
	 * @throws IOException.
	 * @return inteiro lido.
	 */
	public static int le_int(){
		int i;
		while(true)
			try{
				i = EntradaTeclado.leInt();
				return i;
			}catch(IOException e){
				System.out.println("Formato inválido. Tente novamente: ");
			}
	}

	/**
	 * Função que lê um double.
	 * @throws IOException
	 * @return double lido.
	 */
	public static double le_double(){
		double d;
		while(true)
			try{
				d = EntradaTeclado.leDouble();
				return d;
			}catch(IOException e){
				System.out.println("Formato inválido. Tente novamente: ");
			}
	}

	/**
	 * Função que já lê uma opção de 1 até o número de operações.
	 * Confere se o valor lido está no range definido.
	 * @param nOpcoes - Número de operações disponíveis.
	 * @return a opção escolhida pelo usuário.
	 *
	 */
	public static int le_opcao(int nOpcoes){
		int i;
		while(true)
			try{
				System.out.println("Escolha uma das opções: ");
				i = EntradaTeclado.leInt();
				if(i>0 && i<=nOpcoes) return i;
			}catch(Exception e){
				System.out.println("Opção inválida, tente novamente.");
			}
	}
	
	/**
	 * A classe calcula o perímetro e a área e imprime para o usuário.
	 */
	public void areaPerimetro(){
		System.out.println("1: Círculo\n2: Retângulo\n3: Quadrado");
		int opcao;
		opcao = le_opcao(3);
		System.out.println("Cor da figura: ");
		String cor = le_string();
		System.out.println("A figura é preenchida pela cor? S/n");
		boolean filled;
		while(true)
			try{
				String c = le_string();
				if(c.equalsIgnoreCase("s")){
					filled = true;
					break;
				}
				if(c.equalsIgnoreCase("n")){
					filled = false;
					break;
				}
			}catch(Exception e){
				System.out.print("Opção não válida. ");
			}
		switch(opcao){
			case 1:
				System.out.println("Raio: ");
				double raio = le_double();
				Circulo circulo = new Circulo(cor, filled, raio);
				System.out.println("Área = " + circulo.get_area());
				System.out.println("Perímetro = " + circulo.get_perimeter());
				break;
			case 2:
				System.out.println("Lado 1: ");
				double lado1 = le_double();
				System.out.println("Lado 2: ");
				double lado2 = le_double();
				Retangulo retangulo = new Retangulo(cor, filled, lado1, lado2);
				System.out.println("Área = " + retangulo.get_area());
				System.out.println("Perímetro = " + retangulo.get_perimeter());
				break;
			case 3:
				System.out.println("Lado: ");
				double lado = le_double();
				Quadrado quadrado = new Quadrado(cor, filled, lado);
				System.out.println("Área = " + quadrado.get_area());
				System.out.println("Perímetro = " + quadrado.get_perimeter());
				break;
		}	
	}
}
