import java.util.*;

/**
 * Classe que representa um retângulo.
 * @author Maria Eduarda Kawakami Moreira
 */
public class Retangulo extends Figura{
	private double lado1;
	private double lado2;
	
	/**
	 * Cria um retângulo
	 */
	public Retangulo(String cor, boolean filled, double lado1, double lado2){
		super(cor, filled);
		this.lado1 = lado1;
		this.lado2 = lado2;
	}
	
	/**
	 * Getter da área.
	 */
	public double get_area(){
		return lado1 * lado2; 
	}
	
	/**
	 * Getter do perímetro.
	 */
	public double get_perimeter(){
		return 2 * (lado1 + lado2);
	}
}
