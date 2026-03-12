package homework1;

public class Inventory {

	String[] itemName = new String[5];
	double[] itemPrice = new double[5];
	int[] itemQuantity = new int[5];
	int item_count = 0;

	void addItem(String itemName, double itemPrice, int itemQuantity)
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

	void displayAllItems()
	{
		int i = 0;
		System.out.println("Inventory Items:");
		while(i < item_count)
		{
			System.out.println("Item " +  (1+i) + ": " + itemName[i] + ", " +  "Price: $" + itemPrice[i] + ", " + "Quantity: " + itemQuantity[i]);
			i++;
		}
	}
	int getTotalNumberOfItems()
	{
		return(item_count);
	}
	void calculateTotalWorth()
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