#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "php.h"

#define PHP_EXTENSION_VERSION "1.0"
#define PHP_EXTENSION_NAME "type_test"

extern zend_module_entry type_test_module_entry;
#define phpext_type_test_ptr &type_test_module_entry

// declaration of return functions
PHP_FUNCTION(return_string);
PHP_FUNCTION(return_int);
PHP_FUNCTION(return_float);
PHP_FUNCTION(return_bool);
PHP_FUNCTION(return_null);
PHP_FUNCTION(return_float);
PHP_FUNCTION(return_array);

// list of custom PHP functions provided by this extension
// set {NULL, NULL, NULL} as the last record to mark the end of list
static zend_function_entry type_test_functions[] = {
    PHP_FE(return_string, NULL)
    PHP_FE(return_int, NULL)
    PHP_FE(return_float, NULL)
    PHP_FE(return_bool, NULL)
    PHP_FE(return_null, NULL)
    PHP_FE(return_array, NULL)
    PHP_FE_END
};

// the following code creates an entry for the module and registers it with Zend.
zend_module_entry type_test_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_EXTENSION_NAME,
    type_test_functions,
    NULL, // name of the MINIT function or NULL if not applicable
    NULL, // name of the MSHUTDOWN function or NULL if not applicable
    NULL, // name of the RINIT function or NULL if not applicable
    NULL, // name of the RSHUTDOWN function or NULL if not applicable
    NULL, // name of the MINFO function or NULL if not applicable
    PHP_EXTENSION_VERSION,
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(type_test)

// implementation of return functions
PHP_FUNCTION(return_string)
{
    RETURN_STRING("Return string", 1);
}

PHP_FUNCTION(return_int)
{
    RETURN_LONG(1234);
}

PHP_FUNCTION(return_float)
{
    RETURN_DOUBLE(12.34);
}

PHP_FUNCTION(return_bool)
{
    //RETURN_FALSE;
    //RETURN_TRUE;

    RETURN_BOOL(1);
}

PHP_FUNCTION(return_null)
{
    RETURN_NULL();
}

PHP_FUNCTION(return_array)
{
    char *mystr;
    zval *mysubarray;

    array_init(return_value);

    add_index_long(return_value, 42, 123);

    add_next_index_string(return_value, "I should now be found at index 43", 1);

    add_next_index_stringl(return_value, "I'm at 44!", 10, 1);

    mystr = estrdup("Forty Five");
    add_next_index_string(return_value, mystr, 0);

    add_assoc_double(return_value, "pi", 3.1415926535);

    ALLOC_INIT_ZVAL(mysubarray);
    array_init(mysubarray);
    add_next_index_string(mysubarray, "hello", 1);
    add_assoc_zval(return_value, "subarray", mysubarray);
}
