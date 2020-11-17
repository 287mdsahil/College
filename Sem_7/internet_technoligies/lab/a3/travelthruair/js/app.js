function fetchDeals(callback) {
    fetch("api/deals", {"Content-Type": "application/json"})
        .then(response => {
            if (!response.ok) {
                console.log("Failed with HTTP code:" + response.status);
                return {};
            } else {
                return response.json();
            }
        })
        .then(data => {
            callback(data);
        })
        .catch(err => {
            console.log(err);
        });
}

function getDeals() {
    console.log("deals");
    fetchDeals((data) => {
        console.log(data);
        document.getElementById("deal_listing").innerHTML = "";
        for (var deal in data) {
            console.log(data[deal]);
            var dealDiv = document.createElement('div');
            dealDiv.innerHTML =
                "<div>" +
                "From:" + data[deal].departureCity + "\t" +
                "To:" + data[deal].arrivalCity + "\t" +
                "Cost:" + data[deal].cost +
                "</div>";
            document.getElementById("deal_listing").appendChild(dealDiv);
        }
    });
}
