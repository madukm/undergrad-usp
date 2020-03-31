Aula 3 - Exceptions

try{

	Dentro do try vao os comando q podem gerar excecao
}catch{

(dentro do catch vai o tratamento da excecao)

}

usar o throws IOException;

while(true){
	try{
		System.out.print("valor de x: ");
		x = EntradaTeclado.leDouble();
		break;	
	}catch(Exception e){
		System.out.println("Valor n é um double. Try again.");
	}
}
