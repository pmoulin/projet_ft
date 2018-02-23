<?php
require_once('config/database.php');

	$dbh = new PDO('mysql:host=localhost;dbname='.$DB_DSN, $DB_USER, $DB_PASSWORD);
	return ($dbh);
?>
