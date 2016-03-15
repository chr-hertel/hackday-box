# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
  config.vm.box = "ubuntu/trusty64"

  if ENV["PROCESSOR_ARCHITECTURE"] == "x86"
    puts "falling back to 32-bit guest architecture"
    config.vm.box = "ubuntu/trusty32"
  end

  config.ssh.forward_agent = true
  config.vm.network "private_network", ip: "10.0.11.77"

  config.vm.synced_folder ".", "/vagrant", disabled: true

  config.vm.provider :virtualbox do |v|
    v.customize ["modifyvm", :id, "--natdnshostresolver1", "on"]
    v.customize ["modifyvm", :id, "--memory", 1024]
    v.customize ["modifyvm", :id, "--name", "hackday-box"]
  end

  config.vm.provision :ansible do |ansible|
    ansible.playbook = "ansible/main.yml"
  end
end

