import java.util.*;

/**
 * Representa um contato na Agenda.
 * Possui atributos comuns entre Pessoa Física e Pessoa Jurídica.
 * @author Maria Eduarda Kawakami Moreira
 */

public class Contato{
	protected String nome;
	protected String endereco;
	protected String email;

	/**
	 * Cria um contato geral com os atributos comuns aos dois tipos de contato.
	 */	
	public Contato(String nome, String endereco, String email){
		this.nome = nome;
		this.endereco = endereco;
		this.email = email;
	}

	/**
	 * Getter do nome.
	 */
	public String get_nome(){
		return nome;
	}

	/**
	 * Getter do endereço.
	 */
	public String get_endereco(){
		return endereco;
	}

	/**
	 * Getter do email.
	 */
	public String get_email(){
		return email;
	}
}
