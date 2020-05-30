import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class DadoTest {
	private Dado dado;
	private Dado dado10;
	
	@Before
	public void setUp() throws Exception {
		dado = new Dado();
		dado10 = new Dado(10);
	}

	@After
	public void tearDown() throws Exception {
		dado = null;
		dado10 = null;
	}

	@Test
	public void testMain() {
		
	}
	
	@Test
	public void testGetLado() {
		dado.getLado();
	}
	
	@Test
	public void testRolar() {
		dado.rolar();
	}
	
	@Test
	public void testToString() {
		String r;
		for(int i=0; i<50; i++) {
			dado.rolar();
			switch(dado.getLado()) {
			case 1:
				r = "+-----+\n"+
					"|     |\n"+
					"|  *  |\n"+
					"|     |\n"+
					"+-----+\n";
				assertEquals(r, dado.toString());
				break;
			case 2:
				r = "+-----+\n"+
	        		"|*    |\n"+
	        		"|     |\n"+
	        		"|    *|\n"+
	        		"+-----+\n";
				assertEquals(r, dado.toString());
				break;
			case 3:
				r =	"+-----+\n"+
	       			"|*    |\n"+
	       			"|  *  |\n"+
	       			"|    *|\n"+
	       			"+-----+\n";
				assertEquals(r, dado.toString());
				break;
			case 4:
				r =	"+-----+\n"+
	        		"|*   *|\n"+
	        		"|     |\n"+
	        		"|*   *|\n"+
	        		"+-----+\n";
				assertEquals(r, dado.toString());
				break;
			case 5:
				r = "+-----+\n"+
					"|*   *|\n"+
					"|  *  |\n"+
					"|*   *|\n"+
					"+-----+\n";
				assertEquals(r, dado.toString());
				break;
			case 6:
				r = "+-----+\n"+
	                "|* * *|\n"+
	                "|     |\n"+
	                "|* * *|\n"+
	                "+-----+\n";
				assertEquals(r, dado.toString());
				break;
			default:
				assertEquals(null, dado.toString());
				break;
			}
		}
		Dado dado10 = new Dado(10);
		for(int i=0; i<100; i++) {
			dado10.rolar();
			switch(dado10.getLado()) {
			case 1:
				r = "+-----+\n"+
					"|     |\n"+
					"|  *  |\n"+
					"|     |\n"+
					"+-----+\n";
				assertEquals(r, dado10.toString());
				break;
			case 2:
				r = "+-----+\n"+
	        		"|*    |\n"+
	        		"|     |\n"+
	        		"|    *|\n"+
	        		"+-----+\n";
				assertEquals(r, dado10.toString());
				break;
			case 3:
				r =	"+-----+\n"+
	       			"|*    |\n"+
	       			"|  *  |\n"+
	       			"|    *|\n"+
	       			"+-----+\n";
				assertEquals(r, dado10.toString());
				break;
			case 4:
				r =	"+-----+\n"+
	        		"|*   *|\n"+
	        		"|     |\n"+
	        		"|*   *|\n"+
	        		"+-----+\n";
				assertEquals(r, dado10.toString());
				break;
			case 5:
				r = "+-----+\n"+
					"|*   *|\n"+
					"|  *  |\n"+
					"|*   *|\n"+
					"+-----+\n";
				assertEquals(r, dado10.toString());
				break;
			case 6:
				r = "+-----+\n"+
	                "|* * *|\n"+
	                "|     |\n"+
	                "|* * *|\n"+
	                "+-----+\n";
				assertEquals(r, dado10.toString());
				break;
			default:
				assertEquals(null, dado10.toString());
				break;
			}
		}
	}
}
