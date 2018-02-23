<?php
session_start();
require_once('config/dbc.php');
if ($_SESSION['login'] != "" && $_SESSION['id'] != "")
	require_once('header_user_log.html');
else
	require_once('header_no_log.html');
if ($_GET['page'] == "")
	$_GET['page'] = 1;
if ($_GET['id'] != "")
{
		echo "<body>";
		$r = $dbh->prepare("SELECT image, nb_like, nb_comment FROM `galerie` WHERE name_img = :img");
		$r->execute(array("img" => $_GET['id']));
		$rez = $r->fetch();
		echo "<center><div id=\"image_full\">";
		echo "<center><img class='image_center_full' src=\"".$rez['image']."\" />";////////////////// voir cette ptn de taille ..................
		echo "<div id=\"likesandcom\">";
		echo "<a id=\"Comment\" href=\"comment.php?id=".$_GET['id']."\">".$rez['nb_comment']." Comment</a><br />";
		echo "<a id=\"Like\"> ".$rez['nb_like']." Likes</a></div>";
		echo "</div></center></center></body>";
}
else
{
	if ($_GET['page'] == "" || $_GET['page'] == 0)
 		$nb = 0	;
	else
		$nb = 5 * $_GET['page'];
	$i = $nb - 5;
	$id = 0;
	$r = "SELECT * FROM galerie LIMIT 5 OFFSET ".$i."";
	echo "<html><body><center><div class=\"galerie\">";
	foreach ($dbh->query($r) as $key)
	{
		$id++;
		echo "<a href=\"./galerie.php?id=".$key['name_img']."\"><img class='cadre_img_galerie'src=\"".$key['image']."\" /></a>";

	}
	if ($_GET['page'] > 1)
	{
		$old = $_GET['page'] - 1;
		echo "<form method=\"GET\" action=\"./galerie.php\"><input type=\"submit\" name=\"page\" value='".$old."'/>";
	}
	if ($id == 5)
	{
		$next = $_GET['page'] + 1;
		echo "<form method=\"GET\" action=\"./galerie.php\"><input type=\"submit\" name=\"page\" value='".$next."'/>";
	}
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
// echo "<img  class=\"cadre_img_galerie\" src=\"ressources/chinchilla.jpg\"/>";
echo "</div></center></body></html>";
}
?>
