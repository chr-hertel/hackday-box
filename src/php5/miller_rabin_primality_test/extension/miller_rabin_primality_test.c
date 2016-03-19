#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "php.h"

#define PHP_MILLER_RABIN_PRIMALITY_TEST_VERSION "1.0"
#define PHP_MILLER_RABIN_PRIMALITY_TEST_EXTNAME "miller_rabin_primality_test"

extern zend_module_entry miller_rabin_primality_test_module_entry;
#define phpext_miller_rabin_primality_test_ptr &miller_rabin_primality_test_module_entry

// declaration of a custom miller_rabin_primality_test()
PHP_FUNCTION(miller_rabin_primality_test);

// list of custom PHP functions provided by this extension
// set {NULL, NULL, NULL} as the last record to mark the end of list
static zend_function_entry miller_rabin_primality_test_functions[] = {
    PHP_FE(miller_rabin_primality_test, NULL)
    {NULL, NULL, NULL}
};

// the following code creates an entry for the module and registers it with Zend.
zend_module_entry miller_rabin_primality_test_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_MILLER_RABIN_PRIMALITY_TEST_EXTNAME,
    miller_rabin_primality_test_functions,
    NULL, // name of the MINIT function or NULL if not applicable
    NULL, // name of the MSHUTDOWN function or NULL if not applicable
    NULL, // name of the RINIT function or NULL if not applicable
    NULL, // name of the RSHUTDOWN function or NULL if not applicable
    NULL, // name of the MINFO function or NULL if not applicable
#if ZEND_MODULE_API_NO >= 20010901
    PHP_MILLER_RABIN_PRIMALITY_TEST_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(miller_rabin_primality_test)

// implementation of a custom php function()
PHP_FUNCTION(miller_rabin_primality_test)
{

    long n;
    long a;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ll", &n, &a) == FAILURE) {
        RETURN_FALSE;
    }

    if(mrt(n,a) == 1){
        RETURN_TRUE;
    }
    RETURN_FALSE;
}
//https://de.wikipedia.org/wiki/Miller-Rabin-Test#Implementierung
int mrt (const uint32_t n, const uint32_t a) { // n ungerade, 1 < a < n-1

    if(n % 2 == 0){
        return 0;
    }

    const uint32_t n1 = n - 1;
    uint32_t d = n1 >> 1;
    int j = 1;
    while ((d & 1) == 0) d >>= 1, ++j;
    uint64_t t = a, p = a;
    while (d >>= 1) { //square and multiply: a^d mod n
        p = p*p % n;
        if (d & 1) t = t*p % n;
    }
    if (t == 1 || t == n1) return 1; // n ist wahrscheinlich prim
    int k = 1;
    for (k ; k<j ; ++k) {
        t = t*t % n;
        if (t == n1) return 1;
        if (t <= 1) break;
    }
    return 0; // n ist nicht prim
}