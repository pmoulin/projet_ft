<?php
session_start();
if (($_SESSION['login'] == "" && $_SESSION['id'] == "") || ($_SESSION['login'] == "" && $_SESSION['id'] == -1))
{
	require_once('config/dbc.php');
	require_once('header_no_log.html');

	if ($_POST['valid'] == "valid")
	{
		if ($_POST['mail'] != "")
		{
			$key = md5(uniqid(rand(), true));
			$content = "New passwd: http://localhost:8080/reset_passwd.php?id=".$key;
			$r = $dbh->prepare("UPDATE users SET reset_passwd = '".$key."' WHERE mail = :mail_usr");
			echo $_POST['mail'];
			$r->execute(array("mail_usr" => $_POST['mail']));
				// echo "fail02";
			if (mail($_POST['mail'], "resset password", $content))
				echo "send";
			else
				echo "fail send mail";
		}
	}
	else if ($_POST['valid'] == "modifier")
	{
		if ($_POST['new_passwd'] == $_POST['verif_new_passwd'] && strlen($_POST['new_passwd']) >= 8)
		{
			$r = $dbh->prepare("SELECT id FROM users WHERE reset_passwd = :link_pass");
			if ($r->execute(array("link_pass" => $_GET['id'])))
			{
				$rez = $r->fetch();
				print_r($rez);
				echo "R ====";
				echo $rez['id'];
				echo "<br />";
				$new_pass = hash('whirlpool', $_POST['new_passwd']);
				$r = $dbh->prepare("UPDATE users SET passwd = :new_pass WHERE id = ".$rez['id']."");
				if ($r->execute(array("new_pass" => $new_pass)))
					$dbh->exec("UPDATE users SET reset_passwd = '0' WHERE id = ".$rez['id']."");
				echo "<br />YOUR passwd changed";
			}
		}
		else
			echo "your passwd is incorect";

	}
	if ($_GET['id'] != "")
	{
		$r = $dbh->prepare("SELECT reset_passwd FROM users WHERE reset_passwd = :link_pass");
		if ($r->execute(array("link_pass" => $_GET['id'])))
		{
			echo "<html><center><body>";
			echo "<form method=\"POST\" action=\"./reset_passwd.php?id=".$_GET['id']."\">";
			echo "<label>new_pass : </label><input name=\"new_passwd\" type=\"password\" /><br />";
			echo "<label>confirm_new_pass : </label><input name=\"verif_new_passwd\" type=\"password\" /><br />";
			echo "<input name=\"valid\" value=\"modifier\" type=\"submit\"/></form>";
			echo "</html></center></body>";
		}
	}
	if ($_GET['id'] == "")
	{
		echo "<html><center><body>";
		echo "<form method=\"POST\" action=\"./reset_passwd.php\">";
		echo "<label>Your mail : </label><input name=\"mail\" type=\"email\" /><br />";
		echo "<input name=\"valid\" value=\"valid\" type=\"submit\"/></form>";
		echo "</html></center></body>";
	}
}
else
{
	require_once('header_user_log.html');
	echo "already login";
}
?>
