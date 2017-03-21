<?php
include("dbcon.php"); 

$sql="DELETE FROM Persons WHERE FirstName='$_POST[firstname]'";

if (!mysql_query($sql,$con))
  {
  die('Error: ' . mysql_error());
  }
echo "1 record deleted";

mysql_close($con)
?>