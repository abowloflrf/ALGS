<?php

function quick_sort(array $arr)
{
    $len = count($arr);
    if ($len <= 1)
        return $arr;
    //初始化数组
    $lessList = $greaterList = array();
    //基准元素定义为头一个元素
    $pivot = $arr[0];
    //从基准元素后一个元素开始遍历比较
    for ($i = 1; $i < $len; $i++) {
        if ($arr[$i] < $pivot)
            $lessList[] = $arr[$i]; //未指定下标表明添加到数组最后
        else
            $greaterList[] = $arr[$i];
    }
    return array_merge(quick_sort($lessList), array($pivot), quick_sort($greaterList));
}

$arr = [61, 17, 29, 22, 22, 34, 60, 72, 72, 21, 50, 1, 62];
$afterSort = quick_sort($arr);
foreach ($afterSort as $v) {
    echo "[$v]";
}   