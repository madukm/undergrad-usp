import java.util.*;

/**
 * Classe que representa um contato do tipo Pessoa Jurídica.
 * @author Maria Eduarda Kawakami Moreira
 */
public class PessoaJuridica extends Contato{
	private String CNPJ;
	private String inscricao;
	private String razaoSocial;
	
	/**
	 * Cria um contato do tipo Pessoa Jurídica com seus respectivos atributos.
	 */
	public PessoaJuridica(String nome, String endereco, String email, String CNPJ, String inscricao, String razaoSocial){
		super(nome, endereco, email);
		this.CNPJ = CNPJ;
		this.inscricao = inscricao;
		this.razaoSocial = razaoSocial;
	}

	/**
	 * Getter do CNPJ
	 */
	public String get_CNPJ(){
		return CNPJ;
	}

	/**
	 * Getter da inscrição.
	 */
	public String get_inscricao(){
		return inscricao;
	}

	/**
	 * Getter da Razão Social
	 */
	public String get_razaoSocial(){
		return razaoSocial;
	}
		
}
