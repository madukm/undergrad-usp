import java.util.*;

/**
 * Classe que representa um círculo
 * @author Maria Eduarda Kawakami Moreira
 */
public class Circulo extends Figura{
	private double raio;
	
	/**
	 * Cria um círculo.
	 */	
	public Circulo(String cor, boolean filled, double raio){
		super(cor, filled);
		this.raio = raio;
	}

	/**
	 * Getter area.
	 */
	public double get_area(){
		return raio * raio * Math.PI;
	}
	
	/**
	 * Getter perimetro.
	 */
	public double get_perimeter(){
		return 2 * Math.PI * raio;
	}
}
