<?php
session_start();
require_once('config/dbc.php');
require_once('header_user_log.html');

echo $_POST['notif'];
		if ($_POST['Change_login'] == 'OK' && $_POST['login'] != "" && strlen($_POST['login']) < 15)
		{
			echo "modif account";
			$r = $dbh->prepare("SELECT login FROM `users` WHERE login = :login");
			$r->execute(array(
				"login"  => $_POST['login']));
			$rez = $r->fetch();
			if ($rez)
						echo "already used";
			else
			{
				if ($r = $dbh->exec("UPDATE users SET login='".$_POST['login']."' WHERE id = ".$_SESSION['id']))
				{
					echo ("succes login");
					$_SESSION['login'] = $_POST['login'];

				}
				else
					echo ("error db");
			}
		}
		else if ($_POST['Change_login'] == 'OK')
			echo "login vide || trop grand";
		if ($_POST['Change_password'] == "OK" && strlen($_POST['new_passwd']) > 8 && strlen($_POST['new_passwd']) < 25)
		{
				$r = $dbh->prepare("SELECT passwd FROM `users` WHERE passwd = :passwd");
				$r->execute(array("passwd" => hash('whirlpool', $_POST['old_passwd'])));
				$rez = $r->fetch();
				if (hash('whirlpool', $_POST['old_passwd'] == $rez['passwd']))
				{
					if ($_POST['new_passwd'] === $_POST['new_passwd_verif'])
					{

						$r = $dbh->prepare("UPDATE users SET passwd=:newpasswd WHERE id = ".$_SESSION['id']);
						if ($r->execute(array("newpasswd" => hash('whirlpool', $_POST['new_passwd']))))
 						{
							echo ("SUCCES");
						}
						else
							echo "error bdd";
					}
					else
						echo ("pas les meme pass");
				}
				else
					echo ("your old passwd is false");
		}
		else if ($_POST['Change_password'] == "OK" && (strlen($_POST['new_passwd']) < 8 || strlen($_POST['new_passwd']) > 25))
			echo ("> 8 | < 25 carac");
		if ($_POST['Change_mail'] == "OK" && $_POST['new_mail'] != "" && $_POST['new_mail_verif'] != "" && $_POST['new_mail'] == $_POST['new_mail_verif'] )
		{
			$r = $dbh->prepare("SELECT mail FROM `users` WHERE mail = :mail");
			$r->execute(array("mail" => $_POST['new_mail']));
			$rez = $r->fetch();
			if ($rez)
 			{
				echo "mail already used";
			}
			else
				if ($r = $dbh->exec("UPDATE users SET mail='".$_POST['new_mail']."' WHERE id = ".$_SESSION['id']))
					echo ("succes mail");
				else
					echo "error db";
		}
		elseif ($_POST['Change_mail'] == "OK")
			echo "error mail";
		if ($_POST['notif_mail'] == "OK")
		{
			if ($_POST['notif'] == "on")
			{
				if ($r = $dbh->exec("UPDATE users SET notif='1' WHERE id = ".$_SESSION['id']))
					echo ("succes notif");
				else
					echo "error db";
			}
			else
			{
				if ($r = $dbh->exec("UPDATE users SET notif='0' WHERE id = ".$_SESSION['id']))
					echo ("succes notif");
				else
					echo "error db";
			}
		}
?>
<html>
	<body>
		<center><div title="block connexion" class="cadre_conex"> <!--- cadre du formulaire -->
			<form method="POST" action="./modif_account.php"><br/>
				<label>modifer login:speudo : </label><input name="login" type="TEXT"/><br/>
				<input name="Change_login" value="OK" type="submit"/><br/>
			</form>
			<form method="POST" action="./modif_account.php">
				<label>old password : </label><input name="old_passwd" type="TEXT"/><br/>
				<label>new password : </label><input name="new_passwd" type="TEXT"/><br/>
				<label>verif new  password : </label><input name="new_passwd_verif" type="TEXT"/><br/>
				<input name="Change_password" value="OK" type="submit"/><br/>
			</form>
			<form method="POST" action="./modif_account.php"><br/>
				<label>modifer mail : </label><input name="new_mail" type="email"/><br/>
				<label>modifer mail : </label><input name="new_mail_verif" type="email"/><br/>
				<input name="Change_mail" value="OK" type="submit"/><br/>
			</form>
			<form method="POST" action="./modif_account.php">
				<label>recevoir notif : </label><input type="checkbox" name="notif"/>
			<input name="notif_mail" value="OK" type="submit"/><br/>
			</form>
		</div></center>
	</body>
	</html>
