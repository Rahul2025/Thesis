<?php
	mysql_connect('localhost','bopl','bopl') or
    die("Could not connect: " . mysql_error());;
	mysql_select_db('bopl');
	if(isset($_GET['type'])){
		$type =$_GET['type'];
	} else {
		$type = "attribute";
	}
	if(isset($_GET['param'])){
		$param = $_GET['param'];
	} else {
		$param = "compile_memory";
	}
	$return="<table>";
	switch($type){
		case "lang":
				$table = "lang";
			break;
		case "attribute":
				$table= "Final_".$param;
				$return .= "<tr><th>ID</th><th>C</th><th>C++</th><th>Haskell</th><th>Java</th><th>Python</th><th>Cython</th></tr>";
				break;

	}
	switch ($param){
		case "c":
				$clause = "";
				break;
		default:
				$clause="";
	}
	$query = "select * from $table ".$clause;
	$result=mysql_query($query);
	while($row=mysql_fetch_row($result)){
		$return .= "<tr>";
		for($j = 0; $j < count($row); $j++) {
     		   $return .= "<td>".$row[$j]."</td>";
    		}	
		$return .= "</tr>";
	}
	$return .= "</table>";
	echo $return;
?>
