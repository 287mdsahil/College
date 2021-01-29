import Modal from 'react-bootstrap/Modal';
import Form from 'react-bootstrap/Form';
import Button from 'react-bootstrap/Button';
import Tab from 'react-bootstrap/Tab';
import Tabs from 'react-bootstrap/Tabs';
import {useCookies} from 'react-cookie';
import {useRef, useEffect} from 'react';

function LoginScreen(props) {
    const passwd = useRef(null);
    const userid = useRef(null);
    const [cookies, setCookie] = useCookies(["Auth"]);

    var CheckId = () => {
        if (cookies.Auth) props.history.push('/');
    };

    useEffect(CheckId);

    // Login function
    var login = () => {
        let auth = Buffer.from(userid.current + ":" + passwd.current).toString('base64');
        console.log('Logging in');
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
                if (data.id !== undefined)
                    setCookie("Auth", Buffer.from(data.id + ":" + data.password).toString('base64'));
            }).catch(err => {
                console.log(err);
            });
    };

    return (
        <Form>
            <Form.Group controlId="userid"
                onChange={e => {
                    userid.current = e.target.value;
                }}
            >
                <Form.Label>User Id</Form.Label>
                <Form.Control type="text" placeholder="Enter Id" />
                <Form.Text className="text-muted">
                </Form.Text>
            </Form.Group>

            <Form.Group controlId="password"
                onChange={e => {
                    passwd.current = e.target.value;
                }}
            >
                <Form.Label>Password</Form.Label>
                <Form.Control type="password" placeholder="Password" />
            </Form.Group>
            <Button
                variant="primary"
                onClick={login}
            >
                Login
  			</Button>
        </Form>
    );
}


function SignupScreen(props) {
    const passwd = useRef(null);
    const userid = useRef(null);
    const sex = useRef(null);
    const pref = useRef(null);

    const [cookies, setCookie] = useCookies(["Auth"]);
    var CheckId = () => {
        if (cookies.Auth) props.history.push('/');
    };
    useEffect(CheckId);

    // Signup function
    var signup = () => {
        console.log('Signin in');
        const postOptions = {
            method: "POST",
            headers: {"Content-Type": "application/json"},
            body: JSON.stringify({
                "id": userid.current,
                "password": passwd.current,
                "sex": sex.current,
                "pref": pref.current
            })
        };
        console.log(postOptions);
        fetch("http://localhost:8080/notamazon/login", postOptions)
            .then(response => {
                if (!response.ok) {
                    console.log("Failed with HTTP code: " + response.status);
                    return {};
                } else {
                    return response.json;
                }
            })
            .then(data => {
                if (data.id !== undefined) {
                    setCookie("id", data.id);
                }
            }).catch(err => {
                console.log(err);
            });
    };
    return (
        <Form>
            <Form.Group controlId="userid"
                onChange={e => {
                    userid.current = e.target.value;
                }}
            >
                <Form.Label>User Id</Form.Label>
                <Form.Control type="text" placeholder="Enter Id" />
                <Form.Text className="text-muted">
                </Form.Text>
            </Form.Group>

            <Form.Group controlId="password"
                onChange={e => {
                    passwd.current = e.target.value;
                }}
            >
                <Form.Label>Password</Form.Label>
                <Form.Control type="password" placeholder="Password" />
            </Form.Group>
            <Form.Group controlId="sex"
                onChange={e => {
                    sex.current = e.target.value;
                }}
            >
                <Form.Label>Sex</Form.Label>
                <Form.Control as="select">
                    <option>M</option>
                    <option>F</option>
                    <option>O</option>
                </Form.Control>
            </Form.Group>
            <Form.Group controlId="pref"
                onChange={e => {
                    pref.current = (Math.round(e.target.value / 10) / 10);
                }}
            >
                <Form.Label>New Arrival Preference</Form.Label>
                <Form.Control type="range" />
            </Form.Group>
            <Button
                variant="primary"
                onClick={signup}
            >
                Signup
  			</Button>
        </Form>
    );
}


function Login(props) {
    const [cookies,] = useCookies(["Auth"]);

    var CheckId = () => {
        if (cookies.Auth) props.history.push('/');
    };

    useEffect(CheckId);
    return (
        <div style={{
            height: '100vh',
            width: '100vw',
        }}>
            <Modal
                show={true}
                size="lg"
                centered
                onHide={() => {/*do nothing*/}}
            >
                <Modal.Header>
                    <Modal.Title>Login or Signup</Modal.Title>
                </Modal.Header>
                <Modal.Body>
                    <Tabs defaultActiveKey="login" id="uncontrolled-login-tabs">
                        <Tab eventKey="login" title="Login">
                            <LoginScreen history={props.history} />
                        </Tab>
                        <Tab eventKey="signup" title="Signup">
                            <SignupScreen history={props.history} />
                        </Tab>
                    </Tabs>
                </Modal.Body>
            </Modal>
        </div>
    );
}

export default Login;
