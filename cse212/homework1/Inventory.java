package homework1;

public class Inventory {

	private String[] itemName = new String[5]; //oop için best practice de private olmalı bunlar inventoryinin özel variabllearı bunları getter setterlar ile düzenlemeliyiz.
	private double[] itemPrice = new double[5];
	private int[] itemQuantity = new int[5];
	private int item_count = 0;

	public void addItem(String itemName, double itemPrice, int itemQuantity)
	{
		if(item_count == 5)
		{
			System.out.println("You can't enter any items more than five!");
			return;
		}
		this.itemName[item_count] = itemName;
		this.itemPrice[item_count] = itemPrice;
		this.itemQuantity[item_count] = itemQuantity;
		item_count++;
		System.out.println("Item added successfully.");
	}

	public void displayAllItems()
	{
		int i = 0;
		System.out.println("Inventory Items:");
		while(i < item_count)
		{
			System.out.println("Item " +  (1+i) + ": " + itemName[i] + ", " +  "Price: $" + itemPrice[i] + ", " + "Quantity: " + itemQuantity[i]);
			i++;
		}
	}
	public int getTotalNumberOfItems()
	{
		return(item_count);
	}
	public String [] getItemName()
	{
		return(itemName);
	}
	public int [] getQuantity()
	{
		return(itemQuantity);
	}
	public double [] getPrice()
	{
		return(itemPrice);
	}
	public void calculateTotalWorth()
	{
		int i = 0;
		double total = 0;
		while(i < item_count)
		{
			total += (itemPrice[i] * itemQuantity[i]);
			i++;
		}
		System.out.println("Total Worth of Inventory: $" + total );
	}

}