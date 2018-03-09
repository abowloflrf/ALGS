<?php

function swap(int &$a, int &$b) : void
{
    $temp = $a;
    $a = $b;
    $b = $temp;
}

function selection_sort(&$arr)
{
    for ($i = 0; $i < count($arr) - 1; $i++) {
        $min = $i;
        for ($j = $i + 1; $j < count($arr); $j++)
            if ($arr[$j] < $arr[$min])
            $min = $j;
        swap($arr[$min], $arr[$i]);
    }
}


$arr = [61, 17, 29, 22, 22, 34, 60, 72, 72, 21, 50, 1, 62];
selection_sort($arr);

foreach ($arr as $v) {
    echo "[$v]";
} 