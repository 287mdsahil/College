package notamazon.api;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.util.Base64;
import notamazon.model.*;

@WebFilter("/api/*")
public class AuthFilter implements Filter {

    @Override
    public void init(FilterConfig config) throws ServletException {
    };

    @Override
    public void doFilter(ServletRequest req, ServletResponse res, FilterChain chain)
            throws IOException, ServletException {
        HttpServletRequest httpReq = (HttpServletRequest) req;
        HttpServletResponse httpRes = (HttpServletResponse) res;

        String base64auth = httpReq.getHeader("Authorization").split(" ")[1];
        String[] userpass = (new String(Base64.getDecoder().decode(base64auth))).split(":");
        String id = userpass[0];
        String password = userpass[1];

        Users users = new Users();
        if (users.auth(id, password)) {
            req.setAttribute("user", users.getUser(id));
            chain.doFilter(req, res);
        } else {
            httpRes.sendError(HttpServletResponse.SC_UNAUTHORIZED);
        }
    }
}
