import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.border.Border;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class gui extends JFrame{

	private Inventory inv;
	private JTextArea textArea;
	private JButton d_servicesButton;
	private JButton d_orderButton;
	private JButton d_feeButton;
	private JMenu fileMenu;
	private JMenu invMenu;
	private JMenu customerMenu; 
	
	public gui()
	{
		super("Online Shop Inventory Management System");
		setLayout(new BorderLayout());
		ButtonHandler handler = new ButtonHandler();
		ActionHandler handler2 = new ActionHandler();
		textArea = new JTextArea(15,40);

		//--------------------

		JMenuBar menuBar = new JMenuBar(); //creating a component for menu bar
		fileMenu = new JMenu("File"); // menu bar options
		invMenu = new JMenu("Inventory");
		customerMenu = new JMenu("Customer");
		JMenuItem text_exit, text_add_service, text_add_order;
		text_exit = new JMenuItem("Exit"); 
		text_add_service = new JMenuItem("Add Service"); 
		text_add_order = new JMenuItem("Add an Order"); 
		text_exit.addActionListener(handler2);
		text_add_service.addActionListener(handler2);
		text_add_order.addActionListener(handler2);
		fileMenu.add(text_exit);
		invMenu.add(text_add_service);
		customerMenu.add(text_add_order);
		menuBar.add(fileMenu);
		menuBar.add(invMenu);
		menuBar.add(customerMenu);
		this.setJMenuBar(menuBar);

		//----------------

		JPanel buttonPanel = new JPanel();
		d_servicesButton = new JButton("Display Services");
		buttonPanel.add(d_servicesButton);
		d_orderButton = new JButton("Display Order Cost");
		buttonPanel.add(d_orderButton);
		d_feeButton = new JButton("Display Ship Fee above a limit");
		buttonPanel.add(d_feeButton);

		d_servicesButton.addActionListener(handler);
		d_orderButton.addActionListener(handler);
		d_feeButton.addActionListener(handler);

		this.add(buttonPanel,BorderLayout.NORTH);

		//---------

		JPanel textJPanel = new JPanel(new BorderLayout()); //created a jpanel again and re setting its border and put jtextarea in it and 
		textJPanel.setBorder(BorderFactory.createEmptyBorder(15,15,15,15)); // i did this because ı wanted to make near as possible according to image in assigment.pdf
		textJPanel.add(textArea);
		this.add(textJPanel,BorderLayout.CENTER);

	}

	private class ActionHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			Object source = event.getSource(); // which button is pressed?

			if(source == fileMenu)
				System.exit(0);
			else if(source == invMenu)
			{
				//TODO
			}
			else if(source == customerMenu)
			{
				//TODO
			}

		}
	}





	private class ButtonHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			Object source = event.getSource(); // which button is pressed?

			if(source == d_servicesButton)
			{
				try{
				textArea.setText(inv.getAllServicesText());
				}
				catch(NoSuchItemException e)
				{
					JOptionPane.showMessageDialog(gui.this,e.getMessage(),"Error!",JOptionPane.ERROR_MESSAGE);
				}
			}
			else if(source == d_orderButton)
			{
				String result = "";
				for(Service current : inv.getServices())
				{
					result += current.toString();
					result += "\n";
				}
				textArea.setText(result);
			}
			else if(source == d_feeButton)
			{
				try{
					String limit = JOptionPane.showInputDialog(this,"Enter limit:");
					if(limit == null)
						return ;
					int nbr_lmt = Integer.parseInt(limit.trim());
					String result = inv.get_text_fee_limit(nbr_lmt);
					textArea.setText(result);
				}
				catch(NumberFormatException e)
				{
					JOptionPane.showMessageDialog(gui.this,e.getMessage(),"Input Error!",JOptionPane.ERROR_MESSAGE);
				}
				
			}
		}
	}

	
}