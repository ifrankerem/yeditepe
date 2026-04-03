package homework3;

public class Order {

	private Item item;
	private String type;
	private int quantity;

	public Order(Item item, String type)
	{
		this.item = item;
		this.type = type;
	}

	public Item getItem() {
		return item;
	}

	public void setItem(Item item) {
		this.item = item;
	}

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
	}

	public int getQuantity() {
		return quantity;
	}

	public void setQuantity(int quantity) {
		this.quantity = quantity;
	}

	public double calculateOrderCost()
	{
		double cost = item.getItemPrice() * quantity + item.calculateShippingFee();
		return cost;
	}

}