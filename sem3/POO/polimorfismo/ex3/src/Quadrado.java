import java.util.*;

/**
 * Classe que representa um quadrado.
 * @author Maria Eduarda Kawakami Moreira
 */
public class Quadrado extends Retangulo{
	private double lado;

	/**
	 * Cria um quadrado a partir da classe Retangulo.
	 */	
	public Quadrado(String cor, boolean filled, double lado){
		super(cor, filled, lado, lado);
		this.lado = lado;
	}
}
