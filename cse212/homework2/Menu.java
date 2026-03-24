package homework2;

import java.util.Scanner;

import homework1.Inventory;


public class Menu{ 

	public static void menu()
	{
		Option op = null; // ı decleared as null because of errors
		Inventory inv = new Inventory();
		Scanner input = new Scanner(System.in);
		while(op != Option.EXIT)
		{
			System.out.println("INVENTORY MENU:");
            System.out.println("1. Add a new item");
            System.out.println("2. Display all items");
            System.out.println("3. Display total number of items");
            System.out.println("4. Calculate total worth of inventory");
            System.out.println("5. Add an order");
            System.out.println("6. Calculate order cost");
            System.out.println("7. Exit");
            System.out.print("Enter your choice: ");

			int choice = input.nextInt();
			input.nextLine();
			op = Option.ft_int_to_enum(choice);

			switch (op) {
			case ADD_ITEM:
			{
				System.out.println("Enter item name: ");
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
				System.out.println("Enter the item name you want to order: ");
				String name = input.nextLine();
				System.out.println("Enter the quantity: ");
				int quantity = input.nextInt();
				if(Order.checkStorage(name,quantity,inv))
				{
					Order ord = new Order(inv,name,quantity);
					ord.displayOrderInfo();
				}
			}
				break;
			case ORD_COST:
				
				break;
			case EXIT:
				break;
			default:
				System.out.println("Invalıd Selection!");
				return;
			}
		}
	}

	public static void Main(String[] args)
	{
		menu();
	}
	
}