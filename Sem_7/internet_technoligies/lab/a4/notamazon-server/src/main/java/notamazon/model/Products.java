package notamazon.model;

import java.util.List;
import com.amazonaws.services.dynamodbv2.AmazonDynamoDB;
import com.amazonaws.services.dynamodbv2.AmazonDynamoDBClientBuilder;
import com.amazonaws.client.builder.AwsClientBuilder.EndpointConfiguration;
import com.amazonaws.services.dynamodbv2.datamodeling.DynamoDBMapper;
import com.amazonaws.services.dynamodbv2.datamodeling.DynamoDBScanExpression;

public class Products {
    private AmazonDynamoDB client;

    public Products() {
        client = AmazonDynamoDBClientBuilder.standard()
                .withEndpointConfiguration(new EndpointConfiguration("http://localhost:8000", "")).build();
    }

    public List<Product> getProducts() {
        DynamoDBMapper mapper = new DynamoDBMapper(client);
        DynamoDBScanExpression scanExpression = new DynamoDBScanExpression();
        List<Product> products = mapper.scan(Product.class, scanExpression);
        return products;
    }

    public Product getProduct(String id) {
        DynamoDBMapper mapper = new DynamoDBMapper(client);
        Product product = mapper.load(Product.class, id);
        return product;
    }

    public Product addProduct(Product product) {
        DynamoDBMapper mapper = new DynamoDBMapper(client);
        mapper.save(product);
        return getProduct(product.getId());
    }
}
