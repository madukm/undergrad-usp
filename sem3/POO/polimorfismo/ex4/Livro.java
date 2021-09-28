import java.util.*;

public class Livro extends Produto{
	private String autor;
	private int anoDePublicacao;
	private String editora;

	public Livro(String codigoDeBarras, String nome, double preco, int quantidade, String autor, int anoDePublicacao, String editora){
		super(codigoDeBarras, nome, preco, quantidade);
		this.autor = autor;
		this.anoDePublicacao = anoDePublicacao;
		this.editora = editora;
	}

	public String get_autor(){
		return autor;
	}

	public int get_anoDePublicacao(){
		return anoDePublicacao;
	}

	public String get_editora(){
		return editora;
	}
}
