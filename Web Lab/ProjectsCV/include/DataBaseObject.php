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
    public static function find_all(){
        $sql = "select * from user";
        return self::find_by_sql($sql);
    }

    public static function find_by_sql($sql=""){
        global $database;
        $result_set = $database->query($sql);
        $object_array = array();

        while ($row = $database->fetch_array($result_set)){
            $object_array[] = $row;
        }

        return $object_array;

    }
}