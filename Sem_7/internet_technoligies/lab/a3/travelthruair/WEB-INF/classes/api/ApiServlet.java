package api;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.ServletException;
import java.io.IOException;
import java.io.PrintWriter;
import com.google.gson.Gson;
import java.util.Map;
import java.time.format.DateTimeFormatter;
import java.time.LocalDate;

import model.Deals;

public class ApiServlet extends HttpServlet {

    private boolean checkError(HttpServletResponse res, String arrivalCity, String departureCity,
            String arrivalDateString, String departureDateString) throws IOException {
        if (arrivalCity != null && departureCity != null) {
            if (arrivalCity.equals(departureCity)) {
                res.setStatus(406);
                res.setContentType("application/json");
                PrintWriter writer = res.getWriter();
                writer.println("{\"message\":\"Arrival and departure city cannot be the same\"}");
                return true;
            }
        }
        if (arrivalDateString != null) {
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
            LocalDate arrivalDate = LocalDate.parse(arrivalDateString, formatter);
            if (arrivalDate.isBefore(LocalDate.now())) {
                res.setStatus(406);
                res.setContentType("application/json");
                PrintWriter writer = res.getWriter();
                writer.println("{\"message\":\"Arrival date is invalid\"}");
                return true;
            }
        }
        if (departureDateString != null) {
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
            LocalDate departureDate = LocalDate.parse(departureDateString, formatter);
            if (departureDate.isBefore(LocalDate.now())) {
                res.setStatus(406);
                res.setContentType("application/json");
                PrintWriter writer = res.getWriter();
                writer.println("{\"message\":\"Departure date is invalid\"}");
                return true;
            }
        }
        if (arrivalDateString != null && departureDateString != null) {
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
            LocalDate arrivalDate = LocalDate.parse(arrivalDateString, formatter);
            LocalDate departureDate = LocalDate.parse(departureDateString, formatter);
            if (arrivalDate.isBefore(departureDate)) {
                res.setStatus(406);
                res.setContentType("application/json");
                PrintWriter writer = res.getWriter();
                writer.println("{\"message\":\"Arrival date is cannot be before Departure\"}");
                return true;
            }
        }
        return false;
    }

    public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
        String pathInfo = req.getPathInfo();
        pathInfo = pathInfo + "/";

        String arrivalCity = req.getParameter("arrivalCity");
        String departureCity = req.getParameter("departureCity");

        String arrivalDateString = req.getParameter("arrivalDate");
        String departureDateString = req.getParameter("departureDate");

        System.out.println(arrivalCity + " " + departureCity);
        System.out.println(arrivalDateString + " " + departureDateString);

        String[] path = pathInfo.split("/");
        if (path.length < 2) {
            res.setStatus(406);
            res.setContentType("application/json");
            PrintWriter writer = res.getWriter();
            writer.println("{\"message\":\"Invalid API call\"}");
        } else if (path[1].equals("deals")) {
            if (!checkError(res, arrivalCity, departureCity, arrivalDateString, departureDateString)) {
                Gson gson = new Gson();
                String jsonstr = gson.toJson(
                        new Deals().getDeals(arrivalCity, departureCity, arrivalDateString, departureDateString));
                System.out.println(jsonstr);
                res.setContentType("application/json");
                PrintWriter writer = res.getWriter();
                writer.println(jsonstr);
            }
        } else {
            res.setStatus(406);
            res.setContentType("application/json");
            PrintWriter writer = res.getWriter();
            writer.println("{\"message\":\"Invalid API call\"}");
        }
    }
}
