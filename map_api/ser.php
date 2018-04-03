<?php
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "micro";

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    } 

    $sql = "SELECT * FROM bus";  //This is where I specify what data to query
    $result =mysqli_query($conn,$sql);
    $data=array();
    $row=mysqli_fetch_assoc($result);
    $a=array((int)$row['uid'],(int)$row['latitude'],(int)$row['longitude'],(int)$row['speed'],(int)$row['count'],(int)$row['distance']);
    array_push($data,$a);
    echo json_encode($data);
?>