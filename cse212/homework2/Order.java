package homework2;

import homework1.Inventory;

public class Order {

	private int orderID;
	private Inventory inventory;
	private String itemName;
	private int quantity;
	private static int id_counter = 0; // its static because all orders must share same id counter so orderID can ++ even fail attempts


	public static int getNextOrderId()
	{
		id_counter++;
		return (id_counter);
	}

	public Order (Inventory inv,  String itemName, int quantity, int id)
	{
		this.orderID = id;
		this.inventory = inv;
		this.itemName = itemName;
		this.quantity = quantity;
	}

	public void displayOrderInfo()
	{
		System.out.println("Order ID: " + this.orderID);
		System.out.println("Item Name: " + this.itemName);
		System.out.println("Quantity: " + this.quantity);
	}

	//ı did it static because before creating order ı wanted to check storage
	public static boolean checkStorage(String name, int q, Inventory inv)
	{
		for(int i = 0; i < inv.getTotalNumberOfItems(); i++)
		{
			if((inv.getItemName()[i]).equals(name))
			{
				// i writed getter for this time ıtemn_name and quantity in the inventory ı didnt do it before because ı didnt need it on hw1.
				if(inv.getQuantity()[i] >= q)
					return(true);
				else
				{
					System.out.println("Item not found in inventory. Order cannot be placed.");
					return(false);
				}
			}
		}
		System.out.println("There is no item called " + name);
		return(false);
	}
	public void calculateOrderCost()
	{
		double cost = 0;
		for(int i = 0; i < this.inventory.getTotalNumberOfItems(); i++)
		{
			if((this.inventory.getItemName()[i]).equals(this.itemName))
				cost = this.quantity * inventory.getPrice()[i];
		}
		System.out.println("Order cost for " + this.quantity + " " + this.itemName + " is: $" + cost);
	}


}