public interface Service {
    public String getServiceType();
    public double calculateService();
    public void displayServiceInfo();
    public double calculateShippingFee();

    public String getDestinationCity();
    public void setDestinationRegion(String region);
    public void setDestinationCity(String city);
    public void setDestinationPostCode(String postCode);
}