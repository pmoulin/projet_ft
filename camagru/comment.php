<?php
session_start();
if ($_SESSION['login'] != "")
{
	require_once('config/dbc.php');
	require_once('header_user_log.html');
	if ($_POST['comment'] != "" && $_GET['id'] != "")
	{
		if (strlen($_POST['comment']) <= 1000)
		{
			if ($dbh->exec("INSERT INTO `comment` (`id_user`, `name_img`, `login_user`, `content`) VALUES ('".$_SESSION['id']."', '".$_GET['id']."', '".$_SESSION['login']."', '".$_POST['comment']."')"))
			{
				if ($r = $dbh->exec("UPDATE `galerie` SET nb_comment = nb_comment + 1 WHERE name_img = '".$_GET['id']."'"))
				{
					$r = $dbh->prepare("SELECT id_user FROM galerie WHERE name_img = :name_img");
					$rez = $r->execute(array("name_img" => $_GET['id']));
					$rez = $r->fetch();
					$r = $dbh->prepare("SELECT mail, notif FROM users WHERE id = :id_usr");
					$r->execute(array("id_usr" => $rez['id_user']));
					$rez = $r->fetch();
					if ($rez['notif'] == 1)
					{
						$r = NULL;
						$content = "Your image has been commented http://localhost:8080/comment.php?id=".$_GET['id']."\ncontent :\n\"".$_POST['comment']."\"";
						if(mail($rez['mail'], "notification comment" ,$content))
							echo "SEND";
						$rez = NULL;
					}
					else
					{
						echo "no send";
						$rez = NULL;
						$r = NULL;
					}
				}
			}
		}
		else
			echo "your comment not valid <br />";
	}
	$r = $dbh->prepare("SELECT image, nb_like, nb_comment FROM `galerie` WHERE name_img = :img");
	$r->execute(array("img" => $_GET['id']));
	$rez = $r->fetch();
	echo "<center><img style='width:30%;height:auto;'src='".$rez['image']."'/></center>";
//////// formu add com
	echo "<div class='comment'><form method=\"POST\" action=\"./comment.php?id=".$_GET['id']."\">";
	echo "<div class='comment'><div class ='header_comment'>Auteur : ".$_SESSION['login']."<br /></div>";
	echo "<div class='content_comment'><br /><textarea style='width:100%; height:100px;' name=\"comment\">1000 carac max</textarea></div>";
	echo "<input value=\"send\" type=\"submit\"/></div>";
	echo "</form>";
	//////// cahrgement com
	$r = NULL;
	$r = ("SELECT name_img, content, add_date, login_user, id FROM `comment` WHERE name_img = '".$_GET['id']."' ORDER BY `add_date` DESC");
//liste commentaire
	foreach ($dbh->query($r) as $key)
	{
		echo "<div class='comment'><div class ='header_comment'>Auteur : ".$key['login_user']."<br /><p2 style='display: inline-block;'>le ".$key['add_date']."</p2></div>";
		echo "<br /><br /><div class='content_comment'>".$key['content']. "</div></div>";
		echo "<br />";
	}
echo"</div>";
}/////////////////Creation table commentaire "id login name_img, content add_date"
else
{
require_once('config/dbc.php');
require_once('header_no_log.html');

	$r = $dbh->prepare("SELECT image, nb_like, nb_comment FROM `galerie` WHERE name_img = :img");
	$r->execute(array("img" => $_GET['id']));
	$rez = $r->fetch();
echo "<center><img style='width:30%;height:auto;'src='".$rez['image']."'/></center>";
//////// cahrgement com
	$r = NULL;
	$r = ("SELECT name_img, content, add_date, login_user, id FROM `comment` WHERE name_img = '".$_GET['id']."' ORDER BY `add_date` DESC");
//liste commentaire
foreach ($dbh->query($r) as $key)
{
	echo "<div class='comment'><div class ='header_comment'>Auteur : ".$key['login_user']."<br /><p2 style='display: inline-block;'>le ".$key['add_date']."</p2></div>";
	echo "<br /><br /><div class='content_comment'>".$key['content']. "</div></div>";
	echo "<br />";
}
echo"</div>";
}

?>
