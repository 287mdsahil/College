function fetchDeals(callback, url) {
    fetch(url, {"Content-Type": "application/json"})
        .then(response => {
            if (!response.ok) {
                console.log("Failed with HTTP code:" + response.status);
                response.json().then(err => {showError(err.message)})
                return {};
            } else {
                return response.json();
            }
        })
        .then(data => {
            callback(data);
        })
        .catch(err => {
            showError(err);
            console.log(err);
        });
}

function showError(errmsg) {
    document.getElementById("error").innerText = errmsg;
}

function getDeals(queryParams) {
    document.getElementById("deal_listing").innerHTML = "";
    document.getElementById("error").innerText = "";
    console.log("deals");
    let url = "api/deals";
    if (queryParams)
        url += "?" + queryParams;
    console.log(url);
    fetchDeals((data) => {
        console.log(data);
        if (data.length == 0) {
            showError("No flights available");
        }
        for (var deal in data) {
            console.log(data[deal]);
            var dealDiv = document.createElement('div');
            dealDiv.innerHTML =
                "<div>" +
                "From:" + data[deal].departureCity + " || " +
                "To:" + data[deal].arrivalCity + " || " +
                "Departure Date:"
                + data[deal].departureDate.day
                + "/" + data[deal].departureDate.month
                + "/" + data[deal].departureDate.year + " || " +
                "Arrival Date:"
                + data[deal].arrivalDate.day
                + "/" + data[deal].arrivalDate.month
                + "/" + data[deal].arrivalDate.year + " || " +
                "Cost:" + data[deal].cost +
                "</div>";
            document.getElementById("deal_listing").appendChild(dealDiv);
        }
    }, url);
}

function submitSearch(event) {
    event.preventDefault();
    let arrivalCity = document.forms["searchForm"].elements["arrivalCity"].value;
    let arrivalDate = document.forms["searchForm"].elements["arrivalDate"].value;
    let departureCity = document.forms["searchForm"].elements["departureCity"].value;
    let departureDate = document.forms["searchForm"].elements["departureDate"].value;
    let queryParams = "";
    if (arrivalCity !== "")
        queryParams += "arrivalCity=" + arrivalCity + "&";
    if (departureCity !== "")
        queryParams += "departureCity=" + departureCity + "&";
    if (arrivalDate !== "")
        queryParams += "arrivalDate=" + arrivalDate + "&";
    if (departureDate !== "")
        queryParams += "departureDate=" + departureDate + "&";
    getDeals(queryParams);
}
