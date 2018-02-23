<?php
require_once('config/dbc.php');
session_start();
	if ($error == NULL)
		$error = 0;
///////////// chioix des menu a afficher dans le header
if ($_SESSION['id'] != 0 && $_SESSION['login'] != "")
{
	require_once('header_user_log.html');
	echo ("<body><center><div title=\"block connexion\" class=\"cadre_conex\">");
	echo("<p>tu test deja connecter ". $_SESSION['login']. "</p><br /></div></center>");

}
else
{
			require_once('header_no_log.html');
/////////////////// debut insciption
			if ($_POST['login'] != "")
			{
				$error = 0;
				if ($_POST['passwd'] != $_POST['confirm_passwd'])
				{
					//pass non valide;
					$error = 3;
				}
				else if ($_POST['login'] == ""|| $_POST['passwd'] == "" || $_POST['confirm_passwd'] == "" || $_POST['mail'] == "")
				{
					// champs vide
					$error = 4;
				}
				else if ($_POST['login'] == $_POST['passwd'])
				{
					// pass = login
					$error = 5;
				}
				else if (strlen($_POST['passwd']) < 8 || strlen($_POST['passwd']) > 25)
				{
					$error = 7;
				}
				else
				{
					if ($r = $dbh->query("SELECT login, mail FROM users"))
					{
						while ($data = $r->fetch())
						{
							$error = 0;
							if ($_POST['login'] == $data['login'])
							{
								// login already used
								$error = 1;
								break ;
							}
							if ($_POST['mail'] == $data['mail'])
							{
								// mail already used
								$error = 2;
								break ;
							}
						}
						$r = NULL;
						if ($error == 0)
						{
							$message = "please click here for valided your account";
							$mail_hash = hash('whirlpool', $_POST['mail']);
							$login_hash = hash('whirlpool', $_POST['login']);
							$message_validate = hash('whirlpool',"".$mail_hash."&login=".$login);
							$link = "please for valided your account visit : <a href=\"http://localhost:8080/valide_account.php?id=".$message_validate. "\">here</a>";
							$passwd = hash('whirlpool', $_POST['passwd']);
							if ($r = $dbh->exec("INSERT INTO users (login, passwd, mail, valide_account) VALUES ('".$_POST['login']."', '".$passwd."', '".$_POST['mail']."','".$message_validate."')"))
							{
								if (mail($_POST['mail'], "valide your account" ,$link))
									echo ("SEND");
								else
								{
									echo("no send");
									echo ($message_validate."<br /.>".$link);
								}
								$error = -1;
							}
							else
								$error = 6;
						}
					}
					else
						echo "ERROR  REQUETE BDD<br />";
				}
			}
	if ($error != -1)
 	{
?>
	<body>
		<center><div title="block connexion" class="cadre_conex"> <!--- cadre du formulaire -->
		<?php
			if ($error == 1)
			{
				echo ("<div style=\"font-color:red\">Sorry, this login is already used</div><br />");
			}
			else if ($error == 2)
			{
				echo ("<div style=\"font-color:red\">sorry, this mail is already used</div><br />");
			}
			else if ($error == 3)
			{
				echo ("<div style=\"font-color:red\">Error : you enter two password diferent</div><br />");
			}
			else if ($error == 4)
			{
				echo ("<div style=\"font-color:red\">Error : please fill all fields</div><br />");
			}
			else if ($error == 5)
			{
				echo ("<div style=\"font-color:red\">Sorry : your pwd is identical as the login, please choose another pwd or login</div><br />");
			}
			else if ($error == 6)
			{
				echo ("<div style=\"font-color:red\">Error Connection BDD</div><br />");
			}
			else if ($error == 7)
			{
				echo ("<div style=\"font-color:red\">Mots de passe non valide il doit faire minimum 8 caracteres</div><br />");
			}
		?>
		<form method="POST" action="./inscription.php">
			<label>Login : </label>	<input name="login" type="TEXT" /><br />
			<label>Password : </label><input name="passwd" type="TEXT" /><br />
			<label>Confirmation : </label><input name="confirm_passwd" type="TEXT" /><br />
			<label>Adresse mail : </label><input name="mail" type="TEXT" /><br />
			<input name="valid" value="valid" type="submit"/>
		</form>
		</div></center>
	</body>
	</html>
<?php
	}
	else if ($error == -1)
	{
?>
	<body>
		<center><div title="block connexion" class="cadre_conex">
		<p style="font-color:red">Inscription successful</p>
		</div></center>
	</body>
	</html>
<?php
	}
}
?>
