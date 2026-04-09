package homework4;

public class DigitalItem extends Item{

	private double diskSpace;


	public DigitalItem(String itemName, double itemPrice, int itemQuantity ,Provider provider, double diskSpace)
	{
		super(itemName,itemPrice,itemQuantity,provider);
		this.diskSpace = diskSpace;
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