public class FoodDelivery implements Service {


	private String foodName;
	private String restaurantName;
	private double mealPrice;
	private String type;
	private int count;

	private String destinationRegion;
    private String destinationCity;
    private String destinationPostCode;



	public FoodDelivery(String foodName, String restaurantName, double mealPrice, String type, int count) {
		this.foodName = foodName;
		this.restaurantName = restaurantName;
		this.mealPrice = mealPrice;
		this.type = type;
		this.count = count;
	}

	public String toString()
	{
		return ("The total cost of " + this.foodName + " order is: $" + this.calculateService());
	}

	public String getServiceType() {
		return type;
	}

	public double calculateService() {
		return ((mealPrice + calculateShippingFee() )* count);
	}

	public double calculateShippingFee() {
		return 5.0;
	}

	public String  getServiceInfoText() {

		String result = "";
		result+= "Food Name: " + foodName + "\n";
		result+= "Restaurant Name: " + restaurantName + "\n";
		result+= "Meal Price: $" + mealPrice + "\n";
		result+= "Food Count: " + count + "\n";
		return result;
	}

	public void displayServiceInfo()
	{
		System.out.println(getServiceInfoText());
	}

	public double getMealPrice() {
		return mealPrice;
	}

	public int getCount() {
		return count;
	}

	public String getFoodName() {
		return foodName;
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