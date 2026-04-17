public class DigitalItem extends Item implements Service{

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
	
}