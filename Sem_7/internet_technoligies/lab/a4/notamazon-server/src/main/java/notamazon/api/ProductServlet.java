package notamazon.api;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.annotation.WebServlet;
import java.io.IOException;
import com.google.gson.Gson;
import notamazon.model.Products;
import notamazon.model.Product;
import javax.servlet.ServletException;
import java.util.UUID;
import java.util.List;
import java.util.Map;
import java.lang.StringBuffer;
import java.io.BufferedReader;
import com.google.gson.Gson;

@WebServlet("/api/products")
public class ProductServlet extends HttpServlet {
    static final long serialVersionUID = 4l;

    public void doGet(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {
        Gson gson = new Gson();
        Products products = new Products();
        List<Product> productList = products.getProducts();
        String str = gson.toJson(productList);
        res.getWriter().println(str);
    }

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

        String name = (String) requestMap.get("name");
        Double price = (Double) requestMap.get("price");
        int discount = (int) requestMap.get("discount");
        boolean newArrival = (boolean) requestMap.get("newArrival");
        String id = UUID.randomUUID().toString();

        Products products = new Products();
        Product product = products.addProduct(new Product(id, name, price.floatValue(), discount, newArrival));
        res.getWriter().println(gson.toJson(product));
    }
}
