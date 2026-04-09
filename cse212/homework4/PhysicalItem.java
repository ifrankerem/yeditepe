package homework4;

public class PhysicalItem extends Item{
	
	private double width;
	private double length;
	private double height;


	public PhysicalItem(String itemName, double itemPrice, int itemQuantity,Provider provider, double width, double length, double height)
	{
		super(itemName,itemPrice,itemQuantity,provider,"Physical");
		this.width = width;
		this.length = length;
		this.height = height;
	}

	public double calculateVolumetricWeight()
	{
		return((this.length * this.width * this.height) / 5000);
	}

	public double calculateShippingFee()
	{
		double weight = calculateVolumetricWeight();
		double fee = this.getItemPrice() * weight;

		if(weight < 1)
			fee *= 0.1;
		else if(weight >= 1 && weight < 2)
			fee *= 0.25;
		else if(weight >= 2 && weight < 5)
			fee *= 0.35;
		else
			fee *= 0.50;

		return (fee);
					
	}


}