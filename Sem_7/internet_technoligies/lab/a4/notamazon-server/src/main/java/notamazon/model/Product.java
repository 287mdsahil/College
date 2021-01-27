package notamazon.model;

import com.amazonaws.services.dynamodbv2.datamodeling.DynamoDBTable;
import com.amazonaws.services.dynamodbv2.datamodeling.DynamoDBHashKey;
import com.amazonaws.services.dynamodbv2.datamodeling.DynamoDBAttribute;

@DynamoDBTable(tableName = "products")
public class Product {
    private String id;
    private String name;
    private float price;
    private int discount;
    private boolean newArrival;

    public Product() {
    };

    public Product(String id, String name, float price, int discount, boolean newArrival) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.discount = discount;
        this.newArrival = newArrival;
    }

    @DynamoDBHashKey(attributeName = "id")
    public String getId() {
        return this.id;
    }

    public void setId(String id) {
        this.id = id;
    }

    @DynamoDBAttribute(attributeName = "name")
    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @DynamoDBAttribute(attributeName = "price")
    public float getPrice() {
        return this.price;
    }

    public void setPrice(float price) {
        this.price = price;
    }

    @DynamoDBAttribute(attributeName = "discount")
    public int getDiscount() {
        return this.discount;
    }

    public void setDiscount(int discount) {
        this.discount = discount;
    }

    @DynamoDBAttribute(attributeName = "newArrival")
    public boolean getNewArrival() {
        return this.newArrival;
    }

    public void setNewArrival(boolean newArrival) {
        this.newArrival = newArrival;
    }
}
