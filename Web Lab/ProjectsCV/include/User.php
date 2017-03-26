<?php

/**
 * Created by PhpStorm.
 * User: bikas
 * Date: 3/27/2017
 * Time: 12:23 AM
 */
require_once ('include.php');

class User extends DataBaseObject
{
    public $id;
    public $user_name;
    public $password;
}