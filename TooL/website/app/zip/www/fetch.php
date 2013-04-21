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
	$id_number["basic"]=1;
	$id_number["graph"]=2;
	$id_number["misc"]=3;
	$id_number["np"]=4;
	$id_number["numerical"]=5;
	$id_number["web"]=6;
	switch($type){
		case "attribute":
				$return .= "<tr><th>ID</th><th>C</th><th>C++</th><th>Haskell</th><th>Java</th><th>Python</th><th>Cython</th></tr>";
				$query = "select * from Final_$param";
				break;
				break;
		case "domain":
				$return .= "<tr><th>ID</th><th>C</th><th>C++</th><th>Haskell</th><th>Java</th><th>Python</th><th>Cython</th></tr>";
				$id = $id_number[$param];
				$query = "SELECT * 
FROM Final_compile_memory
WHERE id = $id
UNION ALL SELECT * 
FROM Final_compile_time
WHERE id = $id
UNION ALL SELECT * 
FROM Final_LOC
WHERE id = $id
UNION ALL SELECT * 
FROM Final_run_memory
WHERE id = $id
UNION ALL SELECT * 
FROM Final_run_time
WHERE id = $id ";
				break;
		case "language":
				$return .= "<tr><th>Compile Memory</th><th>Compile Time</th><th>LoC</th><th>Runtime Memory</th><th>Runtime</th></tr>";
				$query = "SELECT k.$param, l.$param, m.$param, n.$param, o.$param
FROM Final_compile_memory AS k, Final_compile_time AS l, Final_LOC AS m, Final_run_memory AS n, Final_run_time AS o
WHERE k.id = l.id
AND l.id = m.id
AND m.id = n.id
AND n.id = o.id";
				break;

	}

	
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
