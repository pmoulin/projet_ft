<?php
require_once('config/dbc.php');
session_start();
// ----------------------------------------EXEMPLE
// $j = $dbh->query('SELECT * FROM users');
// 	while ($data = $j->fetch())
// 		echo $data['login'];

// $stmt = $dbh->prepare("INSERT INTO REGISTRY (name, value) VALUES (:name, :value)");
// $stmt->bindParam(':name', $name);
// $stmt->bindParam(':value', $value);


//-----------------------------------------EXEMPLE
		if ($_SESSION['id'] != 0 && $_SESSION['login'] != "")
		{
			require_once('header_user_log.html');
		}
		else
		{
			require_once('header_no_log.html');
		}
?>
	<body>
	<center><div class="all_cadre_center">

		<div class="cadre_center" title="Last add">
			<h1>last add</h1>
<?php
			$r = "SELECT image, name_img FROM `galerie` ORDER BY `add_date` DESC LIMIT 9";
			foreach ($dbh->query($r) as $key)
				echo "<a href='./galerie.php?id=".$key['name_img']."'><img  class='cadre_img' src='".$key['image']."'/></a>";
?>
		</div>
		<div class="cadre_center" title="Last most popular">
			<h1>MOST LIKE</h1>
<?php
			$r = "SELECT image, name_img FROM `galerie` ORDER BY `nb_like`  LIMIT 9";
			foreach ($dbh->query($r) as $key)
				echo "<a href='./galerie.php?id=".$key['name_img']."'><img  class='cadre_img' src='".$key['image']."'/></a>";
?>
		</div>
		<div class="cadre_center" title="Last most COMMENTED">
									<h1>top commented</h1>
<?php
						$r = "SELECT image, name_img FROM `galerie` ORDER BY `nb_comment` DESC LIMIT 9";
						foreach ($dbh->query($r) as $key)
							echo "<a href='./galerie.php?id=".$key['name_img']."'><img  class='cadre_img' src='".$key['image']."'/></a>";
?>
			</div>
			<div class="cadre_center" title="ramdon">
								<h1>ramdon</h1>
<?php
			$r = "SELECT image, name_img FROM `galerie` WHERE 1 ORDER BY RAND() DESC LIMIT 9";
			foreach ($dbh->query($r) as $key)
				echo "<a href='./galerie.php?id=".$key['name_img']."'><img  class='cadre_img' src='".$key['image']."'/></a>";
?>
			</div>
			</div></center>
	</body>
</html>
