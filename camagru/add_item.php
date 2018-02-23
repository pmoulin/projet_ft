<?php
require_once('config/dbc.php');
session_start();
$error = 0;
	echo ($_POST['send']);
	echo ($_POST['img']);
				echo $_FILES['upload']['tmp_name'];

	if ($_SESSION['id'] != 0 && $_SESSION['login'] != "")
	{
		require_once('header_user_log.html');
		if ($_POST['send'] == 'Submit')
		{
			echo ("oco");
				if ($_FILES['upload']['error'] > 0)
					echo "error upload";
				else if ($_FILES['upload']['size'] > 2097152)
					echo "file trop grand";
				else
				{
					echo "galerie/".$_SESSION['login']."/";
					if (!is_dir("./galerie"))
						mkdir('galerie', 0733, true);
					else
						echo "fil already exist galerie";;
					if (!is_dir("galerie/".$_SESSION['login']))
						mkdir("galerie/".$_SESSION['login']."/", 0733, true);
					else
						echo "file already existe login";
					$name = md5(uniqid(rand(), true));
					$acces_img = "galerie/".$_SESSION['login']."/".$name;
					if ($data = $r->query("SELECT MAX(id) AS max_id, id FROM galerie"))
					{
						if ($data['max_id'] == "")
							$data['max_id'] == "1";
					}
					else
						echo "fuck";
					if (move_uploaded_file($_FILES['upload']['tmp_name'] , "galerie/".$_SESSION['login']."/".$data['max_id']."jpg"))
						echo "move good";
					else
						echo "move_imposible";
				}
				$r->exec("INSERT INTO galerie (login, image) VALUES ('".$_SESSION['login'].",".$data['max_id'].".jpg')");
				// echo "<img src='data:image/png;base64,".$_POST['img']."'>\n";
		}
	}
	else
 	{
		require_once('header_no_log.html');
	}


?>

<html>
<body>
<form method="post" action="upload_img.php" enctype="multipart/form-data">
	<input type="file" name="upload" />
	<input type="submit" name="send" />
</form>


</body>
</html>
