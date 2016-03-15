# -*- mode: ruby -*-
# vi: set ft=ruby :

boxes = [
    {
        :name => "php5",
        :ip => "10.0.11.77"
    },
    {
        :name => "php7",
        :ip => "10.0.11.78"
    },
    {
        :name => "hhvm",
        :ip => "10.0.11.79"
    },
    {
        :name => "zephir",
        :ip => "10.0.11.80"
    }
]

Vagrant.configure(2) do |config|

  config.vm.box = "ubuntu/trusty64"
  config.ssh.forward_agent = true
  config.vm.synced_folder ".", "/vagrant", disabled: true

  boxes.each do |opts|
    config.vm.define opts[:name] do |config|
      config.vm.network :private_network, ip: opts[:ip]
      config.vm.synced_folder "src/#{opts[:name]}/", "/opt"

      config.vm.provider :virtualbox do |v|
        v.customize ["modifyvm", :id, "--natdnshostresolver1", "on"]
        v.customize ["modifyvm", :id, "--memory", 1024]
        v.customize ["modifyvm", :id, "--name", "hackday-box-#{opts[:name]}"]
      end

      config.vm.provision :ansible do |ansible|
        ansible.playbook = "ansible/#{opts[:name]}.yml"
      end
    end
  end

end
