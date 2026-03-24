package homework2;

import homework1.Inventory;

public class Order {

	private int orderID;
	private Inventory inventory;
	private String itemName;
	private int quantity;
	private static int ıd_counter = 1; // its static because all orders must share same id counter so orderID can ++


	Order (Inventory inv,  String itemName, int quantity)
	{
		this.orderID = ıd_counter;
		ıd_counter++;
		this.inventory = inv;
		this.itemName = itemName;
		this.quantity = quantity;
	}

	public void displayOrderInfo()
	{
		System.out.println("Order ID: " + this.orderID);
		System.out.println("Item name : " + this.itemName);
		System.out.println("Quantity: " + this.quantity);
	}

	//ı did it static because in the menu there will be only one inv
	public static boolean checkStorage(String name, int q, Inventory inv)
	{
		for(int i = 0; i < inv.getTotalNumberOfItems(); i++)
		{
			if((inv.getItemName()[i]).equals(name))
			{
				// i writed getter for this time ıtemn_name and quantity in the inventory ı didnt do it before because ı didnt need it on hw1.
				if(inv.getQuantity()[i] == q)
					return(true);
				else
				{
					System.out.println("Not have enough of this product in stock!");
					return(false);
				}
			}
		}
		System.out.println("There is no item called " + name);
		return(false);
	}
	public void calculateOrderCost(Inventory inv)
	{
		double cost = 0;
		for(int i = 0; i < inv.getTotalNumberOfItems(); i++)
		{
			if((inv.getItemName()[i]).equals(this.itemName))
				cost = this.quantity * inv.getPrice()[i];
		}
		System.out.println("Order cost for " + this.quantity + " " + this.itemName + " is: $ " + cost);
	}


}