import java.util.*;
import java.io.IOException;

/**
 * A classe representa uma agenda.
 * A main simula a administração dessa agenda.
 * Faz as principais operações:
 * Adiciona, remove, busca, imprime e ordena os contatos na agenda.
 * @author Maria Eduarda Kawakami Moreira
 */
public class Agenda{
	private Contato contatos[] = new Contato[200];
	private int maxContatos = 200;
	private int nContatos = 0;

	/** Menu principal do programa.
	 * Cuida da administração da agenda.
	 * Possui um laço, cada iteração faz uma operação escolhida pelo usuário.
	 * Sai do laço apenas quando o usuário escolhe a opcão SAIR.
	 * @param args -
	 * @throws Exception
	 * @author Maria Eduarda Kawakami Moreira
	 */
	public static void main(String[] args) throws Exception{
		int op = 0;
		Agenda ag = new Agenda();
		System.out.println("----------AGENDA----------\n");
		while(op != 6){
			System.out.println("1: Adicionar Contato\n2: Remover Contato\n3: Buscar Contato\n4: Imprimir Agenda\n5: Imprimir Agenda Ordenada\n6: Sair\n");
			op = le_opcao(6);
			switch(op){
				case 1:
					ag.adicionar_contato();
					break;
				case 2:
					ag.remover_contato();
					break;
				case 3:
					System.out.println("----------BUSCAR CONTATO----------");
					int i = ag.busca_contato();
					if(i != -1)
						System.out.println("----------CONTATO ENCONTRADO-----------");
					break;		
				case 4:
					ag.print_agenda();
					break;
				case 5:
					ag.printar_ordenado();
					break;
				case 6:
					System.out.println("Encerrando....");
					return;	
			}
		}
	}

	/**
	 * Função que já lê uma opção de 1 até o número de operações.
	 * Confere se o valor lido está no range definido.
	 * @param num_op - Número de operações disponíveis.
	 * @return a opção escolhida pelo usuário.
	 *
	 */
	private static int le_opcao(int num_op){
		int k = -1;
		while(true){
			System.out.println("Digite a opção desejada: ");
			try{
				k = le_int();
				if(k>0 && k<=num_op) return k;
			}
			catch(Exception e){
				System.out.print("Opção não válida. ");
			}
		}
	}

	/**
	 * Função que lê um inteiro.
	 * @throws IOException.
	 * @return inteiro lido.
	 */
	private static int le_int(){
		int i;
		while(true){
			try{
				i = EntradaTeclado.leInt();
				return i;	
			}catch(IOException e){
				System.out.println("Número não válido. Tente novamente: ");
			}
		}
	}

	/**
	 * Função que lê uma String.
	 * @throws IOException.
	 * @return String lida.
	 */
	private static String le_string(){
		String str;
		while(true){
			try{
				str = EntradaTeclado.leString();
				return str;
			}catch(IOException e){
				System.out.println("String não válida. Tente novamente: ");
			}
		}
	}

	/**
	 * Adiciona um contato na Agenda, sendo esse Pessoa Física ou Jurídica.
	 * Os dados sobre o contato são recebidos do usuário.
	 *
	 */
	public void adicionar_contato(){
		if(nContatos >= maxContatos){
			System.out.println("Agenda cheia. Não é possível adicionar contatos.\n");
			return;
		}
		System.out.println("----------ADICIONAR CONTATO----------");
		int pessoa;
		System.out.println("1: Pessoa Física\n2: Pessoa Jurídica\n");
		pessoa = le_opcao(2);
		
		System.out.print("Informe o nome: ");
		String nome = le_string();
		
		System.out.print("Informe o endereço todo em uma linha: ");
		String endereco = le_string();
		
		System.out.print("Informe o email: ");
		String email = le_string();

		if(pessoa == 1){
			System.out.print("Informe o CPF: ");
			String CPF = le_string();
			System.out.print("Informe o Estado Civil: ");
			String estadoCivil = le_string();
			System.out.print("Informe a Data de Nascimento no formato DD/MM/AAAA: ");
			String dataDeNascimento = le_string();
			PessoaFisica pf = new PessoaFisica(nome, endereco, email, CPF, estadoCivil, dataDeNascimento);
			contatos[nContatos++] = pf;
		}
		else{
			System.out.print("Informe o CNPJ: ");
			String CNPJ = le_string();
			System.out.print("Informe o número da inscrição estadual: ");
			String inscricao = le_string();
			System.out.print("Informe a Razão Social: ");
			String razaoSocial = le_string();
			PessoaJuridica pj = new PessoaJuridica(nome, endereco, email, CNPJ, inscricao, razaoSocial);
			contatos[nContatos++] = pj;
		}
	}

