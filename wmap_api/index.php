<!DOCTYPE html>
<html lang="en">
<head>
  <script>
    function prov()
      {
        var uid1=obj[0][0];
        var lat1=obj[0][1];
        var lon1=obj[0][2];
        var pc1=obj[0][3];
        console.log(uid1,lat1,lon1,pc1);
        document.getElementById("uid").innerHTML=uid1;
        document.getElementById("lat").innerHTML=lat1;
        document.getElementById("lon").innerHTML=lon1;
        document.getElementById("pc").innerHTML=pc1;
      }
  </script>
  <style>
      @import 'https://fonts.googleapis.com/css?family=Raleway';
       #map {
        height: 400px;
        width: 100%;
       }
       #tabi
       {
          background: #0575E6;  /* fallback for old browsers */
          background: -webkit-linear-gradient(to right, #021B79, #0575E6);  /* Chrome 10-25, Safari 5.1-6 */
          background: linear-gradient(to right, #021B79, #0575E6); /* W3C, IE 10+/ Edge, Firefox 16+, Chrome 26+, Opera 12+, Safari 7+ */
          width:100%;
          margin:0px;
          font-family: Raleway;
          font-color:white;
       }
       .red .active a,
       .red .active a:hover 
       {
            background-color:yellow;
        }
    </style>
  <title>Transport information system</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
 
</head>
<body>

<div id="tabi" class="container">
  
  <h3 style="color:white;">Transport information system</h3>
  <ul class="nav nav-pills red" data-tabs="tabs">
    <li class="active"><a href="#loc" data-toggle="tab">Location</a></li>
    <li><a href="#det" data-toggle="tab">Details of bus</a></li>
    <li><a href="#ab" data-toggle="tab">About</a></li>
  </ul>
  </div>
  <div class="tab-content" style="font-family:Raleway;">
    <div class="tab-pane fade in active" id="loc">
      <div id="map"></div>
        <script>
          var obj;
          $.ajax({
                  url : 'ser.php', // your php file
                  type : 'GET', // type of the HTTP request
                  success : function(data){
                                obj = jQuery.parseJSON(data);
                                console.log(obj);
                  }
            });
      function initMap() 
      {
        var uluru = {lat: obj[0][1], lng: obj[0][2]};
        var map = new google.maps.Map(document.getElementById('map'), {
          zoom: 18,
          center: uluru
        });
         var contentString = '<div id="content">'+
            '<div id="siteNotice">'+
            '</div>'+
            '<h1 id="firstHeading" class="firstHeading">VIT bus stop</h1>'+
            '<div id="bodyContent">'+'<br> Speed:'+obj[0][3]+'<br>Distance:'+obj[0][4]+
            '</div>'+
            '</div>';
        var infowindow = new google.maps.InfoWindow({
          content: contentString
        });
        var marker = new google.maps.Marker({
          position: uluru,
          map: map,
          title:'VIT bus stop'
        });
        marker.addListener('click',function(){
          infowindow.open(map,marker);
        });
      }
      
    </script>
    <script async defer
    src="https://maps.googleapis.com/maps/api/js?key=AIzaSyA4lf0e57xhXg_AAB40Si-lwjlPq2VfET4&callback=initMap">
    </script>


    </div>
    <div class="tab-pane fade" id="det">
    




    </div>
    <div class="tab-pane fade" id="ab">
        <div class="well">
      <h> Developed by <br> S.Abhishek 16BCE1246 <br> Arshad 16BCE1275 </h3>
        </div>


    </div>
  </div>
</div>
</body>
</html>
</html>