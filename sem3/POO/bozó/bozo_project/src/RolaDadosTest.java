import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class RolaDadosTest {
	RolaDados rd;
	@Before
	public void setUp() throws Exception {
		rd = new RolaDados(5);
	}

	@After
	public void tearDown() throws Exception {
		rd = null;
	}

	@Test
	public void testRolarTodos() {
		rd.rolar();
	}
	
	@Test
	public void testRolarBoolean() {
		boolean q[] = {true, false, true, false, true};
		rd.rolar(q);
	}

	@Test
	public void testRolarString() {
		String s = "1 3 4 5";
		rd.rolar(s);
	}
	
	@Test(expected=NumberFormatException.class)
	public void testRolarString2(){
		String s = "9";
		rd.rolar(s);
	}
	
	@Test
	public void testToString() {
		for(int i=0; i<10; i++) {
			rd.rolar();
			System.out.println(rd);
		}
	}
}
