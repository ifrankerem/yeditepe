import java.util.Scanner;


public class Menu{ 

	public static void menu()
	{
		Option op = null; // ı decleared as null because of errors
		Inventory inv = new Inventory();
		Scanner input = new Scanner(System.in);

		
		while(op != Option.EXIT)
		{
			try{
			System.out.println("INVENTORY MENU:");
            System.out.println("1. Add a New Service");
            System.out.println("2. Display all Services");
            System.out.println("3. Display the Total Number of Services");
            System.out.println("4. Calculate the Total Worth of the Inventory");
			System.out.println("5. Increase Price of Specific Type");
			System.out.println("6. List Services with Shipping Fee Above a Limit");
			System.out.println("7. Remove Order For a Specific City");
			System.out.println("CUSTOMER MENU:");
            System.out.println("8. Add an Order");
            System.out.println("9. Calculate Order Cost");
            System.out.println("10. Exit");
            System.out.print("Enter your choice: ");

			int choice = input.nextInt();
			input.nextLine();
			op = Option.ft_int_to_enum(choice);

			if(op == null)
				throw new InvalidSelection("You entered an invalid menu option. Enter again.");
			switch (op) {
				case ADD_SERVICE:
				{
					System.out.println("1. Item (Physical/Digital)");
					System.out.println("2. Streaming");
					System.out.println("3. Food Delivery");
					int serviceTypeChoice = input.nextInt();
					input.nextLine();
					if(serviceTypeChoice == 1) {
						System.out.println("Item's Information:");
						System.out.print("Enter item name: ");
						String name = input.nextLine();
						System.out.print("Enter item price: $");
						double price = input.nextDouble();
						System.out.print("Enter item quantity: ");
						int quantity = input.nextInt();
						input.nextLine();
						System.out.println("Provider's Information:");
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
							double width = input.nextDouble();
							System.out.print("Enter length: ");
							double length = input.nextDouble();
							System.out.print("Enter height: ");
							double height = input.nextDouble();
							input.nextLine();
							PhysicalItem item = new PhysicalItem(name, price, quantity, provider, width, length, height);
							inv.addService(item);
							System.out.println("Physical item added successfully.");
						}
						else if(type.equals("Digital"))
						{
							System.out.print("Enter disk space: ");
							double diskSpace = input.nextDouble();
							input.nextLine();
							DigitalItem item = new DigitalItem(name, price, quantity, provider, diskSpace);
							inv.addService(item);
							System.out.println("Digital item added successfully.");
						}
						else
							System.out.println("Wrong type!");
					} else if (serviceTypeChoice == 2) {
						System.out.println("Streaming Information:");
						System.out.print("Enter title: ");
						String title = input.nextLine();
						System.out.print("Enter category: ");
						String category = input.nextLine();
						System.out.print("Enter cost per day: ");
						double cost = input.nextDouble();
						System.out.print("Enter days: ");
						int days = input.nextInt();
						input.nextLine();
						Streaming stream = new Streaming(title, category, cost, days, "Streaming");
						inv.addService(stream);
						System.out.println("Streaming added successfully.");
					} else if (serviceTypeChoice == 3) {
						System.out.println("Food Delivery Information:");
						System.out.print("Enter food name: ");
						String foodName = input.nextLine();
						System.out.print("Enter restaurant name: ");
						String resName = input.nextLine();
						System.out.print("Enter meal price: $");
						double mealPrice = input.nextDouble();
						System.out.print("Enter food count: ");
						int count = input.nextInt();
						input.nextLine();
						FoodDelivery food = new FoodDelivery(foodName, resName, mealPrice, "FoodDelivery", count);
						inv.addService(food);
						System.out.println("Food Delivery added successfully.");
					}
					break;
				}
				case DISPLAY_SERVICES:
					inv.displayAllServices();
					break;
				case TOTAL_NUM:
					System.out.println("Total number of services: " + inv.getServices().size());
					break;
				case TOTAL_WRTH:
					inv.calculateTotalWorth();
					break;
				case INC_PRICE:
				{
					System.out.print("Which type of items will be raised in price?: ");
					String type = input.nextLine();
					System.out.print("How much will the raise ratio(%) be?: ");	
					double percentage = input.nextDouble();
					input.nextLine();
					inv.ft_increase(type, percentage);
					System.out.println("The raise ratio was applied to " + type + " items.");
					inv.displayAllServices();
					break;
				}
				case LIST_FEE_LIMIT:
				{
					System.out.print("Enter a limit: ");	
					int limit = input.nextInt();
					input.nextLine();
					inv.ft_fee_limit(limit);
					break;
				}
				case REMOVE_ORD:
				{
					System.out.print("Type a name to remove orders destined to a specific city: ");
					String city = input.nextLine();
					inv.removeOrderForCity(city);
					break;
				}
				case ADD_ORD:
				{
					boolean orderPlaced = false;
					while(!orderPlaced) //there is a while for asking again order name it doesnt go whole upper menu in the walkthrough
					{
						try
						{
							System.out.print("Enter the item name you want to order: ");
							String name = input.nextLine();
							inv.ft_check(name, -1);
							System.out.print("Enter the quantity: ");
							int quantity = input.nextInt();
							input.nextLine();
							inv.ft_check(name, quantity);
							System.out.print("Enter destination region: ");
							String region = input.nextLine();
							System.out.print("Enter destination city: ");
							String city = input.nextLine();
							System.out.print("Enter destination post code: ");
							String postCode = input.nextLine();
							inv.ft_add(name, quantity, region, city, postCode);
							orderPlaced = true;
						}
						catch(NoSuchItemException e)
						{
							System.err.println(e.getMessage());
						}
					}
					break;
				}
				case CMPR_ORD_COST:
				{
					if(inv.getOrders().size() == 0)
						System.out.println("There is no active order!");
					else
						inv.DescendingOrderCost();
					break;
				}
				case EXIT:
					System.out.println("Exiting... Goodbye!");
					break;
			}
			System.out.println();
		}
		catch(InvalidSelection | java.util.InputMismatchException e)
		{
			System.err.println("You entered an invalid menu option. Enter again.");
			if (e instanceof java.util.InputMismatchException) { //if user enters non integer buffer need to be cleaned
				input.nextLine();
			}
		}
	}
		input.close();
	}

	public static void main(String[] args)
	{
		menu();
	}
	
}
