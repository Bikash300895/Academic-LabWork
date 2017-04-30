package org.j2eedev.math;


import org.j2eedev.calc.Calculation;

import junit.framework.TestCase;

public class MathTest extends TestCase {

	private int value1=3;
	private int value2=5;

	public MathTest() {}


	public void testAdd() {
		int total = 8;
		int sum = Calculation.add(value1, value2);
		assertEquals(sum, total);
	}

	public void testFailedAdd() {
		int total = 9;
		int sum = Calculation.add(value1, value2);
		assertNotSame(sum, total);
	}
	public void testSub() {
		int total = 0;
		int sub = Calculation.sub(4, 4);
		assertEquals(sub, total);
	}

}
