<!DOCTYPE html>
<html>
<head>
    <title>Log in Page</title>
    <link rel="stylesheet" type="text/css" href="css/bootstrap.min.css">
</head>
<body>

<?php
require_once ('../include/include.php');

if (isset($_POST['Username']) && isset($_POST['Password'])) {
    $username = $_POST['Username'];
    $password = $_POST['Password'];

    if ($username == "bikash" && $password == "pass") {
        ?>
        <nav class="navbar navbar-inverse">
            <div class="container-fluid">
                <!-- Brand and toggle get grouped for better mobile display -->
                <div class="navbar-header">
                    <button type="button" class="navbar-toggle collapsed" data-toggle="collapse"
                            data-target="#bs-example-navbar-collapse-1" aria-expanded="false">
                        <span class="sr-only">Toggle navigation</span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                    </button>
                    <a class="navbar-brand" href="#">CV</a>
                </div>

                <!-- Collect the nav links, forms, and other content for toggling -->
                <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
                    <ul class="nav navbar-nav">
                        <li class="active"><a href="#">Home <span class="sr-only">(current)</span></a></li>
                        <li><a href="about_me.html">About Me</a></li>
                        <li><a href="education.html">Education</a></li>
                        <li><a href="contact.html">Contact</a></li>

                    </ul>
                    <ul class="nav navbar-nav navbar-right">
                        <li><a href="#">Shuvendu Roy</a></li>

                    </ul>
                </div><!-- /.navbar-collapse -->
            </div><!-- /.container-fluid -->
        </nav>

        <div class="container">
            <h1 class="home_header">Welcome</h1>
            <p class="text_center">I am Shuvendu Roy and i am a software developer. You can contact or check my online
                profile from this website</p>

        </div>

        <?php

    } else {
        echo "Username or password is incorrect";
    }
} else {
    ?>
    <div class="container">
        <div class="wrapper">
            <form action="index.php" method="post" name="Login_Form" class="form-signin">
                <h3 style="text-align: center;" class="form-signin-heading">Welcome Back! Please Sign In</h3>
                <hr class="colorgraph">
                <br>

                <input type="text" class="form-control" name="Username" placeholder="Username" required=""
                       autofocus=""/>
                <input type="password" class="form-control" name="Password" placeholder="Password" required=""/>

                <button class="btn btn-lg btn-primary btn-block" name="Submit" value="Login" type="Submit">Login
                </button>
            </form>
        </div>
    </div>

    <?php

}
?>

</body>
</html>

