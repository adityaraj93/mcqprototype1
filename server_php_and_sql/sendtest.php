<?php
	$host = "localhost";
	$username = "root";
	$pass = "";
	$db = "test" ;
	
	$conn = mysqli_connect($host, $username ,$pass, $db) ;
	
	$tn = $_GET['team'];
	$coll = $_GET['college'];
	$ns = $_GET['ns'];
    $name1 = $_GET['name1'];
    $usn1 = $_GET['usn1'];
    $email1 = $_GET['email1'];
    $phone1 = $_GET['phone1'];
	$ipaddress = $_SERVER['REMOTE_ADDR'];

    if($ns==2){
        $name2 = $_GET['name2'];
        $usn2 = $_GET['usn2'];
        $email2 = $_GET['email2'];
        $phone2 = $_GET['phone2'];
        $query2= "UPDATE teaminfo SET name2='".$name2."', usn2='".$usn2."',email2='".$email2."',phone2='".$phone2."' WHERE name='".$tn."'";
    }    
	$query = "insert into teaminfo(name,college,ns,name1,usn1,email1,phone1,ipaddress) values('".$tn."','".$coll."',".$ns.",'".$name1."','".$usn1."','".$email1."','".$phone1."','".$ipaddress."')";
	$res = mysqli_query($conn,$query);
	
	if (!$res){
		echo "0";
		exit(0);
	}
    if($ns==2){
        $res = mysqli_query($conn,$query2);
        if(!$res){
            echo "2";
            exit(0);
        }
    }
	echo "1";
?>