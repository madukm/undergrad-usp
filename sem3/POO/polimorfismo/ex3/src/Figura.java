import java.util.*;

/**
 * Classe que representa uma figura geral.
 * @author Maria Eduarda Kawakami Moreira
 */
public class Figura{
	private String cor;
	private boolean filled;

	/** 
	 * Cria uma figura.
	 */
	public Figura(String cor, boolean filled){
		this.cor = cor;
		this.filled = filled;
	}
	
	/**
	 * Getter filled.
	 */
	public boolean is_filled(){
		return filled;
	}

	/**
	 * Getter cor.
	 */
	public String get_cor(){
		return cor;
	}

	/**
	 * Setter cor.
	 */
	public void set_cor(String cor){
		this.cor = cor;
	}
	
	/**
	 * Setter filled
	 */
	public void set_filled(boolean filled){
		this.filled = filled;
	}
}
