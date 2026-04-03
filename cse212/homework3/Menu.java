package homework3;

import java.util.Scanner;


public class Menu{ 

	public static void menu()
	{
		Option op = null; // ı decleared as null because of errors
		Inventory inv = new Inventory();
		Scanner input = new Scanner(System.in);

		while(op != Option.EXIT)
		{
			System.out.println("INVENTORY MENU:");
            System.out.println("1. Add a New Item");
            System.out.println("2. Display all Items");
            System.out.println("3. Display the Total Number of Items");
            System.out.println("4. Calculate the Total Worth of the Inventory");
			System.out.println("CUSTOMER MENU:");
            System.out.println("5. Add an Order");
            System.out.println("6. Calculate Order Cost");
            System.out.println("7. Exit");
            System.out.print("Enter your choice: ");

			int choice = input.nextInt();
			input.nextLine();
			op = Option.ft_int_to_enum(choice);

			if(op == null)
			{
				System.out.println("Invalid Selection!");
				continue;
			}
			switch (op) {
				case ADD_ITEM:
				{
					System.out.println("");
					System.out.println("Item's Information: ");
					System.out.print("Enter item name: ");
					String name = input.nextLine();
					System.out.print("Enter item price: $");
					double price = input.nextDouble();
					System.out.print("Enter item quantity: ");
					int quantity = input.nextInt();
					input.nextLine();
					System.out.println("Provider's Information: ");
					System.out.print("Enter provider name: ");
					String p_name = input.nextLine();
					System.out.print("Enter country code: ");
					int c_code = input.nextInt();
					System.out.print("Enter area code: ");
					int a_code = input.nextInt();
					System.out.print("Enter phone number: ");
					int phone_nbr = input.nextInt();
					input.nextLine();
					
					Provider provider = new Provider(p_name, c_code, a_code, phone_nbr);
					System.out.print("Physical or Digital Item? ");
					String type = input.nextLine();
					if(type.equals("Physical"))
					{
						System.out.print("Enter width: ");
						int width = input.nextInt();
						System.out.print("Enter length: ");
						int length = input.nextInt();
						System.out.print("Enter height: ");
						int height = input.nextInt();
						input.nextLine();
						PhysicalItem item = new PhysicalItem(name, price, quantity, provider, width, length, height);
						inv.addItem(item);
						System.out.println("Physical item added successfully.");
					}
					else if(type.equals("Digital"))
					{
						System.out.print("Enter disk space: ");
						int diskSpace = input.nextInt();
						input.nextLine();
						DigitalItem item = new DigitalItem(name, price, quantity, provider, diskSpace);
						inv.addItem(item);
						System.out.println("Digital item added successfully.");
					}
					else
						System.out.println("Wrong type!");
					
					break;
				}
				case DISPLAY_ITEMS:
					inv.displayAllItems();
					break;
				case TOTAL_NUM:
					System.out.println("Total number of items: " + inv.getItems().size());
					break;
				case TOTAL_WRTH:
					inv.calculateTotalWorth();
					break;
				case ADD_ORD:
				{
					System.out.print("Enter the item name you want to order: ");
					String name = input.nextLine();
					System.out.print("Enter the quantity: ");
					int quantity = input.nextInt();
					input.nextLine();
					inv.check_and_add(name, quantity);
					break;
				}
				case ORD_COST:
				{
					if(inv.getOrders().size() == 0)
						System.out.println("There is no active order!");
					else
						inv.calculateOrderCost();
				
					break;
				}
				case EXIT:
					System.out.println("Exiting... Goodbye!");
					break;

			}
			System.out.println();
		}
		input.close();
	}

	public static void main(String[] args)
	{
		menu();
	}
	
}