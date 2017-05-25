

public class MiniDuckSimulator {
 
	public static void main(String[] args) {
 
		MallardDuck	mallard = new MallardDuck();
		RubberDuck	rubberDuckie = new RubberDuck();
		DecoyDuck	decoy = new DecoyDuck();
 
		Duck model = new ModelDuck();
		kuet_duck kuet=new kuet_duck();
		kuet.performFly();
		kuet.display();
		kuet.setFlyBehavior(fb);
		kuet.setQuackBehavior(qb);
	

		
		
	}
}
