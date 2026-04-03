package homework3;

import java.util.ArrayList;

public class Inventory {

	private ArrayList<Item> items;
	private ArrayList<Order> orders;

	public Inventory()
	{
		this.items = new ArrayList<Item>();
		this.orders = new ArrayList<Order>();
	}

	public void addItem(Item item)
	{
		this.items.add(item);
	}

	public void displayAllItems()
	{
		for(int i = 0; i < items.size(); i++)
			items.get(i).displayItem();
	}

	public ArrayList<Item> getItems() {
		return items;
	}

	public ArrayList<Order> getOrders() {
		return orders;
	}

	public void calculateTotalWorth()
	{
		for(Item currentItem : items)
			System.out.println("Total Worth of Item " + currentItem.getItemName() + ": $" + currentItem.calculateTotalWorth());
	}

	public boolean check_and_add(String name, int q)
	{
		for(Item currentItem : items)
		{
			if(currentItem.getItemName().equals(name))
			{
				if(currentItem.getItemQuantity() >= q)
				{
					addOrder(currentItem, q);
					currentItem.updateQuantity(q);
					System.out.println("Order has been placed successfully.");
					return(true);
				}
				else
				{
					System.out.println("Insufficient quantity. Order cannot be placed.");
					return(false);
				}
			}
		}
		System.out.println("There is no item called " + name);
		return(false);
	}

	public void addOrder(Item item, int q)
	{	
		Order order = new Order(item, item.getType());
		order.setQuantity(q);
		orders.add(order);
	}
	
	public void calculateOrderCost()
	{
		for(Order currenOrder : orders)
		{
			System.out.println("The total cost of " + currenOrder.getItem().getItemName() + " order is: " + currenOrder.calculateOrderCost());
		}
	}

}