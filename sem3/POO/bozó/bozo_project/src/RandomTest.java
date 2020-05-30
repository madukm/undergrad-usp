import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class RandomTest {
	Random random;
	
	@Before
	public void setUp() throws Exception {
		random = new Random();
	}

	@After
	public void tearDown() throws Exception {
		random = null;
	}
	
	@Test
	public void testRandomSemente() {
		Random r = new Random(12);
		r = null;
	}

	@Test
	public void testGetRand() {
		double k = random.getRand();
	}
	
	@Test
	public void testGetIntRand() {
		int k = random.getIntRand(2);
		
	}
	
	@Test
	public void testSetSemente() {
		random.set_semente(10);
	}
	
	@Test
	public void testToString() {
		random.toString();
	}
	
	@Test(expected=InterruptedException.class)
	public void testRandom() {
		Random r = new Random();
		r = null;
	}
	
}
