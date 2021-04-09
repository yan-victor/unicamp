import java.util.*;
public class JewelCollector {
	public static void main (String[] args) {
		Scanner keyboard = new Scanner (System.in) ;
		boolean running = true;
		Map mapa = new Map(10,10);
		Robot robot = new Robot(0,0);
		ArrayList<Jewel> jewels = new ArrayList<Jewel>();
		ArrayList<Obstacle> obstacles = new ArrayList<Obstacle>();
		mapa.add(0,0,"ME");
		jewels.add(new Jewel(1,9,"JR"));
		jewels.add(new Jewel(8,8,"JR"));
		jewels.add(new Jewel(9,1,"JG"));
		jewels.add(new Jewel(7,6,"JG"));
		jewels.add(new Jewel(3,4,"JB"));
		jewels.add(new Jewel(2,1,"JB"));
		obstacles.add(new Obstacle(5,0,"##"));
		obstacles.add(new Obstacle(5,1,"##"));
		obstacles.add(new Obstacle(5,2,"##"));
		obstacles.add(new Obstacle(5,3,"##"));
		obstacles.add(new Obstacle(5,4,"##"));
		obstacles.add(new Obstacle(5,5,"##"));
		obstacles.add(new Obstacle(5,6,"##"));
		obstacles.add(new Obstacle(5,9,"$$"));
		obstacles.add(new Obstacle(3,9,"$$"));
		obstacles.add(new Obstacle(8,3,"$$"));
		obstacles.add(new Obstacle(2,5,"$$"));
		obstacles.add(new Obstacle(1,4,"$$"));
		for(int i=0;i<6;i++) {
			Jewel novajoia = jewels.get(i);
			mapa.add(novajoia.getX(),novajoia.getY(),novajoia.getTipo());
		}
		for(int i=0;i<12;i++) {
			Obstacle novoobstaculo = obstacles.get(i);
			mapa.add(novoobstaculo.getX(),novoobstaculo.getY(),novoobstaculo.getTipo());
		}
		mapa.printMapa();
		while ( running ) {
			System.out.print("Enter the command: ") ;
			String command = keyboard.nextLine() ;
			if (command.compareTo("quit") == 0) {
				running = false ;
			} else if (command.compareTo ("w") == 0) {
				if(robot.getX()>0) {
					if(mapa.getMapa()[robot.getX()-1][robot.getY()].charAt(0)=='-') { 
						robot.moveUp();
						mapa.add(robot.getX(),robot.getY(),"ME");
						mapa.rem(robot.getX()+1,robot.getY());
					}
				}
				mapa.printMapa();
				robot.imprimirPontos();
			} else if (command.compareTo ("a") == 0) {
				if(robot.getY()>0) {
					if(mapa.getMapa()[robot.getX()][robot.getY()-1].charAt(0)=='-') { 
						robot.moveLeft();
						mapa.add(robot.getX(),robot.getY(),"ME");
						mapa.rem(robot.getX(),robot.getY()+1);
					}
				}
				mapa.printMapa();
				robot.imprimirPontos();
			} else if (command.compareTo ("s") == 0) {
				if(robot.getX()+1<mapa.getDimX()) {
					if(mapa.getMapa()[robot.getX()+1][robot.getY()].charAt(0)=='-') { 
						robot.moveDown();
						mapa.add(robot.getX(),robot.getY(),"ME");
						mapa.rem(robot.getX()-1,robot.getY());
					}
				}
				mapa.printMapa();
				robot.imprimirPontos();
			} else if (command.compareTo ("d") == 0) {
				if(robot.getY()+1<mapa.getDimY()) {
					if(mapa.getMapa()[robot.getX()][robot.getY()+1].charAt(0)=='-') {
						robot.moveRight();
						mapa.add(robot.getX(),robot.getY(),"ME");
						mapa.rem(robot.getX(),robot.getY()-1);
					}
				}
				mapa.printMapa();
				robot.imprimirPontos();
			} else if (command.compareTo ("g") == 0) {
				robot.collectJewel(mapa);
				mapa.printMapa();
				robot.imprimirPontos();
			}

		}
	}
}
