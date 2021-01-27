package notamazon.api;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.*;
import com.google.gson.Gson;
import notamazon.model.*;
import java.util.*;
import java.lang.StringBuffer;
import com.google.gson.Gson;

@WebServlet("/api/cart")
public class CartServlet extends HttpServlet {
    static final long serialVersionUID = 5l;

    public void doPost(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {
        StringBuffer requestBuffer = new StringBuffer();
        String line = null;
        try {
            BufferedReader requestReader = req.getReader();
            while ((line = requestReader.readLine()) != null)
                requestBuffer.append(line);
        } catch (Exception e) {
            e.printStackTrace();
        }

        Gson gson = new Gson();
        Map<String, Object> requestMap = (Map<String, Object>) gson.fromJson(requestBuffer.toString(), Map.class);

        String productId = (String) requestMap.get("id");
        int quantity = (int) requestMap.get("quantity");

        User user = (User) req.getAttribute("user");
        Users users = new Users();
        User updatedUser = users.addToCart(user, new Products().getProduct(productId), quantity);

        res.getWriter().println(gson.toJson(updatedUser));
    }
}
