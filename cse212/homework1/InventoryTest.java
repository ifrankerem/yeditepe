package homework1;

import java.util.Scanner;
// import homework1.Inventory; bu 2 dosyada aynı package altında o nedenle bunu yorum satırına alıyorum.

public class InventoryTest {

	public static void menu()
	{
		Inventory inv = new Inventory();
		Scanner input = new Scanner(System.in);
		int choice = -1;
		while (choice != 0)
		{
			System.out.println("1. Add a new item");
			System.out.println("2. Display all items");
			System.out.println("3. Display total number of items");
			System.out.println("4. Calculate total worth");
			System.out.println("0. Exit");
			System.out.print("Enter your choice: ");	
			choice = input.nextInt();
			input.nextLine(); // newline kalıyor buffer temizlemek için
			if(choice == 1)
			{
				System.out.print("Enter item name: ");
				String itemName = input.nextLine();
				System.out.print("Enter item price: $");
				Double itemPrice = input.nextDouble();
				System.out.print("Enter item quantity: ");
				int itemQuantity = input.nextInt();
				input.nextLine(); // newline kalıyor buffer temizlemek için
				inv.addItem(itemName, itemPrice, itemQuantity);
			}
			else if(choice == 2)
				inv.displayAllItems();
			else if(choice == 3)
				System.out.println("Total number of items: " + inv.getTotalNumberOfItems());
			else if(choice == 4)
				inv.calculateTotalWorth();	
			else if(choice == 0)
				System.out.println("Exiting... Goodbye!");
			else 
				System.out.println("Please enter a number between 0-4!");
			System.out.println();
			
		}
		input.close(); // system in' i kapatmamız lazım aynı c deki fdleri kapattıgımız gibi.
	}

	public static void main(String[] args)
	{
		menu();
	}
}