# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|

  config.vm.provider :virtualbox do |v|
    v.customize ["modifyvm", :id, "--natdnshostresolver1", "on"]
    v.customize ["modifyvm", :id, "--memory", 1024]
  end

  # php5
  config.vm.define "php5" do |php5|
    php5.vm.box = "ubuntu/trusty64"

    php5.ssh.forward_agent = true
    php5.vm.network "private_network", ip: "10.0.11.77"

    php5.vm.synced_folder ".", "/vagrant", disabled: true
    php5.vm.synced_folder "src/php5", "/home/vagrant"

    php5.vm.provision :ansible do |ansible|
        ansible.playbook = "ansible/php5.yml"
    end
  end

  # php7
  config.vm.define "php7" do |php7|
    php7.vm.network "private_network", ip: "10.0.11.78"

    php7.vm.synced_folder "src/php7", "/home/vagrant"

    php7.vm.provision :ansible do |ansible|
        ansible.playbook = "ansible/php7.yml"
    end
  end

end

