public abstract class Item implements Service{

	private String itemName;
	private double itemPrice;
	private int itemQuantity;
	private Provider provider;


	public Item (String itemName, double itemPrice,int itemQuantity, Provider provider)
	{
		this.itemName = itemName;
		this.itemPrice = itemPrice;
		this.itemQuantity = itemQuantity;
		this.provider = provider;
	}

	public abstract void updateQuantity(int purchasedQuantity);

	public abstract double calculateVolumetricWeight();

	public abstract double calculateTotalWorth();
	
	
	public void displayItem()
	{
		System.out.println("Item : " + this.itemName);
		System.out.println("Price: $" + this.itemPrice);
		System.out.println("Quantity: " + this.itemQuantity);
		System.out.println("Provider: " + this.provider.getName());
		System.out.println("Provider Contact: +" + this.provider.getCountryCode() + "(" + this.provider.getAreaCode() + ")" + this.provider.getPhoneNumber());
		System.out.println();

	}

	public double getItemPrice() {
		return itemPrice;
	}
	public int getItemQuantity() {
		return itemQuantity;
	}
	public String getItemName() {
		return itemName;
	}
	
	public void setItemPrice(double itemPrice) {
		this.itemPrice = itemPrice;
	}
}