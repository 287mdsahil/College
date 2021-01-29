package notamazon.model;

import com.amazonaws.services.dynamodbv2.AmazonDynamoDB;
import com.amazonaws.services.dynamodbv2.AmazonDynamoDBClientBuilder;
import com.amazonaws.client.builder.AwsClientBuilder.EndpointConfiguration;
import com.amazonaws.services.dynamodbv2.datamodeling.DynamoDBMapper;

public class Users {
    private AmazonDynamoDB client;

    public Users() {
        client = AmazonDynamoDBClientBuilder.standard()
                .withEndpointConfiguration(new EndpointConfiguration("http://localhost:8000", "")).build();
    }

    public User getUser(String id) {
        DynamoDBMapper mapper = new DynamoDBMapper(client);
        User user = mapper.load(User.class, id);
        return user;
    }

    public User addUser(User user) {
        DynamoDBMapper mapper = new DynamoDBMapper(client);
        mapper.save(user);
        return getUser(user.getId());
    }

    public boolean auth(String id, String password) {
        User user = getUser(id);
        if (user == null)
            return false;
        else
            return getUser(id).getPassword().equals(password);
    }

    public User addToCart(User user, Product product, int quantity) {
        user.addToCart(product.getId(), quantity);
        float newPref = user.getPref();
        if (product.getNewArrival())
            newPref += 0.1f;
        else if (product.getDiscount() > 0)
            newPref -= 0.1f;

        if (newPref > 0.9f)
            newPref = 0.9f;
        if (newPref < 0.1f)
            newPref = 0.1f;

        user.setPref(newPref);

        return addUser(user);
    }

}
