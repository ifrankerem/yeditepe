package homework4;

import java.util.ArrayList;
import java.util.ListIterator;

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
		order.setOrderPrice(item.getItemPrice());
		orders.add(order);
	}
	
	public void calculateOrderCost()
	{
		for(Order currenOrder : orders)
		{
			System.out.println("The total cost of " + currenOrder.getItem().getItemName() + " order is: " + currenOrder.calculateOrderCost());
		}
	}

	public void ft_increase(String type, double percentage)
	{
		ListIterator<Item> it = items.listIterator();

		while(it.hasNext())
		{
			Item currentItem = it.next();
			if(currentItem.getType().equals(type))
				currentItem.setItemPrice(currentItem.getItemPrice() + (currentItem.getItemPrice() * (percentage/100)));
		}
	}

	public void ft_fee_limit(int limit)
	{
		ListIterator<Item> it = items.listIterator();
		ArrayList<Item> temp_list = new ArrayList<Item>();

		while(it.hasNext())
		{
			Item currenItem = it.next();
			if(currenItem.calculateShippingFee() > limit)
				temp_list.add(currenItem);
		}
		if(temp_list.size() != 0)
		{
			System.out.println("Items with shipping fees over " + limit + ":");
			for(Item loop : temp_list)
				System.out.printf("Item: %s, Shipping Fee: %.2f%n", loop.getItemName(), loop.calculateShippingFee()); // ı use printf becaause of the rounding on the output	
			return ;			
		}
		System.out.println("There is no item with a shipping fee over this limit.");
		return ;
	}

}