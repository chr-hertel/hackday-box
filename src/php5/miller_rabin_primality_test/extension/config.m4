PHP_ARG_ENABLE(miller_rabin_primality_test, whether to enable miller rabin primality test,
[ --enable-miller-rabin-primality-test   Enable miller rabin primality test extension])

if test "$PHP_MILLER_RABIN_PRIMALITY_TEST" = "yes"; then
  AC_DEFINE(HAVE_MILLER_RABIN_PRIMALITY_TEST, 1, [Whether you have miller rabin primality test])
  PHP_NEW_EXTENSION(miller_rabin_primality_test, miller_rabin_primality_test.c, $ext_shared)
fi