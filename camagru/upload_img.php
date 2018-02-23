<?php
require_once('config/dbc.php');
session_start();
$error = 0;
	if ($_SESSION['id'] != 0 && $_SESSION['login'] != "")
	{
		require_once('header_user_log.html');
		if ($_POST['send'] == 'Submit')
		{/////////////////////////////////////////////////////////////////////////////////////////////////////////reste gere les .jpg.exe
				$extension = substr($_FILES['upload']['name'], -3, 3);
				if ($extension != "jpg" && $extension != "png" && $extension != "PNG" && $extension != "JPG")
					$error = 3;
				else if ($_FILES['upload']['error'] > 0)
					$error = 1;
				else if ($_FILES['upload']['size'] > 2097152)
					$error = 2;//echo "file trop grand";
				else if ($_FILES == NULL)
					$error = 2;
				else
				{
					echo "galerie/".$_SESSION['id']."/";
					if (!is_dir("./galerie"))
						mkdir('galerie', 0733, true);
					if (!is_dir("galerie/".$_SESSION['id']))
						mkdir("galerie/".$_SESSION['id']."/", 0733, true);
					$name = md5(uniqid(rand(), true));
					$acces_img = "galerie/".$_SESSION['id']."/".$name.".jpg";
					if (move_uploaded_file($_FILES['upload']['tmp_name'] , $acces_img))
						$error = -1;
					else
						$error = 1; // error add photo to folder
				}
				if ($error == -1 && $dbh->prepare("INSERT INTO galerie (id_user, image, name_img) VALUES ('".$_SESSION['id']."','galerie/".$_SESSION['id']."/".$name.".jpg', '".$name.".jpg')")->execute())
				{
						$error = -1;
				}
				else if ($error == 0)
				{
						$error = 4;
				}

		 }
	}
	else
 	{
		require_once('header_no_log.html');
	}
?>
<html>
	<body>
		<center><div title="block connexion" class="cadre_conex"> <!--- cadre du formulaire -->
		<form method="post" action="upload_img.php" enctype="multipart/form-data">
			<input type="file" name="upload" />
			<input type="submit" name="send" />
		</form>
		<br/>
		<?php
 			if ($error == -1)
				echo "<p>your photo is add to your galerie</p><br /><img style=\"widht:50%;height:50%;\" src=\"".$acces_img."\" alt=\"upload\">";
			else if ($error == 1)
				echo "<p>Error while upload file</p>";
			else if ($error == 2)
				echo "<p>Sorry your files are too big";
			else if ($error == 3)
				echo "<p>Please upload only .jpg and .png</p>";
			else if ($error == 4)
				echo "<p>Error bdd</p>";?>
		</center>
		</div>
	</body>
</html>
