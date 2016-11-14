package complexNumber;

public class ComplexNumber {

	private double real;
	private double imaginary;
	private double magnitude;
	private double theta;
	



	/**
	 * Parameterized and non parameterized constructor
	 */
	public ComplexNumber() {
		this.real = 0;
		this.imaginary = 0;
	}
	
	
	public ComplexNumber(double real, double imaginary) {
		this.real = real;
		this.imaginary = imaginary;
		this.magnitude = magnitude();
		this.theta = argument();
	}


	/**
	 * Getter and setter functions
	 */
	public double getReal() {
		return real;
	}


	public void setReal(double real) {
		this.real = real;
		this.magnitude = magnitude();
		this.theta = argument();
	}

	public double getImaginary() {
		return imaginary;
	}
	
	
	public void setImaginary(double imaginary) {
		this.imaginary = imaginary;
		this.magnitude = magnitude();
		this.theta = argument();
	}
	
	public double getMagnitude() {
		return magnitude;
	}


	public double getTheta() {
		return theta;
	}

	

	/**
	 * Class functions
	 */

	public double magnitude(){
		return Math.sqrt(real*real + imaginary*imaginary);
	}
	
	public double argument(){
		return Math.atan(imaginary/real);
	}
	
	public void printComplexNumber(){
		System.out.println(real+"+"+imaginary+"i");
		System.out.println("Magnitude "+magnitude);
		System.out.println("Argument "+theta);
	}
	
	public ComplexNumber add(ComplexNumber Z){
		return new ComplexNumber(real+Z.real, imaginary+Z.imaginary);
	}

	public ComplexNumber sub(ComplexNumber Z){
		return new ComplexNumber(real-Z.real, imaginary-Z.imaginary);
	}

	/**
	 * Main function for test
	 */

	public static void main(String[] args) {
		ComplexNumber c1 = new ComplexNumber(12.0, 10.5);
		ComplexNumber c2 = new ComplexNumber(15.5, 10.5);
		ComplexNumber c3 = new ComplexNumber(12.0, 20.5);
		
		c1.printComplexNumber();
		System.out.println(c1.magnitude()+ " " + c1.argument());
		
		ComplexNumber R1 = c1.add(c2);
		ComplexNumber R2 = c1.sub(c3);
		R1.printComplexNumber();
		R2.printComplexNumber();
		c1.printComplexNumber();
		c2.printComplexNumber();
	}

}
