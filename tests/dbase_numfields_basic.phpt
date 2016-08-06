--TEST--
dbase_numfields(): basic functionality
--SKIPIF--
<?php
if (!extension_loaded('dbase')) die('skip dbase extension not available');
?>
--FILE--
<?php
$filename = __DIR__ . DIRECTORY_SEPARATOR . 'dbase_numfields_basic.dbf';
copy(__DIR__ . DIRECTORY_SEPARATOR . 'example.dbf', $filename);

$db = dbase_open($filename, 2);
var_dump($db);

var_dump(dbase_numfields($db));

var_dump(dbase_close($db));
?>
===DONE===
--EXPECTF--
int(%d)
int(5)
bool(true)
===DONE===
--CLEAN--
<?php
$filename = __DIR__ . DIRECTORY_SEPARATOR . 'dbase_numfields_basic.dbf';
unlink($filename);
?>