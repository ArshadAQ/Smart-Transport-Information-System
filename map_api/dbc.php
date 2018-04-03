<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "micro";

// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);

// Check connection
if (!$conn) 
{
    die("Connection failed: " . mysqli_connect_error());
}
$uid=$_GET["uid"];
$lat=$_GET["lat"];
$lon=$_GET["lon"];
$sp=$_GET["sp"];
$c=$_GET["c"];
$d=$_GET["d"];

//$sql = "INSERT INTO bus (uid,latitude,longitude,speed,count,distance) VALUES ($uid,$lat,$lon,$sp,$c,$d)";
$sql ="UPDATE bus SET latitude=$lat,longitude=$lon,speed=$sp,count=$c,distance=$d WHERE uid=$uid";
if (mysqli_query($conn, $sql)) 
{
    echo "New record created successfully";
} 
else 
{
    echo "Error: " . $sql . "<br>" . mysqli_error($conn);
}

mysqli_close($conn);
?>

