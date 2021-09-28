import java.util.*;

/**
 * Classe que representa um contato do tipo Pessoa Física.
 * @author Maria Eduarda Kawakami Moreira
 */
public class PessoaFisica extends Contato{
	private String CPF;
	private String estadoCivil;
	private String dataDeNascimento;

	/**
	 * Cria um contato do tipo Pessoa Física com seus respectivos atributos.
	 */	
	public PessoaFisica(String nome, String endereco, String email, String CPF, String estadoCivil, String dataDeNascimento){
		super(nome, endereco, email);
		this.CPF = CPF;
		this.estadoCivil = estadoCivil;
		this.dataDeNascimento = dataDeNascimento;
	}

	/**
	 * Getter do CPF
	 */
	public String get_CPF(){
		return CPF;
	}

	/**
	 * Getter do Estado Civil
	 */
	public String get_estadoCivil(){
		return estadoCivil;
	}

	/**
	 * Getter da Data de Nascimento
	 */
	public String get_dataDeNascimento(){
		return dataDeNascimento;
	}
}