	/**
	 * Imprime um contato i da Agenda.
	 * @param i - indíce do contato a ser imprimido.
	 */
	void print_contato(int i){
		if(contatos[i] instanceof PessoaFisica){
			PessoaFisica pf = (PessoaFisica) contatos[i];	
			System.out.println("Pessoa Física");
			System.out.println("Nome: " + pf.get_nome());
			System.out.println("Endereço: " + pf.get_endereco());
			System.out.println("Email: " + pf.get_email());
			System.out.println("CPF: " + pf.get_CPF());
			System.out.println("Estado Civil: " + pf.get_estadoCivil());
			System.out.println("Data de Nascimento: " + pf.get_dataDeNascimento() + "\n");	
			return;	
		}
		if(contatos[i] instanceof PessoaJuridica){
			PessoaJuridica pj = (PessoaJuridica) contatos[i];
			System.out.println("Pessoa Jurídica");
			System.out.println("Nome: " + pj.get_nome());
			System.out.println("Endereço: " + pj.get_endereco());
			System.out.println("Email: " + pj.get_email());
			System.out.println("CNPJ: " + pj.get_CNPJ());
			System.out.println("Inscrição Estadual: " + pj.get_inscricao());
			System.out.println("Razão Social: " + pj.get_razaoSocial() + "\n");
			return;		
		}
	}

	/**
	 * Busca um contato por nome, CPF, CNPJ ou parte deles.
	 * Imprime as informações do contato ao achar um que preencha os requisitos.
	 * Pede confirmação para o usuário se aquele era o contato esperado.
	 * @return indíce do contato buscado. Não será utilizado para esta função e sim para remover_contato.
	 */
	int busca_contato(){
		System.out.println("Opções de busca:");
		System.out.println("1: Nome\n2: CPF\n3: CNPJ");
		int opcao = le_opcao(3);
		String nome = "-";
		String cpf = "-";
		String cnpj = "-";
		if(opcao == 1){
			System.out.println("Informe o nome ou uma parte dele para realizar a busca: ");
			nome = le_string();
		}
		else if(opcao == 2){
			System.out.println("Informe o CPF ou uma parte dele para realizar a busca: ");
			cpf = le_string();
		}
		else{
			System.out.println("Informe o CNPJ ou uma parte dele para realizar a busca: ");
			cnpj = le_string();
		}
		for(int i=0; i<nContatos; i++){
			if(contatos[i] instanceof PessoaFisica){
				PessoaFisica pf = (PessoaFisica) contatos[i];
				if(pf.get_CPF().contains(cpf) || pf.get_nome().contains(nome)){
					print_contato(i);
					while(true)
						try{
							System.out.println("Este é o contato que procurava? S/n.");
							String c = le_string();
							if(c.equalsIgnoreCase("s"))
								return i;
							if(c.equalsIgnoreCase("n")){
								System.out.println("Continuando a busca...\n");
								break;
							}
						}catch(Exception e){
							System.out.print("Opção não válida. ");
						}
				}
			}
			if(contatos[i] instanceof PessoaJuridica){
				PessoaJuridica pj = (PessoaJuridica) contatos[i];
				if(pj.get_CNPJ().contains(cnpj) || pj.get_nome().contains(nome)){
					print_contato(i);
					while(true)
						try{
							System.out.println("Este é o contato que procurava? S/n.");
							String c = le_string();
							if(c.equalsIgnoreCase("s"))
								return i;
							if(c.equalsIgnoreCase("n")){
								System.out.println("Continuando a busca...\n");
								break;
							}
						}catch(Exception e){
							System.out.print("Opção não válida. ");
						}
				}
			}
		}
		System.out.println("Não foi possível encontrar este contato.\n");
		return -1;
	}


