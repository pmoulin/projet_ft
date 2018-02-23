<?php
session_start();
	require_once('header_no_log.html');
	if ($_SESSION['login'] != "" && $_SESSION['id'] > 0)
	{
		$delog = 1;
		$_SESSION['login'] = NULL;
		$_SESSION['id'] = 0;
	}
	else
		$delog = 2;
 ?>
	<center><div title="block connexion" class="cadre_conex">
<?php
	if ($delog == 1)
		echo ("cliquer<a style=\"color:red\"name=\"ici\" href=\"index.php\"> ici </a> pour retourner a l index ");
	else if ($delog == 2)
		Echo ("Vous návez rien a faire ici");
?>
	</center></div>
	</body>
	</html>
