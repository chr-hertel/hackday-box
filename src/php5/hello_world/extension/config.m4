PHP_ARG_ENABLE(hello_world, whether to enable hello world,
[ --enable-hello-world   Enable hello world extension])

if test "$PHP_HELLO_WORLD" = "yes"; then
  AC_DEFINE(HAVE_HELLO_WORLD, 1, [Whether you have hello world])
  PHP_NEW_EXTENSION(hello_world, hello_world.c, $ext_shared)
fi