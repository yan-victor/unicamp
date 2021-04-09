import java.util.*;

public class Robot {
	private int x,y;
	private ArrayList<Jewel> bag;

	Robot(int xx,int yy) {
		x=xx;
		y=yy;
		bag = new ArrayList<Jewel>();
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	void moveRight() {
		y=y+1;
	}

	void moveLeft() {
		y=y-1;
	}

	void moveUp() {
		x=x-1;
	}

	void moveDown() {
		x=x+1;
	}

	void collectJewel(Map m) {
		String[][] mapa = m.getMapa();
		int dimx = m.getDimX();
		int dimy = m.getDimY();
		if(x>0&&mapa[x-1][y].charAt(0)=='J') {
			Jewel joia = new Jewel(x-1,y,mapa[x-1][y]);
			bag.add(joia);
			m.rem(x-1,y);
		}
		if(y>0&&mapa[x][y-1].charAt(0)=='J') {
			Jewel joia = new Jewel(x,y-1,mapa[x][y-1]);
			bag.add(joia);
			m.rem(x,y-1);
		}
		if(mapa[x+1][y].charAt(0)=='J') {
			Jewel joia = new Jewel(x+1,y,mapa[x+1][y]);
			bag.add(joia);
			m.rem(x+1,y);
		}
		if(mapa[x][y+1].charAt(0)=='J') {
			Jewel joia = new Jewel(x,y+1,mapa[x][y+1]);
			bag.add(joia);
			m.rem(x,y+1);
		}
	}

	int pontos() {
		int total=0;
		for(int i=0;i<bag.size();i++) {
			total+=bag.get(i).valor();
		}
		return total;
	}

	void imprimirPontos() {
		System.out.print("Bag total items: "+bag.size()+" | ");
		System.out.println("Bag total value: "+this.pontos());
	}
	
}