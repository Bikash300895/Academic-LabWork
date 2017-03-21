<!DOCTYPE html>
<html>
<head>
	<title>Welcome</title>
</head>
<body>
	<div class="container">
		<?php
			$username = $_POST['Username'];
			$password= $_POST['Password'];

		    if($username=="bikash" && $password=="pass"){
		        echo "Welcome";
		    } else {
		    	echo "Username or password is incorrect";
		    }
		?>
	</div>
</body>
</html>