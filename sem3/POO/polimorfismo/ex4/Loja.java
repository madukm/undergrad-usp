import java.util.*;
import java.io.IOException;

/**
 * A classe representa uma loja.
 * A main simula a administração da loja.
 * Faz as principais operações:
 * Adiciona, remove, busca, imprime.
 * @author Maria Eduarda Kawakami Moreira
 */
public class Loja{
	private Produto produtos[] = new Produto[100];
	private int nProdutos = 0;
	private int maxProdutos = 100;
	
	/**
	 * Menu principal do programa.
	 * Cuida da administração da agenda.
	 * Possui um laço, cada iteração faz uma operação escolhida pelo usuário.
	 * Sai do laço apenas quando o usuário escolhe a opção SAIR.
	 * @param args -
	 * @throws Exception
	 * @author Maria Eduarda Kawakami Moreira
	 */
	public static void main(String[] args) throws Exception{
		int op = 0;
		Loja loja = new Loja();
		System.out.println("----------LOJA----------\n");
		while(op != 5){
			System.out.println("1: Adicionar Produto\n2: Remover Produto\n3: Buscar Produto\n4: Imprimir Loja\n5: Sair\n");
			op = le_opcao(5);
			switch(op){
				case 1:
					loja.inserir_produto();
					break;
				case 2:
					loja.vender_produto();
					break;
				case 3:
					loja.buscar_produto();
					break;		
				case 4:
					loja.printar_loja();
					break;
				case 5:
					System.out.println("Encerrando....");
					return;
			}
		}	
	}

	/**
	 * Função que lê uma String.
	 * @throws IOException.
	 * @return String lida.
	 */
	public static String le_string(){
		String str;
		while(true)
			try{
				str = EntradaTeclado.leString();
				return str;
			}catch(IOException e){
				System.out.println("Formato inválido. Tente novamente: ");
			}
	}

	/**
	 * Função que lê um inteiro.
	 * @throws IOException.
	 * @return inteiro lido.
	 */
	public static int le_int(){
		int i;
		while(true)
			try{
				i = EntradaTeclado.leInt();
				return i;
			}catch(IOException e){
				System.out.println("Formato inválido. Tente novamente: ");
			}
	}

	/**
	 * Função que lê um double.
	 * @throws IOException
	 * @return double lido.
	 */
	public static double le_double(){
		double d;
		while(true)
			try{
				d = EntradaTeclado.leDouble();
				return d;
			}catch(IOException e){
				System.out.println("Formato inválido. Tente novamente: ");
			}
	}

	/**
	 * Função que já lê uma opção de 1 até o número de operações.
	 * Confere se o valor lido está no range definido.
	 * @param num_op - Número de operações disponíveis.
	 * @return a opção escolhida pelo usuário.
	 *
	 */
	public static int le_opcao(int nOpcoes){
		int i;
		while(true)
			try{
				System.out.println("Escolha uma das opções: ");
				i = EntradaTeclado.leInt();
				if(i>0 && i<=nOpcoes) return i;
			}catch(Exception e){
				System.out.println("Opção inválida, tente novamente.");
			}
	}
	
	/**
	 * Adiciona um produto na loja.
	 * Os dados sobre o produto são recebidos do usuário.
	 */
	public void inserir_produto(){
		if(nProdutos >= maxProdutos){
			System.out.println("O estoque de produtos está cheio. Não é possível inserir outros produtos.");
			return;
		}
		System.out.println("----------INSERIR PRODUTO----------");
		System.out.println("-----Produtos-----\n1: Livro\n2: CD\n3: DVD");
		int opcao = le_opcao(3);
		System.out.println("Informe o código de barras do produto: ");
		String codigoDeBarras = le_string();
		System.out.println("Informe o nome/título do produto: ");
		String nome = le_string();
		System.out.println("Informe o preço do produto, apenas o número sem R$ ou $: ");
		double preco = le_double();
		System.out.println("Informe a quantidade de produtos: ");
		int quantidade = le_int();
		switch(opcao){
			case 1:
				System.out.println("Informe o autor do livro: ");
				String autor = le_string();
				System.out.println("Informe o ano de publicação do livro: ");
				int anoDePublicacao = le_int();
				System.out.println("Informe a editora do livro: ");
				String editora = le_string();
				Livro livro = new Livro(codigoDeBarras, nome, preco, quantidade, autor, anoDePublicacao, editora);
				produtos[nProdutos++] = livro;
				break;
			case 2:
				System.out.println("Informe o artista do CD: ");
				String artista = le_string();
				System.out.println("Informe a capacidade de disco do CD: ");
				double capacidade = le_double();
				CD cd = new CD(codigoDeBarras, nome, preco, quantidade, artista, capacidade);
				produtos[nProdutos++] = cd;
				break;	
		}
	}

