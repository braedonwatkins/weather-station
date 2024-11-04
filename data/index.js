// Create events for the sensor readings
if (!!window.EventSource) {
  var source = new EventSource("/events");

  source.addEventListener(
    "open",
    function (e) {
      console.log("Events Connected");
    },
    false,
  );

  source.addEventListener(
    "error",
    function (e) {
      if (e.target.readyState != EventSource.OPEN) {
        console.log("Events Disconnected");
      }
    },
    false,
  );

  source.addEventListener(
    "BME_readings",
    function (e) {
      //console.log("gyro_readings", e.data);
      var obj = JSON.parse(e.data);
      document.getElementById("in_temperature").innerHTML = obj.in_temperature;
      document.getElementById("in_temperatureD").innerHTML =
        obj.in_temperatureD;
      document.getElementById("in_humidity").innerHTML = obj.in_humidity;
      document.getElementById("in_presssure").innerHTML = obj.in_presssure;
      document.getElementById("in_altitude").innerHTML = obj.in_altitude;
    },
    false,
  );
  source.addEventListener(
    "OWM_readings",
    function (e) {
      //console.log("gyro_readings", e.data);
      var obj = JSON.parse(e.data);
      document.getElementById("out_temperature").innerHTML =
        obj.out_temperature;
      document.getElementById("out_temperatureD").innerHTML =
        obj.out_temperatureD;
      document.getElementById("out_humidity").innerHTML = obj.out_humidity;
      document.getElementById("weather_icon").src = obj.weather_icon;
      document.getElementById("Sunset").innerHTML = timeConverter(obj.Sunset);
      document.getElementById("Sunrise").innerHTML = timeConverter1(
        obj.Sunrise,
      );
    },
    false,
  );
}

//block.setAttribute("style", "text-align:center");
function resetPosition(element) {
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/" + element.id, true);
  console.log(element.id);
  xhr.send();
}

function timeConverter(UNIX_timestamp) {
  var a = new Date(UNIX_timestamp * 1000);
  var hour = a.getHours();
  var min = a.getMinutes();
  var time = hour + ":" + min;
  return time;
}
function timeConverter1(UNIX_timestamp) {
  var a = new Date(UNIX_timestamp * 1000);
  var hour = a.getHours();
  var min = a.getMinutes();
  var time = "0" + hour + ":" + min;
  return time;
}
