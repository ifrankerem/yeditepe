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

	public String getServiceType() {
		return type;
	}

	public double calculateService() {
		return (mealPrice * count) + calculateShippingFee();
	}

	public double calculateShippingFee() {
		return 5.0;
	}

	public void displayServiceInfo() {
		System.out.println("Food Name: " + foodName);
		System.out.println("Restaurant Name: " + restaurantName);
		System.out.println("Meal Price: $" + mealPrice);
		System.out.println("Food Count: " + count);
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