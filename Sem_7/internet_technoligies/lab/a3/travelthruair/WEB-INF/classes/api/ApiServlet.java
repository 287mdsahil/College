package api;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.ServletException;
import java.io.IOException;
import java.io.PrintWriter;
import com.google.gson.Gson;

import model.Deals;

public class ApiServlet extends HttpServlet {
    public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
        String pathInfo = req.getPathInfo();
        pathInfo = pathInfo + "/";
        String[] path = pathInfo.split("/");
        if (path.length < 2) {
            res.setContentType("text/html");
            PrintWriter writer = res.getWriter();
            writer.println("<div>Invalid Api Call</div>");

        } else if (path[1].equals("deals")) {
            Gson gson = new Gson();
            String jsonstr = gson.toJson(Deals.getDeals());
            res.setContentType("application/json");
            PrintWriter writer = res.getWriter();
            writer.println(jsonstr);
        } else {
            res.setContentType("text/html");
            PrintWriter writer = res.getWriter();
            writer.println("<div>Invalid Api Call</div>");
        }
    }
}
