To install:

    cd /opt/miller_rabin_primality_test/extension
    phpize
    ./configure
    sudo make install
    
add extension to `/etc/php5/mods-available/devbox.ini`

    extension=miller_rabin_primality_test.so
    
execute `test.php`

    php /opt/miller_rabin_primality_test/test.php
    
Web-Links

    C Implementation
    [https://de.wikipedia.org/wiki/Miller-Rabin-Test#Implementierung]

    PHP Implementation
    [https://rosettacode.org/wiki/Miller%E2%80%93Rabin_primality_test#PHP]
