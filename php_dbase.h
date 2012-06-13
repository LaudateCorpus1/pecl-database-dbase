/*
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2008 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Jim Winstead <jimw@php.net>                                  |
   +----------------------------------------------------------------------+
*/

/* $Id: php_dbase.h,v 1.18 2007/12/31 07:12:08 sebastian Exp $ */

#ifndef PHP_DBASE_H
#define PHP_DBASE_H
#if DBASE
extern zend_module_entry dbase_module_entry;
#define dbase_module_ptr &dbase_module_entry

PHP_MINIT_FUNCTION(dbase);
PHP_FUNCTION(dbase_open);
PHP_FUNCTION(dbase_create);
PHP_FUNCTION(dbase_close);
PHP_FUNCTION(dbase_numrecords);
PHP_FUNCTION(dbase_numfields);
PHP_FUNCTION(dbase_add_record);
PHP_FUNCTION(dbase_get_record);
PHP_FUNCTION(dbase_delete_record);
PHP_FUNCTION(dbase_pack);
PHP_FUNCTION(dbase_get_record_with_names);
PHP_FUNCTION(dbase_get_header_info);
#else
#define dbase_module_ptr NULL
#endif

#define phpext_dbase_ptr dbase_module_ptr

/*
 * zend_list_insert() has changed its prototype as of PHP 5.4
 */
#if PHP_VERSION_ID >= 50400
#define ZEND_LIST_CC TSRMLS_CC
#else
#define ZEND_LIST_CC
#endif

#endif /* PHP_DBASE_H */
