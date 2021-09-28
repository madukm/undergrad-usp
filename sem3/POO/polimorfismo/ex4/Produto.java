import java.util.*;

public class Produto{
	private String codigoDeBarras;
	private String nome;
	private double preco;
	private int quantidade;

	public Produto(String codigoDeBarras, String nome, double preco, int quantidade){
		this.codigoDeBarras = codigoDeBarras;
		this.preco = preco;
		this.nome = nome;
		this.quantidade = quantidade;
	}

	public String get_codigoDeBarras(){
		return codigoDeBarras;
	}

	public String get_nome(){
		return nome;
	}

	public double get_preco(){
		return preco;
	}

	public int get_quantidade(){
		return quantidade;
	}

	public void set_quantidade(int quantidade){
		this.quantidade = quantidade;
	}
	
}