	/**
	 * Imprime um produto i da Loja.
	 * @param i - indíce do produto a ser imprimido.
	 */
	void printar_produto(int i){
		if(produtos[i] instanceof Livro){
			Livro livro = (Livro)produtos[i];
			System.out.println("Livro");
			System.out.println("Código de barras: " + livro.get_codigoDeBarras());
			System.out.println("Nome/Título: " + livro.get_nome());
			System.out.println("Preco: " + livro.get_preco());
			System.out.println("Quantidade: " + livro.get_quantidade());
			System.out.println("Autor: " + livro.get_autor());
			System.out.println("Ano de Publicação: " + livro.get_anoDePublicacao());
			System.out.println("Editora: " + livro.get_editora() + "\n");	
		}
		else if(produtos[i] instanceof CD){
			CD cd = (CD) produtos[i];
			System.out.println("CD");
			System.out.println("Código de barras: " + cd.get_codigoDeBarras());
			System.out.println("Nome/Título: " + cd.get_nome());
			System.out.println("Preco: " + cd.get_preco());
			System.out.println("Quantidade: " + cd.get_quantidade());
			System.out.println("Artista: " + cd.get_artista());
			System.out.println("Capacidade: " + cd.get_capacidade());
		}
		else if(produtos[i] instanceof DVD){
			DVD dvd = (DVD) produtos[i];
			System.out.println("DVD");
			System.out.println("Código de barras: " + dvd.get_codigoDeBarras());
			System.out.println("Nome/Título: " + dvd.get_nome());
			System.out.println("Preco: " + dvd.get_preco());
			System.out.println("Quantidade: " + dvd.get_quantidade());
			System.out.println("Artista: " + dvd.get_artista());
			System.out.println("Capacidade: " + dvd.get_capacidade());
		}
	}

	/**
	 * Busca um produto por nome ou código de barras.
	 * Imprime as informações do produto ao achar um que preencha os requisitos.
	 * Pede confirmação para o usuário se aquele era o produto esperado.
	 */
	void buscar_produto(){
		System.out.println("Opções de busca:");
		System.out.println("1: Nome\n2: Código de Barras");
		int opcao = le_opcao(2);
		String nome = "-";
		String cdb = "-";
		if(opcao == 1){
			System.out.println("Informe o nome ou uma parte dele para realizar a busca: ");
			nome = le_string();
		}
		else{
			System.out.println("Informe o CDB ou uma parte dele para realizar a busca: ");
			cdb = le_string();
		}
		for(int i=0; i<nProdutos; i++){
			if(produtos[i].get_nome().contains(nome) || produtos[i].get_codigoDeBarras().contains(cdb)){
				printar_produto(i);
					while(true)
						try{
							System.out.println("Este é o produto que procurava? S/n.");
							String c = le_string();
							if(c.equalsIgnoreCase("s")){
								System.out.println("----------BUSCA REALIZADA----------");
								return;
							}
							if(c.equalsIgnoreCase("n")){
								System.out.println("Continuando a busca...\n");
								break;
							}
						}catch(Exception e){
							System.out.print("Opção não válida. ");
						}
			}
		}
		System.out.println("Não foi possível encontrar este produto.\n");
	}

	/**
	 * A função remove um produto da loja.
	 * Se a quantidade desse produto na loja for maior que 1, então apenas diminuímos em 1 essa quantidade.
	 * Se a quantidade for igual a 1, retiramos o produto da lista de produtos.
	 */
	void vender_produto(){
		System.out.println("----------REMOVER CONTATO----------\n");
		System.out.println("Informe o CDB ou uma parte dele do produto que deseja vender: ");
		String cdb = le_string();
		int indice = -1;
		for(int i=0; i<nProdutos; i++){
			if(produtos[i].get_codigoDeBarras().contains(cdb)){
				printar_produto(i);
				while(true)
					try{
						System.out.println("Este é o produto que procurava? S/n.");
						String c = le_string();
						if(c.equalsIgnoreCase("s")){
							indice = i;
							break;
						}
						if(c.equalsIgnoreCase("n")){
							System.out.println("Continuando a busca...\n");
							break;
						}
					}catch(Exception e){
						System.out.print("Opção não válida. ");
					}
				if(indice != -1) break;
			}
		}
		System.out.println("Nenhum produto foi vendido.\n\n");
		int quant = produtos[indice].get_quantidade();
		if(quant > 1)
			produtos[indice].set_quantidade(quant-1);
		else{
			for(int j=indice; j<nProdutos; j++){
				produtos[j+1] = produtos[j];
				nProdutos--;
			}
		}
		System.out.println("----------PRODUTO VENDIDO----------\n\n");
	}

	/**
	 * A função imprime a agenda.
	 */
	void printar_loja(){
		System.out.println("----------PRINTAR LOJA----------\n");
		if(nProdutos == 0){
			System.out.println("Loja vazia. Não há produtos ainda.\n\n");
			return;
		}
		System.out.println("-----LIVRO-----");
		for(int i=0; i<nProdutos; i++)
			if(produtos[i] instanceof Livro)
				printar_produto(i);
			System.out.println("-----CD-----");
		for(int i=0; i<nProdutos; i++)
			if(produtos[i] instanceof CD)
				printar_produto(i);
		System.out.println("-----DVD-----");
		for(int i=0; i<nProdutos; i++)
			if(produtos[i] instanceof DVD)
				printar_produto(i);
		System.out.println("-----FIM DO ESTOQUE-----\n\n");
	}

}
