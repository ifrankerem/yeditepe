package homework4;

public class Item {

	private String itemName;
	private double itemPrice;
	private int itemQuantity;
	private Provider provider;
	private String type;


	public Item (String itemName, double itemPrice,int itemQuantity, Provider provider, String type)
	{
		this.itemName = itemName;
		this.itemPrice = itemPrice;
		this.itemQuantity = itemQuantity;
		this.provider = provider;
		this.type = type;
	}

	public void updateQuantity(int purchasedQuantity)
	{
		this.itemQuantity -= purchasedQuantity;
	}

	public double calculateVolumetricWeight() 
	{
		return 0;
	}

	public double calculateShippingFee()
	{
		return (0);
	}

	public double calculateTotalWorth()
	{
		return(this.itemQuantity * this.itemPrice);
	}

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
	public String getType() {
		return type;
	}
	
	public void setItemPrice(double itemPrice) {
		this.itemPrice = itemPrice;
	}
}