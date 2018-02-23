<?php
require_once('config/database.php');
if ($Co_sql = new PDO('mysql:host=localhost', $DB_USER, $DB_PASSWORD))
	echo "CONEC SQL GOOD <br />";
else
	echo "Error comnnection sql serveur";
if (!($Co_sql->exec("CREATE DATABASE IF NOT EXISTS camagru")))
	echo ("ERROR CRREATION DATABASE camagru <br />");
else
	echo "database camagru create <br />";
$Co_sql = NULL;

require_once('config/dbc.php');

if (!($dbh->query("CREATE TABLE IF NOT EXISTS comment (
`id` int(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
`id_user` varchar(255) NOT NULL,
`login_user` varchar(255) NOT NULL,
`name_img` varchar(255) NOT NULL,
`content` varchar(255) NOT NULL,
`add_date` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP)")))
	echo "table comment create fail<br />";
else
	echo "table comment create <br />";

if (!($dbh->query("CREATE TABLE IF NOT EXISTS galerie (
	`id` int(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
	`id_user` varchar(255) NOT NULL,
	`image` longtext NOT NULL,
	`name_img` varchar(255) NOT NULL,
	`nb_comment` int(255) NOT NULL DEFAULT '0',
	`nb_like` int(255) NOT NULL DEFAULT '0',
	`add_date` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP)")))
	echo "Error creation table galerie<br />";
else
    echo "Table galerie create ! <br />";

if (!($dbh->query("CREATE TABLE IF NOT EXISTS `users` (
	`id` int(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
	`login` char(255) NOT NULL,
	`passwd` char(255) NOT NULL,
	`mail` char(255) NOT NULL,
	`notif` INT(2) NOT NULL DEFAULT '1',
	`date creation` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
	`reset_passwd` VARCHAR(255) NOT NULL DEFAULT '0',
	`valide_account` char(255) NOT NULL
)")))
	echo "Error Creation table users <br />";
else
    echo "Table users create! <br />";

if (!($dbh->query("INSERT INTO `users` (`login`, `passwd`, `mail`, `date creation`, `valide_account`) VALUES
('phmoulin', 'b7352c249c7aff837ddf59b5a10b776cc913fc533c3ce64d74aea6e15ea90c7ca4cb63a190e136b20d0f08d321e0533683eebc4986e7ece6fb062e5f0e6306c2',
'philleouf@gmail.com', '2018-02-09 15:25:00', 'valide'),
('philippe', '344907e89b981caf221d05f597eb57a6af408f15f4dd7895bbd1b96a2938ec24a7dcf23acb94ece0b6d7b0640358bc56bdb448194b9305311aff038a834a079f',
'phmoulin42@gmail.com', '2018-02-09 16:45:09', '750a53321bebd80fd6d49ee11d267df37c26a3ef8819582f174114ead477f49f12de6a79c9ddecf564f85cf8c57fdfb538615cb06c4035d7e668737829a9c5ff')
")))
    echo "ERROR INSERT users <br />";
else
    echo "user add succes! <br />";
?>
