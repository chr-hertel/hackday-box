PHP_ARG_ENABLE(type_test, whether to enable type test,
[ --enable-type-test   Enable type extension])

if test "$PHP_TYPE_TEST" = "yes"; then
  AC_DEFINE(HAVE_TYPE_TEST, 1, [Whether you have type test])
  PHP_NEW_EXTENSION(type_test, type_test.c, $ext_shared)
fi