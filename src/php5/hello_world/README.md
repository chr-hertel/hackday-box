To install:

    cd /opt/hello_world/extension
    phpize
    ./configure
    sudo make install
    
add extension to `/etc/php5/mods-available/devbox.ini`

    extension=hello_world.so
    
execute `test.php`

    php /opt/hello_world/test.php
    
