<?php
/**
 * Created by PhpStorm.
 * User: bikash
 * Date: 3/26/2017
 * Time: 11:37 PM
 */

require_once ('config.php');

class MySQLDatabase{
    private $connection;

    function __construct()
    {
//        echo "database connection call";
        $this->open_connection();
    }

    public function open_connection(){
        $this->connection = mysqli_connect(DB_SERVER, DB_USER, DB_PASS, DB_NAME);
        if(mysqli_errno($this->connection)){
            die("Database connection failed: " .
                mysqli_connect_error().
                "(" . mysqli_connect_errno(). ")"
            );
        }
    }
}

$database = new MySQLDatabase();
$db = & $database;

?>