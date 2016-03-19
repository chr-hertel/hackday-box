To install:

    cd /opt/miller_rabin_primality_test/extension
    phpize
    ./configure
    sudo make install
    
add extension to `/etc/php5/mods-available/devbox.ini`

    extension=miller_rabin_primality_test.so
    
execute `test.php`

    php /opt/miller_rabin_primality_test/test.php
    
