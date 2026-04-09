package homework4;

public class Order {

	private Item item;
	private int quantity;
	private double orderPrice; // i declared this because "if a product was ordered before the price raise, its price should be kept as is"

	public Order(Item item)
	{
		this.item = item;
	}

	public Item getItem() {
		return item;
	}

	public void setItem(Item item) {
		this.item = item;
	}

	public int getQuantity() {
		return quantity;
	}

	public void setQuantity(int quantity) {
		this.quantity = quantity;
	}

	public double getOrderPrice() {
		return orderPrice;
	}

	public void setOrderPrice(double orderPrice) {
		this.orderPrice = orderPrice;
	}

	public double calculateOrderCost()
	{
		double cost = orderPrice * quantity;
		return cost;
	}

}