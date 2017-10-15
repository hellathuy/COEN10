<html>
<body style="background-color:#CCFFCC">

<?php
        $guess=$_POST["guess"];

	echo "THE NUMBERS CHOSEN ARE ";
        
	for ($i=0; $i < 5; $i++) {
		$numbers[$i]=rand(1,20);
		echo $numbers[$i] . ", ";
	}
	
	$count=0;
	$size=count($numbers);
	$f=0;
	for ($i=0; $i < $size; $i++) {
		if ($numbers[$i] == $guess) {
		$f = 1;
		echo "YOU GUESSED THE NUMBER RIGHT! GOOD JOB, BUT NOT REALLY BECAUSE GUESSING A NUMBER DOESN'T REQUIRE ANY SKILLS.";
		}		
}
if ($f==0) {
	echo "YOU GUESSED IT WRONG. YOU SUCK.";	
}

?>

<form method="POST" action="guess.php" style="text-align:center;">
        <input type="submit" value="TRY ANOTHER GUESS" />
</form>

</body>

</html>
