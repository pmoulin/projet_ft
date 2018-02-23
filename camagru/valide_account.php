<?php
require_once('config/dbc.php');
require_once('header_no_log.html');
	if ($_GET['id'] != "")
	{
		$r = $dbh->query("SELECT id, login, passwd, valide_account FROM users");
		$valide = -1;
		while ($data = $r->fetch())
		{
			if ($data['valide_account'] != "valide" && $data['valide_account'] == $_GET['id'])
			{
				$valide = 1;
				$data['valide_account'] = "valide";
				$r = $dbh->exec("UPDATE users SET valide_account=\"valide\" WHERE id=".$data['id']."");
				break ;
			}
		}
		if ($valide == -1)
		{
			echo ("<html><body><center><div title=\"block connexion\" class=\"cadre_conex\">");
			echo ("lien de validation invalide ou deja utiliser.");
			echo("</div></center></html></body>");

		}
		else
		{
			echo ("<html><body><center><div title=\"block connexion\" class=\"cadre_conex\">");
			echo "your account is valided";
			echo("</div></center></html></body>");
		}

	}
	else
	{
		echo ("<html><body><center><div title=\"block connexion\" class=\"cadre_conex\">");
		echo("Vous náve rien a faire ici");
		echo("</div></center></html></body>");
	}
?>
