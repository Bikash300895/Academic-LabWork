package complexNumber;

import java.util.ArrayList;

public class ComplexQueue {
	private ArrayList<ComplexNumber> queue;
	
	public ComplexQueue(){
		queue = new ArrayList<>();
	}
	
	public void push(ComplexNumber c){
		queue.add(c);
	}
	
	public ComplexNumber top(){
		ComplexNumber c = queue.get(0);
		return c;
	}
	
	public ComplexNumber peek(){
		ComplexNumber c = queue.get(0);
		queue.remove(0);
		return c;
	}
	
}
