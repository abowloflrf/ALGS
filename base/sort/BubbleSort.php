<?php

function swap(&$a, &$b)
{
    $temp = $a;
    $a = $b;
    $b = $temp;
}

function bubble_sort(&$arr)
{
    $i = $j = 0;

    for ($i = 0; $i < count($arr); $i++)
        for ($j = 0; $j < count($arr) - $i - 1; $j++)
        if ($arr[$j] > $arr[$j + 1])
        swap($arr[$j], $arr[$j + 1]);
}

$arr = [61, 17, 29, 22, 22, 34, 60, 72, 72, 21, 50, 1, 62];
bubble_sort($arr);

foreach ($arr as $v) {
    echo "[$v]";
}   