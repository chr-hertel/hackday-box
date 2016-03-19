<?php

namespace PharDemo\Command;

use Symfony\Component\Console\Command\Command;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Output\OutputInterface;
use Symfony\Component\Process\Process;

class ServerCommand extends Command
{
    protected function configure()
    {
        $this
            ->setName('run')
        ;
    }

    protected function execute(InputInterface $input, OutputInterface $output)
    {
        $webRoot = __DIR__.'/../../web/';
        $cmd = '/usr/bin/php -S localhost:8000 -t '.$webRoot;

        $output->writeln($cmd);

        $process = new Process($cmd);
        $process->run();
    }
}