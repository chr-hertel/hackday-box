Hackday VM
==========

Requirements
------------

* VirtualBox
* Vagrant
* Ansible

Idea
----

* master branch as base
* separate branches for
    * php 5.6 + dev
    * php 7.0 + dev
    * hhvm (TODO)
    * zephir (TODO)
    
How to start
------------

* clone repository

    ```
    git clone git@github.com:chr-hertel/hackday-box.git
    ```
    
* checkout specific branch

    ```
    git checkout php7
    ```
    
* create vm

    ```
    vagrant up
    ```
    
* enter vm

    ```
    vagrant ssh
    ```
    
Sidenotes
---------

* ensure to re-provision after checking out
* there might be some conflicts while switching branches
* PRs are welcome
