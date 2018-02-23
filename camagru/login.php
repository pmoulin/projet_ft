<?php

require_once('config/dbc.php');
session_start ();
$error == 0;
if ($_SESSION['login'] != "" && $_SESSION['id'] > 0)
{
	$error = -2;
	// echo("<p>tu test deja connecter ". $_SESSION['login']. "<br />");
	require_once('header_user_log.html');
}
else
{
	require_once('header_no_log.html');
	$_SESSION['id'] = -1;
	if ($_POST['valid'] == "valid" && ($_POST['login'] == "" || $_POST['passwd'] == ""))
		$error = 1;
	if ($_POST['valid'] == "valid")
	{
			if($r = $dbh->query("SELECT id, login, passwd FROM users"))
				echo "";
			else
				echo ("REQUET ERROR");
			$_SESSION['id'] = 0;
			while ($data = $r->fetch())
			{
				if ($data['login'] == $_POST['login'])
				{
					if (($ph = hash('whirlpool', $_POST['passwd'])) == $data['passwd'])
					{
							$_SESSION['login'] = $data['login'];
							$_SESSION['id'] = $data['id'];
							echo ($_SESSION['login']);
							echo ($_SESSION['id']);
							$error = -1;
							break ;
					}
					else
					{
						$error = 3;
						break ;
					}
				}
			}
			if ($error == 0)
				$error = 2;

	}
}
?>
	<body>

		<center><div title="block connexion" class="cadre_conex">
<?php
	if ($_SESSION['id'] != 0 && $_SESSION['login'] != "" && $error != -2)
	{
		echo("<p>Welcome ". $_SESSION['login']. "<br />");
		echo ("cliquer<a style=\"color:red\"name=\"ici\" href=\"index.php\"> ici </a> pour retourner a l index ");
	}
	else
	{
		if ($error == 1)
			echo ("<div style=\"font-color:red\">Error : please fill all fields</div><br />");
		else if ($error == 2)
			echo ("<div style=\"font-color:red\">Error : the login is false</div><br />");
		else if ($error == 3)
			echo ("<div style=\"font-color:red\">Error : your password is not match with login</div><br />");
		else if ($error == -2)
		{
			echo ("<div style=\"font-color:red\">Error : Your already connected</div><br />");
			echo ("<div style=\"font-color:red\">Please click <a style=\"color:red\"href=\"index.php\"> here </a> to return a index</div><br />");
		}
		if ($error != -2)
		{
?>
			<form method="POST" action="./login.php">
				<label>Login : </label>	<input name="login" type="TEXT"/>
				<label>Password : </label><input name="passwd" type="TEXT"/>
				<input name="valid" value="valid" type="submit"/>
			</form>
<?php
		}
	}
?>
		</div></center>
	</body>
</html>
