package Four;


public class Rectangle extends Shape {
	private int width;
	private int height;
	public int s;
	public Rectangle(int w, int h) {
		this.width = w;
		this.height = h;
	}

	@Override
	public double getArea() {
		s=this.height*this.width;
		return s; // to be replaced
	}

}
