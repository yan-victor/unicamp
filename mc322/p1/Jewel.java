public class Jewel {
	private int x,y;
	private String tipo;

	public Jewel(int _x,int _y,String _tipo) {
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

	int valor() {
		if(tipo.charAt(1)=='B') return 10;
		if(tipo.charAt(1)=='G') return 50;
		return 100;
	}
}