package model;

import java.util.ArrayList;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Deals {
    private ArrayList<Deal> deals;

    public Deals() {
        deals = new ArrayList<Deal>();
        deals.add(new Deal("Kolkata", "Delhi", 3000.00f, LocalDate.now().plusDays(40), LocalDate.now().plusDays(39)));
        deals.add(new Deal("Kolkata", "Mumbai", 5000.00f, LocalDate.now().plusDays(30), LocalDate.now().plusDays(29)));
        deals.add(new Deal("Kolkata", "New York", 55000.00f, LocalDate.now().plusDays(40), LocalDate.now().plusDays(38)));
        deals.add(new Deal("Delhi", "Bermuda Triangle", 0.00f, LocalDate.now().plusDays(40), LocalDate.now().plusDays(40)));
    }

    public ArrayList<Deal> getDeals() {
        return deals;
    }

    public ArrayList<Deal> getDeals(String departureCity, String arrivalCity, String arrivalDateString,
            String departureDateString) {
        ArrayList<Deal> d = new ArrayList<Deal>(deals);
        if (arrivalCity != null)
            d.removeIf(deal -> !deal.getArrivalCity().equals(arrivalCity));
        if (departureCity != null)
            d.removeIf(deal -> !deal.getDepartureCity().equals(departureCity));

        if (arrivalDateString != null) {
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
            LocalDate arrivalDate = LocalDate.parse(arrivalDateString, formatter);
            d.removeIf(deal -> !deal.getArrivalDate().equals(arrivalDate));
        }
        if (departureDateString != null) {
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
            LocalDate departureDate = LocalDate.parse(departureDateString, formatter);
            d.removeIf(deal -> !deal.getDepartureDate().equals(departureDate));
        }

        System.out.println(d.size());
        return d;
    }
}
