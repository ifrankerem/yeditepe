import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import java.awt.BorderLayout;
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
	private JMenuItem text_exit, text_add_service, text_add_order;
	
	public gui()
	{
		super("Online Shop Inventory Management System");
		inv = new Inventory();
		setLayout(new BorderLayout());
		ButtonHandler handler = new ButtonHandler();
		ActionHandler handler2 = new ActionHandler();
		textArea = new JTextArea(15,40);

		//--------------------

		JMenuBar menuBar = new JMenuBar(); //creating a component for menu bar
		fileMenu = new JMenu("File"); // menu bar options
		invMenu = new JMenu("Inventory");
		customerMenu = new JMenu("Customer");
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
		d_orderButton = new JButton("Display Order Costs");
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


	// ı writed helper functions for showInputDialog because there is a case when user can click cancel so string will return null so we have to handle this for all 
	private String ask(String message) 
	{
	 	String input = JOptionPane.showInputDialog(gui.this, message);
		if(input == null)
			throw new IllegalArgumentException("Operation cancelled.");
		return input.trim();
	}

	private int askInt(String message)
	{
		String input = JOptionPane.showInputDialog(gui.this, message);

		if (input == null)
			throw new NumberFormatException("Operation cancelled.");

		return Integer.parseInt(input.trim());
	}

	private Double askDouble(String message)
	{
		String input = JOptionPane.showInputDialog(gui.this, message);

		if (input == null)
			throw new NumberFormatException("Operation cancelled.");

		return Double.parseDouble(input.trim());
	}

	private class ActionHandler implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			Object source = event.getSource(); // which button is pressed?

			if(source == text_exit)
				System.exit(0);
			else if(source == text_add_service)
			{
				try{
					int nbr = askInt("1. Item (Physical/Digital)\n2. Streaming\n3. Food Delivery");
					if(nbr == 1)
					{
						String name = ask("Item's Information:\nEnter item name: \n");
						double price = askDouble("Enter item price: $\n");
						int quantity = askInt("Enter item quantity: \n");
						String p_name = ask("Provider's Information:\nEnter provider name: \n");
						int c_code = askInt("Enter country code: \n");
						int a_code = askInt("Enter area code: \n");
						int phone_nbr = askInt("Enter phone number: \n");
						Provider provider = new Provider(p_name, c_code, a_code, phone_nbr);
						String type = ask("Physical or Digital Item?\n");
						if(type.equals("Physical"))
						{
							double width = askDouble("Enter width: \n");
							double length = askDouble("Enter length: \n");
							double height = askDouble("Enter height: \n");
							PhysicalItem item = new PhysicalItem(name, price, quantity, provider, width, length, height);
							inv.addService(item);
							JOptionPane.showMessageDialog(gui.this,"DONE!","Physical item added successfully.",JOptionPane.INFORMATION_MESSAGE);
						}
						else if(type.equals("Digital"))
						{
							double diskSpace = askDouble("Enter disk space: \n");
							DigitalItem item = new DigitalItem(name, price, quantity, provider, diskSpace);
							inv.addService(item);
							JOptionPane.showMessageDialog(gui.this,"DONE!","Digital item added successfully.",JOptionPane.INFORMATION_MESSAGE);
						}
						else
							JOptionPane.showMessageDialog(gui.this,"ERROR!","Wrong type!",JOptionPane.ERROR_MESSAGE);
					}
					else if(nbr == 2)
					{
						String title = ask("Streaming Information:\nEnter title:\n");
						String category = ask("Enter category:\n");
						double cost = askDouble("Enter cost per day:\n");
						int days = askInt("Enter days:\n");
						Streaming stream = new Streaming(title, category, cost, days, "Streaming");
						inv.addService(stream);
						JOptionPane.showMessageDialog(gui.this,"DONE!","Streaming added successfully.",JOptionPane.INFORMATION_MESSAGE);
					}
					else if(nbr == 3)
					{
						String foodName = ask("Food Delivery Information:\nEnter food name:\n");
						String resName = ask("Enter restaurant name:\n");
						double mealPrice = askDouble("Enter meal price: $\n");
						int count = askInt("Enter food count:\n");
						FoodDelivery food = new FoodDelivery(foodName, resName, mealPrice, "FoodDelivery", count);
						inv.addService(food);
						JOptionPane.showMessageDialog(gui.this,"DONE!","Food Delivery added successfully.",JOptionPane.INFORMATION_MESSAGE);
					}
				}
				catch(IllegalArgumentException e)
				{
					JOptionPane.showMessageDialog(gui.this,e.getMessage(),"Operation Cancelled!",JOptionPane.WARNING_MESSAGE);
				}
			}
			else if(source == text_add_order)
			{
				try
				{
					String name = ask("Enter the item name you want to order:\n");
					inv.ft_check(name, -1);
					int quantity = askInt("Enter the quantity:\n");
					inv.ft_check(name, quantity);
					String region = ask("Enter destination region:\n");
					String city = ask("Enter destination city:\n");
					String postCode = ask("Enter destination post code:\n");
					inv.ft_add(name, quantity, region, city, postCode);
					JOptionPane.showMessageDialog(gui.this,"DONE!","Order added successfully.",JOptionPane.INFORMATION_MESSAGE);
				}
				catch(IllegalArgumentException e)
				{
					JOptionPane.showMessageDialog(gui.this,e.getMessage(),"Operation Cancelled!",JOptionPane.WARNING_MESSAGE);
				}
				catch(NoSuchItemException e)
				{
					JOptionPane.showMessageDialog(gui.this,e.getMessage(),"Order Error!",JOptionPane.ERROR_MESSAGE);
				}
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
				if(inv.getOrders().size() == 0) {
					JOptionPane.showMessageDialog(gui.this,"There is no active order!","Error!",JOptionPane.ERROR_MESSAGE);
				} else {
					java.util.Collections.sort(inv.getOrders()); //in descending order
					String result = "";
					for(Service current : inv.getOrders())
					{
						result += current.toString();
						result += "\n";
					}
					textArea.setText(result);
				}
			}
			else if(source == d_feeButton)
			{
				try{
				int nbr_lmt = askInt("Enter limit:");
				String result = inv.get_text_fee_limit(nbr_lmt);
				textArea.setText(result);
			}
			catch(IllegalArgumentException e)
			{
				JOptionPane.showMessageDialog(gui.this,e.getMessage(),"Operation Cancelled!",JOptionPane.WARNING_MESSAGE);
			}
				
			}
		}
	}
}
