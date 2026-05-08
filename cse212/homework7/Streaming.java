public class Streaming implements Service {

	private String title;
	private String category;
	private double costPerDay;
	private int days;
	private String type;

    private String destinationRegion;
    private String destinationCity;
    private String destinationPostCode;


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
		System.out.println("Title : " + this.title);
		System.out.println("Category: " + this.category);
		System.out.println("Cost Per Day: $" + this.costPerDay);
		System.out.println("Rental Days: " + this.days);
	}

	public String toString()
	{
		return ("The total cost of " + this.title + " order is: $" + this.calculateService());
	}

	public double calculateShippingFee()
	{
		return 0;
	}

	public double getCostPerDay() {
		return costPerDay;
	}

	public int getDays() {
		return days;
	}

	public String getTitle() {
		return title;
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