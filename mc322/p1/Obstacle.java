public class Obstacle {
	private int x,y;
	private String tipo;

	Obstacle(int _x,int _y,String _tipo) {
		x=_x;
		y=_y;
		tipo=_tipo;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	String getTipo() {
		return tipo;
	}
}