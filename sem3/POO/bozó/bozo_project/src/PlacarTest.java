import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class PlacarTest {
	private Placar p1;
	
	@Before
	public void setUp() throws Exception {
		p1 = new Placar();
	}
	
	@After
	public void tearDown() throws Exception {
		p1 = null;
	}
	
	@Test
	public void getScoreVazio() {
		int k = p1.getScore();
		assertEquals(0, k);
	}
	
	@Test
	public void testToString1() {
		String r =  " (1)    |   (7)    |   (4)    \n" + 
					" --------------------------\n" + 
					" (2)    |   (8)    |   (5)    \n" + 
					" --------------------------\n" + 
					" (3)    |   (9)    |   (6)    \n" + 
					" --------------------------\n" + 
					"        |   (10)   |\n" + 
					"        +----------+ ";
		assertEquals(p1.toString(), r);
	}
	
	@Test
	public void getScoreCheio() {
		p1.add(1, new int[] {1, 2, 3, 4, 5} );
		p1.add(2, new int[] {1, 2, 3, 4, 5} );
		p1.add(3, new int[] {1, 2, 3, 4, 5} );
		p1.add(4, new int[] {1, 2, 3, 4, 5} );
		p1.add(5, new int[] {1, 2, 3, 4, 5} );
		p1.add(6, new int[] {1, 2, 3, 4, 5} );
		p1.add(7, new int[] {1, 1, 3, 4, 5} );
		p1.add(8, new int[] {1, 2, 3, 4, 5} );
		p1.add(9, new int[] {1, 2, 3, 4, 5} );
		p1.add(10, new int[] {1, 2, 3, 4, 5} );
		int k = p1.getScore();
		assertEquals(35, k);
	}
	
	@Test
	public void testToString2() {
		p1.add(1, new int[] {1, 2, 3, 4, 5} );
		p1.add(2, new int[] {1, 2, 3, 4, 5} );
		p1.add(3, new int[] {1, 2, 3, 4, 5} );
		p1.add(4, new int[] {1, 2, 3, 4, 5} );
		p1.add(5, new int[] {1, 2, 3, 4, 5} );
		p1.add(6, new int[] {1, 2, 3, 4, 6} );
		p1.add(7, new int[] {1, 1, 3, 3, 3} );
		p1.add(8, new int[] {1, 2, 3, 4, 5} );
		p1.add(9, new int[] {1, 1, 1, 1, 5} );
		p1.add(10, new int[] {1, 1, 1, 1, 1} );
		String s =  " 1      |    15    |   4    \n" + 
					" --------------------------\n" + 
					" 2      |    20    |   5    \n" + 
					" --------------------------\n" + 
					" 3      |    30    |   6    \n" + 
					" --------------------------\n" + 
					"        |    40    |\n" + 
					"        +----------+ ";
		assertEquals(p1.toString(), s);
	}
	
	@Test
	public void testToString3() {
		p1.add(1, new int[] {1, 2, 3, 4, 5} );
		p1.add(2, new int[] {1, 2, 3, 4, 5} );
		p1.add(3, new int[] {1, 2, 3, 4, 5} );
		p1.add(4, new int[] {1, 2, 3, 4, 5} );
		p1.add(5, new int[] {1, 2, 3, 4, 5} );
		p1.add(6, new int[] {1, 2, 3, 4, 6} );
		p1.add(7, new int[] {1, 1, 1, 1, 1} );
		p1.add(8, new int[] {1, 2, 2, 4, 5} );
		p1.add(9, new int[] {1, 1, 1, 1, 5} );
		p1.add(10, new int[] {1, 1, 1, 1, 1} );
		String s =  " 1      |    15    |   4    \n" + 
					" --------------------------\n" + 
					" 2      |    0    |   5    \n" + 
					" --------------------------\n" + 
					" 3      |    30    |   6    \n" + 
					" --------------------------\n" + 
					"        |    40    |\n" + 
					"        +----------+ ";
		assertEquals(p1.toString(), s);
	}
	
	@Test(expected=IllegalArgumentException.class)
	public void testAddPosInferior() {
		p1.add(0, new int[] {1, 2, 3, 4, 5});
		
	}
	
	@Test(expected=IllegalArgumentException.class)
	public void testAddPosSuperior() {
		p1.add(11, new int[] {1, 2, 3, 4, 5});
	}
	
	@Test(expected=IllegalArgumentException.class)
	public void testAddPosMarcada() {
		p1.add(1, new int[] {1, 2, 3, 4, 5});
		p1.add(1, new int[] {1, 1, 3, 4, 5});
	}
	
	
}
