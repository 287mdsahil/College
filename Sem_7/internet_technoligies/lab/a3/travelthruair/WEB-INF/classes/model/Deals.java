package model;

import java.util.ArrayList;

public class Deals {
    public static ArrayList<Deal> getDeals() {
        ArrayList<Deal> deals = new ArrayList<Deal>();
        deals.add(new Deal("Kolkata", "Delhi", 3000.00f));
        deals.add(new Deal("Kolkata", "Mumbai", 5000.00f));
        deals.add(new Deal("Kolkata", "New York", 55000.00f));
        return deals;
    }
}
