import './App.css';
import {useHistory, Switch, Route} from 'react-router-dom';
import Login from './components/Login';
import Home from './components/Home';
import {useCookies} from 'react-cookie';

function App() {
    const CheckAuth = () => {
        const [cookies] = useCookies(["Auth"]);
        let h = useHistory();
        if (!cookies.Auth || cookies.Auth === undefined) {
            h.push('/login/');
        }
    }

    return (
        <div className="App">
            <Switch>
                {CheckAuth()}
                <Route exact path="/login/" component={Login} />
                <Route path="/" component={Home} />
            </Switch>
        </div>
    );
}

export default App;
