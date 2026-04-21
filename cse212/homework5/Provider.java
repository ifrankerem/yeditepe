public class Provider
{
	private String name;
	private int countryCode;
	private int areaCode;
	private int phoneNumber;

	public Provider(String name, int countryCode , int areaCode , int phoneNumber)
	{
		this.name = name;
		this.countryCode = countryCode;
		this.areaCode = areaCode;
		this.phoneNumber = phoneNumber;
	}

	public String getName() {
		return name;
	}

	public int getPhoneNumber() {
		return phoneNumber;
	}

	public int getCountryCode() {
		return countryCode;
	}

	public int getAreaCode() {
		return areaCode;
	}
	
}