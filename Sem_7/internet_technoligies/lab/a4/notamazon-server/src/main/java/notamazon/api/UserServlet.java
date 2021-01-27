package notamazon.api;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.annotation.WebServlet;
import java.io.IOException;
import com.google.gson.Gson;
import notamazon.model.*;
import javax.servlet.ServletException;
import java.util.Map;
import java.lang.StringBuffer;
import java.io.BufferedReader;
import com.google.gson.Gson;
import java.util.Base64;

@WebServlet("/login")
public class UserServlet extends HttpServlet {
    static final long serialVersionUID = 3l;

    public void doGet(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException {
        String base64auth = req.getHeader("Authorization").split(" ")[1];
        String[] userpass = (new String(Base64.getDecoder().decode(base64auth))).split(":");
        String id = userpass[0];
        String password = userpass[1];

        Users users = new Users();
        if (users.auth(id, password)) {
            String str = new Gson().toJson(users.getUser(id));
            res.getWriter().println(str);
        } else {
            res.sendError(HttpServletResponse.SC_UNAUTHORIZED);
        }
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

        String id = (String) requestMap.get("id");
        String password = (String) requestMap.get("password");
        String sex = (String) requestMap.get("sex");
        Double pref = (Double) requestMap.get("pref");

        User newUser = new User(id, password, sex.charAt(0), pref.floatValue());
        Users users = new Users();
        users.addUser(newUser);

        res.getWriter().println(gson.toJson(users.getUser(id)));
    }
}
