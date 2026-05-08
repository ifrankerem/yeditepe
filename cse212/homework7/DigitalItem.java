public class DigitalItem extends Item {

	private double diskSpace;


	public DigitalItem(String itemName, double itemPrice, int itemQuantity ,Provider provider, double diskSpace)
	{
		super(itemName,itemPrice,itemQuantity,provider);
		this.diskSpace = diskSpace;
	}

	public String getServiceType() {
		return "Digital";
	}
	public double calculateVolumetricWeight()
	{
		return(0);
	}

	public double calculateShippingFee()
	{
		return (0);
	}

	public void updateQuantity(int purchasedQuantity) {
		setItemQuantity(getItemQuantity() - purchasedQuantity);
	}

	public double calculateTotalWorth() {
		return getItemPrice() * getItemQuantity();
	}

	public void displayServiceInfo() {
		super.displayServiceInfo();
		System.out.println("Disk Space: " + diskSpace);
	}

	public double getDiskSpace() {
		return diskSpace;
	}
}