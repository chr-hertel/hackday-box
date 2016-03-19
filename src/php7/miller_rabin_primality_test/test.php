<?php
$start = microtime(true);

$limit = 10000000;

$maxOne = 1373653;
$maxTwo = 9080191;

for($number=5;$number<$limit;$number++) {
    $isPrime = false;
    if($number < $maxOne){
        $isPrime = miller_rabin_primality_test($number,2) && miller_rabin_primality_test($number,3);
    }else if($number < $maxTwo){
        $isPrime = miller_rabin_primality_test($number,31) && miller_rabin_primality_test($number,73);
    }

    //echo "Is " . $number . " a prime? " . ($isPrime ? 'yes':'no').PHP_EOL;
}

echo (microtime(true)-$start).PHP_EOL;