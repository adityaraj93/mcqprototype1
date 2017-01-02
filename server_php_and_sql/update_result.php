<?php
	$host = "localhost";
	$username = "root";
	$pass = "";
	$db = "test" ;
	
	$conn = mysqli_connect($host, $username ,$pass, $db) ;
	
	$name = $_GET['name'];
	$score = $_GET['score'];
	$time = $_GET['time'];
	
	$query = "UPDATE teaminfo SET score=".$score.", time=".$time." WHERE name='".$name."'";
	
	$res = mysqli_query($conn,$query);
	
	if (!$res){
		print("0");
		exit(0);
	}
	echo "1";
	
?>