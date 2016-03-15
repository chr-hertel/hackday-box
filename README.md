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
    * php 5.6 + dev -> php5
    * php 7.0 + dev -> php7
    * hhvm (TODO) -> hhvm
    * zephir (TODO) -> zephir

    
How to start
------------

* clone repository

    ```
    git clone git@github.com:chr-hertel/hackday-box.git
    ```
    
* create specific vm

    ```
    vagrant up php5
    ```
    
* enter vm

    ```
    vagrant ssh
    ```
    
Sidenotes
---------

* ensure to re-provision after checking out
* PRs are welcome
