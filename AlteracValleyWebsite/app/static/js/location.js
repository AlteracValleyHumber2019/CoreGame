x = navigator.geolocation;
x.getCurrentPosition(success, failure);
function success(position){
  console.log("i am here");
  console.log(position);
  var mylat = position.coords.latitude;
  var mylong = position.coords.longitude;
  console.log(mylat);
  console.log(mylong);

  var coords = new google.maps.LatLng(mylat, mylong);

  var mapOptions = {
    zoom : 16,
    center: coords,
    mapTypeId: google.maps.MapTypeId.ROADMAP
  };

  var map = new google.maps.Map(document.getElementById("map"), mapOptions);

  var marker = new google.maps.Marker({map:map, position: coords});
}

function failure(){
  $('#lat').html("<p> It didn't work</p>");
}