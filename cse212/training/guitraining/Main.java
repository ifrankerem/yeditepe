package training.guitraining;
import javax.swing.JFrame;

public class Main
{
	public static void main(String[] args)
	{
		GUI labelframe = new GUI();
		labelframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		labelframe.setSize(300, 300);
		labelframe.setVisible(true);
	}
}