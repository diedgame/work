package third;

public class PointGrey extends Point {
	private int greyscale;
	private int px;
	private int py;
	private int x;// [0, 255] from black to white
	private int y;
	private int z;
	// TODO: add a constructor for PointGrey
	public PointGrey(int a,int b ,int c) {
	x=a;
	y=b;
	z=c;
		
		
		// TODO Auto-generated constructor stub
	}
	@Override
	public double getDistance(Point p) {
		int distance=(int) Math.sqrt((px-p.px)*(px-p.px)+(py-p.py)*(py-p.py));
		
		return distance; // to be replaced
	}

	@Override
	public int grayscaleDiff(Point p) {
		// TODO: fill this function up
		return 0; // to be replaced
	}

}
