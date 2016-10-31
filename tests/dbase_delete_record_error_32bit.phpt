--TEST--
dbase_delete_record(): error conditions
--SKIPIF--
<?php
if (!extension_loaded('dbase')) die('skip dbase extension not available');
if (PHP_INT_SIZE != 4) die('skip for 32bit platforms only');
?>
--FILE--
<?php
$filename = __DIR__ . DIRECTORY_SEPARATOR . 'dbase_delete_record_error.dbf';
$db = dbase_create($filename, [['foo', 'C', 15]]);
var_dump(dbase_delete_record($db, -1));
var_dump(dbase_delete_record($db, 2147483648));
?>
===DONE===
--EXPECTF--
Warning: dbase_delete_record(): record number has to be in range 1..2147483647, but is -1 in %s on line %d
bool(false)

Warning: dbase_delete_record() expects parameter 2 to be integer, float given in %s on line %d
NULL
===DONE===
--CLEAN--
<?php
unlink(__DIR__ . DIRECTORY_SEPARATOR . 'dbase_delete_record_error.dbf');
?>
