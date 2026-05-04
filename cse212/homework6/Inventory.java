import java.util.ArrayList;
import java.util.ListIterator;
import java.util.Collections;

public class Inventory{

	private ArrayList<Service> services;
	private ArrayList<Service> orders;

	public Inventory()
	{
		this.services = new ArrayList<Service>();
		this.orders = new ArrayList<Service>();
	}

	public void addService(Service service)
	{
		this.services.add(service);
	}

	public void displayAllServices()
	{
		for(int i = 0; i < services.size(); i++)
			services.get(i).displayServiceInfo();
	}

	public ArrayList<Service> getServices() {
		return services;
	}

	public ArrayList<Service> getOrders() {
		return orders;
	}

	public void calculateTotalWorth()
	{
		double physical = 0, digital = 0, food = 0, streaming = 0;
		for(Service s : services) {
			if(s instanceof PhysicalItem) 
				physical += ((PhysicalItem)s).calculateTotalWorth();
			else if(s instanceof DigitalItem) 
				digital += ((DigitalItem)s).calculateTotalWorth();
			else if(s instanceof FoodDelivery) 
				food += ((FoodDelivery)s).getMealPrice() * ((FoodDelivery)s).getCount();
			else if(s instanceof Streaming) 
				streaming += ((Streaming)s).getCostPerDay() * ((Streaming)s).getDays();
		}
		System.out.println("Total Worth of Service Physical: $" + physical);
		System.out.println("Total Worth of Service Digital: $" + digital);
		System.out.println("Total Worth of Service FoodDelivery: $" + food);
		System.out.println("Total Worth of Service Streaming: $" + streaming);
	}

	public boolean check_and_add(String name, int q, String region, String city, String postCode)
	{
		for(Service currentService : services)
		{
			String serviceName = "";
			if(currentService instanceof Item)
				serviceName = ((Item)currentService).getItemName();
			else if(currentService instanceof FoodDelivery)
				serviceName = ((FoodDelivery)currentService).getFoodName();
			else if(currentService instanceof Streaming)
				serviceName = ((Streaming)currentService).getTitle();

			if(serviceName.equals(name))
			{
				if(currentService instanceof Item) {
					Item currentItem = (Item) currentService;
					if(currentItem.getItemQuantity() >= q) {
						addOrder(currentService, q, region, city, postCode);
						currentItem.updateQuantity(q);
						System.out.println("Order has been placed successfully.");
						return(true);
					} else {
						System.out.println("Insufficient quantity. Order cannot be placed.");
						return(false);
					}
				} else {
					addOrder(currentService, q, region, city, postCode);
					System.out.println("Order has been placed successfully.");
					return(true);
				}
			}
		}
		System.out.println("There is no item called " + name);
		return(false);
	}

	public void addOrder(Service s, int q, String region, String city, String postCode)
	{	
		Service order = null;
		if(s instanceof PhysicalItem) 
		{
			PhysicalItem item = (PhysicalItem) s;
			order = new PhysicalItem(item.getItemName(), item.getItemPrice(), q, null, item.getWidth(), item.getLength(), item.getHeight());
		} else if(s instanceof DigitalItem) 
		{
			DigitalItem item = (DigitalItem) s;
			order = new DigitalItem(item.getItemName(), item.getItemPrice(), q, null, item.getDiskSpace());
		} else if(s instanceof FoodDelivery) 
		{
			FoodDelivery food = (FoodDelivery) s;
			order = new FoodDelivery(food.getFoodName(), "", food.getMealPrice(), food.getServiceType(), q);
		} else if(s instanceof Streaming) 
		{
			Streaming stream = (Streaming) s;
			order = new Streaming(stream.getTitle(), "", stream.getCostPerDay(), stream.getDays(), stream.getServiceType());
		}
		if (order != null) {
			order.setDestinationRegion(region);
			order.setDestinationCity(city);
			order.setDestinationPostCode(postCode);
			orders.add(order);
		}
	}

	public void calculateOrderCost()
	{
		for(Service order : orders)
		{
			String serviceName = "";
			if(order instanceof Item) 
				serviceName = ((Item)order).getItemName();
			else if(order instanceof FoodDelivery) 
				serviceName = ((FoodDelivery)order).getFoodName();
			else if(order instanceof Streaming) 
				serviceName = ((Streaming)order).getTitle();

			double cost = order.calculateService();
			System.out.println("The total cost of " + serviceName + " order is: $" + cost);
		}
	}

	public void DescendingOrderCost()
	{
		Collections.sort(orders);
		for(Service order : orders)
			System.out.println(order);
	}

	public void removeOrderForCity(String city) {
		boolean found = false;
		ListIterator<Service> it = orders.listIterator();
		while(it.hasNext()) {
			Service s = it.next();
			String orderCity = s.getDestinationCity();

			if(orderCity != null && orderCity.equals(city)) {
				it.remove();
				found = true;
			}
		}
		if(found) {
			System.out.println("The order(s) for " + city + " was deleted successfully");
		} else {
			System.out.println("There are no orders placed for " + city);
		}
	}

	public void ft_increase(String type, double percentage)
	{
		ListIterator<Service> it = services.listIterator();

		while(it.hasNext())
		{
			Service s = it.next();
			if(s instanceof Item) {
				Item currentItem = (Item) s;
				if(type.equals("Digital") &&  currentItem instanceof DigitalItem)
					currentItem.setItemPrice(currentItem.getItemPrice() + (currentItem.getItemPrice() * (percentage/100)));
				else if(type.equals("Physical") && currentItem instanceof PhysicalItem)
					currentItem.setItemPrice(currentItem.getItemPrice() + (currentItem.getItemPrice() * (percentage/100)));
			}
		}
	}

	public void ft_fee_limit(int limit)
	{
		ListIterator<Service> it = services.listIterator();
		ArrayList<Service> temp_list = new ArrayList<Service>();

		while(it.hasNext())
		{
			Service currentService = it.next();
			if(currentService.calculateShippingFee() > limit)
				temp_list.add(currentService);
		}
		if(temp_list.size() != 0)
		{
			System.out.println("Services with shipping fees over " + limit + ":");
			for(Service loop : temp_list) {
				String serviceName = "";
				if(loop instanceof Item) 
					serviceName = ((Item)loop).getItemName();
				else if(loop instanceof FoodDelivery) 
					serviceName = ((FoodDelivery)loop).getFoodName();
				else if(loop instanceof Streaming) 
					serviceName = ((Streaming)loop).getTitle();
				System.out.printf("Service: %s, Shipping Fee: %.2f%n", serviceName, loop.calculateShippingFee());
			}
			return ;			
		}
		System.out.println("There is no service with a shipping fee over this limit.");
		return ;
	}

}