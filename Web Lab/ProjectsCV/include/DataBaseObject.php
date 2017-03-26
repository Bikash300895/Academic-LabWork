<?php

/**
 * Created by PhpStorm.
 * User: bikas
 * Date: 3/27/2017
 * Time: 12:25 AM
 */
require_once ('include.php');

class DataBaseObject
{
    public static function find_by_sql($sql=""){
        global $database;
        $result = $database->query($sql);
        $result_set = $database->fetch_array($result);

        return $result_set;

    }
}