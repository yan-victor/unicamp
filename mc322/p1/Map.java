public class Map {
	private String[][] mapa = new String[200][200];
	private int dimx,dimy;

	Map(int _dimx,int _dimy) {
		for(int i=0;i<=_dimx;i++) {
			for(int j=0;j<=_dimy;j++) {
				mapa[i][j]="--";
			}
		}
		dimx=_dimx;
		dimy=_dimy;
	} 

	void add(int x,int y,String tipo) {
		mapa[x][y]=tipo;
	}

	void rem(int x,int y) {
		mapa[x][y]="--";
	}

	String[][] getMapa() {
		return mapa;
	}

	int getDimX() {
		return dimx;
	}

	int getDimY() {
		return dimy;
	}

	void printMapa() {
		for(int i=0;i<dimx;i++) {
			for(int j=0;j<dimy;j++) {
				System.out.print(mapa[i][j]+" ");
			}
			System.out.println();
		}
	}
}