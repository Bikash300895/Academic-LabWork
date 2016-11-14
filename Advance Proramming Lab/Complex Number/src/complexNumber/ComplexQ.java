package complexNumber;

public class ComplexQ {
	private ComplexNumber[] Q;
	private int upperPointer;
	private int lowerPointer;
	
	
	public ComplexQ(){
		Q = new ComplexNumber[100];
		upperPointer =0;
		lowerPointer =0;
	}
	
	public ComplexQ(int size){
		Q = new ComplexNumber[size];
		upperPointer =0;
		lowerPointer =0;
	}
	
	public void addItem(ComplexNumber Z){
		Q[upperPointer] = Z;
		upperPointer++;
	}
	
	public void remove(){
		Q[lowerPointer] = null;
		lowerPointer++;
		
	}
	
	public void showQueue(){
		for(int i=lowerPointer; i<upperPointer; i++){
			Q[i].printComplexNumber();
		}
	}
}
