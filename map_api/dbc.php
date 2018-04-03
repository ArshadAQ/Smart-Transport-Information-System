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

	$bus_id=$_GET["bus_id"];
	$curr_lat=$_GET["curr_lat"];
	$curr_lon=$_GET["curr_lon"];
	$sp=$_GET["sp"];
	$pc=$_GET["pc"];
	$d=$_GET["d"];

	//$sql = "INSERT INTO bus (bus_id,curr_latitude,curr_longitude,speed,count,distance) VALUES ($bus_id,$curr_lat,$curr_lon,$sp,$c,$d)";
	$sql ="UPDATE bus SET curr_latitude=$curr_lat,curr_longitude=$curr_lon,speed=$sp,count=$pc WHERE bus_id=$bus_id";
	if (mysqli_query($conn, $sql)) 
	{
	    echo "New record created successfully";
	} 
	else 
	{
	    echo "Error: " . $sql . "<br>" . mysqli_error($conn);
	}

	$sql ="UPDATE distance_to_stops SET VIT=$d[0],kandigai=$d[1],Vandalur=$d[2],Perungalathur=$d[3],Tambaram=$d[4] WHERE bus_id=$bus_id";
	
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

