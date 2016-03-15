Hackday VM
==========

Requirements
------------

* VirtualBox
* Vagrant
* Ansible

Idea
----

* separate vm for
    * php 5.6 + dev
    * php 7.0 + dev
    * hhvm
    * zephir

    
How to start
------------

* clone repository

    ```
    git clone git@github.com:chr-hertel/hackday-box.git
    ```
    
* create specific vm

    ```
    vagrant up [php5]
    ```
    
    vm names: php5, php7, hhvm & zephir
    
* enter vm

    ```
    vagrant ssh
    ```
    
Sidenotes
---------

* ensure to re-provision after pulling
* more about zephir: https://github.com/phalcon/zephir
* more about hhvm: http://hhvm.com/
* PRs are welcome
