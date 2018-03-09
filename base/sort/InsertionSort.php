<?php

function insertion_sort(array &$arr)
{
    $i = $j = 0;
    for ($i = 1; $i < count($arr); $i++) {
        //本次要插入到目标
        $target = $arr[$i];

        //若这是第x次插入，则前面x-1位数据应该是已经排序好的
        //则将这个数与前面排序好到数以此进行比较然后插入到指定到位置
        //先从后往前比较若target较小则数据往后移
        for ($j = $i; $j > 0 && $arr[$j - 1] > $target; $j--) {
            $arr[$j] = $arr[$j - 1];
        }
        //直到target不小于前面已经排序的数组，则可插入
        $arr[$j] = $target;
    }
}

$arr = [61, 17, 29, 22, 22, 34, 60, 72, 72, 21, 50, 1, 62];
insertion_sort($arr);

foreach ($arr as $v) {
    echo "[$v]";
}   