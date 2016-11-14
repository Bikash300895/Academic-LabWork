package complexNumber;

public class TestClass {
	ComplexNumber c1,c2,c3;
	ComplexQueue q;
	ComplexQ CQ;
	
	public void testRun(){
		c1 = new ComplexNumber(12.0, 10.5);
		c2 = new ComplexNumber(15.5, 10.5);
		c3 = new ComplexNumber(12.0, 20.5);
		
		ComplexNumber R1 = c1.add(c2);
		//R1.printComplexNumber();
		
		/*
		q = new ComplexQueue();
		q.push(c1);
		q.push(c2);
		q.push(c3);
		q.push(R1);
		
		ComplexNumber n = q.peek();
		n.printComplexNumber();
		ComplexNumber m = q.top();
		m.printComplexNumber();
		
		*/
		
		CQ = new ComplexQ(5);
		CQ.addItem(c1);
		CQ.addItem(c2);
		CQ.addItem(c3);
		CQ.addItem(R1);
		
		CQ.showQueue();
	}
	
	public static void main(String [] args){
		TestClass t1 = new TestClass();
		t1.testRun();
	}

}
