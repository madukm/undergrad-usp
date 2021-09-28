import java.util.*;

public class CD extends Produto{
	private String artista;
	private double capacidade;

	public CD(String codigoDeBarras, String nome, double preco, int quantidade, String artista, double capacidade){
		super(codigoDeBarras, nome, preco, quantidade);
		this.artista = artista;
		this.capacidade = capacidade;
	}

	public String get_artista(){
		return artista;
	}

	public double get_capacidade(){
		return capacidade;
	}
}
