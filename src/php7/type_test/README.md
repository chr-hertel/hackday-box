To install:

    cd /opt/type_test/extension
    phpize
    ./configure
    sudo make install
    
add extension to `/etc/php/7.0/mods-available/devbox.ini`

    extension=type_test.so
    
execute `test.php`

    php /opt/type_test/test.php
    
