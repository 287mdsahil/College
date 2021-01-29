import Button from 'react-bootstrap/Button';
import Card from 'react-bootstrap/Card';
import {useCookies} from 'react-cookie';
import {useEffect, useState} from 'react';

function Product(props) {
    const cookies = props.cookies;

    const addToCart = () => {
        let auth = cookies.Auth;
        console.log('Adding to cart');
        const postOptions = {
            method: "POST",
            headers: {
                "Authorization": "Basic " + auth,
                "Content-Type": "application/json"
            },
            body: JSON.stringify({
                "id": props.id,
                "quantity": 1
            })
        };
        console.log(postOptions);
        fetch("http://localhost:8080/notamazon/api/cart", postOptions)
            .then(response => {
                if (!response.ok) {
                    console.log("Failed with HTTP code: " + response.status);
                    return {};
                } else {
                    return response.json();
                }
            }).then(data => {
                console.log(data);
                props.setUser(data);
            }).catch(err => {
                console.log(err);
            });
    }

    return (
        <Card>
            <Card.Body>
                <Card.Title>{props.name}</Card.Title>
                <Card.Text>
                    <div>New Arrival: {props.newArrival ? "True" : "False"}</div>
                    <div>Discount: {props.discount}%</div>
                    <div>Price: Rs.{props.price}</div>
                </Card.Text>
                <Button variant="primary" onClick={addToCart}>Add to cart</Button>
            </Card.Body>
        </Card>
    );
}

function Header(props) {
    return (
        <Card bg='secondary' text='white'>
            <Card.Body>
                <Card.Title>{props.user.id}</Card.Title>
                <Card.Text>
                    Items in cart: {Object.getOwnPropertyNames(props.user.cart).length}
                    <br />
                    Preference for new Arrival: {props.user.pref}
                </Card.Text>
                <Button variant="primary">Proceed to checkout</Button>
            </Card.Body>
        </Card>
    )
}

function Home(props) {
    const [cookies, setCookie] = useCookies(["Auth"]);
    const [products, setProducts] = useState([]);
    const [user, setUser] = useState(null);

    var CheckId = () => {
        if (cookies.Auth) props.history.push('/');
    };
    useEffect(CheckId, []);

    const fetchUser = () => {
        let auth = cookies.Auth;
        console.log('Fetching user');
        const getOptions = {
            method: "GET",
            headers: {"Authorization": "Basic " + auth},
        };
        fetch("http://localhost:8080/notamazon/login", getOptions)
            .then(response => {
                if (!response.ok) {
                    console.log("Failed with HTTP code: " + response.status);
                    return {};
                } else {
                    return response.json();
                }
            }).then(data => {
                console.log(data);
                setUser(data);
            }).catch(err => {
                console.log(err);
            });
    }
    useEffect(fetchUser, []);

    const fetchProducts = () => {
        let auth = cookies.Auth;
        console.log('Fetching products');
        const getOptions = {
            method: "GET",
            headers: {"Authorization": "Basic " + auth},
        };
        fetch("http://localhost:8080/notamazon/api/products", getOptions)
            .then(response => {
                if (!response.ok) {
                    console.log("Failed with HTTP code: " + response.status);
                    return {};
                } else {
                    return response.json();
                }
            }).then(data => {
                console.log(data);
                setProducts(data);
            }).catch(err => {
                console.log(err);
            });

    }

    useEffect(fetchProducts, [user]);

    return (
        <div>
            {user != null && <Header user={user} />}
            {products.map((product) => <Product key={product.id} setUser={setUser} cookies={cookies} {...product} />)}
        </div>
    );
}

export default Home;
