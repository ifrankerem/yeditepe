public abstract class Item implements Service {

	private String itemName;
	private double itemPrice;
	private int itemQuantity;
	private Provider provider;

	private String destinationRegion;
    private String destinationCity;
    private String destinationPostCode;



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

	public double calculateService() {
		return (this.itemPrice * this.itemQuantity) + calculateShippingFee();
	}
	
	public String getServiceInfoText()
	{
		String result = "";
		result += "Item : " + this.itemName + "\n";
		result += "Price: $" + this.itemPrice + "\n";
		result += "Quantity: " + this.itemQuantity + "\n";
		if (this.provider != null) {
			result += "Provider: " + this.provider.getName() + "\n";
			result += "Provider Contact: +" + this.provider.getCountryCode() + "(" + this.provider.getAreaCode() + ")" + this.provider.getPhoneNumber() + "\n";
		} else {
			result += "Provider: Unknown\n";
			result += "Provider Contact: Unknown\n";
		}
		return result;
	}

	public void displayServiceInfo()
	{
		System.out.println(getServiceInfoText());
	}

	public String toString()
	{
		return ("The total cost of " + this.itemName + " order is: $" + this.calculateService());
	}

	public Provider getProvider() {
		return provider;
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
	
	public void setItemQuantity(int itemQuantity) {
		this.itemQuantity = itemQuantity;
	}

	public String getDestinationCity() {
		return destinationCity;
	}

	public void setDestinationRegion(String region) {
		this.destinationRegion = region;
	}

	public void setDestinationCity(String city) {
		this.destinationCity = city;
	}

	public void setDestinationPostCode(String postCode) {
		this.destinationPostCode = postCode;
	}
}