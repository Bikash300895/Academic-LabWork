package classes;
import java.util.ArrayList;

import interfaces.*;

public class Stack implements Collection,Summary{
	public ArrayList<Double> data;
	
	public Stack(){
		data = new ArrayList<>();
	}

	@Override
	public double mean() {
		int n = data.size();
		double sum = 0;
		for (int i=0; i<n; i++){
			sum+=data.get(i);
		}
		return sum/n;
	}

	@Override
	public double median() {
		int n = data.size();
		data.sort(null);
		return data.get(n/2);
	}

	@Override
	public double range() {
		int n = data.size();
		data.sort(null);
		return data.get(n-1) - data.get(0);
	}

	@Override
	public int len() {
		return data.size();
	}

	@Override
	public void addItem(double a) {
		data.add(a);
		
	}

	@Override
	public void removeItem() {
		int n = data.size();
		data.remove(n-1);
		
	}

	@Override
	public double firstQuartile() {
		data.sort(null);
		int n = data.size();
		double min = data.get(0);
		return (data.get(n/2) - min)/2;
	}

	@Override
	public double secondQuartile() {
		data.sort(null);
		int n = data.size();
		double mx = data.get(n-1);
		return (mx - data.get(n/2))/2;
	}

	@Override
	public double min() {
		data.sort(null);
		return data.get(0);
	}

	@Override
	public double max() {
		int n = data.size();
		data.sort(null);
		return data.get(n-1);
	}

	@Override
	public void sort() {
		data.sort(null);
	}

	@Override
	public double search(int x) {
		return data.get(x);
	}

}
