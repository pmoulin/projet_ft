<?php
require_once('config/database.php');
require_once('config/dbc.php');
require_once('header_user_log.html');

session_start ();

	if ($_SESSION['id'] == "" || $_SESSION['login'] == "")
	{
		echo ("<html><body><center><div title=\"block connexion\" class=\"cadre_conex\">");
		echo("Vous n'avez rien a faire ici");
		echo("</div></center></html></body>");
	}
	////////// a finir

?>
<html>
<body>
	<div class="menu_member_left" name="menu_left">
		<center><h1>Information : </h1></center><br /><br />
		<h1>Login/speudo :</h1><br /> SEGHERTHEGFSDADFGHGMMJHNFGBVDCSXASDFNJMHNGB
		<h1>Mail :</h1><br />owhrgihregihrgnr@rohborjgr.com
		<h1>date insciption :</h1><br /> 21/21/21;
		<form method="post" action="./modif_account.php"> <!--- modifier le lien ?? -->
		<input name="valid" value="Modifier" type="submit"/>
		</form>
	</div>
	<div class="menu_member_center" name="menu_center">
		<center><h1>Statistic : </h1></center><br /><br />
		<h1>Vous avez ajouter au total X photo dans votre galerie</h1><br />
		<h1>Un total de X Likes pour lénsemble de votre galerie</h1><br />
		<h1>Votre galerie a recu X commentaire</h1><br />
		<h1>límage la plus commenter a recu X commentaires</h1><br />
		<h1>l'image la qui a recu le plus populaire de votre galerie a recu Xlike</h1><br />
	</div>
	<!-- <div class="menu_member_right" name="menu_right">
		<center><h1>dernier ajout : </h1></center><br /><br />
	</div> -->

</body>
</html>
