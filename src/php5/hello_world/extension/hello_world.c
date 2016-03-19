#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "php.h"

#define PHP_HELLO_WORLD_VERSION "1.0"
#define PHP_HELLO_WORLD_EXTNAME "hello_world"

extern zend_module_entry hello_world_module_entry;
#define phpext_hello_world_ptr &hello_world_module_entry

// declaration of a custom hello_world()
PHP_FUNCTION(hello_world);
PHP_FUNCTION(hello_name);

// list of custom PHP functions provided by this extension
// set {NULL, NULL, NULL} as the last record to mark the end of list
static zend_function_entry hello_world_functions[] = {
    PHP_FE(hello_world, NULL)
    PHP_FE(hello_name, NULL)
    {NULL, NULL, NULL}
};

// the following code creates an entry for the module and registers it with Zend.
zend_module_entry hello_world_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_HELLO_WORLD_EXTNAME,
    hello_world_functions,
    NULL, // name of the MINIT function or NULL if not applicable
    NULL, // name of the MSHUTDOWN function or NULL if not applicable
    NULL, // name of the RINIT function or NULL if not applicable
    NULL, // name of the RSHUTDOWN function or NULL if not applicable
    NULL, // name of the MINFO function or NULL if not applicable
#if ZEND_MODULE_API_NO >= 20010901
    PHP_HELLO_WORLD_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(hello_world)

// implementation of a custom my_function()
PHP_FUNCTION(hello_world)
{
    RETURN_STRING("Hello world!", 1);
}

PHP_FUNCTION(hello_name)
{
    char *name;
    int name_len;
    char result[0];


    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &name_len) == FAILURE) {
        RETURN_NULL();
    }


    php_sprintf(result, "Hello %s", name);
    RETURN_STRING(result, 1);

}