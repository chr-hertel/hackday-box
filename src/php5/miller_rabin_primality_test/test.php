<?php
$lowest = 19100000;
$limit =  19110000;

$maxOne = 1373653;
$maxTwo = 9080191;
$maxThree = 4759123141;

echo "Range is " .$lowest.' - '.$limit.PHP_EOL;
echo "Amount of numbers to check " .($limit - $lowest).PHP_EOL;

$start = microtime(true);
for($number=$lowest;$number<$limit;$number++) {
    $isPrime = false;

    if($number < $maxOne){
        $isPrime = miller_rabin_primality_test($number,2) && miller_rabin_primality_test($number,3);
    }else if($number >= $maxOne && $number < $maxTwo){
        $isPrime = miller_rabin_primality_test($number,31) && miller_rabin_primality_test($number,73);
    }else if($number >= $maxTwo && $number < $maxThree){
        $isPrime = miller_rabin_primality_test($number,2) && miller_rabin_primality_test($number,7) && miller_rabin_primality_test($number,61);
    }
    //echo "Is " . $number . " a prime? " . ($isPrime ? 'yes':'no').PHP_EOL;
}
$cNeeded = microtime(true)-$start;
echo 'c needed for ' . $cNeeded.PHP_EOL;

$start = microtime(true);
for($number=$lowest;$number<$limit;$number++) {
    $isPrime = false;
    if($number < $maxOne){
        $isPrime = pmiller_rabin_primality_test($number,2) && pmiller_rabin_primality_test($number,3);
    }else if($number >= $maxOne && $number < $maxTwo){
        $isPrime = pmiller_rabin_primality_test($number,31) && pmiller_rabin_primality_test($number,73);
    }else if($number >= $maxTwo && $number < $maxThree){
        $isPrime = pmiller_rabin_primality_test($number,2) && pmiller_rabin_primality_test($number,7) && pmiller_rabin_primality_test($number,61);
    }
    //echo "Is " . $number . " a prime? " . ($isPrime ? 'yes':'no').PHP_EOL;
}
$phpNeeded=microtime(true)-$start;
echo 'php needed for ' . $phpNeeded.PHP_EOL;


echo "c is " .($phpNeeded / $cNeeded) . " times faster".PHP_EOL;
echo "comparing results".PHP_EOL;

for($number=$lowest;$number<$limit;$number++) {
    $isPrimePHP = false;
    if($number < $maxOne){
        $isPrime = miller_rabin_primality_test($number,2) && miller_rabin_primality_test($number,3);
        $isPrimePHP = pmiller_rabin_primality_test($number,2) && pmiller_rabin_primality_test($number,3);
    }else if($number >= $maxOne && $number < $maxTwo){
        $isPrime = miller_rabin_primality_test($number,31) && miller_rabin_primality_test($number,73);
        $isPrimePHP = pmiller_rabin_primality_test($number,31) && pmiller_rabin_primality_test($number,73);
    }else if($number >= $maxTwo && $number < $maxThree){
        $isPrime = miller_rabin_primality_test($number,2) && miller_rabin_primality_test($number,7) && miller_rabin_primality_test($number,61);
        $isPrimePHP = pmiller_rabin_primality_test($number,2) && pmiller_rabin_primality_test($number,7) && pmiller_rabin_primality_test($number,61);
    }

    if($isPrime != $isPrimePHP){
        echo "Got different resuts for " . $number . ' c: '. $isPrime .' != php: ' . $isPrimePHP.PHP_EOL;
    }
}
echo "done".PHP_EOL;

// https://rosettacode.org/wiki/Miller%E2%80%93Rabin_primality_test#PHP
function pmiller_rabin_primality_test($n, $k) {
    if ($n == 2)
        return true;
    if ($n < 2 || $n % 2 == 0)
        return false;

    $d = $n - 1;
    $s = 0;

    while ($d % 2 == 0) {
        $d /= 2;
        $s++;
    }

    for ($i = 0; $i < $k; $i++) {
        $a = rand(2, $n-1);

        $x = bcpowmod($a, $d, $n);
        if ($x == 1 || $x == $n-1)
            continue;

        for ($j = 1; $j < $s; $j++) {
            $x = bcmod(bcmul($x, $x), $n);
            if ($x == 1)
                return false;
            if ($x == $n-1)
                continue 2;
        }
        return false;
    }
    return true;
}