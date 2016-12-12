package classes;

import java.awt.Graphics;

import javax.swing.JComponent;
import javax.swing.JFrame;

class myCanvas extends JComponent{

	private static final long serialVersionUID = 1L;
	public double n1,n2,n3,n4;
	public myCanvas(double n1,double n2,double n3,double n4) {
		this.n1=n1*4;
		this.n2=n2*4;
		this.n3=n3*4;
		this.n4=n4*4;
		System.out.println(n1+" "+n2+" "+n3+" "+n4+" ");
	}

	@Override
	public void paint(Graphics g) {
		g.drawRect((int) (100*n1), 50, (int) (100*n2), 50);
		g.drawRect((int) (100*n2), 50, (int) (100*n2)+(int) (100*n3), 50);
		
		g.drawString("median", (int) (100*n1)-20, 120);
		g.drawString("1st Quartile", (int) ((100*n1)+100*n2)-30, 120);
		g.drawString("3rd Quartile", (int) (100*n1)+(int) (100*n2)+(int) (100*n3)-30, 120);
		
		g.drawRoundRect(5, 70, 10, 10, 100, 100);
		g.drawRoundRect((int) ((int) (100*n1)+(int) (100*n2)+(int) (100*n3)+100*n4), 70, 10, 10, 100, 100);
		
		g.drawString("min", 5, 120);
		g.drawString("max", (int) ((int) (100*n1)+(int) (100*n2)+(int) (100*n3)+100*n4)-10, 120);
		g.drawLine(15, 75, (int) (100*n1), 75);
		g.drawLine((int) (100*n1)+(int) (100*n2)+(int) (100*n3), 75, (int) ((int) (100*n1)+(int) (100*n2)+(int) (100*n3)+100*n4), 75);
	}
	
	
}

public class Visualize {
	public static void main(String[] args){
		Queue q = new Queue();
		q.addItem(10);
		q.addItem(20);
		q.addItem(30);
		q.addItem(40);
		q.addItem(80);
		
		double min = q.min();
		System.out.println(min);
		double max = q.max();
		System.out.println(max);
		double mid = q.median();
		System.out.println(mid);
		double q1 = q.firstQuartile();
		System.out.println(q1);
		double q3 = q.secondQuartile();
		System.out.println(q3);
		double range = q.range();
		
		double n1 = (q1-min)/range;
		double n2 = (mid-q1)/range;
		double n3 = (q3-mid)/range;
		double n4 = (max-q3)/range;
		
		
		JFrame window = new JFrame();
		window.setBounds(30, 30, 500, 300);
		window.getContentPane().add(new myCanvas(n1,n2,n3,n4));
		window.setVisible(true);
	}
	
}
