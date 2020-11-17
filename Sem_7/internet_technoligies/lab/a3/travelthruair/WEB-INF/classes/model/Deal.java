package model;

public class Deal {
    private String departureCity;
    private String arrivalCity;
    private float cost;

    public Deal() {
    };

    public Deal(String departureCity, String arrivalCity, float cost) {
        this.departureCity = departureCity;
        this.arrivalCity = arrivalCity;
        this.cost = cost;
    };

    public String getDepartureCity() {
        return departureCity;
    }

    public void setDepartureCity(String city) {
        this.departureCity = city;
    }

    public String getArrivalCity() {
        return arrivalCity;
    }

    public void setArrivalCity(String city) {
        this.arrivalCity = city;
    }

    public float getCost() {
        return cost;
    }

    public void setCost(float cost) {
        this.cost = cost;
    }
}
