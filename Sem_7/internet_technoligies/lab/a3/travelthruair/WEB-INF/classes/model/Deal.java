package model;

import java.time.LocalDate;

public class Deal {
    private String departureCity;
    private String arrivalCity;
    private float cost;
    private LocalDate arrivalDate;
    private LocalDate departureDate;

    public Deal() {
    };

    public Deal(String departureCity, String arrivalCity, float cost, LocalDate arrivalDate, LocalDate departureDate) {
        this.departureCity = departureCity;
        this.arrivalCity = arrivalCity;
        this.cost = cost;
        this.arrivalDate = arrivalDate;
        this.departureDate = departureDate;
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

    public LocalDate getArrivalDate() {
        return arrivalDate;
    }

    public void setArrivalDate(LocalDate arrivalDate) {
        this.arrivalDate = arrivalDate;
    }

    public LocalDate getDepartureDate() {
        return departureDate;
    }

    public void seDepartureDate(LocalDate departureDate) {
        this.departureDate = departureDate;
    }
}
