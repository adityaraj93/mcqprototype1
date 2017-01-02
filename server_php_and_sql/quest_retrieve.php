<?php

	$conn=mysqli_connect('localhost', 'root', '','test');
	
	if ($conn->connect_error) {
		die("Connection failed: " . $conn->connect_error);
	}

	$query = "SELECT * FROM questions_type1";
	$res = mysqli_query($conn , $query);

	$xml = new XMLWriter();
	//$xml->openURI("abc.xml");
	$xml->openURI("php://output");
	$xml->startDocument('1.0','UTF-8');
	$xml->setIndent(true);

	$xml->startElement('qtype1');
    $xml->writeAttribute('total',$res->num_rows);
	$number=0;
	while ($row = mysqli_fetch_assoc($res)) {
		$xml->startElement("question");

		$xml->writeAttribute('number', ++$number);

		$xml->startElement("ques");
		$xml->writeRaw($row['ques']);
		$xml->endElement();

		$xml->startElement("code");
		$xml->writeRaw($row['code']);
		$xml->endElement();
		
		$xml->startElement("opta");
		$xml->writeRaw($row['opta']);
		$xml->endElement();
		
		$xml->startElement("optb");
		$xml->writeRaw($row['optb']);
		$xml->endElement();
		
		$xml->startElement("optc");
		$xml->writeRaw($row['optc']);
		$xml->endElement();
		
		$xml->startElement("optd");
		$xml->writeRaw($row['optd']);
		$xml->endElement();
		
		$xml->startElement("optright");
		$xml->writeRaw($row['optright']);
		$xml->endElement();
		
		$xml->endElement();
	}
	$xml->endElement();
	header('Content-type: text/xml');
	$xml->flush();
	mysqli_close($conn);
	//echo "done";
?>