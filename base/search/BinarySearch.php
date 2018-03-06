<?php

function binary_search(array $arr, $start, $end, $target)
{
    $ret = -1;//未搜索到，返回-1下标

    while ($start <= $end) {
        $mid = intval($start + ($end - $start) / 2);
        if ($arr[$mid] < $target)
            $start = $mid + 1;
        else if ($arr[$mid] > $target)
            $end = $mid - 1;
        else {
            $ret = $mid;
            break;
        }
    }
    return $ret;
}

$arr = [1, 3, 4, 6, 7, 8, 10, 13, 14];

echo binary_search($arr, 1, count($arr) - 1, 13) . "\n";