	/**
	 * A função remove um contato da Agenda.
	 * O retorno da função busca_contato é o indice do contato para realizar a remoção.
	 */
	void remover_contato(){
		System.out.println("----------REMOVER CONTATO----------\n");
		System.out.println("Vamos primeiro encontrar o contato a ser removido.");
		int i = busca_contato();
		if(i == -1){
			System.out.println("Nenhum contato foi removido.\n\n");
			return;
		}
		for(int j=i; j<nContatos; j++){
			contatos[j+1] = contatos[j];
			nContatos--;
		}
		System.out.println("----------CONTATO REMOVIDO----------\n\n");
	}

	/**
	 * Utiliza um bubble sort recursivo para ordenar a agenda pelo CPF/CNPJ dos contatos.
	 * @param n - número de elementos a serem ordenados. Nesse caso passamos o nContatos.
	 */
	public void bubbleSort(int n){
		Contato temp;
		if(n < 1) return;
		for(int i=0; i<n; i++){
			if(contatos[i] instanceof PessoaFisica){
				PessoaFisica pf1 = (PessoaFisica)contatos[i];
				if(contatos[i+1] instanceof PessoaFisica){
					PessoaFisica pf2 = (PessoaFisica)contatos[i+1];
					if(pf1.get_CPF().compareTo(pf2.get_CPF()) > 0){
						temp = contatos[i];
						contatos[i] = contatos[i+1];
						contatos[i+1] = temp;	
					}
				}
				if(contatos[i+1] instanceof PessoaJuridica){
					PessoaJuridica pj2 = (PessoaJuridica)contatos[i+1];
					if(pf1.get_CPF().compareTo(pj2.get_CNPJ()) > 0){
						temp = contatos[i];
						contatos[i] = contatos[i+1];
						contatos[i+1] = temp;	
					}
				}
			}
			else{
				PessoaJuridica pj1 = (PessoaJuridica)contatos[i];
				if(contatos[i+1] instanceof PessoaFisica){
					PessoaFisica pf2 = (PessoaFisica)contatos[i+1];
					if(pj1.get_CNPJ().compareTo(pf2.get_CPF()) > 0){
						temp = contatos[i];
						contatos[i] = contatos[i+1];
						contatos[i+1] = temp;	
					}
				}
				if(contatos[i+1] instanceof PessoaJuridica){
					PessoaJuridica pj2 = (PessoaJuridica)contatos[i+1];
					if(pj1.get_CNPJ().compareTo(pj2.get_CNPJ()) > 0){
						temp = contatos[i];
						contatos[i] = contatos[i+1];
						contatos[i+1] = temp;	
					}
				}
			}	
		}
		bubbleSort(n-1);
	}



	/**
	 * A função ordena a agenda pelo CPF e CNPJ e imprime as Pessoas Físicas antes das Pessoas Jurídicas.
	 * Utiliza a função bubble_sort para ordenar.
	 */
	void printar_ordenado(){
		bubbleSort(nContatos);
		System.out.println("----------IMPRIMIR AGENDA ORDENADA----------\n");
		System.out.println("-----PESSOA FÍSICA-----");
		for(int i=0; i<nContatos; i++)
			if(contatos[i] instanceof PessoaFisica)
				print_contato(i);
		System.out.println("-----PESSOA JURÍDICA-----");
		for(int i=0; i<nContatos; i++)
			if(contatos[i] instanceof PessoaJuridica)
				print_contato(i);
	}

	/**
	 * A função imprime a agenda.
	 */
	void print_agenda(){
		System.out.println("----------IMPRIMIR AGENDA----------\n");
		if(nContatos == 0){
			System.out.println("Agenda vazia. Não há contatos ainda.\n\n");
			return;
		}
		for(int i=0; i<nContatos; i++)
			print_contato(i);
		System.out.println("-----FIM DA AGENDA-----\n\n");
	}
}
