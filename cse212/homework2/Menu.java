package homework2;

import java.util.Scanner;

import homework1.Inventory;


public class Menu{ 

	public static void menu()
	{
		Option op = null; // ı decleared as null because of errors
		Inventory inv = new Inventory();
		Scanner input = new Scanner(System.in);
		Order currentOrd = null; 

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
				System.out.println("Invalıd Selection!");
				continue;
			}
			switch (op) {
				case ADD_ITEM:
				{
					System.out.print("Enter item name: ");
					String name = input.nextLine();
					System.out.print("Enter item price: $");
					double price = input.nextDouble();
					System.out.print("Enter item quantity: ");
					int quantity = input.nextInt();
					input.nextLine();

					inv.addItem(name, price, quantity);
					break;
				}
				case DISPLAY_ITEMS:
					inv.displayAllItems();
					break;
				case TOTAL_NUM:
					System.out.println("Total number of items: " + inv.getTotalNumberOfItems());
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
					int newId = Order.getNextOrderId();
					// in every order attempt ++ the order id.
					if(Order.checkStorage(name,quantity,inv))
					{
						currentOrd = new Order(inv,name,quantity,newId);
						currentOrd.displayOrderInfo();
					}
					break;
				}
				case ORD_COST:
				{
					if(currentOrd == null)
						System.out.println("There is no active order!");
					else
						currentOrd.calculateOrderCost();
				
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