

public class kuet_duck extends Duck {

	public kuet_duck() {

		quackBehavior = new Quack();
		flyBehavior = new FlyWithWings();
		flyBehavior = new FlyWithSpaceship();
		
	//flyBehavior = new FlyWithflyBallor();

	}

	public void display() {
		System.out.println("I'm a kuetian duck");
	}

	public void flyBehavior() {
		System.out.println("I'm a kuetian duck");
		
	}
	public void Swimbehaviour() {
		System.out.println("I'm a swimming");
		
	}
}
