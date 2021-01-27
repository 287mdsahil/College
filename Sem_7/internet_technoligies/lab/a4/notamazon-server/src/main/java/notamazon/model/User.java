package notamazon.model;

import com.amazonaws.services.dynamodbv2.datamodeling.DynamoDBTable;
import com.amazonaws.services.dynamodbv2.datamodeling.DynamoDBHashKey;
import com.amazonaws.services.dynamodbv2.datamodeling.DynamoDBAttribute;
import java.util.*;

@DynamoDBTable(tableName = "users")
public class User {
    private String id;
    private String password;
    private char sex;
    private float pref;
    private List<CartItem> cart;

    public User(String id, String password, char sex, float pref) {
        this.id = id;
        this.password = password;
        this.sex = sex;
        this.pref = pref;
        this.cart = new ArrayList<CartItem>();
    }

    public User() {
    }

    @DynamoDBHashKey(attributeName = "id")
    public String getId() {
        return this.id;
    }

    public void setId(String id) {
        this.id = id;
    }

    @DynamoDBAttribute(attributeName = "password")
    public String getPassword() {
        return this.password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    @DynamoDBAttribute(attributeName = "sex")
    public char getSex() {
        return this.sex;
    }

    public void setSex(char sex) {
        this.sex = sex;
    }

    @DynamoDBAttribute(attributeName = "pref")
    public float getPref() {
        return this.pref;
    }

    public void setPref(float pref) {
        this.pref = pref;
    }

    @DynamoDBAttribute(attributeName = "cart")
    public List<CartItem> getCart() {
        return this.cart;
    }

    public void setCart(List<CartItem> cart) {
        this.cart = cart;
    }

    public void addToCart(CartItem cartItem) {
        this.cart.add(cartItem);
    }

}
