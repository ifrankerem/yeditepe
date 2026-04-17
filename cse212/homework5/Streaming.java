public class Streaming implements Service{

	private String title;
	private String category;
	private double costPerDay;
	private int days;
	private String type;


	public Streaming(String title, String category, double costPerDay, int days, String type) {
		this.title = title;
		this.category = category;
		this.costPerDay = costPerDay;
		this.days = days;
		this.type = type;
	}

	public String getServiceType()
	{
		return (type);
	}

	public double calculateService()
	{
		return((costPerDay * days) + calculateShippingFee());
	}

	public void displayServiceInfo()
	{
		System.out.println();
	}

	public double calculateShippingFee()
	{
		return 0; //?Should not diyo ? anlamadım dön buraya
	}





}