<?php
	mysql_connect('localhost','root','root') or
    die("Could not connect: " . mysql_error());;
	mysql_select_db('bopl');
	if(isset($_GET['type'])){
		$type =$_GET['type'];
	} else {
		$type = "lang";
	}
	if(isset($_GET['param'])){
		$param = $_GET['param'];
	} else {
		$param = "c";
	}
	switch($type){
		case "lang":
				$table = "lang";
			break;

	}
	switch ($param){
		case "c":
				$clause = "";
				break;
	}
	$query = "select * from $table ".$clause;
	$result=mysql_query($query);
	$return="";
	while($row=mysql_fetch_array($result)){
		$return .= "<tr>";
		$return .= "</tr>";
	}

?>
