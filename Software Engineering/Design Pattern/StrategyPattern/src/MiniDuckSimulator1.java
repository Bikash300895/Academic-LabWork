

public class MiniDuckSimulator1 {
 
	public static void main(String[] args) {
 
		
		kuet_duck kuet=new kuet_duck();
   
		
		kuet.performFly();
		kuet.display();
		kuet.setFlyBehavior(new FlyWithSpaceship());
		kuet.Swimbehaviour();
		
	


	}
}
