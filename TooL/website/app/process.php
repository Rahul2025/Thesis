<?php
	if(isset($_REQUEST['id']){
		move_uploaded_file($_FILES["source"]["tmp_name"],"upload/" . $_FILES["source"]["name"]);
		mysql_connect('localhost','bopl','bopl') or
    die("Could not connect: " . mysql_error());;
	mysql_select_db('bopl');
	$id = $_REQUEST['id'];
	$query="Select * from individual_stats where id = $id";
	$result=mysql_query($query);
	$stat=mysql_fetch_assoc($result);
	shell_exec("upload/input_run.sh $id");
	$ext = pathinfo($_FILES["source"]["name"], PATHINFO_EXTENSION);
	//read value from 'upload/stats' to $current['time'] $current['mem']
	$fp = fopen("upload/stats","r");
	$current['time']=fgets($fp,4096);
	$current['mem']=fgets($fp,4096);
	fclose($fp);
	if($current['time'] < $stat[$ext."_mem_time"] && $current['time'] < $stat[$ext."_time_time"]){
						$query="update individual_stats set $ext"."_time_time='".$current['time']."', $ext"."_time_mem='".$current['mem']."' where id=$id";
						mysql_query($query);
	}
	
	if($current['mem'] < $stat[$ext."_mem_mem"] && $current['mem'] < $stat[$ext."_time_mem"]){
						$query="update individual_stats set $ext"."_mem_time='".$current['time']."', $ext"."_mem_mem='".$current['mem']."' where id=$id";
						mysql_query($query);
	}
}
?>